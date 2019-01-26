//===--------------------------------------------------------------------------------------------===
// ggj19.hpp - Game Manager
// This source is part of GGJ19
//
// Created on 2019-01-26 by Amy Parent <amy@amyparent.com>
// Copyright (c) 2019 IDSMLM Games
// Licensed under the MIT License
// =^•.•^=
//===--------------------------------------------------------------------------------------------===
#pragma once
#include <string>
#include <vector>
#include <house/loader.hpp>
#include <house/entity.hpp>
#include <game/driver.hpp>
#include <language/parser.hpp>

class GGJ19: public App {
public:
    GGJ19();
    virtual ~GGJ19() {}
    
    virtual void onStart(GGJDriver& driver);
    virtual void onFinish(GGJDriver& driver);
    
    virtual void handleInput(GGJDriver& driver, const std::string& str);
    
private:
    GGJEntity* findEntity(const std::string& key);
    void resolveLinks(GGJEntity& entity);
    
    GGJEntity* checkCommand(const NLCommand& cmd);
    void showEntity(GGJDriver& driver, GGJEntity* entity);
    
    GGJEntity*              current_ = nullptr;
    NLParser                parser_ = NLParser();
    GGJLoader               loader_ = GGJLoader("intro.txt", "assets/");
    std::vector<GGJEntity>  entities_;
};
