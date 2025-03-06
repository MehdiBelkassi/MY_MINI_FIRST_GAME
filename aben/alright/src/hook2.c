/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelkass <mbelkass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 06:28:35 by mbelkass          #+#    #+#             */
/*   Updated: 2025/02/28 06:28:37 by mbelkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
