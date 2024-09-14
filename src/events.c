/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolin <ccolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 12:28:17 by ccolin            #+#    #+#             */
/*   Updated: 2024/09/14 10:40:36 by ccolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "othello.h"

void	place(t_param *param)
{
	(void)param;
	t_cursor	cursor;
	cursor.x = -1;
    cursor.y = -1;
	find_cursor(param, &cursor);
	if (sandwich(param, &cursor))
	{
		if (param->board->blackturn)
			param->board->blackturn = 0;
		else
			param->board->blackturn = 1;
		return ;
	}
	system("afplay ./sounds/failure.mp3 &");
}

void	right(t_param *param)
{
	t_cursor	cursor;
	printf("right");
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
	t_cursor	cursor;
	printf("left\n");
	cursor.x = -1; // Default value if cursor is not found
    cursor.y = -1;
	find_cursor(param, &cursor);
	if (cursor.x == 0) // Check if at the left edge of the board
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
	t_cursor	cursor;
	printf("down\n");
	cursor.x = -1; // Default value if cursor is not found
    cursor.y = -1;
	find_cursor(param, &cursor);
	if (cursor.y == 7) // Check if at the bottom edge of the board
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
	t_cursor	cursor;
	printf("up\n");
	cursor.x = -1; // Default value if cursor is not found
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
	printf("%d", keycode);
	p = (t_param *)param;
	u = 126;
	d = 125;
	l = 123;
	r = 124;
	e = 36;
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