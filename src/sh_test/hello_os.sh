#!/bin/bash
sed -n '8p' $1 >$2.c
sed -n '32p' $1 >$2.c
sed -n '128p' $1 >$2.c
sed -n '512p' $1 >$2.c
sed -n '1024p' $1 >$2.c

