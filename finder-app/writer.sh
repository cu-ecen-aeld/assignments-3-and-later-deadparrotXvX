#!/bin/bash

if [ $# -ne 2 ]
then
	echo "$0 needs exactly two arguments"
	echo "Usage:"
	echo "  $0 writefile writestr"
	exit 1
fi

mkdir -p $1
rm -rf $1
echo $2 > $1
