/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolin <ccolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 12:28:17 by ccolin            #+#    #+#             */
/*   Updated: 2024/09/14 15:55:47 by ccolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "othello.h"

void	place(t_param *param)
{
	printf("place\n");fflush(stdout);
	if (param->board->game_end)
		return;
	(void)param;
	t_cursor	cursor;
	cursor.x = -1;
    cursor.y = -1;
	find_cursor(param, &cursor);
	if (sandwich(param, &cursor))
	{
		printf("sandwich\n");fflush(stdout);
		print_board(param->board);
		is_playable(param, 1);
		return ;
	}
	system("afplay ./sounds/failure.wav &");
}

void	right(t_param *param)
{
	if (param->board->game_end)
		return;
	t_cursor	cursor;
	cursor.x = -1;
    cursor.y = -1;
	find_cursor(param, &cursor);
	if (cursor.x == 7)
		return ;
	if (param->board->board[cursor.y][cursor.x] == EC)
		param->board->board[cursor.y][cursor.x] = E;
	if (param->board->board[cursor.y][cursor.x] == WC)
		param->board->board[cursor.y][cursor.x] = W;
	if (param->board->board[cursor.y][cursor.x] == BC)
		param->board->board[cursor.y][cursor.x] = B;
	if (param->board->board[cursor.y][cursor.x + 1] == E)
		param->board->board[cursor.y][cursor.x + 1] = EC;
	if (param->board->board[cursor.y][cursor.x + 1] == W)
		param->board->board[cursor.y][cursor.x + 1] = WC;
	if (param->board->board[cursor.y][cursor.x + 1] == B)
		param->board->board[cursor.y][cursor.x + 1] = BC;
	ft_render_board(param->board, param->mlx);
}


void	left(t_param *param)
{
		if (param->board->game_end)
	return;
	t_cursor	cursor;
	cursor.x = -1;
    cursor.y = -1;
	find_cursor(param, &cursor);
	if (cursor.x == 0)
		return ;
	if (param->board->board[cursor.y][cursor.x] == EC)
		param->board->board[cursor.y][cursor.x] = E;
	if (param->board->board[cursor.y][cursor.x] == WC)
		param->board->board[cursor.y][cursor.x] = W;
	if (param->board->board[cursor.y][cursor.x] == BC)
		param->board->board[cursor.y][cursor.x] = B;
	if (param->board->board[cursor.y][cursor.x - 1] == E)
		param->board->board[cursor.y][cursor.x - 1] = EC;
	if (param->board->board[cursor.y][cursor.x - 1] == W)
		param->board->board[cursor.y][cursor.x - 1] = WC;
	if (param->board->board[cursor.y][cursor.x - 1] == B)
		param->board->board[cursor.y][cursor.x - 1] = BC;
	ft_render_board(param->board, param->mlx);
}

void	down(t_param *param)
{
	if (param->board->game_end)
		return;
	t_cursor	cursor;
	cursor.x = -1;
    cursor.y = -1;
	find_cursor(param, &cursor);
	if (cursor.y == 7)
		return ;
	if (param->board->board[cursor.y][cursor.x] == EC)
		param->board->board[cursor.y][cursor.x] = E;
	if (param->board->board[cursor.y][cursor.x] == WC)
		param->board->board[cursor.y][cursor.x] = W;
	if (param->board->board[cursor.y][cursor.x] == BC)
		param->board->board[cursor.y][cursor.x] = B;
	if (param->board->board[cursor.y + 1][cursor.x] == E)
		param->board->board[cursor.y + 1][cursor.x] = EC;
	if (param->board->board[cursor.y + 1][cursor.x] == W)
		param->board->board[cursor.y + 1][cursor.x] = WC;
	if (param->board->board[cursor.y + 1][cursor.x] == B)
		param->board->board[cursor.y + 1][cursor.x] = BC;
	ft_render_board(param->board, param->mlx);
}

void	up(t_param *param)
{
	if (param->board->game_end)
		return;
	t_cursor	cursor;
	cursor.x = -1;
    cursor.y = -1;
	find_cursor(param, &cursor);
	if (cursor.y == 0)
		return ;
	if (param->board->board[cursor.y][cursor.x] == EC)
		param->board->board[cursor.y][cursor.x] = E;
	if (param->board->board[cursor.y][cursor.x] == WC)
		param->board->board[cursor.y][cursor.x] = W;
	if (param->board->board[cursor.y][cursor.x] == BC)
		param->board->board[cursor.y][cursor.x] = B;
	if (param->board->board[cursor.y - 1][cursor.x] == E)
		param->board->board[cursor.y - 1][cursor.x] = EC;
	if (param->board->board[cursor.y - 1][cursor.x] == W)
		param->board->board[cursor.y - 1][cursor.x] = WC;
	if (param->board->board[cursor.y - 1][cursor.x] == B)
		param->board->board[cursor.y - 1][cursor.x] = BC;
	ft_render_board(param->board, param->mlx);
}

int	events(int keycode, void *param)
{
	t_param	*p;
	int		u;
	int		d;
	int		l;
	int		r;
	int		e;
	int		just_restarted;
	p = (t_param *)param;
	u = 126;
	d = 125;
	l = 123;
	r = 124;
	e = 36;
	just_restarted = 0;
	if (p->board->game_end)
		{
			p->board->game_end = 0;
			initialize_board(p->board);
			ft_render_board(p->board, p->mlx);
			just_restarted = 1;
			return (0);
		}
	if (just_restarted == 1)
	{
		just_restarted = 0;
		return (0);
	}
	if (keycode == u)
		up(p);
	if (keycode == l)
		left(p);
	if (keycode == d)
		down(p);
	if (keycode == r)
		right(p);
	if (keycode == e)
		place(p);
	if (keycode == 53)
		cleanup(p);
	return (0);
}