/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolin <ccolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 09:33:30 by ccolin            #+#    #+#             */
/*   Updated: 2024/09/14 15:09:18 by ccolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "othello.h"

void	free_textures(t_mlx *mlx)
{
	free(mlx->width_empty);
	free(mlx->height_empty);
	free(mlx->width_black);
	free(mlx->height_black);
	free(mlx->width_white);
	free(mlx->height_white);
	free(mlx->width_bcursor);
	free(mlx->height_bcursor);
	free(mlx->width_wcursor);
	free(mlx->height_wcursor);
	free(mlx->width_blackv);
	free(mlx->height_blackv);
	free(mlx->width_whitev);
	free(mlx->height_whitev);
}

void	freeboard(char **board)
{
	int	y;

	y = 0;
	while (board[y])
	{
		free(board[y]);
		y++;
	}
	free(board);
}

void	unload_textures(t_mlx *mlx)
{
	if (mlx->empty)
		mlx_destroy_image(mlx->mlx, mlx->empty);
	if (mlx->black)
		mlx_destroy_image(mlx->mlx, mlx->black);
	if (mlx->white)
		mlx_destroy_image(mlx->mlx, mlx->white);
	if (mlx->wcursor)
		mlx_destroy_image(mlx->mlx, mlx->wcursor);
	if (mlx->bcursor)
		mlx_destroy_image(mlx->mlx, mlx->bcursor);
	if (mlx->blackv)
		mlx_destroy_image(mlx->mlx, mlx->blackv);
	if (mlx->whitev)
		mlx_destroy_image(mlx->mlx, mlx->whitev);
}

int	cleanup(void *p)
{
	t_param *param = (t_param *)p;
	unload_textures(param->mlx);
	free_textures(param->mlx);
	freeboard(param->board->board);
	mlx_destroy_window(param->mlx->mlx, param->mlx->win);
	exit(0);
}
