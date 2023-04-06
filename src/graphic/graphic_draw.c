/*
** EPITECH PROJECT, 2022
** test_map
** File description:
** graphic_draw.c
*/

#include "../../include/graphic.h"

void graphic_draw(graphic_t *graphic)
{
    sfRenderWindow_clear(graphic->window, sfBlack);
    draw_layers(graphic, graphic->map);
}