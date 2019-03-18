#!/bin/sh

./a.out 1 2 1 &
./a.out 1 5 2 &

./a.out 2 1 3 &
./a.out 2 12 4 &
./a.out 2 8 5 &
./a.out 1 5 6 &
