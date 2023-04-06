/*
** EPITECH PROJECT, 2022
** test_map
** File description:
** graphic.h
*/

#ifndef GRAPHIC_H_
    #define GRAPHIC_H_
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <SFML/Window.h>
    #include <SFML/System.h>
    #include "utils.h"
    #include "map.h"

typedef struct project_s project_t;
typedef struct map_s map_t;

typedef struct graphic_s {
    sfRenderWindow *window;
    map_t *map;
} graphic_t;

graphic_t *graphic_init();
void graphic_draw(graphic_t *graphic);
void graphic_event(project_t *project);
graphic_t *graphic_init(void);
void graphic_event(project_t *project);

#endif