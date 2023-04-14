#!/usr/bin/env sh


set -xe


# cc -Wall -Wextra -o main main.c -lm
gcc main.c `pkg-config --cflags --libs gstreamer-1.0`
