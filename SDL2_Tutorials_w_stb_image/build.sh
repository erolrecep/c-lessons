#!/usr/bin/env bash

set -ex

cc -Wall -Wextra -o main main.c -lm `pkg-config --cflags --libs sdl2` -Iinclude/
