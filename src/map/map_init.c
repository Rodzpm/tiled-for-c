/*
** EPITECH PROJECT, 2022
** test_map
** File description:
** map_init.c
*/

#include "../../include/map.h"

int get_nb_layers(char *path)
{
    FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;
    int total = 0;

    fp = fopen(path, "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);
    while ((read = getline(&line, &len, fp)) != -1) {
        if (!my_strcmp(line, "#layer\n"))
            total++;
    }
    if (line)
        free(line);
    close(fp);
    return total;
}

char *get_value(char *path, char *name)
{
    FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;

    fp = fopen(path, "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);
    while ((read = getline(&line, &len, fp)) != -1) {
        if (!my_strcmp(line, name)) {
            getline(&line, &len, fp);
            return line;
        }
    }
    if (line)
        free(line);
    close(fp);
    return NULL;
}

list_t **get_layers(char *path, map_t *map)
{
    int nb_layer = get_nb_layers(path);
    int i = -1;
    list_t **layers = malloc(sizeof(list_t *) * (nb_layer + 1));
    FILE * fp;
    char * line = NULL;
    int x = 0;
    int y = 0;
    size_t len = 0;
    char *token;
    ssize_t read;
    bool checking = false;

    fp = fopen(path, "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);
    while ((read = getline(&line, &len, fp)) != -1) {
        if (!my_strcmp(line, "#layer\n")) {
            printf("layer !\n");
            i++;
            layers[i] = NULL;
            x = 0;
            y = 0;
            checking = true;
        }
        if (line[0] == '#' && my_strcmp(line, "#layer\n")) {
            checking = false;
        }
        if (line[0] != '#' && checking) {
            if (!my_strcmp(line, "0\n")) {
                //printf("oh bof\n");
                push_back(&layers[i], "sprite", NULL, SPRITE);
                if (x + 1 == map->size.x) {
                    x = 0;
                    y++;
                } else
                    x++;
                continue;
            }
            token = strtok(line, " ");
            int tileset = my_getnbr(token);
            token = strtok(NULL, " ");
            float img_x = my_getnbr(token);
            token = strtok(NULL, " ");
            float img_y = my_getnbr(token);
            printf("sprite en %d %d\n", x, y);
            sprite_t *sprite = create_sprite(x * 16, y * 16, map->tilesets[tileset], (sfIntRect){img_x, img_y, 16, 16});
            push_back(&layers[i], "sprite", sprite, SPRITE);
            if (x + 1 == map->size.x) {
                x = 0;
                y++;
            } else
                x++;
        }
    }
    if (line)
        free(line);
    close(fp);
    layers[nb_layer] = NULL;
    return layers;
}

char **get_tilesets(char *path)
{
    int nb_tilesets = my_getnbr(get_value(path, "#nb_tilesets\n"));
    char **tilesets = malloc(sizeof(char *) * (nb_tilesets + 1));
    int i = 0;
    bool checking = false;
    FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;

    fp = fopen(path, "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);
    while ((read = getline(&line, &len, fp)) != -1) {
        if (line[0] == '#' && checking)
            break;
        if (!my_strcmp(line, "#tilesets\n"))
            checking = true;
        if (line[0] != '#' && checking) {
            tilesets[i] = malloc(my_strlen(line));
            line[my_strlen(line) - 1] = '\0';
            my_strcpy(tilesets[i], line);
            i++;
        }
    }
    if (line)
        free(line);
    close(fp);
    tilesets[nb_tilesets] = NULL;
    return tilesets;
}

map_t *map_init(char *path)
{
    printf("%s\n", path);
    map_t *map = malloc(sizeof(map_t));
    int width = my_getnbr(get_value(path, "#width\n"));
    int height = my_getnbr(get_value(path, "#height\n"));

    map->size = (sfVector2f){width, height};
    map->tilesets = get_tilesets(path);
    map->layers = get_layers(path, map);
    return map;
}