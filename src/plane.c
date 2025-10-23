/*
** EPITECH PROJECT, 2023
** myradar
** File description:
** plane
*/

#include "my.h"

void hitbox(plane_t *plane, game_t *game)
{
    float velocity = sqrt(VELOCITY.x * VELOCITY.x + VELOCITY.y * VELOCITY.y);
    float unit_vx = VELOCITY.x / velocity;
    float unit_vy = VELOCITY.y / velocity;
    float angle = atan2(unit_vy, unit_vx);

    angle = angle * 180 / PI;
    sfRectangleShape_setSize(plane->hitbox, (sfVector2f){20, 20});
    sfRectangleShape_setFillColor(plane->hitbox,
        sfColor_fromRGBA(255, 255, 255, 0));
    sfRectangleShape_setOutlineColor(plane->hitbox, sfRed);
    sfRectangleShape_setOutlineThickness(plane->hitbox, 3);
    sfRectangleShape_setOrigin(plane->hitbox, (sfVector2f){10, 10});
    sfRectangleShape_setRotation(plane->hitbox, angle);
    sfRectangleShape_setPosition(plane->hitbox,
        (sfVector2f){plane->x - 3, plane->y + 5});
    if (plane->delay <= game->option_id.timer && plane->activate == true)
        if (game->key.hitbox == 1)
            sfRenderWindow_drawRectangleShape(WINDOW, plane->hitbox, NULL);
}

void orientation(plane_t *plane)
{
    float velocity = sqrt(VELOCITY.x * VELOCITY.x + VELOCITY.y * VELOCITY.y);
    float unit_vx = VELOCITY.x / velocity;
    float unit_vy = VELOCITY.y / velocity;
    float angle = atan2(unit_vy, unit_vx);

    angle = angle * 180 / PI;
    plane->sprite.origin.x = 250;
    plane->sprite.origin.y = 250;
    sfSprite_setOrigin(plane->sprite.sprite, plane->sprite.origin);
    sfSprite_setRotation(plane->sprite.sprite, angle);
}

void determinat_speed(plane_t *plane)
{
    float spe_x = (ABS(END_X - START_X) / SPEED);
    float spe_y = (ABS(END_Y - START_Y) / SPEED);
    int sig_x = (END_X > CO_X ? 1 : -1);
    int sig_y = (END_Y > CO_Y ? 1 : -1);

    if (spe_x > spe_y) {
        VELOCITY.x = SPEED * sig_x;
        VELOCITY.y = ((ABS(END_Y - START_Y) / spe_x) * sig_y);
    } else if (spe_y > spe_x) {
        VELOCITY.x = (ABS(END_X - START_X) / spe_y) * sig_x;
        VELOCITY.y = SPEED * sig_y;
    } else {
        VELOCITY.x = SPEED * sig_x;
        VELOCITY.y = SPEED * sig_y;
    }
}

void moving_plane(plane_t *plane)
{
    if (CO_X >= 1920 || CO_Y >= 1080)
        plane->activate = false;
    CO_X += VELOCITY.x;
    CO_Y += VELOCITY.y;
    if ((END_X - 3 <= CO_X && CO_X <= END_X + 3)
    && (END_Y - 3 <= CO_Y && CO_Y <= END_Y + 3))
        plane->activate = false;
    sfSprite_move(plane->sprite.sprite, VELOCITY);
}
