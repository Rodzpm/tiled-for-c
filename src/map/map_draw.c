/*
** EPITECH PROJECT, 2022
** test_map
** File description:
** map_draw.c
*/

#include "../../include/map.h"
#include "../../include/graphic.h"

void draw_sprites(graphic_t *graphic, list_t *sprites, map_t *map)
{
    list_t *tmp = sprites;
    for (int i = 0; i != map->size.x * map->size.y; i++) {
        if (tmp->element == NULL) {
            tmp = tmp->next;
            continue;
        }
        sfVector2f pos = sfSprite_getPosition(((sprite_t *)tmp->element)->sprite);
        //printf("position %d %d\n", pos.x, pos.y);
        sfRenderWindow_drawSprite(graphic->window, ((sprite_t *)tmp->element)->sprite, NULL);
        tmp = tmp->next;
    }
}

void draw_layers(graphic_t *graphic, map_t *map)
{
    if (map->layers == NULL)
        return;
    for (int i = 0; map->layers[i]; i++) {
        draw_sprites(graphic, map->layers[i], map);
    }
}
