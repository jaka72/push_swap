/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmurovec <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 18:34:53 by jmurovec      #+#    #+#                 */
/*   Updated: 2021/09/29 12:18:41 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	overflow(int sign, int num, const char *str, int i)
{
	if (ft_isdigit(str[i + 1]))
		return (-1);
	if (sign == -1 && str[i] > '8')
		return (-1);
	if (sign == -1 && num > 214748364)
		return (-1);
	if (sign == 1 && str[i] > '7')
		return (-1);
	if (sign == 1 && num > 214748364)
		return (-1);
	else
	{
		num = (num * 10) + (str[i] - '0');
		return (num * sign);
	}
}

void	check_sign(int *i, const char *str, int *sign)
{
	while (str[*i] == ' ' || (str[*i] >= '\t' && str[*i] <= '\r'))
		(*i)++;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			*sign = -1;
		(*i)++;
	}
}

int	ft_atoi(const char *str, int *flag_overflow)
{
	int	i;
	int	sign;
	int	num;

	i = 0;
	sign = 1;
	check_sign(&i, str, &sign);
	num = 0;
	*flag_overflow = 0;
	while (str[i] && ft_isdigit(str[i]))
	{
		if (num >= 214748364)
		{
			if (overflow(sign, num, str, i) == -1)
			{
				*flag_overflow = 1;
				return (-1);
			}
		}
		num = num * 10 + str[i] - '0';
		i++;
	}
	return (num * sign);
}
