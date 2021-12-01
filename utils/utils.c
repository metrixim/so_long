/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcarelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 22:07:28 by gcarelle          #+#    #+#             */
/*   Updated: 2021/09/30 22:07:31 by gcarelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

size_t	ft_strlen(const char *s)
{
	size_t				len;

	len = 0;
	while ((unsigned char)s[len])
		len++;
	return (len);
}

void	free_map(char **map_str, t_map *map)
{
	int	i;

	i = 0;
	while (i <= map->line)
	{
		free(map_str[i]);
		i++;
	}
	free(map_str);
}

int	check_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	close_win(t_game *game)
{
	free_map(game->map.map, &game->map);
	exit(0);
}

void	check_side(t_game *game, int key)
{
	if (key == DOWN)
		game->side = DOWN;
	else if (key == TOP)
		game->side = TOP;
	else if (key == RIGHT)
		game->side = RIGHT;
	else if (key == LEFT)
		game->side = LEFT;
}
