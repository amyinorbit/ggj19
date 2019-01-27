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

    parser_.addArticle("the");
    parser_.addArticle("a");
    parser_.addArticle("an");
    parser_.addArticle("to");
    parser_.addArticle("at");
}

void GGJ19::resetStory() {
    // Load in the story data
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

GGJEntity* GGJ19::checkCommand(const NLCommand& cmd) {
    const auto& links = current_->links;
    const auto it = std::find_if(links.begin(), links.end(), [&](const GGJLink& link) {
        return link.verb == cmd.verb && link.object == cmd.object;
    });
    return (it != links.end()) ? it->entity : nullptr;
}

void GGJ19::handleInput(GGJDriver& driver, const std::string& str) {
    auto result = parser_.parse(str);
    if(!result.first) {
        driver.print("> '" + str + "': nope\n");
        return;
    }
    
    auto command = result.second;
    auto next = checkCommand(command);
    if(!next) {
        driver.print("> '" + str + "': nuh-uh\n");
        return;
    }
    
    showEntity(driver, next);
}

void GGJ19::showEntity(GGJDriver& driver, GGJEntity* entity) {
    driver.clear();
    driver.print(entity->name + "\n\n");
    driver.print(entity->desc + "\n\n");
    current_ = entity;
}

bool GGJ19::handleSpecialVerb(GGJDriver& driver, NLCommand& cmd) {
    return false;
}
