#/bin/bash

COL="3[4;34;37m"
YEL="\033[1;33m"
RES="\033[1;37m"
LGREY="\033[0;37m"
LCYAN="\033[1;36m"

#########################################
# HOW TO USE ############################
# 	RUN FROM THIS FOLDER ( ./test_files )
# 	CHECK IF YOUR PATH IS CORRECT
	PUSHSWAP_PATH=../push_swap

### CHOOSE A CHECKER ####################
#	CHECKER=./checker_Mac 
	CHECKER=./checker_linux
#	CHECKER=./checker_bonus


#########################################
# The numbers come from file 'generate_numbers_mine.c' (gen_nums)
# This generates packages of random integers in range -200 to 299
	NUMS_TO_GENERATE=(2 3 4 5 6 50 100 500)
	CYCLES=5


#bash make_mychecker.sh

j=0
while (( $j < 8))
do
	echo -e $YEL"\n------------------------------------"
	echo -e "\n     ${NUMS_TO_GENERATE[j]} NUMBERS \n"
	echo -e "------------------------------------\n"$LGREY
	i=0
	while (( $i < $CYCLES ))
	do
		gcc generate_numbers_mine.c -o gen_nums
		
		./gen_nums ${NUMS_TO_GENERATE[j]} | (read numbers; echo -e $LCYAN ${numbers} $LGREY; \
			$PUSHSWAP_PATH ${numbers} | $CHECKER \
			$numbers; $PUSHSWAP_PATH $numbers | wc -l)

		i=$(( i+1 ))
		sleep 0.8  # (without sleep it gives repeated ints)
	done
	j=$(( j+1 ))
done



# With 3 numbers, not more than 3 instructions.
# With 5 numbers, not more than 12 instructions.

# With 100 numbers
# 5 points if the size of the list of instructions is less than 700
# 4 points if the size of the list of instructions is less than 900
# 3 points if the size of the list of instructions is less than 1100
# 2 points if the size of the list of instructions is less than 1300
# 1 points if the size of the list of instructions is less than 1500

# With 500 numbers
# 5 points if the size of the list of instructions is less than 5500
# 4 points if the size of the list of instructions is less than 7000
# 3 points if the size of the list of instructions is less than 8500
# 2 points if the size of the list of instructions is less than 10000
# 1 points if the size of the list of instructions is less than 11500

# Need to get at least 6 points to pass ???
