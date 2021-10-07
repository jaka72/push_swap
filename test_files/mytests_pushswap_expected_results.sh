#/bin/bash

COL="3[4;34;37m"
YEL="\033[1;33m"
RES="\033[1;37m"
LGREY="\033[0;37m"
LCYAN="\033[1;36m"

CHECKER=checker_Mac
#CHECKER=checker_bonus


echo -e "$YEL\n\n--- Push_swap, Expected: 'exit' ---------------------------------$RES"


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



echo -e "$YEL\n\n--- Push_swap, Expected: 'Error' ---------------------------------$RES"

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

echo -e "$LCYAN\nTEST ./push_swap 3 0 2 '' 1 \n expected:$RES Error"
./push_swap 3 0 2 '' 1
sleep 0.1

echo -e "$LCYAN\nTEST ./push_swap 5 3 '' 0 \n expected:$RES Error"
./push_swap 5 3 '' 0
sleep 0.1

echo -e "$LCYAN\nTEST ./push_swap 5 '  3  ' \n expected:$RES Error"
./push_swap 5 '  3  '
sleep 0.1


echo -e "$LCYAN\nTEST ./push_swap '' \n expected:$RES Error"
./push_swap ''
sleep 0.1


echo -e "$LCYAN\nTEST ./push_swap '   ' \n expected:$RES Error"
./push_swap '   '
sleep 0.1





echo -e "$YEL\n\n--- Push_swap, Expected: Print instructions ---------------------------------$RES"

echo -e "$LCYAN\nTEST ./push_swap 2147483647 33 \nexpected:$RES sa"
./push_swap 2147483647 33
sleep 0.1

echo -e "$LCYAN\nTEST ./push_swap -33 -2147483648 \nexpected:$RES sa"
./push_swap -33 -2147483648
sleep 0.1

echo -e "$LCYAN\nTEST ./push_swap -0 \n expected:$RES"
./push_swap -0
sleep 0.1

echo -e "$LCYAN\nTEST ./push_swap 5 -0 \n expected:$RES sa"
./push_swap 5 -0
sleep 0.1


### STILL NOT EQUAL TO CHECKER_MAC
echo -e "$LCYAN\nTEST ./push_swap 5 3 '1 0' \nexpected:$RES OK (ra ra pb ...)"
./push_swap 5 3 '1 0'
sleep 0.1


echo -e "$LCYAN\nTEST ./push_swap 5 '  3  ' \nexpected:$RES OK (sa)"
./push_swap 5 '  3  '
sleep 0.1


echo -e "$YEL\n\n-----------------------------------------------------$RES"
echo -e "$YEL\n--- $CHECKER -----------------------------------$RES"


echo -e "$LCYAN\nTEST ./$CHECKER  ,  [''] \nexpected:$RES "
echo "" | ./$CHECKER

echo -e "$LCYAN\nTEST ./$CHECKER  ,  [' '] \nexpected:$RES "
echo " " | ./$CHECKER

echo -e "$LCYAN\nTEST ./$CHECKER  ,  ['     '] \nexpected:$RES "
echo "     " | ./$CHECKER

echo -e "$LCYAN\nTEST ./$CHECKER 5 3, [sa] \nexpected:$RES OK"
echo "sa" | ./$CHECKER 5 3

echo -e "$LCYAN\nTEST ./$CHECKER 3 9 7, [ra sa rra] \nexpected:$RES OK"
echo -e "ra\nsa\nrra" | ./$CHECKER 3 9 7

echo -e "$LCYAN\nTEST ./$CHECKER 5 3, [sa sa sa]  \nexpected:$RES OK"
echo -e "sa\nsa\nsa" | ./$CHECKER 5 3

echo -e "$LCYAN\nTEST ./$CHECKER 5 3, [   sa   ] \nexpected:$RES Error"
echo "   sa   " | ./$CHECKER 5 3

echo -e "$LCYAN\nTEST ./$CHECKER 5 3, [  x  sa   ] \nexpected:$RES Error"
echo "  x  sa   \n\0" | ./$CHECKER 5 3

echo -e "$LCYAN\nTEST ./$CHECKER 3 3, [sa] \nexpected:$RES Error"
echo -e "sa" | ./$CHECKER 3 3

echo -e "$LCYAN\nTEST ./$CHECKER 2147483648 3, [sa] \nexpected:$RES Error"
echo -e "sa" | ./$CHECKER 2147483648 3

echo -e "$LCYAN\nTEST ./$CHECKER 3 9 7, [xssa] \nexpected:$RES Error"
echo -e "xssa" | ./$CHECKER 3 9 7

echo -e "$LCYAN\nTEST ./$CHECKER 3 9 7, [ra sa rra x] \nexpected:$RES Error"
echo -e "ra\nsa\nrra\nx" | ./$CHECKER 3 9 7

echo -e "$LCYAN\nTEST ./$CHECKER 5 3, [pb] \nexpected:$RES KO"
echo -e "pb" | ./$CHECKER 5 3

echo -e "$LCYAN\nTEST ./$CHECKER 0 9 1 8 2 7 3 6 4 5, [sa pb rrr] \nexpected:$RES KO"
echo -e "sa\npb\nrrr" | ./$CHECKER 0 9 1 8 2 7 3 6 4 5

