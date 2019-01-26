//===--------------------------------------------------------------------------------------------===
// sdlio.hpp - SDL-based vintage CRT console
// This source is part of GGJ19
//
// Created on 2019-01-26 by Amy Parent <amy@amyparent.com>
// Copyright (c) 2019 IDSMLM Games
// Licensed under the MIT License
// =^•.•^=
//===--------------------------------------------------------------------------------------------===
#pragma once
#include <game/driver.hpp>
#include <SDL.h>

#define SDLIO_COLS 40
#define SDLIO_ROWS 28

class SDLIO: public IOManaging {
public:
    
    SDLIO(int char_w, int char_h, int mul);
    virtual ~SDLIO();
    
    virtual void onStart(GGJDriver& driver);
    virtual bool onUpdate(GGJDriver& driver);
    virtual void onFinish(GGJDriver& driver);
    
    virtual void print(GGJDriver& driver, const std::string& str);
    virtual void clear(GGJDriver& driver);
private:
    
    void drawChar(char c, int index);
    void drawChar(char c, int x, int y);
    
    void blitOutput();
    void blitInput();
    
    void clearInput();
    void clearScreenBuffer();
    void updateLag();
    
    bool doEvents(GGJDriver& driver);
    
    char outBuffer_[SDLIO_COLS*SDLIO_ROWS * 2];
    
    char screen_[SDLIO_COLS*SDLIO_ROWS];
    char inBuffer_[SDLIO_COLS*2];
    
    int lagHead_;
    int printHead_;
    int inputHead_;
    int charWidth, charHeight;
    
    SDL_Window* window_;
    SDL_Renderer* renderer_;
    SDL_Texture* target_;
};
