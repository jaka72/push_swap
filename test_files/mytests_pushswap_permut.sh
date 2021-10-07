#/bin/bash

COL="3[4;34;37m"
YEL="\033[1;33m"
RES="\033[1;37m"
LGREY="\033[0;37m"
LCYAN="\033[1;36m"


arr3=( 1 2 3 1 3 2 2 1 3 2 3 1 3 1 2 3 2 1 )

arr4=( 1 2 3 4 1 2 4 3 1 3 2 4 1 3 4 2 1 4 2 3 1 4 3 2 2 1 3 4 2 1 4 3 2 3 1 4 2 3 4 1 2 4 1 3 2 4 3 1 3 1 2 4 3 1 4 2 3 2 1 4 3 2 4 1 3 4 1 2 3 4 2 1 4 1 2 3 4 1 3 2 4 2 1 3 4 2 3 1 4 3 1 2 4 3 2 1 )

arr5=( 1 2 3 4 5 1 2 3 5 4 1 2 4 3 5 1 2 4 5 3 1 2 5 3 4 1 2 5 4 3 1 3 2 4 5 1 3 2 5 4 1 3 4 2 5 1 3 4 5 2 1 3 5 2 4 1 3 5 4 2 1 4 2 3 5 1 4 2 5 3 1 4 3 2 5 1 4 3 5 2 1 4 5 2 3 1 4 5 3 2 1 5 2 3 4 1 5 2 4 3 1 5 3 2 4 1 5 3 4 2 1 5 4 2 3 1 5 4 3 2 2 1 3 4 5 2 1 3 5 4 2 1 4 3 5 2 1 4 5 3 2 1 5 3 4 2 1 5 4 3 2 3 1 4 5 2 3 1 5 4 2 3 4 1 5 2 3 4 5 1 2 3 5 1 4 2 3 5 4 1 2 4 1 3 5 2 4 1 5 3 2 4 3 1 5 2 4 3 5 1 2 4 5 1 3 2 4 5 3 1 2 5 1 3 4 2 5 1 4 3 2 5 3 1 4 2 5 3 4 1 2 5 4 1 3 2 5 4 3 1 3 1 2 4 5 3 1 2 5 4 3 1 4 2 5 3 1 4 5 2 3 1 5 2 4 3 1 5 4 2 3 2 1 4 5 3 2 1 5 4 3 2 4 1 5 3 2 4 5 1 3 2 5 1 4 3 2 5 4 1 3 4 1 2 5 3 4 1 5 2 3 4 2 1 5 3 4 2 5 1 3 4 5 1 2 3 4 5 2 1 3 5 1 2 4 3 5 1 4 2 3 5 2 1 4 3 5 2 4 1 3 5 4 1 2 3 5 4 2 1 4 1 2 3 5 4 1 2 5 3 4 1 3 2 5 4 1 3 5 2 4 1 5 2 3 4 1 5 3 2 4 2 1 3 5 4 2 1 5 3 4 2 3 1 5 4 2 3 5 1 4 2 5 1 3 4 2 5 3 1 4 3 1 2 5 4 3 1 5 2 4 3 2 1 5 4 3 2 5 1 4 3 5 1 2 4 3 5 2 1 4 5 1 2 3 4 5 1 3 2 4 5 2 1 3 4 5 2 3 1 4 5 3 1 2 4 5 3 2 1 5 1 2 3 4 5 1 2 4 3 5 1 3 2 4 5 1 3 4 2 5 1 4 2 3 5 1 4 3 2 5 2 1 3 4 5 2 1 4 3 5 2 3 1 4 5 2 3 4 1 5 2 4 1 3 5 2 4 3 1 5 3 1 2 4 5 3 1 4 2 5 3 2 1 4 5 3 2 4 1 5 3 4 1 2 5 3 4 2 1 5 4 1 2 3 5 4 1 3 2 5 4 2 1 3 5 4 2 3 1 5 4 3 1 2 5 4 3 2 1 )


j=0;
while (( $j < 18 ))
do 
    echo ${arr3[j]} ${arr3[j + 1]} ${arr3[j + 2]} | (read numbers; echo -e $LCYAN $numbers $LGREY; ./push_swap $numbers | ./checker_bonus $numbers;)
    echo ${arr3[j]} ${arr3[j + 1]} ${arr3[j + 2]} | (read numbers; ./push_swap $numbers | wc -l)
    j=$(( j + 3 ))
done

j=0;
while (( $j < 96 ))
do 
    echo ${arr4[j]} ${arr4[j + 1]} ${arr4[j + 2]} ${arr4[j + 3]} | (read numbers; echo -e $LCYAN $numbers $LGREY; ./push_swap $numbers | ./checker_bonus $numbers;)
    echo ${arr4[j]} ${arr4[j + 1]} ${arr4[j + 2]} ${arr4[j + 3]} | (read numbers; ./push_swap $numbers | wc -l)
    j=$(( j + 4 ))
done


j=0;
while (( $j < 120 ))
do 
    echo ${arr5[j]} ${arr5[j + 1]} ${arr5[j + 2]} ${arr5[j + 3]} ${arr5[j + 4]}| (read numbers; echo -e $LCYAN $numbers $LGREY; ./push_swap $numbers | ./checker_bonus $numbers;)
    echo ${arr5[j]} ${arr5[j + 1]} ${arr5[j + 2]} ${arr5[j + 3]} ${arr5[j + 4]}| (read numbers; ./push_swap $numbers | wc -l)
    j=$(( j + 5 ))
done

