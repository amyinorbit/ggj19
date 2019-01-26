//===--------------------------------------------------------------------------------------------===
// command.hpp - Adventure-style language command
// This source is part of GGJ19
//
// Created on 2019-01-25 by Amy Parent <amy@amyparent.com>
// Copyright (c) 2019 IDSMLM Games
// Licensed under the MIT License
// =^•.•^=
//===--------------------------------------------------------------------------------------------===
#pragma once
#include <string>

struct NLCommand {
    NLCommand() : verb(""), object(""), complement("") {}
    NLCommand(const std::string& v, const std::string& o, const std::string& c)
        : verb(v), object(o), complement(c) {}
    std::string  verb = "";
    std::string  object = "";
    std::string  complement = "";
};
