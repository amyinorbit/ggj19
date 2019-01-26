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

GGJDriver::GGJDriver(std::shared_ptr<App> app, std::shared_ptr<IOManaging> io)
: app_(app), io_(io) {
    
}

void GGJDriver::run() {
    if (!app_ || !io_) return;
    io_->onStart(*this);
    app_->onStart(*this);
    
    for(;;) {
        bool again = io_->onUpdate(*this);
        if(!again) break;
    }
    
    app_->onFinish(*this);
    io_->onFinish(*this);
}

void GGJDriver::handleInput(const std::string& str) {
    if (!app_) return;
    app_->handleInput(*this, str);
}

void GGJDriver::print(const std::string& str) {
    if (!io_) return;
    io_->print(*this, str);
}

void GGJDriver::clear() {
    if (!io_) return;
    io_->clear(*this);
}
