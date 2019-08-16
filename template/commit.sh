#!/bin/bash

git add main.cpp cases results problem.txt performance.txt Makefile

rm -rf commit.sh main.dSYM tmp.txt

git commit

git push origin master
