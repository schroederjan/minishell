#!/usr/bin/env bash

echo 1
echo | grep "line" < input.txt | sed 's/line/LINE/'

echo 2
grep 'a' | grep "line" < input.txt | sed 's/line/LINE/'

echo 3
grep 'a' < input.txt | grep "line" | sed 's/line/LINE/'

echo 4
grep 'a' | grep "line" | sed 's/line/LINE/' < input.txt

echo 5
grep 'a' | grep "line" | sed 's/line/LINE/' > out.txt < input.txt
cat out.txt

echo 6
< input.txt grep 'a'

echo 7
grep 'a' | grep "line" | sed 's/line/LINE/' < input.txt > out.txt 
cat out.txt
