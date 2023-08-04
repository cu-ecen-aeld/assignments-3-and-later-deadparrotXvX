#!/bin/bash

if [ $# -ne 2 ]
then
	echo "finder.sh needs exactly two arguments"
	echo "Usage:"
	echo "  $0 filesdir searchstr"
	exit 1
fi

if [ -d $1 ]
then
	x=$(ls $1 | wc -w)
	y=$(grep $2 -R $1 | wc -w)
	echo "The number of files are $x and the number of matching lines are $y"
else
	echo "$1 is not a directory"
	exit 1
fi
