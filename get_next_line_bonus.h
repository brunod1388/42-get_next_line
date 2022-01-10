/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoncalv <bgoncalv@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 21:19:44 by bgoncalv          #+#    #+#             */
/*   Updated: 2022/01/10 00:23:29 by bgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include <unistd.h> 
# include <stdlib.h>

size_t	ft_strlen(char *s);
int		ft_hasline(char *s);
char	*ft_strndup(char *s, size_t l);
char	*ft_strjoin(char *s1, char *s2);

char	*get_next_line(int fd);

#endif
