/*
** EPITECH PROJECT, 2023
** myradar
** File description:
** aircraft
*/

#include "my.h"

static void animation(game_t *game)
{
    plane_t *plane = game->plane;

    while (plane) {
        if (plane->delay <= game->option_id.timer && plane->activate == true)
            moving_plane(plane);
        plane = plane->next;
    }
}

void display_tower(game_t *game)
{
    tower_t *tower = game->tower;

    while (tower) {
        if (sfTime_asMilliseconds(ELAP) > 50)
            tower->rotation += 2;
        sfSprite_setRotation(tower->radar.sprite, tower->rotation);
        if (ENTITIES == 1)
            sfRenderWindow_drawSprite(WINDOW, tower->sprite.sprite, NULL);
        if (game->key.radian == 1)
            sfRenderWindow_drawSprite(WINDOW, tower->radar.sprite, NULL);
        tower = tower->next;
    }
}

static void display_sprite(game_t *game)
{
    plane_t *plane = game->plane;

    sfRenderWindow_drawSprite(WINDOW, game->set->background.sprite, NULL);
    while (plane) {
        if (ENTITIES == 1 && plane->delay <= game->option_id.timer
            && plane->activate == true) {
            sfRenderWindow_drawSprite(WINDOW, plane->sprite.sprite, NULL);
        }
        hitbox(plane, game);
        if (plane->activate == false && plane->boom == false && ENTITIES == 1)
            sfRenderWindow_drawSprite(WINDOW, plane->france.sprite, NULL);
        if (plane->boom == true && ENTITIES == 1)
            sfRenderWindow_drawSprite(WINDOW, plane->rip.sprite, NULL);
        plane = plane->next;
    }
    display_tower(game);
}

static void clock_time(game_t *game)
{
    ELAP =
        sfClock_getElapsedTime(game->option_id.clock);
    game->option_id.frame_counter++;
    if (sfTime_asMilliseconds(ELAP) > 1000) {
        game->option_id.fps = game->option_id.frame_counter;
        game->option_id.frame_counter = 0;
        sfClock_restart(game->option_id.clock);
        game->option_id.timer += 1;
    }
    sfSleep(sfMilliseconds(8.3));
}

void clock_animation(game_t *game)
{
    ELAP =
        sfClock_getElapsedTime(game->option_id.clock);
    sfSleep(sfMilliseconds(8.3));
}

void aircraft(game_t *game)
{
    int a = 0;

    init_window(game);
    while (sfRenderWindow_isOpen(WINDOW)) {
        gestion_poll_event(game);
        if (sfTime_asSeconds(ELAP) >= 1 && a == 0) {
            a = 1;
            sfClock_restart(game->option_id.clock);
        }
        clock_animation(game);
        if (game->key.start == 1 && a == 1) {
            clock_time(game);
            animation(game);
            sfRenderWindow_clear(WINDOW, sfBlack);
            colision(game);
            display_sprite(game);
            display_text(game);
            sfRenderWindow_display(WINDOW);
        }
    }
}
