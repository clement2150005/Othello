/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sandwich.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolin <ccolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 17:31:21 by ccolin            #+#    #+#             */
/*   Updated: 2024/09/14 10:40:18 by ccolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "othello.h"

int	is_sandwichl(int y, int x, char player,char opponent, t_param *param)
{
	if (x <= 1)
		return (0);
	if (param->board->board[y][x - 1] != opponent)
		return(0);
	x--;
	while (x >= 1 && param->board->board[y][x] == opponent)
		x--;
	if (param->board->board[y][x] == player)
		return (1);
	return (0);
}

int	is_sandwichr(int y, int x, char player,char opponent, t_param *param)
{
	if (x >= 6)
		return (0);
	if (param->board->board[y][x + 1] != opponent)
		return(0);
	x++;
	while (x <= 6 && param->board->board[y][x] == opponent)
		x++;
	if (param->board->board[y][x] == player)
		return (1);
	return (0);
}

int	is_sandwichd(int y, int x, char player,char opponent, t_param *param)
{
	if (y >= 6)
		return (0);
	if (param->board->board[y + 1][x] != opponent)
		return(0);
	y++;
	while (y <= 6 && param->board->board[y][x] == opponent)
		y++;
	if (param->board->board[y][x] == player)
		return (1);
	return (0);
}

int	is_sandwichu(int y, int x, char player,char opponent, t_param *param)
{
	if (y <= 1)
		return (0);
	if (param->board->board[y - 1][x] != opponent)
		return(0);
	y--;
	while (y >= 1 && param->board->board[y][x] == opponent)
		y--;
	if (param->board->board[y][x] == player)
		return (1);
	return (0);
}

int	is_sandwichlu(int y, int x, char player,char opponent, t_param *param)
{
	if (x <= 1 || y <= 1)
		return (0);
	if (param->board->board[y - 1][x - 1] != opponent)
		return(0);
	x--;
	y--;
	while (x >= 1 && y >= 1 && param->board->board[y][x] == opponent)
	{
		y--;
		x--;
	}
	if (param->board->board[y][x] == player)
		return (1);
	return (0);
}

int	is_sandwichld(int y, int x, char player,char opponent, t_param *param)
{
	if (x <= 1 || y >= 6)
		return (0);
	if (param->board->board[y + 1][x - 1] != opponent)
		return(0);
	x--;
	y++;
	while (x >= 1 && y <= 6 && param->board->board[y][x] == opponent)
	{
		y++;
		x--;
	}
	if (param->board->board[y][x] == player)
		return (1);
	return (0);
}

int	is_sandwichru(int y, int x, char player,char opponent, t_param *param)
{
	if (x >= 6 || y <= 1)
		return (0);
	if (param->board->board[y - 1][x + 1] != opponent)
		return(0);
	x++;
	y--;
	while (x <= 6 && y >= 1 && param->board->board[y][x] == opponent)
	{
		y--;
		x++;
	}
	if (param->board->board[y][x] == player)
		return (1);
	return (0);
}

int	is_sandwichrd(int y, int x, char player,char opponent, t_param *param)
{
	if (x >= 6 || y >= 6)
		return (0);
	if (param->board->board[y + 1][x + 1] != opponent)
		return(0);
	x++;
	y++;
	while (x <= 6 && y <= 6 && param->board->board[y][x] == opponent)
	{
		y++;
		x++;
	}
	if (param->board->board[y][x] == player)
		return (1);
	return (0);
}

void	sandwichl(t_param *param, t_cursor *cursor)
{
	int		y;
	int		x;
	char	c;

	y = cursor->y;
	x = cursor->x;
	if (param->board->blackturn)
		c = W;
	else
		c = B;
	x--;
	while (param->board->board[y][x] == c)
	{
		flip(param, y, x);
		x--;
	}
}

void	sandwichr(t_param *param, t_cursor *cursor)
{
	int		y;
	int		x;
	char	c;

	y = cursor->y;
	x = cursor->x;
	if (param->board->blackturn)
		c = W;
	else
		c = B;
	x++;
	while (param->board->board[y][x] == c)
	{
		flip(param, y, x);
		x++;
	}
}

void	sandwichu(t_param *param, t_cursor *cursor)
{
	int		y;
	int		x;
	char	c;

	y = cursor->y;
	x = cursor->x;
	if (param->board->blackturn)
		c = W;
	else
		c = B;
	y--;
	while (param->board->board[y][x] == c)
	{
		flip(param, y, x);
		y--;
	}
}

void	sandwichd(t_param *param, t_cursor *cursor)
{
	int		y;
	int		x;
	char	c;

	y = cursor->y;
	x = cursor->x;
	if (param->board->blackturn)
		c = W;
	else
		c = B;
	y++;
	while (param->board->board[y][x] == c)
	{
		flip(param, y, x);
		y++;
	}
}

void	sandwichld(t_param *param, t_cursor *cursor)
{
	int		y;
	int		x;
	char	c;

	y = cursor->y;
	x = cursor->x;
	if (param->board->blackturn)
		c = W;
	else
		c = B;
	x--;
	y++;
	while (param->board->board[y][x] == c)
	{
		flip(param, y, x);
		x--;
		y++;
	}
}

void	sandwichlu(t_param *param, t_cursor *cursor)
{
	int		y;
	int		x;
	char	c;

	y = cursor->y;
	x = cursor->x;
	if (param->board->blackturn)
		c = W;
	else
		c = B;
	x--;
	y--;
	while (param->board->board[y][x] == c)
	{
		flip(param, y, x);
		x--;
		y--;
	}
}

void	sandwichru(t_param *param, t_cursor *cursor)
{
	int		y;
	int		x;
	char	c;

	y = cursor->y;
	x = cursor->x;
	if (param->board->blackturn)
		c = W;
	else
		c = B;
	x++;
	y--;
	while (param->board->board[y][x] == c)
	{
		flip(param, y, x);
		x++;
		y--;
	}
}

void	sandwichrd(t_param *param, t_cursor *cursor)
{
	int		y;
	int		x;
	char	c;

	y = cursor->y;
	x = cursor->x;
	if (param->board->blackturn)
		c = W;
	else
		c = B;
	x++;
	y++;
	while (param->board->board[y][x] == c)
	{
		flip(param, y, x);
		x++;
		y++;
	}
}

void	is_sandwich(t_sandwich *sandwich, t_param *param, t_cursor *cursor)
{
	int		y;
	int		x;
	char	player;
	char	opponent;

	y = cursor->y;
	x = cursor->x;
	if (param->board->blackturn)
	{
		player = B;
		opponent = W;
	}
	else
	{
		player = W;
		opponent = B;
	}
	sandwich->l = is_sandwichl(y, x, player, opponent, param);
	sandwich->r = is_sandwichr(y, x, player, opponent, param);
	sandwich->d = is_sandwichd(y, x, player, opponent, param);
	sandwich->u = is_sandwichu(y, x, player, opponent, param);
	sandwich->lu = is_sandwichlu(y, x, player, opponent, param);
	sandwich->ld = is_sandwichld(y, x, player, opponent, param);
	sandwich->ru = is_sandwichru(y, x, player, opponent, param);
	sandwich->rd = is_sandwichrd(y, x, player, opponent, param);
}

int	sandwich(t_param *param, t_cursor *cursor)
{
	t_sandwich	sandwich;
	is_sandwich(&sandwich, param, cursor);
	if (sandwich.l == 1 || sandwich.r == 1 || sandwich.u == 1 || sandwich.d == 1 || sandwich.lu == 1 || sandwich.ld == 1 || sandwich.ru == 1 || sandwich.rd == 1)
	{
		if (param->board->blackturn)
		{
			param->board->board[cursor->y][cursor->x] = BC;
			ft_render_board(param->board, param->mlx);
			mlx_do_sync(param->mlx->mlx);
			system("afplay ./sounds/success.mp3");
		}
		else
		{
			param->board->board[cursor->y][cursor->x] = WC;
			ft_render_board(param->board, param->mlx);
			mlx_do_sync(param->mlx->mlx);
			system("afplay ./sounds/success.mp3");
		}
		if (sandwich.l == 1)
			sandwichl(param, cursor);
		if (sandwich.r == 1)
			sandwichr(param, cursor);
		if (sandwich.d == 1)
			sandwichd(param, cursor);
		if (sandwich.u == 1)
			sandwichu(param, cursor);
		if (sandwich.lu == 1)	
			sandwichlu(param, cursor);
		if (sandwich.ld == 1)
			sandwichld(param, cursor);
		if (sandwich.rd == 1)
			sandwichrd(param, cursor);
		if (sandwich.ru == 1)
			sandwichru(param, cursor);
		return (1);
	}
	return (0);
}
