#!/bin/bash

RED='\033[0;31m'
GREEN='\033[0;32m'
BLUE='\033[0;34m'
CYAN='\033[0;36m'
PURPLE='\033[0;35m'
YELLOW='\033[0;33m'
NC='\033[0m'
MAX=0
LIMIT=700
FILE=log.txt
SUM=0

echo -e "${CYAN}\nPush_swap_test\n${NC}"



echo -e "${CYAN}\t--------------------\n\t| Error management |\n\t--------------------\n${NC}"

./push_swap "" &> tmp_tester

if grep -q Error tmp_tester; then
	echo -e "\t./push_swap ''""\t\t\t\t${GREEN}OK${NC}"
else
	echo -e "\t./push_swap ''""\t\t\t\t${RED}KO${NC}"
fi

./push_swap "54" "" &> tmp_tester

if grep -q Error tmp_tester; then
	echo -e "\t./push_swap 54 ''""\t\t\t${GREEN}OK${NC}"
else
	echo -e "\t./push_swap 54 ''""\t\t\t${RED}KO${NC}"
fi

./push_swap 9 98 9 &> tmp_tester

if grep -q Error tmp_tester; then
	echo -e "\t./push_swap 9 98 9""\t\t\t${GREEN}OK${NC}"
else
	echo -e "\t./push_swap 9 98 9""\t\t\t${RED}KO${NC}"
fi

./push_swap -05 -0005 &> tmp_tester

if grep -q Error tmp_tester; then
	echo -e "\t./push_swap -05 -0005""\t\t\t${GREEN}OK${NC}"
else
	echo -e "\t./push_swap -05 -0005""\t\t\t${RED}KO${NC}"
fi

./push_swap -0 +0 2 &> tmp_tester

if grep -q Error tmp_tester; then
	echo -e "\t./push_swap -0 +0 2""\t\t\t${GREEN}OK${NC}"
else
	echo -e "\t./push_swap -0 +0 2""\t\t\t${RED}KO${NC}"
fi

./push_swap 98 one &> tmp_tester

if grep -q Error tmp_tester; then
	echo -e "\t./push_swap 98 one""\t\t\t${GREEN}OK${NC}"
else
	echo -e "\t./push_swap 98 one""\t\t\t${RED}KO${NC}"
fi

./push_swap 1 2 2147483648 &> tmp_tester

if grep -q Error tmp_tester; then
	echo -e "\t./push_swap 1 2 2147483648""\t\t${GREEN}OK${NC}"
else
	echo -e "\t./push_swap 1 2 2147483648""\t\t${RED}KO${NC}"
fi

./push_swap 1 2 -2147483649 &> tmp_tester

if grep -q Error tmp_tester; then
	echo -e "\t./push_swap 1 2 -2147483649""\t\t${GREEN}OK${NC}"
else
	echo -e "\t./push_swap 1 2 -2147483649""\t\t${RED}KO${NC}"
fi

./push_swap 1 2 18446744073709551616 &> tmp_tester

if grep -q Error tmp_tester; then
	echo -e "\t./push_swap 1 2 18446744073709551616""\t${GREEN}OK${NC}"
else
	echo -e "\t./push_swap 1 2 18446744073709551616""\t${RED}KO${NC}"
fi

./push_swap ++69 69 &> tmp_tester

if grep -q Error tmp_tester; then
	echo -e "\t./push_swap ++69 69""\t\t\t${GREEN}OK${NC}"
else
	echo -e "\t./push_swap ++69 69""\t\t\t${RED}KO${NC}"
fi

./push_swap --69 69 &> tmp_tester

if grep -q Error tmp_tester; then
	echo -e "\t./push_swap --69 69""\t\t\t${GREEN}OK${NC}"
else
	echo -e "\t./push_swap --69 69""\t\t\t${RED}KO${NC}"
fi

./push_swap 420--69 &> tmp_tester

if grep -q Error tmp_tester; then
	echo -e "\t./push_swap 420--69""\t\t\t${GREEN}OK${NC}"
