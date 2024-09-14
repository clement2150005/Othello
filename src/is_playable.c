/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_playable.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolin <ccolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 11:38:11 by ccolin            #+#    #+#             */
/*   Updated: 2024/09/14 16:20:41 by ccolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "othello.h"

void	is_playable(t_param *param, int first)
{
	int		y;
	int		x;
	char	player;
	char	opponent;
	char	opponentc;
	if (param->board->blackturn)
	{
		player = B;
		opponent = W;
		opponentc = WC;
	}
	else
	{
		player = W;
		opponent = B;
		opponentc = BC;
	}
	y = -1;
	x = -1;
	while (y < 7)
	{
		y++;
		while (x < 7)
		{
			x++;
			if (param->board->board[y][x] == E || param->board->board[y][x] == EC)
			{
				if (is_sandwichl(y, x, player, opponent, opponentc, param))
					return ;
				if (is_sandwichr(y, x, player, opponent, opponentc, param))
					return ;
				if (is_sandwichd(y, x, player, opponent, opponentc, param))
					return ;
				if (is_sandwichu(y, x, player, opponent, opponentc, param))
					return ;
				if (is_sandwichlu(y, x, player, opponent, opponentc, param))
					return ;
				if (is_sandwichld(y, x, player, opponent, opponentc, param))
					return ;
				if (is_sandwichru(y, x, player, opponent, opponentc, param))
					return ;
				if (is_sandwichrd(y, x, player, opponent, opponentc, param))
					return ;
			}
		}
		x = -1;
	}
	if (!first)
	{
		game_end(param);
		return ;
	}
	if (param->board->blackturn)
		param->board->blackturn = 0;
	else
		param->board->blackturn = 1;
	is_playable(param, 0);
}
