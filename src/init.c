/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcarelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 22:04:08 by gcarelle          #+#    #+#             */
/*   Updated: 2021/09/30 22:04:17 by gcarelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_struct_map(t_map *map)
{
	map->colum = 0;
	map->line = 0;
	map->valid = 1;
	map->check.collect = 0;
	map->check.exit = 0;
	map->check.player = 0;
}

t_img	init_image(void *mlx)
{
	t_img	img;

	init_wall(&img, mlx);
	init_exit(&img, mlx);
	init_item(&img, mlx);
	init_player(&img, mlx);
	init_enemy(&img, mlx);
	return (img);
}

char	**init_map(t_game *game, char **argv)
{
	char	**map;

	map = read_map(argv[1], &game->map);
	if (!map)
		return (0);
	return (map);
}

void	init_window(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->map.colum * TILES,
			game->map.line * TILES, "so_long");
}

int	init_game(t_game *game, char **argv)
{
	t_map	map;

	init_struct_map(&map);
	game->map = map;
	game->map.map = init_map(game, argv);
	if (game->map.map == NULL)
		return (-1);
	init_window(game);
	 game->img = init_image(game->mlx);
	 game->side = DOWN;
	 print_map(game);
	 game->init_game = 1;
	return (1);
}
