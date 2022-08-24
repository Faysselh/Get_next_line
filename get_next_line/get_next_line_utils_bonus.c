/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fayel-ha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 20:31:39 by fayel-ha          #+#    #+#             */
/*   Updated: 2020/06/30 15:29:21 by fayel-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strdup(const char *s1)
{
	char	*dest;
	int		i;

	i = 0;
	if (!s1)
	{
		if (!(dest = (char *)malloc(sizeof(*dest) * 1)))
			return (NULL);
		dest[0] = '\0';
		return (dest);
	}
	if (!(dest = malloc(sizeof(*dest) * ft_strlen(s1) + 1)))
		return (NULL);
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int			i;
	const char	*s1;

	i = 0;
	s1 = s;
	if (s == NULL)
		return (NULL);
	while (s1[i])
	{
		if (s1[i] == c)
			return ((char *)s + i);
		i++;
	}
	if (s1[i] == c)
		return ((char *)s + i);
	else
		return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*dest;

	i = 0;
	if (!s)
		return (NULL);
	if (!(dest = (char *)malloc(sizeof(*dest) * len + 1)))
		return (NULL);
	if ((start > (unsigned int)ft_strlen((char *)s)))
		len = 0;
	while (s[start] && i < len)
	{
		dest[i] = s[start];
		i++;
		start++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strj(char const *s1, char const *s2)
{
	int		i;
	int		n;
	char	*dest;

	i = 0;
	n = 0;
	if (!s1 || !s2)
		return (NULL);
	if (!(dest = malloc(sizeof(*dest) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	while (s2[n])
	{
		dest[i] = s2[n];
		i++;
		n++;
	}
	dest[i] = '\0';
	return (dest);
}
