/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelkass <mbelkass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 06:28:15 by mbelkass          #+#    #+#             */
/*   Updated: 2025/03/07 09:20:35 by mbelkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**malloc_readmap_helper(char **map, int fd, int map_height)
{
	map = malloc(sizeof(char *) * map_height + 1);
	if (!map)
	{
		close(fd);
		ft_putstr_fd("Memory allocation error\n", 2);
		exit(1);
	}
	return (map);
}

void	handle_err(int fd, char *message)
{
	ft_putstr_fd(message, 2);
	if (fd > 0)
		close(fd);
	exit(1);
}

void	process_line(char *line, char **map, int *map_height, int fd)
{
	line[ft_strcspn(line, "\n")] = '\0';
	if (ft_strlen(line) == 0)
	{
		free(line);
		return ;
	}
	map[*map_height] = line;
	if (!map[*map_height])
	{
		free_map(map, *map_height);
		handle_err(fd, "Memory allocation error for line\n");
	}
	(*map_height)++;
}

void	check_extension(char *file)
{
	if (ft_strlen(file - 1) != 5)
	{
		file++;
		if (ft_strncmp(file, ".ber", 4) != 0)
		{
			ft_putstr_fd("Error\ninvalid extension", 2);
			exit(1);
		}
	}
}
