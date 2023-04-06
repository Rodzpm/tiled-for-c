/*
** EPITECH PROJECT, 2022
** test_map
** File description:
** list.c
*/

#include "../../include/utils.h"
#include "../../include/graphic.h"
#include "../../include/map.h"
#include <string.h>

void push_back(list_t **list, const char *id, void *node, enum type type)
{
    list_t *tmp = (*list);
    list_t *new_node = malloc(sizeof(list_t));

    new_node->element = node;
    new_node->id = strdup(id);
    new_node->next = NULL;
    new_node->type = type;
    if ((*list) == NULL) {
        (*list) = new_node;
    } else {
        for (; tmp->next != NULL; tmp = tmp->next);
        tmp->next = new_node;
    }
}