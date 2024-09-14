/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_board.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolin <ccolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 09:18:53 by ccolin            #+#    #+#             */
/*   Updated: 2024/09/13 15:51:01 by ccolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "othello.h"

void	initialize_board(t_board *board)
{
	int		fd;
	char	*line;
	char	*temp;
	char*	txt_board;
	
	txt_board = ft_strdup("");
	fd = open("./board/board.txt", O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		temp = txt_board;
		txt_board = ft_strjoin(txt_board, line);
		free(line);
		free(temp);
		line = get_next_line(fd);
	}
	close(fd);
	board->board = ft_split(txt_board, '\n');
	free(txt_board);
	board->height = 8 * TILE;
	board->width = 8 * TILE;
	board->blackturn = 1;
}
