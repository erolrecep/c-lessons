#!/usr/bin/env bash

set -ex

cc -Wall -Wextra -o main display_image_chatGPT.c -lm `pkg-config --cflags --libs sdl2`
