#include "so_long.h"

void free_map(char **map, int map_height) {
    if (map) {
        for (int i = 0; i < map_height; i++)
            free(map[i]);
        free(map);
    }
}