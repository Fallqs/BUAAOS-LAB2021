#!/bin/bash
sed -n '8p' $1 -e '32p' $1 -e '128p' $1 -e '512p' $1 -e '1024p' $1 >$2
