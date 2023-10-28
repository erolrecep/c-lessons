#!/usr/bin/env bash

set -ex

cc -Wall -Wextra -o main blank_screen.c -lm `pkg-config --cflags --libs sdl2`
