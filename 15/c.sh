#!/bin/bash

echo $1
x=1
echo $x

if [[ $x == $1 ]]; then
	echo yes
else
	echo no
fi

for x in q 123 "e" "r"
do
	echo $x
done

for x in $(cat a.cpp)
do
	echo $x
done

for ((i = 0; i < 10; i++))
do
	echo $i
done
