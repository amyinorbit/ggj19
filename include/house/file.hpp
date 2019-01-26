//===--------------------------------------------------------------------------------------------===
// file.hpp - Representation of a loaded room file
// This source is part of GGJ19
//
// Created on 2019-01-26 by Amy Parent <amy@amyparent.com>
// Copyright (c) 2019 IDSMLM Games
// Licensed under the MIT License
// =^•.•^=
//===--------------------------------------------------------------------------------------------===
#pragma once
#include <iostream>
#include <string>
#include <utility>
#include <house/entity.hpp>
#include <house/utf8.h>

// class GGJFileLink {
//     std::string object;
//     std::string verb;
//     std::string key;
// };

struct GGJToken {
    enum Kind { Object, Room, Links, QuotedString, Identifier, Star, Comma, End };
    Kind kind;
    std::string text;
};

class GGJFile {
public:
    // enum class Kind { Room, Object };

    GGJFile(const std::string& key, std::istream& stream);
    const std::string& key() const;
    
    GGJEntity compile();
    const GGJToken& nextToken();
private:

    bool have(GGJToken::Kind kind);
    void match(GGJToken::Kind kind, const std::string& error = "invalid token");
    
    std::pair<GGJKind, std::string> recHeader();
    std::string recDescription();
    std::vector<GGJLink> recLinks();
    GGJLink recLink();
    
    // LEXER
    codepoint_t current() const;
    codepoint_t nextChar();
    std::size_t remaining() const;
    
    const GGJToken& makeToken(GGJToken::Kind kind, const std::string& str = "");
    
    bool isIdentifier(codepoint_t c);
    void updateTokenStart();
    
    const GGJToken& lexIdent();
    const GGJToken& lexKeyword();
    const GGJToken& lexString();
    

    std::string key_ = "";
    std::string file_ = "";
    
    std::size_t ptr_ = 0;
    std::size_t start_ = 0;
    
    codepoint_t current_;
    GGJToken    currentToken_;
};
