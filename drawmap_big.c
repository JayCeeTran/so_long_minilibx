/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawmap_big.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtran <jtran@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 10:39:22 by jtran             #+#    #+#             */
/*   Updated: 2025/01/22 11:09:06 by jtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    check_struct_big(t_map map, t_game *game, int i, int j)
{
    if (map.wall)
        mlx_put_image_to_window(game->mlx, game->win, game->img_wall, j * game->tilesize, i
            * game->tilesize);
    else if (map.player)
        mlx_put_image_to_window(game->mlx, game->win, game->img_player, j * game->tilesize,
            i * game->tilesize);
    else if (map.exit)
        mlx_put_image_to_window(game->mlx, game->win, game->img_exit, j * game->tilesize, i
            * game->tilesize);
    else if (map.empty)
        mlx_put_image_to_window(game->mlx, game->win, game->img_empty, j * game->tilesize, i
            * game->tilesize);
    else if (map.collectible)
        mlx_put_image_to_window(game->mlx, game->win, game->img_collectible, j
            * game->tilesize, i * game->tilesize);
}

void	drawmap_big(t_game *game)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = 0;
	x = -1;
	if (game->player.pi > 5)
		i = game->player.pi - 5;
	while (++x < 11)
	{
		j = 0;
		y = 0;
		if (game->player.pj > 7)
			j = game->player.pj - 7;
		while (y < 15)
		{
			if (i < game->rows && j < game->cols)
				check_struct_big(game->map[i][j++], game, x, y++);
			else
				mlx_put_image_to_window(game->mlx, game->win, game->img_wall, (y++)
					* game->tilesize, x * game->tilesize);
		}
		i++;
	}
}
