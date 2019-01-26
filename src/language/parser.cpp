//===--------------------------------------------------------------------------------------------===
// parser.cpp - Adventure-style language parser
// This source is part of GGJ19
//
// Created on 2019-01-25 by Amy Parent <amy@amyparent.com>
// Copyright (c) 2019 IDSMLM Games
// Licensed under the MIT License
// =^•.•^=
//===--------------------------------------------------------------------------------------------===
#include <language/parser.hpp>

NLVerb::NLVerb(const std::string& ident)
: keyword(ident)
, synonyms(0) {}

bool NLVerbs::matches(const std::string& ident) const {
    const auto str = ident;
    if (str == keyword) return true;
    
    for (const auto& syn: synonyms) {
        if (syn == str) return true
    }
    
    return false;
}


NLParser::NLParser() : articles(0), verbs(0) {
    
}

NLParser::~NLParser() {
    
}

void NLParser::addArticle(const std::string& article) {
    articles.push_back(article);
}

void NLParser::addVerb(const NLVerb& verb) {
    verbs.push_back(verb);
}

void NLParser::parse(const std::string&) {
    
}
