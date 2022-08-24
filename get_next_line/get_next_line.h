/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fayel-ha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 12:14:53 by fayel-ha          #+#    #+#             */
/*   Updated: 2020/07/02 17:36:22 by Fayel-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdio.h>
# include <fcntl.h>

size_t	ft_strlen(const char *s);
int		get_next_line(int fd, char **line);
char	*ft_strdup(const char *s1);
char	*ft_strch(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strj(char const *s1, char const *s2);

#endif
