//===--------------------------------------------------------------------------------------------===
// lexer.cpp - Lexing functions of the room parser
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

std::size_t GGJFile::remaining() const {
    return file_.length() - ptr_;
}

codepoint_t GGJFile::current() const {
    return utf8_getCodepoint(file_.data() + ptr_, remaining());
}

codepoint_t GGJFile::nextChar() {
    if (ptr_ >= file_.size()) return current_ = '\0';
    
    current_ = current();
    auto size = utf8_codepointSize(current_);
    if (size > 0) {
        ptr_ += size;
    }
    return current_;
}

bool GGJFile::isIdentifier(codepoint_t c) {
    return utf8_isIdentifier(c)
        || c == '-'
        || c == '/'
        || c == '.';
}

void GGJFile::updateTokenStart() {
    start_ = ptr_;
}

const GGJToken& GGJFile::lexIdent() {
    while(isIdentifier(current())) {
        nextChar();
    }
    
    const auto length = ptr_ - start_;
    return makeToken(GGJToken::Identifier, file_.substr(start_, length));
}

const GGJToken& GGJFile::lexKeyword() {
    while(isIdentifier(current())) {
        nextChar();
    }
    
    const auto length = ptr_ - start_;
    const auto str = file_.substr(start_, length);
    
    if (str == "@room") {
        return makeToken(GGJToken::Room);
    }
    if (str == "@object") {
        return makeToken(GGJToken::Object);
    }
    if (str == "@links") {
        return makeToken(GGJToken::Links);
    }
    std::cerr << "Invalid section keyword '" << str << "' in '" << key_ << "'\n";
    abort();
}

const GGJToken& GGJFile::lexString() {
    
    while(1) {
        codepoint_t c = nextChar();
        
        if(c == '"') break;
        if(c == '\0') {
            std::cerr << "quoted string not finished in '" << key_ << "'\n";
            abort();
        }
    }
    
    const auto length = (ptr_ - start_)-2;
    return makeToken(GGJToken::QuotedString, file_.substr(start_+1, length));
}

const GGJToken& GGJFile::makeToken(GGJToken::Kind kind, const std::string& str) {
    currentToken_.kind = kind;
    currentToken_.text = str;
    //std::cout << "[ " << currentToken_.kind << " ] " << currentToken_.text << "\n";
    return currentToken_;
}

const GGJToken& GGJFile::nextToken() {
    if (ptr_ >= file_.size()) {
        return makeToken(GGJToken::End);
    }
    
    while (current() != '\0') {
        updateTokenStart();
        codepoint_t c = nextChar();
        
        switch(c) {
            //whitespace
            case 0x0020:
            case 0x000d:
            case 0x0009:
            case 0x000b:
            case 0x000c:
            case 0x000a:
                break;

            // // line feed
            //     return makeToken(GGJToken::Newline);
            
            case ',':
                return makeToken(GGJToken::Comma);
                
            case '*':
                return makeToken(GGJToken::Star);
                
            case '@':
                return lexKeyword();
                
            case '"':
                return lexString();
                
            default:
                if (isIdentifier(c)) {
                    return lexIdent();
                }
                std::cerr << "Invalid character in room file '" << key_ << "'\n";
                abort();
        }
    }
    return makeToken(GGJToken::End);
}