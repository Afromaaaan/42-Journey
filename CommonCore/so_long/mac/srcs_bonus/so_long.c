/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbaeza-c <jbaeza-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:50:21 by jimmy             #+#    #+#             */
/*   Updated: 2023/11/15 14:21:14 by jbaeza-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl_bonus/so_long.h"

static void	init_game_data(t_game *game, char *map)
{
	init_structs(game);
	read_map(map, game);
	check_route(game);
	game->win = mlx_new_window(game->mlx, game->width * SIZE,
			game->height * SIZE, "so_long");
	print_map(game);
}

void	so_long(int argc, char **argv)
{
	t_game	*game;

	(void)argc;
	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		return ;
	init_game_data(game, argv[1]);
	mlx_loop_hook(game->mlx, idle_animation, game);
	mlx_key_hook(game->win, ft_key_press, game);
	mlx_hook(game->win, 17, 0, ft_free, game);
	mlx_loop(game->mlx);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		ft_printf("Error. No se ha introducido ningún mapa\n");
		return (0);
	}
	if (!check_extension(argv[1]))
		so_long(argc, argv);
	return (0);
}
