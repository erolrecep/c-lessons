#!/usr/bin/env sh


set -xe

cc -Wall -Wextra -o dynamic allocate_2D_array_in_main.c -lm
