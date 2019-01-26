//===--------------------------------------------------------------------------------------------===
// loader.cpp - Implementation of the recursive house loader
// This source is part of GGJ19
//
// Created on 2019-01-26 by Amy Parent <amy@amyparent.com>
// Copyright (c) 2019 IDSMLM Games
// Licensed under the MIT License
// =^•.•^=
//===--------------------------------------------------------------------------------------------===
#include <fstream>
#include <iostream>
#include <house/loader.hpp>
#include <house/file.hpp>

GGJLoader::GGJLoader(const std::string& root) : rootKey_(root) {
    
}

const std::map<std::string, GGJEntity>& GGJLoader::compileGraph() {
    if (entities_.empty()) {
        compile(rootKey_);
    }
    return entities_;
}

void GGJLoader::compile(const std::string& key) {
    if (files_.find(key) != files_.end()) return;
    
    std::ifstream in(key);
    if(!in.is_open()) {
        std::cerr << "file '" << key << "' not found\n";
        abort();
    }
    
    GGJFile file(key, in);
    
    const auto entity = file.compile();
    
    entities_[key] = entity;
    files_.emplace(std::make_pair(key, file));
    
    for (const auto& link: entity.links) {
        compile(link.key);
    }
}