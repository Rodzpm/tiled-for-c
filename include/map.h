/*
** EPITECH PROJECT, 2022
** test_map
** File description:
** map.h
*/

#ifndef INVENTORY_H_
    #define INVENTORY_H_
    #include <stdbool.h>
    #include "utils.h"
    #include "graphic.h"

typedef struct graphic_s graphic_t;

typedef struct sprite_s {
    sfSprite *sprite;
    sfTexture *texture;
} sprite_t;

typedef struct map_s {
    sfVector2f size;
    char **tilesets;
    list_t **layers;
} map_t;

map_t *map_init(char *path);
void draw_layers(graphic_t *graphic, map_t *map);
void draw_sprites(graphic_t *graphic, list_t *sprites, map_t *map);
sprite_t *create_sprite(int x, int y, char *path, sfIntRect rect);

#endif