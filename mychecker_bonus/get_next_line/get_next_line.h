/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/30 10:34:51 by jaka          #+#    #+#                 */
/*   Updated: 2021/09/30 16:47:01 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

int		get_next_line(char **line);
size_t	gnl_strlen(char *str);
char	*gnl_strchr(char *str, int c);
char	*gnl_strdup(char *str);
char	*gnl_strcat(char *joined, char *str1, char *str2);
char	*gnl_strjoin(char *s1, char *s2);

#endif