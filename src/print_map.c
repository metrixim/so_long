/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcarelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 22:05:29 by gcarelle          #+#    #+#             */
/*   Updated: 2021/09/30 22:05:34 by gcarelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	print_string(t_game *game)
{
	if (game->end_game == 1)
		mlx_string_put(game->mlx, game->win, 150, 25, 0xFFFF00,
			"YOU WIN!!!");
	else if (game->end_game == 2)
		mlx_string_put(game->mlx, game->win, 150, 25, 0xFFFF00,
			"Pizdec...");
}

/* Draw player*/
void	print_player(t_game *game, t_pos pos)
{
	if (game->side == DOWN)
		mlx_put_image_to_window(game->mlx, game->win,
			game->img.player.down.img, pos.x, pos.y);
	else if (game->side == TOP)
		mlx_put_image_to_window(game->mlx, game->win,
			game->img.player.top.img, pos.x, pos.y);
	else if (game->side == RIGHT)
		mlx_put_image_to_window(game->mlx, game->win,
			game->img.player.right.img, pos.x, pos.y);
	else
		mlx_put_image_to_window(game->mlx, game->win,
			game->img.player.left.img, pos.x, pos.y);
}

/* Draw exit, collect and enemy */
void	print_sprites_cex(t_game *game, int line, int col)
{
	int	x;
	int	y;

	x = col * TILES;
	y = line * TILES;
	if (game->map.map[line][col] == 'E')
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->img.exit.img, x, y);
	}
	if (game->map.map[line][col] == 'C')
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->img.item.img, x, y);
	}
	if (game->map.map[line][col] == 'V')
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->img.enemy.img, x, y);
	}
}

/* Draw wall, empty*/
void	print_sprites_wpe(t_game *game, int line, int col)
{
	int		x;
	int		y;
	t_pos	pos;

	pos.x = col * TILES;
	pos.y = line * TILES;
	x = col * TILES;
	y = line * TILES;
	if (game->map.map[line][col] == '1')
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->img.wall.img, x, y);
	}
	if (game->map.map[line][col] == '0')
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->img.emp.img, x, y);
	}
	if (game->map.map[line][col] == 'P')
	{
		print_player(game, pos);
	}
}

/* Print map */
void	print_map(t_game *game)
{
	int		line;
	int		col;
	char	*str;

	line = 0;
	while (line < game->map.line)
	{
		col = 0;
		while (col < game->map.colum)
		{
			print_sprites_cex(game, line, col);
			print_sprites_wpe(game, line, col);
			col++;
		}
		line++;
		str = ft_itoa(game->steps);
		mlx_string_put(game->mlx, game->win, 25, 25, 0xFFFF00,
			"STEPS:");
		mlx_string_put(game->mlx, game->win, 120, 25, 0xFFFF00, str);
		free(str);
		print_string(game);
	}
}
