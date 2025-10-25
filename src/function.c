/*
** EPITECH PROJECT, 2023
** myradar
** File description:
** function
*/

#include "my.h"

void init_window(game_t *game)
{
    game->set = malloc(sizeof(load_game_t));
    MODE.bitsPerPixel = 64;
    MODE.height = 1080;
    MODE.width = 1920;
    WINDOW = SFWC(MODE, "Aircraft", sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(WINDOW, 120);
    game->option_id.clock = sfClock_create();
    game->option_id.fps = 0;
    game->option_id.frame_counter = 0.000;
    game->option_id.timer = 0;
    game->option_id.missing = 0;
    game->clock.clock = sfClock_create();
    load_aircraft(game);
}

static void split_tower(tower_t *tmp_tower)
{
    tmp_tower->sprite.texture = SFCF("assets/tower.png", NULL);
    tmp_tower->sprite.sprite = sfSprite_create();
    tmp_tower->sprite.scale.x = 0.13;
    tmp_tower->sprite.scale.y = 0.13;
    tmp_tower->sprite.pos.x = tmp_tower->x;
    tmp_tower->sprite.pos.y = tmp_tower->y;
    tmp_tower->radar.texture = SFCF("assets/radar.png", NULL);
    tmp_tower->radar.sprite = sfSprite_create();
    tmp_tower->radar.scale.x = 0.53 / (100 / tmp_tower->radian);
    tmp_tower->radar.scale.y = 0.53 / (100 / tmp_tower->radian);
    tmp_tower->radar.pos.x = tmp_tower->x + 40;
    tmp_tower->radar.pos.y = tmp_tower->y + 45;
    tmp_tower->radar.origin.x = 250;
    tmp_tower->radar.origin.y = 250;
}

void load_tower(game_t *game)
{
    tower_t *tmp_tower = game->tower;

    while (tmp_tower) {
        split_tower(tmp_tower);
        set_sprite(tmp_tower->sprite.sprite, tmp_tower->sprite.texture,
            tmp_tower->sprite.scale, tmp_tower->sprite.pos);
        set_sprite(tmp_tower->radar.sprite, tmp_tower->radar.texture,
            tmp_tower->radar.scale, tmp_tower->radar.pos);
        sfSprite_setOrigin(tmp_tower->radar.sprite, tmp_tower->radar.origin);
        sfSprite_setColor(tmp_tower->radar.sprite,
            (sfColor){255, 255, 255, 128});
        tmp_tower->rotation = 0;
        tmp_tower->colision = false;
        tmp_tower = tmp_tower->next;
    }
}

static void split_plane(plane_t *plane)
{
    plane->sprite.texture = SFCF("assets/avion.png", NULL);
    plane->sprite.sprite = sfSprite_create();
    plane->sprite.scale.x = 0.08;
    plane->sprite.scale.y = 0.08;
    plane->sprite.pos.x = START_X;
    plane->sprite.pos.y = START_Y;
    plane->x = START_X;
    plane->y = START_Y;
    plane->activate = true;
    plane->boom = false;
    plane->france.texture = SFCF("assets/france.png", NULL);
    plane->france.sprite = sfSprite_create();
    plane->france.scale.x = 0.03;
    plane->france.scale.y = 0.03;
    plane->france.pos.x = END_X + 5;
    plane->france.pos.y = END_Y - 40;
    plane->hitbox = sfRectangleShape_create();
}

void load_plane(game_t *game)
{
    plane_t *plane = game->plane;

    while (plane) {
        split_plane(plane);
        determinat_speed(plane);
        orientation(plane);
        plane->rip.texture = SFCF("assets/boom.png", NULL);
        plane->rip.sprite = sfSprite_create();
        plane->rip.scale.x = 0.1;
        plane->rip.scale.y = 0.1;
        plane->rip.pos.x = 0;
        plane->rip.pos.y = 0;
        set_sprite(plane->sprite.sprite, plane->sprite.texture,
            plane->sprite.scale, plane->sprite.pos);
        set_sprite(plane->rip.sprite, plane->rip.texture,
            plane->rip.scale, plane->rip.pos);
        set_sprite(plane->france.sprite, plane->france.texture,
            plane->france.scale, plane->france.pos);
        plane = plane->next;
    }
}

static void ini_text(game_t *game)
{
    sfText_setPosition(game->text.t_fps, (sfVector2f){1680, 35});
    sfText_setPosition(game->text.s_fps, (sfVector2f){1610, 35});
    sfText_setPosition(game->text.t_time, (sfVector2f){1855, 35});
    sfText_setPosition(game->text.s_time, (sfVector2f){1755, 35});
    sfText_setPosition(game->text.t_plane, (sfVector2f){1550, 35});
    sfText_setPosition(game->text.s_plane, (sfVector2f){1300, 35});
    sfText_setFillColor(game->text.t_fps, sfBlack);
    sfText_setFillColor(game->text.t_time, sfBlack);
    sfText_setFillColor(game->text.s_fps, sfBlack);
    sfText_setFillColor(game->text.s_time, sfBlack);
    sfText_setFillColor(game->text.s_plane, sfBlack);
    sfText_setFillColor(game->text.t_plane, sfBlack);
    sfText_scale(game->text.t_fps, (sfVector2f){1.2, 1.2});
    sfText_scale(game->text.s_fps, (sfVector2f){1.2, 1.2});
    sfText_scale(game->text.t_time, (sfVector2f){1.2, 1.2});
    sfText_scale(game->text.s_time, (sfVector2f){1.2, 1.2});
    sfText_scale(game->text.s_plane, (sfVector2f){1.2, 1.2});
    sfText_scale(game->text.t_plane, (sfVector2f){1.2, 1.2});
}

static void load_text(game_t *game)
{
    game->text.font = sfFont_createFromFile("Charcoal.ttf");
    game->text.s_fps = sfText_create();
    game->text.t_fps = sfText_create();
    game->text.s_time = sfText_create();
    game->text.t_time = sfText_create();
    game->text.s_plane = sfText_create();
    game->text.t_plane = sfText_create();
    sfText_setFont(game->text.s_fps, game->text.font);
    sfText_setFont(game->text.s_time, game->text.font);
    sfText_setFont(game->text.t_fps, game->text.font);
    sfText_setFont(game->text.t_time, game->text.font);
    sfText_setFont(game->text.s_plane, game->text.font);
    sfText_setFont(game->text.t_plane, game->text.font);
    ini_text(game);
}

void load_aircraft(game_t *game)
{
    load_tower(game);
    load_plane(game);
    load_text(game);
    game->key.hitbox = 1;
    game->key.radian = 1;
    game->key.iud = 1;
    game->key.start = 1;
    game->key.enties = 1;
    BACKGROUND.texture = SFCF("assets/background.jpg", NULL);
    BACKGROUND.sprite = sfSprite_create();
    BACKGROUND.scale.x = 1.076;
    BACKGROUND.scale.y = 1;
    SET->music = SMCF("music/Fluxxwave-_Lay-With-Me_.ogg");
    sfMusic_play(SET->music);
    sfMusic_setLoop(SET->music, true);
    sfSprite_setTexture(BACKGROUND.sprite, BACKGROUND.texture, sfTrue);
    sfSprite_setScale(BACKGROUND.sprite, BACKGROUND.scale);
}

void set_sprite(sfSprite *sprite, sfTexture *texture,
    sfVector2f scale, sfVector2f pos)
{
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setScale(sprite, scale);
    sfSprite_setPosition(sprite, pos);
}
