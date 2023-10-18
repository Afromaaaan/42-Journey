/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimmy <jbaeza-c@student.42madrid.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 20:26:34 by jimmy             #+#    #+#             */
/*   Updated: 2023/10/18 12:56:48 by jbaeza-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

static void	print_corners(t_game *game, t_terrain *wall, int x, int y)
{
	x *= IMG_SIZE;
	y *= IMG_SIZE;
	if (!x && !y)
		mlx_put_image_to_window(game->mlx, game->win, wall->up_l, x, y);
	else if (!x)
		mlx_put_image_to_window(game->mlx, game->win, wall->down_l, x, y);
	else if (!y)
		mlx_put_image_to_window(game->mlx, game->win, wall->up_r, x, y);
	else
		mlx_put_image_to_window(game->mlx, game->win, wall->down_r, x, y);
}

static void	print_vertical(t_game *game, t_terrain *wall, int x, int y)
{
	x *= IMG_SIZE;
	y *= IMG_SIZE;
	if (!x)
		mlx_put_image_to_window(game->mlx, game->win, wall->left, x, y);
	else
		mlx_put_image_to_window(game->mlx, game->win, wall->right, x, y);
}

static void	print_horizontal(t_game *game, t_terrain *wall, int x, int y)
{
	x *= IMG_SIZE;
	y *= IMG_SIZE;
	if (!y)
		mlx_put_image_to_window(game->mlx, game->win, wall->up, x, y);
	else
		mlx_put_image_to_window(game->mlx, game->win, wall->down, x, y);
}

void	print_walls(t_game *game, int x, int y)
{
	if ((!x || x == game->width - 1) && (!y || y == game->height - 1))
		print_corners(game, game->terrain, x, y);
	else if (!x || x == game->width - 1)
		print_vertical(game, game->terrain, x, y);
	else if (!y || y == game->height - 1)
		print_horizontal(game, game->terrain, x, y);
	else
		mlx_put_image_to_window(game->mlx, game->win,
			game->terrain->block, x, y);
}
