/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/30 10:34:10 by jaka          #+#    #+#                 */
/*   Updated: 2021/09/30 16:47:45 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	str_to_line(char **str, char **line)
{
	int		len;
	char	*temp;

	len = 0;
	while ((*str)[len] != '\n' && (*str)[len] != '\0')
		len++;
	if ((*str)[len] == '\n')
	{
		(*str)[len] = '\0';
		*line = gnl_strdup(*str);
		temp = gnl_strdup(&(*str)[len + 1]);
		free(*str);
		*str = temp;
		if (*line == NULL || *str == NULL)
			return (-1);
	}
	else
	{
		*line = gnl_strdup(*str);
		free(*str);
		*str = NULL;
		if (*line == NULL)
			return (-1);
	}
	return (1);
}

static int	buff_to_str(int bytes_read, char *buff, char **str)
{
	char	*temp;

	while (bytes_read > 0)
	{
		bytes_read = read(0, buff, 1000);
		if (bytes_read >= 0)
			buff[bytes_read] = '\0';
		if (*str == NULL)
		{
			*str = gnl_strdup(buff);
			if (*str == NULL)
				return (-1);
		}
		else
		{
			temp = gnl_strjoin(*str, buff);
			free(*str);
			*str = temp;
			if (*str == NULL)
				return (-1);
		}
		if (gnl_strchr(*str, '\n'))
			return (bytes_read);
	}
	return (bytes_read);
}

int	get_next_line(char **line)
{
	int			bytes_read;
	char		buff[1001];
	static char	*str;

	if (line == NULL)
		return (-1);
	if (str == NULL || gnl_strchr(str, '\n') == NULL)
		bytes_read = buff_to_str(1, buff, &str);
	else
		bytes_read = 0;
	if (bytes_read < 0)
		return (-1);
	if (str_to_line(&str, line) < 0)
		return (-1);
	if (bytes_read == 0 && str == NULL)
		return (0);
	return (1);
}
