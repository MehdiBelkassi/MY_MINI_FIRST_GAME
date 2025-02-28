/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelkass <mbelkass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:15:54 by mbelkass          #+#    #+#             */
/*   Updated: 2025/02/27 22:45:57 by mbelkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	*check(char tile, t_game *game)
{
	if (tile == '1')
		return (game->wall_img);
	else if (tile == '0')
		return (game->space_img);
	else if (tile == 'C')
		return (game->collectible_img);
	else if (tile == 'E')
		return (game->exit_img);
	else if (tile == 'P')
		return (game->player_img);
	else if (tile == 'W')
		return (game->enemy_img);
	return (NULL);
}

void	render_map(t_game *game)
{
	int		y;
	int		x;
	void	*img;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			img = check(game->map[y][x], game);
			if (img)
			{
				mlx_put_image_to_window
				(
					game->mlx, game->win, img, x * TILE_SIZE, y * TILE_SIZE
				);
			}
			x++;
		}
		y++;
	}
}
