#!/usr/bin/env sh


set -xe


gcc-12 -fopenmp -Wall -Wextra -o main main.c -lm
