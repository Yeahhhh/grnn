#!/bin/sh

grep -x '.\{60,60\}' final_contigs.fa > a1

grep -v n a1 > a2

head -n 10000 a2 > a3

cat a3 | \
sed -e s/A/1/g - | \
sed -e s/T/2/g - | \
sed -e s/C/3/g - | \
sed -e s/G/4/g - > a4

./1pair a4 > a5

./2random a5 > a.raw

./3modify a.raw > a.raw.mod

./4format1 a.raw.mod > a.raw.mod.format1
./4format2 a.raw.mod > a.raw.mod.format2
./4format3 a.raw.mod > a.raw.mod.format3

