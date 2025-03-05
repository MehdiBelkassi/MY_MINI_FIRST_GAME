/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook2_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelkass <mbelkass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 06:29:32 by mbelkass          #+#    #+#             */
/*   Updated: 2025/03/04 21:08:19 by mbelkass         ###   ########.fr       */
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
