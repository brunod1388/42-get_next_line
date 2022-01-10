/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoncalv <bgoncalv@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 21:19:40 by bgoncalv          #+#    #+#             */
/*   Updated: 2022/01/10 00:21:06 by bgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_line(char **s)
{
	size_t	l;
	char	*dst;
	char	*tmp;

	l = 0;
	if (!*s)
		return (NULL);
	while ((*s)[l] && (*s)[l] != '\n')
		l++;
	if ((*s)[l] == '\n')
		l++;
	if (!(*s)[l])
		tmp = NULL;
	else
		tmp = ft_strndup(*s + l, ft_strlen(*s + l));
	dst = ft_strndup(*s, l);
	free(*s);
	*s = tmp;
	return (dst);
}

char	*get_next_line(int fd)
{
	static char	*s_left = NULL;
	char		buffer[BUFFER_SIZE + 1];
	size_t		n;

	if (fd < 0 || 4095 < fd || BUFFER_SIZE < 0)
		return (NULL);
	if (s_left && ft_hasline(s_left))
		return (get_line(&s_left));
	n = read(fd, buffer, BUFFER_SIZE);
	buffer[n] = 0;
	while (0 < n && n <= BUFFER_SIZE)
	{
		s_left = ft_strjoin(s_left, buffer);
		if (!s_left || ft_hasline(s_left))
			break ;
		n = read(fd, buffer, BUFFER_SIZE);
		buffer[n] = 0;
	}
	return (get_line(&s_left));
}
