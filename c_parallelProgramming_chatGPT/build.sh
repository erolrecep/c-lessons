#!/usr/bin/env sh


set -xe


gcc-12 -Wall -Wextra -lm -fopenmp -o main main.c
