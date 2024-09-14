/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolin <ccolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 14:59:50 by ccolin            #+#    #+#             */
/*   Updated: 2024/09/14 07:57:38 by ccolin           ###   ########.fr       */
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

void	print_board(t_board *board)
{
	int y = 0;

	while (board->board[y])  // Loop through each row until null
	{
		int x = 0;
		while (board->board[y][x])  // Loop through each column until null
		{
			x++;
		}
		y++;
	}
}

void	init_sandwich(t_sandwich *sandwich)
{
	sandwich->l = 0;
	sandwich->r = 0;
	sandwich->u = 0;
	sandwich->d = 0;
	sandwich->lu = 0;
	sandwich->ld = 0;
	sandwich->ru = 0;
	sandwich->rd = 0;
}

void	flip(t_param *param, int y, int x)
{
	if (param->board->board[y][x] == W)
	{
		param->board->board[y][x] = B;
		ft_render_board(param->board, param->mlx);
		mlx_do_sync(param->mlx->mlx);
		system("afplay ./sounds/success.mp3");
	}
	else
	{
		param->board->board[y][x] = W;
		ft_render_board(param->board, param->mlx);
		mlx_do_sync(param->mlx->mlx);
		system("afplay ./sounds/success.mp3");
	}
}