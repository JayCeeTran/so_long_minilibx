/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtran <jtran@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 10:40:11 by jtran             #+#    #+#             */
/*   Updated: 2025/01/22 12:53:52 by jtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	win_game(t_game *game)
{
	ft_printf("GG!\n");
	close_game(game);
}

void	lose_game(t_game *game)
{
	ft_printf("Noa You SUCK!!!\n");
	close_game(game);
}

void	close_game(t_game *game)
{
	freemap(game);
	delete_imgs(game);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
}

void	reset_visited(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->rows)
	{
		j = 0;
		while (j < game->cols)
		{
			game->map[i][j].visited = 0;
			j++;
		}
		i++;
	}
}

int	keyhook(int keycode, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keycode == 65307)
		close_game(game);
	if (keycode == 100 || keycode == 97 || keycode == 115
			|| keycode == 119)
		moving_keys(game, keycode);
	if (game->lastc == 1 && game->collectibles == 0)
	{
		game->moves = 0;
		game->sp.rear = 0;
		game->lastc = 0;
		reset_visited(game);
		short_path(game, 0);
	}
}
