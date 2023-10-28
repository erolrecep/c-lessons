#!/usr/bin/env bash

set -ex

cc -Wall -Wextra -o main bmp_image_display.c -lm `pkg-config --cflags --libs sdl2`
