#!/bin/bash
g++ -g -std=c++17 -Wall -Wextra "./src/$1.cpp" -D DEBUG -o "./out/$1"