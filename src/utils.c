/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolin <ccolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 14:59:50 by ccolin            #+#    #+#             */
/*   Updated: 2024/09/14 16:20:44 by ccolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "othello.h"

void find_cursor(t_param *param, t_cursor *cursor)
{
    int x, y;

    for (y = 0; y < 8; y++)
    {
        for (x = 0; x < 8; x++)
        {
            if (param->board->board[y][x] == BC || param->board->board[y][x] == WC || param->board->board[y][x] == EC)
            {
                cursor->x = x;
                cursor->y = y;
				return ;
            }
        }
    }
}

void	flip(t_param *param, int y, int x)
{
	if (param->board->board[y][x] == W)
	{
		param->board->board[y][x] = B;
		ft_render_board(param->board, param->mlx);
		mlx_do_sync(param->mlx->mlx);
		system("afplay ./sounds/flip.wav");
	}
	else
	{
		param->board->board[y][x] = W;
		ft_render_board(param->board, param->mlx);
		mlx_do_sync(param->mlx->mlx);
		system("afplay ./sounds/flip.wav");
	}
}
