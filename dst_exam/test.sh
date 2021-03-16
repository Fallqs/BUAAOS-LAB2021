#!/bin/bash
grep -r -n  -e 'hello OS lab0' dir >lab0_exam.c
find -name  lab0_x -printf "%P">>lab0_exam.c
