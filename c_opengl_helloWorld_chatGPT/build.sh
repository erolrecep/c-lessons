#!/usr/bin/env sh


set -xe


# cc -Wall -Wextra -o main main.c -lm

cc -framework OpenGL -o main main.c -lGL -lGLU -lglut
