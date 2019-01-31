//===--------------------------------------------------------------------------------------------===
// sdlio.cpp - Implemenation of the SDL-backed io system
// This source is part of GGJ19
//
// Created on 2019-01-26 by Amy Parent <amy@amyparent.com>
// Copyright (c) 2019 IDSMLM Games
// Licensed under the MIT License
// =^•.•^=
//===--------------------------------------------------------------------------------------------===
#include <cstdint>
#include <iostream>
#include <game/sdlio.hpp>
#include <game/font.h>

#define SDLIO_MARGIN 20

#ifdef __MINGW32__
#include <direct.h>
#else
#include <unistd.h>
#endif

SDLIO::SDLIO(int char_w, int char_h, int mul) {
    charWidth = char_w;
    charHeight = char_h;
    
    //inBuffer_ = "";
    //outBuffer_ = "";
    lagHead_ = 0;
    
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
        std::cerr << "cannot initialise SDL\n";
        abort();
    }
    
    width = ((char_w+2) * SDLIO_COLS) + (SDLIO_MARGIN*2);
    height = ((char_h+2) * SDLIO_ROWS) + (SDLIO_MARGIN*2);
    
    window_ = SDL_CreateWindow(
        "console", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        width * mul, height* mul,
        SDL_WINDOW_SHOWN | SDL_WINDOW_ALLOW_HIGHDPI | SDL_WINDOW_RESIZABLE
    );
    if (!window_) {
        std::cerr << "cannot create window\n";
        abort();
    }
    renderer_ = SDL_CreateRenderer(window_, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!renderer_) {
        std::cerr << "cannot create renderer\n";
        abort();
    }
    
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "0");
    SDL_RenderSetLogicalSize(renderer_, width, height);
    
    target_ = SDL_CreateTexture(
        renderer_, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_TARGET, width, height
    );
    SDL_SetTextureBlendMode(target_, SDL_BLENDMODE_BLEND);
	SDL_SetTextureAlphaMod(target_, 0x80);
	SDL_SetRenderDrawColor(renderer_, 0x00, 0x00, 0x00, 0xff);
	SDL_SetRenderDrawBlendMode(renderer_, SDL_BLENDMODE_ADD);
    
    std::cout << "Graphics subsystem init done\n";
    
    char *cpath = SDL_GetBasePath();     
    std::string path(cpath);
    SDL_free(cpath);
                     
#ifdef __MINGW32__
    path += "assets\\";
    _chdir(path.c_str());
#else
    chdir(path.c_str());
#endif
}

SDLIO::~SDLIO() {
    if (target_)
        SDL_DestroyTexture(target_);
    if (renderer_)
        SDL_DestroyRenderer(renderer_);
    if (window_)
        SDL_DestroyWindow(window_);
    SDL_Quit();
}

void SDLIO::onStart(GGJDriver& driver) {
    clear(driver);
    SDL_StartTextInput();
}

bool SDLIO::onUpdate(GGJDriver& driver) {
    
    bool result = doEvents(driver);
    clearScreenBuffer();
    blitOutput();
    blitInput();
    updateLag();
    
    if(dirty_) {
        SDL_SetRenderTarget(renderer_, target_);
        SDL_SetRenderDrawColor(renderer_, 0x08, 0x08, 0x02, 0xff);
        SDL_RenderClear(renderer_);
        
        for(std::uint64_t i = 0; i < SDLIO_COLS*SDLIO_ROWS; ++i) {
            drawChar(screen_[i], i);
        }
    }
    
	SDL_SetRenderTarget(renderer_, NULL);
    SDL_SetRenderDrawColor(renderer_, 0x10, 0x10, 0x10, 0x80);
    
	SDL_RenderCopy(renderer_, target_, NULL, NULL);
	SDL_RenderPresent(renderer_);
    return result;
}

bool SDLIO::doEvents(GGJDriver& driver) {
    SDL_Event e;
    while (SDL_PollEvent(&e) != 0) {
        
        if(e.type == SDL_QUIT) return false;
        
        if (e.type == SDL_KEYDOWN) {
            switch (e.key.keysym.sym) {
            case SDLK_BACKSPACE:
                if (inBuffer_.size()) {
                    inBuffer_.pop_back();
                }
                dirty_ = true;
                break;
                
            case SDLK_RETURN:
            {
                if (inBuffer_.size() > 0) {
                    driver.handleInput(inBuffer_);
                }
                inBuffer_.clear();
                dirty_ = true;
            }
                break;
            }
        }
        else if (e.type == SDL_TEXTINPUT) {
            inBuffer_ += e.text.text;
            dirty_ = true;
        }
    }
    return true;
}

void SDLIO::onFinish(GGJDriver& driver) {
    SDL_StopTextInput();
}

void SDLIO::print(GGJDriver& driver, const std::string& str) {
    outBuffer_ += str;
    dirty_ = true;
}

void SDLIO::clearScreenBuffer() {
    for (int i = 0; i < SDLIO_COLS*SDLIO_ROWS; ++i) {
        screen_[i] = 0;
    }
}

void SDLIO::blitOutput() {
    int address = 0;
    int count = 0;
    
    for (char c: outBuffer_) {
        int line = address / SDLIO_COLS;
        if (line > (SDLIO_ROWS - 3)) {
            scrollUp();
            address -= SDLIO_COLS;
            line -= 1;
        }
        if (c == '\n') {
            address = (line+1) * SDLIO_COLS;
            continue;
        }
        if (c == ' ' && (address % SDLIO_COLS) == 0) continue;
        screen_[address] = c;
        address += 1;
        count += 1;
        
        if (count >= lagHead_) break;
    }
}

void SDLIO::blitInput() {
    int offset = (SDLIO_ROWS-1) * SDLIO_COLS;
    
    screen_[offset] = '>';
    for (int i = 0; i < (SDLIO_COLS-2) && i < inBuffer_.size(); ++i) {
        screen_[offset+2+i] = inBuffer_[i];
    }
}

void SDLIO::scrollUp() {
    for (int i = SDLIO_COLS; i < SDLIO_COLS*SDLIO_ROWS; ++i) {
        screen_[i - SDLIO_COLS] = screen_[i];
        screen_[i] = '\0';
    }
    dirty_ = true;
}

void SDLIO::updateLag() {
    if(lagHead_ == outBuffer_.size()) return;
    dirty_ = true;
    lagHead_ += 1;
}

static inline int get_bit(std::uint8_t byte, int idx) {
	int ix = (7-idx);
	return (byte & (0b1 << ix)) >> ix;
}

void SDLIO::drawChar(char c, int index) {
    int cx = index % SDLIO_COLS;
    int cy = index / SDLIO_COLS;
    drawChar(c, cx, cy);
}

void SDLIO::drawChar(char c, int cx, int cy) {
    
    int px = 1+(cx * (charWidth+2)) + SDLIO_MARGIN;
    int py = 1+(cy * (charHeight+2)) + SDLIO_MARGIN;
    
    if (c < 32) return;
    if (c > 127) return;
    
    uint8_t* glyph = appleII_font[c-32];
    for (int y = 0; y < charHeight; ++y) {
        for (int x = 0; x < charWidth; ++x) {
            if (get_bit(glyph[x], y)) {
                SDL_SetRenderDrawColor(renderer_, 0xb9, 0x90, 0x05, 0xff);
                SDL_RenderDrawPoint(renderer_, px+x, py+y);
            }
        }
    }
}

void SDLIO::clear(GGJDriver& driver) {
    lagHead_ = 0;
    dirty_ = true;
    outBuffer_.clear();
}
