/*
** EPITECH PROJECT, 2022
** test_map
** File description:
** main.c
*/

#include "../include/project.h"

void main_loop(project_t *project)
{
    while (sfRenderWindow_isOpen(WINDOW)) {
        graphic_event(project);
        graphic_draw(project->graphic);
        sfRenderWindow_display(WINDOW);
    }
}

project_t *init_project()
{
    project_t *project = malloc(sizeof(project_t));

    project->graphic = graphic_init();
    return project;
}

int main()
{
    project_t *project = init_project();
    main_loop(project);
    return 0;
}