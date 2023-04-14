#!/usr/bin/env sh


set -xe


gcc-12 -fopenmp -Wall -Wextra -o main_fopenmp main_w_openmp.c -lm
