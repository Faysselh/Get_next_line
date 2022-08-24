/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fayel-ha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 20:31:18 by fayel-ha          #+#    #+#             */
/*   Updated: 2020/06/30 15:29:11 by fayel-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int		ft_next(char *stock)
{
	int i;

	i = 0;
	while (stock[i] != '\n')
		i++;
	return (i);
}

char			*ft_recup_line(char *recup, char **stock)
{
	char *tmp;

	if (ft_strchr(*stock, '\n'))
	{
		if (!(recup = ft_substr(*stock, 0, ft_next(*stock))))
			return (0);
		tmp = *stock;
		if (!(*stock = ft_substr(tmp, ft_next(tmp) + 1, ft_strlen(tmp))))
			return (0);
		free(tmp);
	}
	else
	{
		if (!(recup = ft_strdup(*stock)))
			return (0);
		free(*stock);
		*stock = NULL;
	}
	return (recup);
}

int				ft_free(char *str)
{
	free(str);
	return (-1);
}

int				get_next_line(int fd, char **line)
{
	int				ret;
	static char		*stok[1024];
	char			*buf;
	char			*tmp;

	if (!(buf = malloc(sizeof(char) * BUFFER_SIZE + 1)))
		return (-1);
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (ft_free(buf));
	while ((!(ft_strchr(stok[fd], '\n'))) && \
			(ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = '\0';
		tmp = stok[fd];
		stok[fd] = stok[fd] == NULL ? ft_strj("", buf) : ft_strj(stok[fd], buf);
		free(tmp);
	}
	free(buf);
	if ((ret == -1) || (!(*line = ft_recup_line(*line, &stok[fd]))))
		return (-1);
	if (!stok[fd])
		return (0);
	return (1);
}
