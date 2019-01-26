//===--------------------------------------------------------------------------------------------===
// lexer.cpp - Adventure-style lexer
// This source is part of GGJ19
//
// Created on 2019-01-25 by Amy Parent <amy@amyparent.com>
// Copyright (c) 2019 IDSMLM Games
// Licensed under the MIT License
// =^•.•^=
//===--------------------------------------------------------------------------------------------===
#include <cctype>
#include <language/lexer.hpp>

NLLexer::NLLexer(const std::string& phrase) : phrase_(phrase) {
    nextToken();
}

const NLToken& NLLexer::currentToken() const {
    return current_;
}

char NLLexer::current() const {
    if ((ptr_) < phrase_.size()) return phrase_[ptr_];
    return '\0';
}

char NLLexer::nextChar() {
    char c = current();
    if ((ptr_) < phrase_.size()) ptr_ += 1;
    return c;
}

std::string NLLexer::cut(std::size_t start, std::size_t end) {
    
    const auto len = end - start;
    const auto str = phrase_.substr(start, len);
    phrase_.erase(0, end);
    return str;
}

const NLToken& NLLexer::lexIdent() {
    const auto start = ptr_-1;
    
    while(std::isalnum(current())) {
        nextChar();
    }
    const auto end = ptr_;
    
    current_.first = cut(start, end);
    current_.second = false;
    return current_;
}

const NLToken& NLLexer::nextToken() {
    // TODO: please change that to something UTF-8 compliant in the future
    ptr_  = 0;
    while(current() != '\0') {
        char c = nextChar();
        if (std::isalnum(c)) {
            return lexIdent();
        }
    }
    
    current_.first = "";
    current_.second = true;
    
    return current_;
}

bool NLLexer::end() const {
    return current_.second;
}
