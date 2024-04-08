#!/bin/bash

MAX=0
ITERATIONS=1
LIMIT=700
FILE=log.txt
SUM=0
RED='\033[0;31m'
GREEN='\033[0;32m'
BLUE='\033[0;34m'
CYAN='\033[0;36m'
YELLOW='\033[0;33m'
NC='\033[0m'

for i in {1..50}
do
		export ARG=$(seq -10000 10000 | sort -R | head -n 100)
		if ./push_swap $ARG | ./checker_Mac $ARG | grep -q KO
		then
			echo -e "${RED}Error!${NC}"
			echo -e "${RED}ARG=" $ARG
			break
		fi
		NUMBER="$(./push_swap $ARG | wc -l | sed 's/ //g')"
		if [ "$NUMBER" -gt "$LIMIT" ]
			then
			echo -e "\n\nTest: " $ITERATIONS >> $FILE
			echo -e "Number of instructions:" $NUMBER >> $FILE
			echo -e "\nARG=" $ARG >> $FILE
		fi
		if [ "$NUMBER" -gt "$MAX" ]
			then
			MAX=$NUMBER;
		fi
		echo -e "${YELLOW}Test ${NC}" ":" $i "\t${CYAN}Instructions: ${NC}" $NUMBER
		let SUM+=$NUMBER;
		let ITERATIONS+=1
done
echo -e "${GREEN}ARG $(($SUM / $ITERATIONS))${NC}"
echo -e "${RED}MAX:" $MAX
