/*
** EPITECH PROJECT, 2023
** myradar
** File description:
** clear_sprite
*/

#include "my.h"

static void clear_tower(game_t *game)
{
    tower_t *tmp_tower = game->tower;
    plane_t *tmp_plane = game->plane;

    while (tmp_tower) {
        sfSprite_destroy(tmp_tower->sprite.sprite);
        tmp_tower = tmp_tower->next;
    }
    while (tmp_plane) {
        sfSprite_destroy(tmp_plane->sprite.sprite);
        tmp_plane = tmp_plane->next;
    }
}

void clear_all(game_t *game)
{
    sfRenderWindow_destroy(WINDOW);
    sfMusic_destroy(game->set->music);
    sfClock_destroy(game->option_id.clock);
    sfText_destroy(game->text.t_fps);
    sfText_destroy(game->text.s_fps);
    sfText_destroy(game->text.t_time);
    sfText_destroy(game->text.s_time);
    sfFont_destroy(game->text.font);
    clear_tower(game);
}

static int end_game(game_t *game)
{
    plane_t *plane = game->plane;
    int i = 0;

    while (plane) {
        if (plane->activate == false)
            i++;
        plane = plane->next;
    }
    if (game->nb_plane == i) {
        sfSleep(sfSeconds(1));
        clear_all(game);
        exit(0);
    }
    return i;
}

static void display(game_t *game)
{
    sfRenderWindow_drawText(WINDOW, game->text.s_fps, NULL);
    sfRenderWindow_drawText(WINDOW, game->text.t_fps, NULL);
    sfRenderWindow_drawText(WINDOW, game->text.s_time, NULL);
    sfRenderWindow_drawText(WINDOW, game->text.t_time, NULL);
    sfRenderWindow_drawText(WINDOW, game->text.s_plane, NULL);
    sfRenderWindow_drawText(WINDOW, game->text.t_plane, NULL);
}

void display_text(game_t *game)
{
    char *str;
    char *str2;
    char *str5;
    char *str3 = "FPS :";
    char *str4 = "Time :";
    char *str6 = "Missing plane";

    game->option_id.missing = end_game(game);
    str = my_put_nbr(game->option_id.timer);
    str2 = my_put_nbr(game->option_id.fps);
    str5 = my_put_nbr(game->option_id.missing);
    sfText_setString(game->text.t_time, str);
    sfText_setString(game->text.t_fps, str2);
    sfText_setString(game->text.s_fps, str3);
    sfText_setString(game->text.s_time, str4);
    sfText_setString(game->text.t_plane, str5);
    sfText_setString(game->text.s_plane, str6);
    if (game->key.iud == 1)
        display(game);
}
