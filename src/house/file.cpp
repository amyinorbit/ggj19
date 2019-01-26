//===--------------------------------------------------------------------------------------------===
// file.cpp - Implementation of loaded room files
// This source is part of GGJ19
//
// Created on 2019-01-26 by Amy Parent <amy@amyparent.com>
// Copyright (c) 2019 IDSMLM Games
// Licensed under the MIT License
// =^•.•^=
//===--------------------------------------------------------------------------------------------===
#include <algorithm>
#include <cctype>
#include <iostream>
#include <cassert>
#include <house/file.hpp>

GGJFile::GGJFile(const std::string& key, std::istream& stream) {
    key_ = key;
    file_ = std::string(std::istreambuf_iterator<char>(stream), {});
}

GGJEntity GGJFile::compile() {
    GGJEntity entity;
    ptr_ = 0;
    
    nextToken();
    const auto [kind, name] = recHeader();
    
    entity.kind = kind;
    entity.name = name;
    entity.desc = recDescription();
    entity.links = recLinks();
    
    return entity;
}


bool GGJFile::have(GGJToken::Kind kind) {
    return currentToken_.kind == kind;
}

void GGJFile::match(GGJToken::Kind kind, const std::string& error) {
    if(have(kind)) {
        nextToken();
        return;
    }
    std::cerr << "error in file '" << key_ << "': " << error << "\n";
    abort();
}

std::pair<GGJKind, std::string> GGJFile::recHeader() {
    GGJKind kind;
    if (have(GGJToken::Room)) {
        nextToken();
        kind = GGJKind::Room;
    }
    else if (have(GGJToken::Object)) {
        nextToken();
        kind = GGJKind::Object;
    }
    else {
        std::cerr << "error in file '" << key_ << "': invalid entity type\n";
        abort();
    }
    
    const auto tok = currentToken_;
    match(GGJToken::QuotedString,  "Invalid entity name (not quoted?)");
    return std::make_pair(kind, tok.text);
}

std::string GGJFile::recDescription() {
    const auto tok = currentToken_;
    match(GGJToken::QuotedString, "Invalid entity description text (not quoted?)");
    return tok.text;
}

std::vector<GGJLink> GGJFile::recLinks() {
    std::vector<GGJLink> links;
    match(GGJToken::Links, "Links section not where expected");
    while(have(GGJToken::Star)) {
        links.push_back(recLink());
    }
    return links;
}

GGJLink GGJFile::recLink() {
    match(GGJToken::Star);
    
    const auto objTok = currentToken_;
    match(GGJToken::QuotedString, "Invalid link object name (not quoted?)");
    match(GGJToken::Comma);
    
    const auto verbTok = currentToken_;
    match(GGJToken::Identifier, "Invalid link verb '" + verbTok.text + "'");
    match(GGJToken::Comma);
    
    const auto keyTok = currentToken_;
    match(GGJToken::Identifier, "Invalid link file name '" + keyTok.text + "'");
    // match(GGJToken::Newline);
    
    GGJLink link;
    link.object = objTok.text;
    link.verb = verbTok.text;
    link.key = keyTok.text;
    link.entity = nullptr;
    return link;
}