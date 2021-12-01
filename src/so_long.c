/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcarelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 22:05:44 by gcarelle          #+#    #+#             */
/*   Updated: 2021/09/30 22:05:48 by gcarelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_struct_game(t_game *game)
{
	game->side = 0;
	game->end_game = 0;
	game->steps = 0;
	game->init_game = 0;
}

int	main(int argc, char **argv)
{
	t_game	game;

	init_struct_game(&game);
	if (argc < 2 || argc > 3)
		return (0);
	if (init_game(&game, argv) < 0)
		return (0);
	mlx_hook(game.win, 17, 0, close_win, (void *)&game);
	 mlx_hook(game.win, 2, 1L << 0, action, (void *)&game);
	 mlx_loop_hook(game.mlx, update, &game);
	 mlx_loop(game.mlx);
	return (1);
}
