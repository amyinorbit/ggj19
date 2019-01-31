//===--------------------------------------------------------------------------------------------===
// entity.hpp - Representation of room and objects in the game
// This source is part of GGJ19
//
// Created on 2019-01-26 by Amy Parent <amy@amyparent.com>
// Copyright (c) 2019 IDSMLM Games
// Licensed under the MIT License
// =^•.•^=
//===--------------------------------------------------------------------------------------------===
#pragma once
#include <string>
#include <vector>

struct GGJEntity;

struct GGJLink {
    std::string     object;
    std::string     verb;
    std::string     key;
    std::string     lock;
    GGJEntity*      entity;
};

enum class GGJKind { Room, Object, Container };

struct GGJEntity {
    GGJKind                 kind    = GGJKind::Room;
    std::string             key     = "";
    std::string             name    = "";
    std::string             desc    = "";
    std::vector<GGJLink>    links;
};
