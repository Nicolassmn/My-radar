/*
** EPITECH PROJECT, 2023
** myradar
** File description:
** myradar
*/

#include "my.h"

static void gestion_open_fd(char *file, int argc)
{
    if (argc != 2)
        exit(84);
    if (my_strcmp(file, "-h") == 0) {
        description("description.txt");
        exit(0);
    }
}

int main(int argc, char **argv)
{
    FILE *fd = fopen(argv[1], "r");
    game_t *game = malloc(sizeof(game_t));

    gestion_open_fd(argv[1], argc);
    if (game == NULL || fd == NULL)
        exit(84);
    PLANE = malloc(sizeof(plane_t));
    TOWER = malloc(sizeof(tower_t));
    if (PLANE == NULL || TOWER == NULL)
        exit(84);
    PLANE = NULL;
    TOWER = NULL;
    game->nb_plane = 0;
    parting(game, fd);
    aircraft(game);
    free(PLANE);
    free(TOWER);
    fclose(fd);
    return 0;
}
