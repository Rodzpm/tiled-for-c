/*
** EPITECH PROJECT, 2022
** test_map
** File description:
** graphic_event.c
*/

#include "../../include/project.h"

void graphic_key_event(project_t *project, sfKeyCode key)
{
    switch (key) {
        case sfKeyEscape : sfRenderWindow_close(WINDOW); break;
        default : break;
    }
}

void graphic_event(project_t *project)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(WINDOW, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(WINDOW);
        if (event.type == sfEvtKeyPressed)
            graphic_key_event(project, event.key.code);
    }
}