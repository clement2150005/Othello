/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolin <ccolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 08:57:03 by ccolin            #+#    #+#             */
/*   Updated: 2024/09/14 12:27:58 by ccolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "othello.h"

int	main(void)
{
	t_mlx	mlx;
	t_board	board;
	initialize_board(&board);
	start_mlx(&board, &mlx);
	mlx_loop(mlx.mlx);
}