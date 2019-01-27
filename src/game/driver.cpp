//===--------------------------------------------------------------------------------------------===
// driver.cpp - Implementation of the game driver
// This source is part of GGJ19
//
// Created on 2019-01-26 by Amy Parent <amy@amyparent.com>
// Copyright (c) 2019 IDSMLM Games
// Licensed under the MIT License
// =^•.•^=
//===--------------------------------------------------------------------------------------------===
#include <game/driver.hpp>

GGJDriver::GGJDriver(App& app, IOManaging& io)
: app_(app), io_(io) {
    
}

void GGJDriver::run() {
    io_.onStart(*this);
    app_.onStart(*this);
    
    for(;;) {
        bool again = io_.onUpdate(*this);
        if(!again) break;
    }
    
    app_.onFinish(*this);
    io_.onFinish(*this);
}

void GGJDriver::handleInput(const std::string& str) {
    app_.handleInput(*this, str);
}

void GGJDriver::print(const std::string& str) {
    io_.print(*this, str);
}

void GGJDriver::clear() {
    io_.clear(*this);
}
