/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelkass <mbelkass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:30:18 by mbelkass          #+#    #+#             */
/*   Updated: 2025/02/07 16:50:40 by mbelkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char **read_map(const char *file, int *map_width, int *map_height) {
    int fd = open(file, O_RDONLY);
    if (fd < 0) {
        ft_putstr_fd("Error opening file\n", 2);
        exit(1);
    }

    char **map = malloc(sizeof(char *) * MAX_MAP_SIZE);
    if (!map) {
        close(fd);
        ft_putstr_fd("Memory allocation error\n", 2);
        exit(1);
    }

    *map_height = 0;
    char *line;
    while ((line = get_next_line(fd)) != NULL && *map_height < MAX_MAP_SIZE) 
    {
        line[ft_strcspn(line, "\n")] = '\0';
        
        if (ft_strlen(line) == 0) 
        {
            free(line);
            continue;
        }
        
        map[*map_height] = ft_strdup(line);
        free(line);
        
        if (!map[*map_height]) {
            ft_putstr_fd("Memory allocation error for line\n", 2);
            free_map(map, *map_height);
            close(fd);
            exit(1);
        }
        (*map_height)++;
    }

    close(fd);

    if (*map_height == 0) {
        ft_putstr_fd("Error: Empty map file\n", 2);
        free(map);
        exit(1);
    }

    *map_width = ft_strlen(map[0]);
    return map;
}

void validate_map(t_game *game) {
    int exit_count = 0, player_count = 0, collectible_count = 0;

    for (int y = 0; y < game->map_height; y++) {
        if ((int)ft_strlen(game->map[y]) != game->map_width) {
            ft_printf("Error\nMap is not rectangular.\n");
            free_map(game->map, game->map_height);
            exit(1);
        }

        for (int x = 0; x < game->map_width; x++) {
            char c = game->map[y][x];

            if (y == 0 || y == game->map_height - 1 || x == 0 || x == game->map_width - 1) {
                if (c != '1') {
                    ft_printf("Error\nMap is not surrounded by walls.\n");
                    free_map(game->map, game->map_height);
                    exit(1);
                }
            }

            if (c == 'E')
                exit_count++;
            else if (c == 'P') {
                player_count++;
                game->player_x = x;
                game->player_y = y;
            } else if (c == 'C')
                collectible_count++;
            else if (c != '1' && c != '0' && c != 'N') {
                ft_printf("Error\nInvalid character '%c' in map.\n", c);
                free_map(game->map, game->map_height);
                exit(1);
            }
        }
    }

    if (exit_count != 1 || player_count != 1 || collectible_count < 1) {
        ft_printf("Error\nMap must contain 1 exit, 1 player, and at least 1 collectible.\n");
        free_map(game->map, game->map_height);
        exit(1);
    }

    game->collectibles = collectible_count;
}

//i have to verify the file format 