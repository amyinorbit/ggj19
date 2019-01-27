//===--------------------------------------------------------------------------------------------===
// driver.hpp - "Manages" the visual and story subsystems of the game
// This source is part of GGJ19
//
// Created on 2019-01-26 by Amy Parent <amy@amyparent.com>
// Copyright (c) 2019 IDSMLM Games
// Licensed under the MIT License
// =^•.•^=
//===--------------------------------------------------------------------------------------------===
#pragma once
#include <string>
#include <memory>

class GGJDriver;

class IOManaging {
public:
    virtual ~IOManaging() {}
    
    virtual void onStart(GGJDriver& driver) = 0;
    virtual bool onUpdate(GGJDriver& driver) = 0;
    virtual void onFinish(GGJDriver& driver) = 0;
    
    virtual void print(GGJDriver& driver, const std::string& str) = 0;
    virtual void clear(GGJDriver& driver) = 0;
};

class App {
public:
    virtual ~App() {}
    
    virtual void onStart(GGJDriver& driver) = 0;
    virtual void onFinish(GGJDriver& driver) = 0;
    
    virtual void handleInput(GGJDriver& driver, const std::string& str) = 0;
};

class GGJDriver {
public:
    GGJDriver(App& app, IOManaging& io);
    
    void run();
    void handleInput(const std::string& str);
    
    void print(const std::string& str);
    void clear();
    
private:
    App&        app_;
    IOManaging& io_;
};
