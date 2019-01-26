//===--------------------------------------------------------------------------------------------===
// parser.hpp - Adventure-style language parser
// This source is part of GGJ19
//
// Created on 2019-01-25 by Amy Parent <amy@amyparent.com>
// Copyright (c) 2019 IDSMLM Games
// Licensed under the MIT License
// =^•.•^=
//===--------------------------------------------------------------------------------------------===
#pragma once
#include <string>
#include <vector>
#include <utility>

#include <language/command.hpp>

struct NLVerb {
    NLVerb(const std::string& ident);
    bool matches(const std::string& ident) const;
    
    std::string                 keyword;
    std::vector<std::string>    synonyms;
};

class NLParser final {
public:
    
    using Result = std::pair<bool, NLCommand>;
    
    NLParser();
    ~NLParser();
    
    void addArticle(const std::string& article);
    void addVerb(const NLVerb& verb);
    
    Result parse(const std::string& phrase);
    
private:
    
    bool isVerb()
    
    std::vector<std::string>    articles;
    std::vector<NLVerb>    verbs;
};
