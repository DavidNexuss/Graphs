#!/bin/bash
#This script is made to test isomorph detection algorithm

bin=./../bin

echo "Testing isomorph detection algorithm."
N=10
$bin/matrix_generator 8 > 0.mat
for i in $(seq $N); do
    $bin/matrix_generator 8 > $i.mat
    echo -n $(cat $i.mat 0.mat | $bin/isomorph)
done
echo ""
for i in $(seq $N); do
    cat 0.mat | $bin/create_isomorph 8 > 1$i.mat
    echo -n $(cat 1$i.mat 0.mat | $bin/isomorph)
done
echo ""
