#!/usr/bin/env bash
set -e

# Превращаем путь вида ./cses/dp/coins.cpp в имя таргета cses_dp_coins_cpp
TARGET=$(echo "${1#./}" | sed 's/[\/.]/_/g')

cmake --build build -t "$TARGET" -j
"./build/$TARGET"