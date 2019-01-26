//===--------------------------------------------------------------------------------------------===
// loader.hpp - House loader
// This source is part of GGJ19
//
// Created on 2019-01-26 by Amy Parent <amy@amyparent.com>
// Copyright (c) 2019 IDSMLM Games
// Licensed under the MIT License
// =^•.•^=
//===--------------------------------------------------------------------------------------------===
#pragma once
#include <string>
#include <map>
#include <vector>
#include <house/file.hpp>

class GGJLoader {
public:
    
    GGJLoader(const std::string& root);
    
    const std::map<std::string, GGJEntity>& compileGraph();
    
private:
    void compile(const std::string& key);
    
    const std::string&                  rootKey_;
    
    std::map<std::string, GGJEntity>    entities_;
    std::map<std::string, GGJFile>      files_;
};

