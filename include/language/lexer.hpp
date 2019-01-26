//===--------------------------------------------------------------------------------------------===
// lexer.hpp - Adventure-style lexer
// This source is part of GGJ19
//
// Created on 2019-01-25 by Amy Parent <amy@amyparent.com>
// Copyright (c) 2019 IDSMLM Games
// Licensed under the MIT License
// =^•.•^=
//===--------------------------------------------------------------------------------------------===
#pragma once
#include <cstdint>
#include <string>
#include <utility>

using NLToken = std::pair<std::string, bool>;


class NLLexer {
public:
    NLLexer(const std::string& phrase);
    
    const NLToken& currentToken() const;
    const NLToken& nextToken();
    bool end() const;
    
private:
    // TODO: UTF8 support
    char current() const;
    char nextChar();
    const NLToken& lexIdent();
    std::string cut(std::size_t start, std::size_t end);

    std::uint64_t       ptr_;
    NLToken             current_;
    std::string         phrase_;
};
