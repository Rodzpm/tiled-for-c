/*
** EPITECH PROJECT, 2022
** test_map
** File description:
** map_create.c
*/

#include "../../include/map.h"
#include "../../include/utils.h"
#include <string.h>

sprite_t *create_sprite(int x, int y, char *path, sfIntRect rect)
{
    sprite_t *sprite = malloc(sizeof(sprite_t));
    printf("x %d y %d left %d top %d width %d height %d\n", x, y, rect.left, rect.top, rect.width, rect.height);
    sprite->texture = sfTexture_createFromFile(cat("./assets/", path), &rect);
    sprite->sprite = sfSprite_create();
    sfSprite_setTexture(sprite->sprite, sprite->texture, sfFalse);
    sfSprite_setPosition(sprite->sprite, (sfVector2f){(float)x, (float)y});
    return sprite;
}

void destroy_sprite(sprite_t *sprite)
{
    sfSprite_destroy(sprite->sprite);
    sfTexture_destroy(sprite->texture);
    free(sprite);
}