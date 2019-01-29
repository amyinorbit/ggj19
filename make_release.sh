#!/usr/bin/env bash

VERSION_NUMBER=2

CMAKE_CMD_MACOS="cmake"
CMAKE_CMD_WIN32="i686-w64-mingw32.static-cmake"
CMAKE_FLAGS = -DCMAKE_BUILD_TYPE=Release

CURRENT_DIR="$(pwd)"
PRODUCT_DIR="${CURRENT_DIR}/product"
PRODUCT_DIR_MACOS="${PRODUCT_DIR}/macOS"
PRODUCT_DIR_WIN32="${PRODUCT_DIR}/windows"

BUILD_DIR_MACOS="$(pwd)/build.macOS"
BUILD_DIR_WIN32="$(pwd)/build.win32"

# First we create our build folders

mkdir -p ${BUILD_DIR_MACOS}
mkdir -p ${BUILD_DIR_WIN32}

echo "building macOS release"
cd ${BUILD_DIR_MACOS} && ${CMAKE_CMD_MACOS} ${CURRENT_DIR} ${CMAKE_FLAGS}
cd ${BUILD_DIR_MACOS} && make -j4

echo "building win32 release"
cd ${BUILD_DIR_WIN32} && ${CMAKE_CMD_WIN32} ${CURRENT_DIR} ${CMAKE_FLAGS}
cd ${BUILD_DIR_WIN32} && make -j4

echo "creating multi-platform package"
cd ${PRODUCT_DIR} && zip -r "${PRODUCT_DIR}/alive.zip" macOS windows *.pdf -x ".*" -x "__MACOSX"

echo "creating macOS binary package"
cd ${PRODUCT_DIR_MACOS} && zip -r "${PRODUCT_DIR}/alive-macOS-v${VERSION_NUMBER}.zip" *.app  -x ".*" -x "__MACOSX"

echo "creating win32 binary package"
cd ${PRODUCT_DIR_WIN32} && zip -r "${PRODUCT_DIR}/alive-win32-v${VERSION_NUMBER}.zip" assets alive.exe  -x ".*" -x "__MACOSX"
