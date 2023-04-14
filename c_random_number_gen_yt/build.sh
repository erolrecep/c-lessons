#!/usr/bin/env sh


set -xe


cc -Wall -Wextra -lm -o main main.c `pkg-config --libs --cflags openssl`
