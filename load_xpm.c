#include "so_long.h"

int	press_x(t_game *game)
{
	close_game(game);
	exit(EXIT_SUCCESS);
}

void	delete_imgs(t_game *game)
{
	mlx_destroy_image(game->mlx, game->img_wall);
	mlx_destroy_image(game->mlx, game->img_empty);
	mlx_destroy_image(game->mlx, game->img_collectible);
	mlx_destroy_image(game->mlx, game->img_exit);
	mlx_destroy_image(game->mlx, game->img_player);
}

int	load_png(t_game *game)
{
    game->img_wall = mlx_xpm_file_to_image(game->mlx, "textures/tree.xpm", &game->win_width, &game->win_height);
    game->img_empty = mlx_xpm_file_to_image(game->mlx, "textures/empty.xpm", &game->win_width, &game->win_height);
    game->img_collectible = mlx_xpm_file_to_image(game->mlx, "textures/Taide.xpm", &game->win_width, &game->win_height);
    game->img_exit = mlx_xpm_file_to_image(game->mlx, "textures/Ditto.xpm", &game->win_width, &game->win_height);
    game->img_player = mlx_xpm_file_to_image(game->mlx, "textures/Player.xpm", &game->win_width, &game->win_height);
    if(!game->img_wall || !game->img_empty || !game->img_collectible || !game->img_exit || !game->img_player)
    {
        printf("Error loading images\n");
        return (0);
    }
    game->tilesize = game->win_width;
    return (1);
}
