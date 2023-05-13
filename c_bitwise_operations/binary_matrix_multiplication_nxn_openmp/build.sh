#!/usr/bin/env bash

set -xe

gcc-13 -Wall -Wextra -openmp -o main binary_matrix_multiply.c -lm
