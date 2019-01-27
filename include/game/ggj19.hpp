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
#include <set>
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
    void resetStory();
    GGJEntity* findEntity(const std::string& key);
    void resolveLinks(GGJEntity& entity);
    
    void showEntity(GGJDriver& driver, GGJEntity* entity);
    
    // Handles non-story related verbs, or things that can change inventory and all
    // Returns true if the verb has been fully handled and there is no need for the game to
    // take further action
    GGJEntity* handleVerb(GGJDriver& driver, NLCommand& cmd);
    
    GGJEntity* handleTake(GGJDriver& driver, NLCommand& cmd);
    GGJEntity* handleInventory(GGJDriver& driver);
    GGJEntity* handleHelp(GGJDriver& driver);
    GGJEntity* handleLink(GGJDriver& driver, NLCommand& cmd);
    GGJEntity* handleReset(GGJDriver& driver);
    
    GGJEntity*              current_ = nullptr;
    NLParser                parser_ = NLParser();
    GGJLoader               loader_ = GGJLoader("intro.txt");
    
    std::vector<GGJEntity>  entities_;
    std::set<std::string>   inventory_;
};