else
	echo -e "\t./push_swap 420--69""\t\t\t${RED}KO${NC}"
fi

./push_swap 420++69 &> tmp_tester

if grep -q Error tmp_tester; then
	echo -e "\t./push_swap 420++69""\t\t\t${GREEN}OK${NC}"
else
	echo -e "\t./push_swap 420++69""\t\t\t${RED}KO${NC}"
fi

./push_swap + &> tmp_tester

if grep -q Error tmp_tester; then
	echo -e "\t./push_swap +""\t\t\t\t${GREEN}OK${NC}"
else
	echo -e "\t./push_swap +""\t\t\t\t${RED}KO${NC}"
fi

./push_swap - &> tmp_tester

if grep -q Error tmp_tester; then
	echo -e "\t./push_swap -""\t\t\t\t${GREEN}OK${NC}"
else
	echo -e "\t./push_swap -""\t\t\t\t${RED}KO${NC}"
fi

rm -rf tmp_tester





echo -e "${CYAN}\t---------------------\n\t| 100 numbers tests |\n\t---------------------\n${NC}"

if uname | grep -q Linux
then
	CHECKER=./checker_linux
else
	CHECKER=./checker_Mac
fi

for i in {1..50}
do
		export ARG=$(seq -10000 10000 | sort -R | head -n 100)
		if ./push_swap $ARG | $CHECKER $ARG | grep -q KO
		then
			echo -e "${RED}Error!${NC}"
			echo -e "${RED}ARG=" $ARG
			break
		fi
		NUMBER="$(./push_swap $ARG | wc -l | sed 's/ //g')"
		if [ "$NUMBER" -gt "$LIMIT" ]
			then
			echo -e "\nTest: " $ITERATIONS >> $FILE
			echo -e "Number of instructions:" $NUMBER >> $FILE
			echo -e "\nARG=" $ARG >> $FILE
		fi
		if [ "$NUMBER" -gt "$MAX" ]
			then
			MAX=$NUMBER;
		fi
		if [  "$LIMIT" -gt "$NUMBER" ]
			then
			echo -e $i"\t${GREEN}OK${NC}" "\tSteps:" "${GREEN}$NUMBER${NC}"
		else
			echo -e $i"\t${RED}KO${NC}" "\tSteps:" "${RED}$NUMBER${NC}"
		fi
		let SUM+=$NUMBER
done

echo -e "\nAVERAGE: ""${GREEN}$(($SUM / $i))${NC}"
echo -e "MAX:\t" "${RED}$MAX${NC}"





echo -e "${CYAN}\t---------------------\n\t| 500 numbers tests |\n\t---------------------\n${NC}"

LIMIT=5500
SUM=0

for i in {1..50}
do
		export ARG=$(seq -10000 10000 | sort -R | head -n 500)
		if ./push_swap $ARG | $CHECKER $ARG | grep -q KO
		then
			echo -e "${RED}Error!${NC}"
			echo -e "${RED}ARG=" $ARG
			break
		fi
		NUMBER="$(./push_swap $ARG | wc -l | sed 's/ //g')"
		if [ "$NUMBER" -gt "$LIMIT" ]
			then
			echo -e "\nTest: " $ITERATIONS >> $FILE
			echo -e "Number of instructions:" $NUMBER >> $FILE
			echo -e "\nARG=" $ARG >> $FILE
		fi
		if [ "$NUMBER" -gt "$MAX" ]
			then
			MAX=$NUMBER;
		fi
		if [  "$LIMIT" -gt "$NUMBER" ]
			then
			echo -e $i"\t${GREEN}OK${NC}" "\tSteps:" "${GREEN}$NUMBER${NC}"
		else
			echo -e $i"\t${RED}KO${NC}" "\tSteps:" "${RED}$NUMBER${NC}"
		fi
		let SUM+=$NUMBER
done

echo -e "\nAVERAGE: ""${GREEN}$(($SUM / $i))${NC}"
echo -e "MAX:\t" "${RED}$MAX${NC}"
