/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolin <ccolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 09:19:19 by ccolin            #+#    #+#             */
/*   Updated: 2024/09/13 15:50:58 by ccolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "othello.h"

void	ft_render_image(char c, t_mlx *mlx, int x, int y, t_board *board)
{
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->empty, x * TILE, y * TILE);
	if (c == W)
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->white, x * TILE, y * TILE);
	else if (c == B)
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->black, x * TILE, y * TILE);
	else if (c == EC)
	{
		if (board->blackturn)
			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->bcursor, x * TILE, y * TILE);
		if (!board->blackturn)
			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->wcursor, x * TILE, y * TILE);
	}
	else if (c == WC)
	{
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->white, x * TILE, y * TILE);
		if (board->blackturn)
			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->bcursor, x * TILE, y * TILE);
		if (!board->blackturn)
			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->wcursor, x * TILE, y * TILE);
	}
	else if (c == BC)
	{
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->black, x * TILE, y * TILE);
		if (board->blackturn)
			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->bcursor, x * TILE, y * TILE);
		if (!board->blackturn)
			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->wcursor, x * TILE, y * TILE);
	}
}

void	ft_render_board(t_board *board, t_mlx *mlx)
{
	int	y;
	int	x;
	y = 0;
	x = 0;
	mlx_clear_window(mlx->mlx, mlx->win);
	while (board->board[y])
	{
		while (board->board[y][x])
		{
			ft_render_image(board->board[y][x], mlx, x, y, board);
			x++;
		}
		y++;
		x = 0;
	}
}

void	ft_load_textures(t_mlx *mlx)
{
	mlx->width_empty = malloc(sizeof(int));
	mlx->height_empty = malloc(sizeof(int));
	mlx->width_black = malloc(sizeof(int));
	mlx->height_black = malloc(sizeof(int));
	mlx->width_white = malloc(sizeof(int));
	mlx->height_white = malloc(sizeof(int));
	mlx->width_bcursor = malloc(sizeof(int));
	mlx->height_bcursor = malloc(sizeof(int));
	mlx->height_wcursor = malloc(sizeof(int));
	mlx->width_wcursor = malloc(sizeof(int));
	mlx->empty = mlx_xpm_file_to_image(mlx->mlx, EMPTY, mlx->width_empty, mlx->height_empty);
	mlx->black = mlx_xpm_file_to_image(mlx->mlx, BLACK, mlx->width_black, mlx->height_black);
	mlx->white = mlx_xpm_file_to_image(mlx->mlx, WHITE, mlx->width_white, mlx->height_white);
	mlx->bcursor = mlx_xpm_file_to_image(mlx->mlx, BCURSOR, mlx->width_wcursor, mlx->height_wcursor);
	mlx->wcursor = mlx_xpm_file_to_image(mlx->mlx, WCURSOR, mlx->width_bcursor, mlx->height_bcursor);
}

void	start_mlx(t_board *board, t_mlx *mlx)
{
	static t_param		param;
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, board->width, board->height, "Othello");
	ft_load_textures(mlx);
	ft_render_board(board, mlx);
	param.board = board;
	param.mlx = mlx;
	mlx_hook(mlx->win, 17, 0, cleanup, &param);
	mlx_key_hook(mlx -> win, events, &param);
}