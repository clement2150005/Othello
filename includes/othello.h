/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   othello.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolin <ccolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 08:18:06 by ccolin            #+#    #+#             */
/*   Updated: 2024/09/14 16:20:37 by ccolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OTHELLO_H
# define OTHELLO_H

# include "mlx.h"
# include "libft.h"
# include "get_next_line_bonus.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define TILE 64
# define E '0'
# define B 'B'
# define W 'W'
# define BC 'T'
# define WC 'Y'
# define EC 'U'
# define EMPTY "./textures/empty.xpm"
# define WHITE "./textures/white.xpm"
# define BLACK "./textures/black.xpm"
# define BCURSOR "./textures/black_cursor.xpm"
# define WCURSOR "./textures/white_cursor.xpm"
# define BLACKV "./textures/blackv.xpm"
# define WHITEV "./textures/whitev.xpm"

typedef struct s_board
{
	char	**board;
	int		height;
	int		width;
	int		blackturn;
	int		game_end;
}					t_board;

typedef struct s_sandwich
{
	int	l;
	int	r;
	int	u;
	int	d;
	int	lu;
	int	ld;
	int	ru;
	int	rd;
}					t_sandwich;

typedef struct s_cursor
{
	int		x;
	int		y;
}					t_cursor;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*black;
	void	*white;
	void	*empty;
	void	*wcursor;
	void	*bcursor;
	void	*blackv;
	void	*whitev;
	int		*height_white;
	int		*height_black;
	int		*height_whitev;
	int		*height_blackv;
	int		*height_empty;
	int		*width_black;
	int		*width_white;
	int		*width_blackv;
	int		*width_whitev;
	int		*width_empty;
	int		*height_bcursor;
	int		*width_bcursor;
	int		*height_wcursor;
	int		*width_wcursor;
}					t_mlx;

typedef struct s_param
{
	t_board	*board;
	t_mlx	*mlx;
}					t_param;

int 	cleanup(void *param);
void	start_mlx(t_board *board, t_mlx *mlx);
void	initialize_board(t_board *board);
int		events(int keycode, void *param);
void	ft_render_board(t_board *board, t_mlx *mlx);
void 	find_cursor(t_param *param, t_cursor *cursor);
void	flip(t_param *param, int y, int x);
int		sandwich(t_param *param, t_cursor *cursor);
void	is_playable(t_param *param, int first);
void	game_end(t_param *param);
int		is_sandwichl(int y, int x, char player, char opponent, char opponentc, t_param *param);
int		is_sandwichr(int y, int x, char player, char opponent, char opponentc, t_param *param);
int		is_sandwichd(int y, int x, char player, char opponent, char opponentc, t_param *param);
int		is_sandwichu(int y, int x, char player, char opponent, char opponentc, t_param *param);
int		is_sandwichlu(int y, int x, char player, char opponent, char opponentc, t_param *param);
int		is_sandwichld(int y, int x, char player, char opponent, char opponentc, t_param *param);
int		is_sandwichru(int y, int x, char player, char opponent, char opponentc, t_param *param);
int		is_sandwichrd(int y, int x, char player, char opponent, char opponentc, t_param *param);

#endif