/*
** EPITECH PROJECT, 2024
** myradar
** File description:
** poll_event
*/

#include "my.h"

void gestion_poll_event(game_t *game)
{
    while (SFPOLL(WINDOW, &EVENT)) {
        if (EVENT.type == sfEvtClosed)
            sfRenderWindow_close(WINDOW);
        if (EVENT.type == sfEvtKeyPressed && EVENT.key.code == sfKeyQ)
            sfRenderWindow_close(WINDOW);
        if (EVENT.type == sfEvtKeyPressed && EVENT.key.code == sfKeyS) {
            game->key.hitbox *= -1;
            game->key.radian *= -1;
        }
        if (EVENT.type == sfEvtKeyPressed && EVENT.key.code == sfKeyI)
            game->key.iud *= -1;
        if (EVENT.type == sfEvtKeyPressed && EVENT.key.code == sfKeyL)
            game->key.enties *= -1;
        if (EVENT.type == sfEvtKeyPressed && EVENT.key.code == sfKeySpace)
            game->key.start *= -1;
    }
}
