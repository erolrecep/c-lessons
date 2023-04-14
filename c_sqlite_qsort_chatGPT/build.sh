#!/usr/bin/env sh


set -xe


gcc-12 -Wall -Wextra -o main main.c -lm -lsqlite3
