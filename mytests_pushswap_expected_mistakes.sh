#/bin/bash

COL="3[4;34;37m"
YEL="\033[1;33m"
RES="\033[1;37m"
LGREY="\033[0;37m"
LCYAN="\033[1;36m"

echo -e "$LCYAN\nTEST ./push_swap \n expected:$RES"
./push_swap
sleep 0.1

echo -e "$LCYAN\nTEST ./push_swap 3 \n expected:$RES"
./push_swap 3
sleep 0.1

echo -e "$LCYAN\nTEST ./push_swap 3 5 \n expected:$RES"
./push_swap 3 5
sleep 0.1

echo -e "$LCYAN\nTEST ./push_swap -4 -3 \n expected:$RES"
./push_swap -4 -3
sleep 0.1

echo -e "$LCYAN\nTEST ./push_swap +3 +5 \n expected:$RES"
./push_swap +3 +5
sleep 0.1

echo -e "$LCYAN\nTEST ./push_swap 1 3 6 9 \n expected:$RES"
./push_swap 1 3 6 9
sleep 0.1

echo -e "$LCYAN\nTEST ./push_swap 1 3 +6 9 \n expected:$RES"
./push_swap 1 3 +6 9
sleep 0.1

echo -e "$LCYAN\nTEST ./push_swap -1 3 6 9 \n expected:$RES"
./push_swap -1 3 6 9
sleep 0.1

echo -e "$LCYAN\nTEST ./push_swap -4 \n expected:$RES"
./push_swap -4
sleep 0.1

echo -e "$LCYAN\nTEST ./push_swap +4 \n expected:$RES"
./push_swap +4
sleep 0.1

echo -e "$LCYAN\nTEST ./push_swap 33 2147483647 \nexpected:$RES"
./push_swap 33 2147483647
sleep 0.1

echo -e "$LCYAN\nTEST ./push_swap -2147483648 33 \nexpected:$RES"
./push_swap -2147483648 33
sleep 0.1

echo -e "$LCYAN\nTEST ./push_swap - \n expected:$RES Error"
./push_swap -
sleep 0.1

echo -e "$LCYAN\nTEST ./push_swap + \n expected:$RES Error"
./push_swap +
sleep 0.1

echo -e "$LCYAN\nTEST ./push_swap 3 b 1 \nexpected:$RES Error"
./push_swap 3 b 1
sleep 0.1

echo -e "$LCYAN\nTEST ./push_swap 3 1 2 b \nexpected:$RES Error"
./push_swap 3 1 2 b
sleep 0.1

echo -e "$LCYAN\nTEST ./push_swap 3 + 1 \nexpected:$RES Error"
./push_swap 3 + 1
sleep 0.1

echo -e "$LCYAN\nTEST ./push_swap 3 - 1 \nexpected:$RES Error"
./push_swap 3 - 1
sleep 0.1

echo -e "$LCYAN\nTEST ./push_swap 3 5 7 3 \nexpected:$RES Error"
./push_swap 3 5 7 3
sleep 0.1

echo -e "$LCYAN\nTEST ./push_swap 2147483648 \nexpected:$RES Error"
./push_swap 2147483648
sleep 0.1

echo -e "$LCYAN\nTEST ./push_swap 2147483648 \nexpected:$RES Error"
./push_swap 21474836471
sleep 0.1

echo -e "$LCYAN\nTEST ./push_swap 33 2147483648 \nexpected:$RES Error"
./push_swap 33 2147483648
sleep 0.1

echo -e "$LCYAN\nTEST ./push_swap -2147483649 \nexpected:$RES Error"
./push_swap -2147483649
sleep 0.1

echo -e "$LCYAN\nTEST ./push_swap 2147483647 33 \nexpected:$RES sa"
./push_swap 2147483647 33
sleep 0.1

echo -e "$LCYAN\nTEST ./push_swap -33 -2147483648 \nexpected:$RES sa"
./push_swap -33 -2147483648
