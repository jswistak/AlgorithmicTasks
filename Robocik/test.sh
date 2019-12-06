#!/bin/sh

for i in `seq 3000 0`
do
       ./a.out <2/in/rob"$i".in >xd
        DIFF=$(diff xd 2/out/rob"$i".out)
        echo $i$DIFF
done
