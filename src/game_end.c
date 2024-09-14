/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_end.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolin <ccolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 12:08:07 by ccolin            #+#    #+#             */
/*   Updated: 2024/09/14 15:23:22 by ccolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "othello.h"

void	game_end(t_param *param)
{
	int	y;
	int	x;
	int	blacks;
	int	whites;
	system("afplay ./sounds/end.mp3 &");
	blacks = 0;
	whites = 0;
	y = -1;
	x = -1;
	param->board->game_end = 1;
	while (y < 7)
	{
		y++;
		while (x < 7)
		{
			x++;
			if (param->board->board[y][x] == BC || param->board->board[y][x] == B)
				blacks++;
			if (param->board->board[y][x] == WC || param->board->board[y][x] == W)
				whites++;
		}
		x = -1;
	}
	if (blacks < whites)
		mlx_put_image_to_window(param->mlx->mlx, param->mlx->win, param->mlx->whitev, 1 * TILE, 2 * TILE);
	else
		mlx_put_image_to_window(param->mlx->mlx, param->mlx->win, param->mlx->blackv, 1 * TILE, 2 * TILE);
}