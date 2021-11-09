#/bin/bash

COL="3[4;34;37m"
YEL="\033[1;33m"
RES="\033[1;37m"
LGREY="\033[0;37m"
LCYAN="\033[1;36m"

#
# numbers come from 'generate_numbers_mine.c' 
#  IT WILL GENERATE 500 INTS IN RANGE -200 TO 299./ch
#

# CHECK IF THE PATHS ARE CORRECT
PUSHSWAP_PATH=../
LIBFT_PATH=../libft/libft.a
NUMS_TO_GENERATE=(2 3 4 5 6 50 100 500)
CYCLES=5

CHECKER=./checker_Mac 
#CHECKER=./checker_Linux
#CHECKER=./checker_Bonus

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
		gcc generate_numbers_mine.c $LIBFT_PATH -o gen_nums
		
		./gen_nums ${NUMS_TO_GENERATE[j]} | (read numbers; echo -e $LCYAN ${numbers} $LGREY; \
			$PUSHSWAP_PATH/push_swap ${numbers} | $CHECKER \
			$numbers; $PUSHSWAP_PATH/push_swap $numbers | wc -l)


		i=$(( i+1 ))
		sleep 0.8  # WITHOUT THIS GIVES THE SAME NUMBERS
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
