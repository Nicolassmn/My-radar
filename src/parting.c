/*
** EPITECH PROJECT, 2023
** myradar
** File description:
** parting
*/

#include "my.h"

static int check(char **tmp)
{
    if (!tmp)
        return 84;
    if (my_strcmp(tmp[0], "T") != 0 && my_strcmp(tmp[0], "A") != 0)
        return 84;
    for (int j = 1; tmp[j]; j++)
        if (my_str_isnum(tmp[j]) == false)
            return 84;
    return 0;
}

static void tower(char **tmp, game_t *game)
{
    tower_t *new_node;
    tower_t *current = game->tower;

    new_node = malloc(sizeof(tower_t));
    if (new_node == NULL)
        exit(84);
    new_node->x = my_atoi(tmp[1]);
    new_node->y = my_atoi(tmp[2]);
    new_node->radian = str_to_double(tmp[3]);
    new_node->next = NULL;
    if (!game->tower)
        game->tower = new_node;
    else {
        while (current->next)
            current = current->next;
        current->next = new_node;
    }
}

static void plane(char **tmp, game_t *game)
{
    plane_t *new_node;
    plane_t *current = game->plane;

    new_node = malloc(sizeof(plane_t));
    new_node->start_x = my_atoi(tmp[1]);
    new_node->start_y = my_atoi(tmp[2]);
    new_node->arrival_x = my_atoi(tmp[3]);
    new_node->arrival_y = my_atoi(tmp[4]);
    new_node->speed = str_to_double(tmp[5]);
    new_node->delay = str_to_double(tmp[6]);
    new_node->next = NULL;
    if (!game->plane) {
        game->plane = new_node;
    } else {
        while (current->next)
            current = current->next;
        current->next = new_node;
    }
}

static void gestion(char **tmp, game_t *game)
{
    if (my_strcmp(tmp[0], "T") == 0)
        tower(tmp, game);
    else if (my_strcmp(tmp[0], "A") == 0) {
        plane(tmp, game);
        game->nb_plane++;
    }
}

static void free_all(char **tab, char **tmp, int a)
{
    if (a == 5) {
        for (int k = 0; tmp[k]; k++)
            free(tmp[k]);
        free(tmp);
    } else {
        for (int k = 0; tab[k]; k++)
            free(tab[k]);
        free(tab);
    }
}

int count_lines(FILE *fd)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read = getline(&line, &len, fd);
    int size = 0;

    while (read != -1) {
        size++;
        read = getline(&line, &len, fd);
    }
    rewind(fd);
    return size;
}

void parting(game_t *game, FILE *fd)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    int tab_size = 0;
    char **tab = malloc(sizeof(char *) * (count_lines(fd) + 1));
    char **tmp;

    while ((read = getline(&line, &len, fd)) != -1) {
        tab[tab_size] = my_strdup(line);
        tab_size++;
    }
    tab[tab_size] = NULL;
    for (int i = 0; tab[i]; i++) {
        tmp = my_str_to_word_array(tab[i]);
        if (check(tmp) != 0);
        else
            gestion(tmp, game);
        free_all(tab, tmp, 5);
    }
    free_all(tab, tmp, 0);
}
