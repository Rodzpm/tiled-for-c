/*
** EPITECH PROJECT, 2022
** test_map
** File description:
** graphic_init.c
*/

#include "../../include/graphic.h"

graphic_t *graphic_init(void)
{
    graphic_t *graphic = malloc(sizeof(graphic_t));
    sfVideoMode mode = (sfVideoMode){1920, 1080, 32};

    graphic->window = sfRenderWindow_create(mode, "test map", sfClose | sfFullscreen, NULL);
    graphic->map = map_init("assets/res.map");
    return graphic;
}