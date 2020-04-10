#!/bin/bash

function query_url() { 

A=$2
echo "+ $2 $1"
txt=$(lynx -listonly -dump $1)

echo "$txt" | tail -n +4 | awk '{print $2}' |
    while read line; do
        A=$(($A + 1))
        echo "* $2 $line"
        [[ ! $3 -eq "0" ]] && query_url $line $(($A + $(echo "$txt" | wc -l))) $(($3 - 1))
    done 
}


query_url $@
