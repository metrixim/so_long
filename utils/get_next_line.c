/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcarelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 22:06:38 by gcarelle          #+#    #+#             */
/*   Updated: 2021/09/30 22:06:42 by gcarelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static char	*ft_aux(char *s, char c)
{
	char	*res;
	int		len;

	len = ft_strlen(s);
	res = malloc(len + 2);
	if (!res)
		return (NULL);
	res[len + 1] = '\0';
	res[len] = c;
	while (--len >= 0)
		res[len] = s[len];
	free(s);
	return (res);
}

int	get_next_line(int fd, char **line)
{
	char	buffer;
	int		ret;

	if (!line)
		return (-1);
	*line = malloc(1);
	*line[0] = '\0';
	ret = read(fd, &buffer, 1);
	while (ret > 0)
	{
		if (buffer == '\n')
			break ;
		*line = ft_aux(*line, buffer);
		ret = read(fd, &buffer, 1);
	}
	return (ft_strlen(*line));
}
