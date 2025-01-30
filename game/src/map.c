#include "so_long.h"

char **read_map(const char *file, int *map_width, int *map_height) {
    FILE *fp = fopen(file, "r");
    if (!fp) {
        fprintf(stderr, "Error opening file %s: %s\n", file, strerror(errno));
        exit(1);
    }

    char **map = malloc(sizeof(char *) * MAX_MAP_SIZE);
    if (!map) {
        fclose(fp);
        fprintf(stderr, "Memory allocation error\n");
        exit(1);
    }

    *map_height = 0;
    char line[4096];
    while (fgets(line, sizeof(line), fp) && *map_height < MAX_MAP_SIZE) {
        line[strcspn(line, "\n")] = 0;
        
        if (strlen(line) == 0) continue;

        map[*map_height] = strdup(line);
        if (!map[*map_height]) {
            fprintf(stderr, "Memory allocation error for line\n");
            free_map(map, *map_height);
            fclose(fp);
            exit(1);
        }
        (*map_height)++;
    }

    fclose(fp);

    if (*map_height == 0) {
        fprintf(stderr, "Error: Empty map file\n");
        free(map);
        exit(1);
    }

    *map_width = strlen(map[0]);
    return map;
}

void validate_map(t_game *game) {
    int exit_count = 0, player_count = 0, collectible_count = 0;

    for (int y = 0; y < game->map_height; y++) {
        if ((int)strlen(game->map[y]) != game->map_width) {
            printf("Error\nMap is not rectangular.\n");
            free_map(game->map, game->map_height);
            exit(1);
        }

        for (int x = 0; x < game->map_width; x++) {
            char c = game->map[y][x];

            if (y == 0 || y == game->map_height - 1 || x == 0 || x == game->map_width - 1) {
                if (c != '1') {
                    printf("Error\nMap is not surrounded by walls.\n");
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
                printf("Error\nInvalid character '%c' in map.\n", c);
                free_map(game->map, game->map_height);
                exit(1);
            }
        }
    }

    if (exit_count != 1 || player_count != 1 || collectible_count < 1) {
        printf("Error\nMap must contain 1 exit, 1 player, and at least 1 collectible.\n");
        free_map(game->map, game->map_height);
        exit(1);
    }

    game->collectibles = collectible_count;
}
