/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcarelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 22:04:48 by gcarelle          #+#    #+#             */
/*   Updated: 2021/09/30 22:04:52 by gcarelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	action(int keycode, t_game *game)
{
	int	line;
	int	col;

	line = game->map.player.x;
	col = game->map.player.y;
	if (keycode == ESC)
		close_win(game);
	if (keycode == TOP)
		line--;
	if (keycode == DOWN)
		line++;
	if (keycode == LEFT)
		col--;
	if (keycode == RIGHT)
		col++;
	if (!game->end_game)
		move_player(game, line, col, keycode);
	return (1);
}

int	update(t_game *game)
{
	if (game->end_game < 1)
	{
		mlx_clear_window(game->mlx, game->win);
	}
	print_map(game);
	return (0);
}

void	kill_player(t_game *game)
{
	int	y;
	int	x;

	y = game->map.player.y;
	x = game->map.player.x;
	game->map.map[x][y] = '0';
	game->side = DOWN;
	print_map(game);
}

int	verify_move(t_game *game, int line, int col, int key)
{
	if (game->map.map[line][col] == '1')
		return (-1);
	if (game->map.map[line][col] == 'E' && game->map.check.collect == 0)
	{
		game->end_game = 1;
	}
	if (game->map.map[line][col] == 'E')
		return (-1);
	if (game->end_game)
		return (-1);
	if (game->map.map[line][col] == 'V')
	{
		game->side = DOWN;
		game->end_game = 2;
		return (-1);
	}
	if (key != TOP && key != DOWN && key != LEFT && key != RIGHT)
		return (-1);
	else
		return (1);
}

void	move_player(t_game *game, int line, int col, int key)
{
	int	x;
	int	y;
	int	valid;

	x = game->map.player.x;
	y = game->map.player.y;
	valid = verify_move(game, line, col, key);
	check_side(game, key);
	if (game->end_game)
		kill_player(game);
	if (valid > 0)
	{
		if (game->map.map[line][col] == 'C')
			game->map.check.collect--;
		game->map.map[x][y] = '0';
		game->map.map[line][col] = 'P';
		game->map.player.x = line;
		game->map.player.y = col;
		game->steps++;
	}
}
