//===--------------------------------------------------------------------------------------------===
// ggj19.cpp - Implementation of the main app class
// This source is part of GGJ19
//
// Created on 2019-01-26 by Amy Parent <amy@amyparent.com>
// Copyright (c) 2019 IDSMLM Games
// Licensed under the MIT License
// =^•.•^=
//===--------------------------------------------------------------------------------------------===
#include <algorithm>
#include <iostream>
#include <game/ggj19.hpp>

GGJ19::GGJ19() {
    // Set up natural language parser
    auto goVerb = NLVerb("go");
    goVerb.synonyms.push_back("enter");
    goVerb.synonyms.push_back("walk");

    auto useVerb = NLVerb("use");
    useVerb.synonyms.push_back("toggle");
    useVerb.synonyms.push_back("touch");
    
    auto takeVerb = NLVerb("take");
    takeVerb.synonyms.push_back("get");
    takeVerb.synonyms.push_back("grab");

    parser_.addVerb(goVerb);
    parser_.addVerb(useVerb);
    parser_.addVerb(takeVerb);
    
    parser_.addVerb(NLVerb("stand"));
    parser_.addVerb(NLVerb("look"));
    parser_.addVerb(NLVerb("open"));
    parser_.addVerb(NLVerb("farside"));
    
    parser_.addVerb(NLVerb("help"));
    parser_.addVerb(NLVerb("inventory"));
    parser_.addVerb(NLVerb("reset"));

    parser_.addArticle("the");
    parser_.addArticle("a");
    parser_.addArticle("an");
    parser_.addArticle("to");
    parser_.addArticle("at");
}

void GGJ19::resetStory() {
    // Load in the story data
    inventory_.clear();
    entities_.clear();
    const auto data = loader_.compileGraph();
    for (const auto& p: data) {
        entities_.push_back(p.second);
    }
    
    for (auto& entity: entities_) {
        resolveLinks(entity);
    }
    std::cout << entities_.size() << " entities loaded\n";
}

GGJEntity* GGJ19::findEntity(const std::string& key) {
    const auto it = std::find_if(entities_.begin(), entities_.end(), [&](const GGJEntity& entity) {
        return entity.key == key;
    });
    
    if (it == entities_.end()) {
        std::cerr << "Invalid entity link found\n";
        abort();
    }
    return &(*it);
}

void GGJ19::resolveLinks(GGJEntity& entity) {
    for (auto& link: entity.links) {
        link.entity = findEntity(link.key);
    }
}

void GGJ19::onStart(GGJDriver& driver) {
    resetStory();
    showEntity(driver, findEntity("intro.txt"));
}

void GGJ19::onFinish(GGJDriver& driver) {
    
}

void GGJ19::handleInput(GGJDriver& driver, const std::string& str) {
    auto result = parser_.parse(str);
    if(!result.first) {
        driver.print("> what?\n");
        return;
    }
    
    auto command = result.second;
    auto next = handleVerb(driver, command);
    if(next)
        showEntity(driver, next);
}

void GGJ19::showEntity(GGJDriver& driver, GGJEntity* entity) {
    driver.clear();
    driver.print(entity->name + "\n\n");
    driver.print(entity->desc + "\n\n");
    current_ = entity;
}

GGJEntity* GGJ19::handleVerb(GGJDriver& driver, NLCommand& cmd) {
    if (cmd.verb == "take")
        return handleTake(driver, cmd);
    if (cmd.verb == "inventory")
        return handleInventory(driver);
    if (cmd.verb == "help")
        return handleHelp(driver);
    if (cmd.verb == "reset")
        return handleReset(driver);
    return handleLink(driver, cmd);
}

GGJEntity* GGJ19::handleTake(GGJDriver& driver, NLCommand& cmd) {
    auto& links = current_->links;
    const auto it = std::find_if(links.begin(), links.end(), [&](const GGJLink& link) {
        return link.verb == cmd.verb && link.object == cmd.object;
    });
    if (it == links.end()) {
        driver.print("> nopity nope\n");
        return nullptr;
    }
    const auto link = *it;
    
    inventory_.insert(link.object);
    links.erase(it);
    return link.entity;
}

GGJEntity* GGJ19::handleInventory(GGJDriver& driver) {
    driver.print("\nyou have:\n");
    for (const auto& obj: inventory_) {
        driver.print(" - " + obj);
    }
    return nullptr;
}

GGJEntity* GGJ19::handleHelp(GGJDriver& driver) {
    driver.print("\ncommands:\n - go [to] (enter, walk)\n - use (toggle, touch)\n - take (get, grab)\n - stand\n - look\n - open\n - go back\n - inventory");
    return nullptr;
}


GGJEntity* GGJ19::handleLink(GGJDriver& driver, NLCommand& cmd) {
    const auto& links = current_->links;
    const auto it = std::find_if(links.begin(), links.end(), [&](const GGJLink& link) {
        return link.verb == cmd.verb && link.object == cmd.object;
    });
    if (it == links.end()) {
        driver.print("> nah, you can't do that\n");
        return nullptr;
    }
    
    if (!it->lock.size()) return it->entity;
    
    // We need an item from the inventory:
    const auto lock = it->lock;
    const auto item = inventory_.find(lock);
    if (item != inventory_.end()) return it->entity;
    
    driver.print("> Nuh-uh. You need '" + lock + "'");
    return nullptr;
}

GGJEntity* GGJ19::handleReset(GGJDriver& driver) {
    resetStory();
    return findEntity("intro.txt");
}
