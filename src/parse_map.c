/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcarelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 22:05:03 by gcarelle          #+#    #+#             */
/*   Updated: 2021/09/30 22:05:06 by gcarelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_form(char **map, t_map *map_ptr)
{
	int		i;
	size_t	columns;

	i = 0;
	columns = ft_strlen(map[i]);
	while (map[i])
	{
		if (columns != ft_strlen(map[i]))
			map_ptr->valid = 0;
		if (map[i][0] != '1' || map[i][columns - 1] != '1')
			map_ptr->valid = 0;
		i++;
	}
	if (!check_line(map[0]) || !check_line(map[i - 1]))
		map_ptr->valid = 0;
}

void	check_map(char **map, t_map *map_ptr)
{
	int	i;
	int	j;

	i = 0;
	while (i < map_ptr->line)
	{
		j = 0;
		while (j < map_ptr->colum)
		{
			if (map[i][j] == 'P')
			{
				map_ptr->check.player++;
				map_ptr->player.x = i;
				map_ptr->player.y = j;
			}
			if (map[i][j] == 'E')
				map_ptr->check.exit++;
			if (map[i][j] == 'C')
				map_ptr->check.collect++;
			j++;
		}
		i++;
	}
}

int	get_size(t_map *map, char *argv)
{
	char	*line;
	int		columns;
	int		lines;
	int		fd;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
		return (0);
	columns = 0;
	lines = 0;
	while (get_next_line(fd, &line))
	{
		columns = (int)ft_strlen(line);
		lines++;
		free(line);
	}
	free(line);
	close(fd);
	map->line = lines;
	map->colum = columns;
	return (1);
}

void	check_valid(char **map, t_map *map_ptr)
{
	check_form(map, map_ptr);
	check_map(map, map_ptr);
	if (map_ptr->check.player != 1 || map_ptr->check.exit != 1
		|| map_ptr->check.collect < 1)
		map_ptr->valid = 0;
}

char	**read_map(char *path, t_map *map_ptr)
{
	int		fd;
	int		i;
	char	**map;

	get_size(map_ptr, path);
	map = malloc(sizeof(char *) * ((map_ptr -> line) + 1));
	if (!map)
		return (0);
	fd = open(path, O_RDONLY);
	i = 0;
	while (get_next_line(fd, &map[i]))
		i++;
	free(map[i]);
	map[i] = NULL;
	check_valid(map, map_ptr);
	if (map_ptr -> valid == 0)
	{
		printf("NOT VALID MAP!!!\n");
		free_map(map, map_ptr);
		return (0);
	}
	close(fd);
	return (map);
}
