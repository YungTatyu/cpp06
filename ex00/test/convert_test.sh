#!/bin/bash

# expect
char='char: '
int='int: '
float='float: '
double='double: '

# color
RESET='\033[0m'
RED='\033[0;31m'
GREEN='\033[0;32m'


TRUE=1
FALSE=0

# function	expect () {

# 	if [ $1 -eq $1 ]

# }

printf "---------------test start---------------\n";

inputs=("0", "nan")
for i in ${inputs[@]}; do
	printf "testing ${i} ...\n";
	output=(../convert ${i})
	exoect="${char}${i}\n${int}${i}\n${float}${i}.0f\n${double}${i}.0\n"
	# if [ output -eq expect ] then;
	result=expect ${i} ${output}
	if [ ${result} == ${expect} ] then;
		printf "${GREEN}OK${RESET}\n";
	else
		printf "${RED}KO${RESET}\n";
		printf "expect:${expect}\nactual:${result}\n"
done;


printf "---------------test done---------------\n";
