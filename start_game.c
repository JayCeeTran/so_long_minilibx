/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtran <jtran@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 10:48:33 by jtran             #+#    #+#             */
/*   Updated: 2025/01/22 12:45:39 by jtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*start_game(t_game *game)
{
	game->action = 0;
	game->lastc = 1;
	game->big = 1;
	game->mlx = mlx_init();
	if(!game->mlx)
	{
		freemap(game);
		write(2, "Failed to initialize minilib\n", 29);
		exit(EXIT_FAILURE);
	}
	if (game->cols <= 15 && game->rows <= 11)
	{
		game->big = 0;
		game->win = mlx_new_window(game->mlx, game->cols * 64, game->rows * 64, "Noa's Game");
	}
	else
		game->win = mlx_new_window(game->mlx, 64 * 15, 64 * 11, "Noa's Game");
	if (game->mlx == NULL)
		initialization_fail(game);
	load_png(game);
	if (game->big == 0)
		drawmap(game);
	else
		drawmap_big(game);
	return (game->mlx);
}
