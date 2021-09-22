#include <stdio.h>
#include "libft.h"



int main(void)
{
   char *str;
    long long a;

    // 2.147.483.647
    str =  "-2147483649";
    a = ft_atoi(str);

    printf("a: [%lld]\n", a);

    return (0);
}