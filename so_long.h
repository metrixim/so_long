/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcarelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 22:15:46 by gcarelle          #+#    #+#             */
/*   Updated: 2021/09/30 22:15:52 by gcarelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "./minilibx/mlx.h"

# define TILES 40
# define PATH_W "./sprite_file/wall4.xpm"
# define PATH_E "./sprite_file/empty4.xpm"
# define PATH_EX "./sprite_file/exit4.xpm"
# define PATH_PD "./sprite_file/player_down4.xpm"
# define PATH_PT "./sprite_file/player_top4.xpm"
# define PATH_PR "./sprite_file/player_right4.xpm"
# define PATH_PL "./sprite_file/player_left4.xpm"
# define PATH_I "./sprite_file/item4.xpm"
# define PATH_V "./sprite_file/venom4.xpm"

//клавиши
# define TOP 13
# define DOWN 1
# define LEFT 0
# define RIGHT 2
# define ESC 53

//game structs

typedef struct s_position
{
	int	x;
	int	y;
}				t_pos;

typedef struct s_map_check
{
	int	player;
	int	exit;
	int	collect;
}				t_map_check;

typedef struct s_map
{
	t_pos		player;
	int			valid;
	int			line;
	int			colum;
	t_map_check	check;
	char		**map;
}				t_map;

typedef struct s_data
{
	void	*img;
	char	*pixel;
	t_pos	pos;
	t_pos	size;
	int		bpp;
	int		line_size;
	int		endian;
}				t_data;

typedef struct s_side
{
	t_data	down;
	t_data	top;
	t_data	left;
	t_data	right;
}				t_side;

typedef struct s_img
{
	t_data	wall;
	t_data	emp;
	t_data	exit;
	t_side	player;
	t_data	item;
	t_data	enemy;
}				t_img;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_map	map;
	t_img	img;
	int		end_game;
	int		steps;
	int		init_game;
	int		side;
}				t_game;

// init game
void	init_struct_map(t_map *map);
t_img	init_image(void *mlx);
char	**init_map(t_game *game, char **argv);
void	init_window(t_game *game);
int		init_game(t_game *game, char **argv);

// init sprites
void	init_wall(t_img *img, void *mlx);
void	init_item(t_img *img, void *mlx);
void	init_exit(t_img *img, void *mlx);
void	init_enemy(t_img *img, void *mlx);
void	init_player(t_img *img, void *mlx);

//parse map
char	**read_map(char *path, t_map *map_ptr);
void	check_valid(char **map, t_map *map_ptr);
int		get_size(t_map *map, char *argv);
void	check_map(char **map, t_map *map_ptr);
void	check_form(char **map, t_map *map_ptr);
int		check_line(char *line);

//utils files
size_t	ft_strlen(const char *s);
int		get_next_line(int fd, char **line);
void	free_map(char **map_str, t_map *map);
char	*ft_itoa(int n);

//print map
void	print_map(t_game *game);
void	print_sprites_wpe(t_game *game, int line, int col);
void	print_sprites_cex(t_game *game, int line, int col);
void	print_player(t_game *game, t_pos pos);

//move player
int		close_win(t_game *game);
int		action(int keycode, t_game *game);
void	check_side(t_game *game, int key);
int		update(t_game *game);
void	kill_player(t_game *game);
int		verify_move(t_game *game, int line, int col, int key);
void	move_player(t_game *game, int line, int col, int key);

#endif
