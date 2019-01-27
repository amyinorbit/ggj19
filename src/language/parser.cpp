//===--------------------------------------------------------------------------------------------===
// parser.cpp - Adventure-style language parser
// This source is part of GGJ19
//
// Created on 2019-01-25 by Amy Parent <amy@amyparent.com>
// Copyright (c) 2019 IDSMLM Games
// Licensed under the MIT License
// =^•.•^=
//===--------------------------------------------------------------------------------------------===
#include <algorithm>
#include <cassert>
#include <language/lexer.hpp>
#include <language/parser.hpp>

NLVerb::NLVerb(const std::string& ident)
: keyword(ident)
, synonyms(0) {}

bool NLVerb::matches(const std::string& ident) const {
    const auto str = ident;
    if (str == keyword) return true;
    
    for (const auto& syn: synonyms) {
        if (syn == str) return true;
    }
    return false;
}


NLParser::NLParser() {
    
}

NLParser::~NLParser() {
    
}

void NLParser::addArticle(const std::string& article) {
    articles.push_back(article);
}

void NLParser::addVerb(const NLVerb& verb) {
    verbs.push_back(verb);
}

// RECURSIVE DESCENT YAY

bool NLParser::isVerb(const NLLexer& lexer) {
    const auto& result = lexer.currentToken();
    const auto& tok = result.first;
    const auto eof = result.second;
    if (eof) return false;
    
    const auto it = std::find_if(verbs.begin(), verbs.end(), [tok=tok](const NLVerb& verb) {
        return verb.matches(tok);
    });
    return it != verbs.end();
}

bool NLParser::isArticle(const NLLexer& lexer) {
    const auto& result = lexer.currentToken();
    const auto& tok = result.first;
    const auto eof = result.second;
    if (eof) return false;
    return std::find(articles.begin(), articles.end(), tok) != articles.end();
}

std::string NLParser::canonicalVerb(const NLLexer& lexer) {
    const auto& result = lexer.currentToken();
    const auto& tok = result.first;
    const auto eof = result.second;
    
    assert(!eof && "invalid token!");
    const auto it = std::find_if(verbs.begin(), verbs.end(), [tok=tok](const NLVerb& verb) {
        return verb.matches(tok);
    });
    assert(it != verbs.end() && "invalid verb!");
    return it->keyword;
}

NLParser::Result NLParser::parse(const std::string& phrase) {
    auto lexer = NLLexer(phrase);
    
    auto command = NLCommand();
    command.object = "";
    command.complement = "";
    
    if (!isVerb(lexer)) return std::make_pair(false, NLCommand());
    command.verb = canonicalVerb(lexer);
    lexer.nextToken();
    
    while (isArticle(lexer)) {
        lexer.nextToken();
    }
    
    while (!lexer.currentToken().second) {
        if (command.object.size() > 0) command.object += " ";
        command.object += lexer.currentToken().first;
        lexer.nextToken();
    }
    return std::make_pair(true, command);
}
