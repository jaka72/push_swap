/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/30 16:45:50 by jaka          #+#    #+#                 */
/*   Updated: 2021/09/30 16:48:17 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gnl_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*gnl_strchr(char *str, int c)
{
	char	*s;

	if (c == '\0')
		return (str + gnl_strlen(str));
	s = str;
	while (*s)
	{
		if (c == *s)
			return (s);
		s++;
	}
	return (NULL);
}

char	*gnl_strdup(char *str)
{
	int		i;
	char	*newstr;

	if (!str)
		return (NULL);
	newstr = malloc((gnl_strlen(str) + 1) * sizeof(char));
	if (newstr == NULL)
		return (NULL);
	i = 0;
	while (str[i])
	{
		newstr[i] = str[i];
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}

char	*gnl_strcat(char *joined, char *str1, char *str2)
{
	int	i;
	int	j;

	i = 0;
	while (str1[i])
	{
		joined[i] = str1[i];
		i++;
	}
	j = 0;
	while (str2[j])
	{
		joined[i] = str2[j];
		i++;
		j++;
	}
	joined[i] = '\0';
	return (joined);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	char	*joined;

	if (!s1 || !s2)
		return (NULL);
	joined = malloc((gnl_strlen(s1) + gnl_strlen(s2) + 1) * sizeof(char));
	if (joined == NULL)
		return (NULL);
	return (gnl_strcat(joined, s1, s2));
}
