/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook2_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelkass <mbelkass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 06:29:32 by mbelkass          #+#    #+#             */
/*   Updated: 2025/03/08 22:17:00 by mbelkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	update_moves_display(t_game *game)
{
	free(game->moves_str);
	game->moves_str = ft_itoa(game->moves);
	mlx_string_put(game->mlx, game->win, 10, 10, 0xFFFF00, "Moves: ");
	mlx_string_put(game->mlx, game->win, 70, 10, 0xFFFF00, game->moves_str);
}

void	valid_pieces(t_game *game)
{
	if (game->player_count != 1)
	{
		ft_putstr_fd("Error :CHECK PLAYER IN THE MAP", 2);
		exit(1);
	}
	if (game->exit_count != 1)
	{
		ft_putstr_fd("Error :CHECK EXIT IN THE MAP", 2);
		exit(1);
	}
	if (game->collectible_count <= 0)
	{
		ft_putstr_fd("Error :CHECK COLLECTIBLES IN THE MAP", 2);
		exit(1);
	}
}

void	handle_fd(int *fd, char *file)
{
	*fd = open(file, O_RDONLY);
	if (*fd < 0)
		handle_err(*fd, "Error opening file\n");
}
