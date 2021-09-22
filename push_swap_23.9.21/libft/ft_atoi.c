/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmurovec <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 18:34:53 by jmurovec      #+#    #+#                 */
/*   Updated: 2021/09/22 13:42:05 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// long long 9223372036854775807  the last digit 7 is taken away and then checked
// int 2147483647
// int 214748364  ,to check, delete last digit

static int	overflow(int sign, int num, const char *str, int i)
{
	//printf(" start overflow\n");

	if (sign == -1 && str[i] > '8')
		return (-1);
	if (sign == -1 && num > 214748364)
		return (-1);
	if (sign == 1 && str[i] > '7')
		return (-1);
	//if (sign == 1 && num > 922337203685477580)
	if (sign == 1 && num > 214748364)
		return (-1);
	else
	{
		//printf(" from overflow\n");
		num = (num * 10) + (str[i] - '0');
		return (num * sign);
	}
}

int			ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	num;

	i = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	num = 0;
	while (str[i] && ft_isdigit(str[i]))
	{
		
		if (num >= 214748364)
		{
			//printf(" in loop if num\n");
			return (overflow(sign, num, str, i));
		}
		num = num * 10 + str[i] - '0';
		i++;
	}
	//printf(" end atoi\n");
	return (num * sign);
}
