/*
** EPITECH PROJECT, 2023
** myradar
** File description:
** colision
*/

#include "my.h"

static void success_colision(plane_t *p, plane_t *p2)
{
    p2->activate = false;
    p->activate = false;
    p2->boom = true;
    p->boom = true;
    p->rip.pos.x = p->x;
    p->rip.pos.y = p->y;
    p2->rip.pos.x = p->x - 15;
    p2->rip.pos.y = p->y - 15;
    sfSprite_setPosition(p->rip.sprite, p->rip.pos);
    sfSprite_setPosition(p2->rip.sprite, p2->rip.pos);
}

static void testing_colision(plane_t *p, game_t *game)
{
    plane_t *p2 = game->plane;
    tower_t *t = game->tower;

    while (t) {
        if ((t->x - t->radian <= p->x && p->x <= t->x + t->radian) &&
            (t->y - t->radian <= p->y && p->y <= t->y + t->radian))
            return;
        t = t->next;
    }
    while (p2) {
        if (p2->activate != false && p2 != p &&
        ((p2->x - 25 <= p->x && p->x <= p2->x + 25) &&
        (p2->y - 25 <= p->y && p->y <= p2->y + 25)))
            success_colision(p, p2);
        p2 = p2->next;
    }
}

void colision(game_t *game)
{
    plane_t *p = game->plane;

    while (p) {
        if (p->activate == false) {
            p = p->next;
            continue;
        }
        testing_colision(p, game);
        p = p->next;
    }
}
