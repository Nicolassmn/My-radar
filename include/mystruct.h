/*
** EPITECH PROJECT, 2023
** myhunter
** File description:
** mystruct
*/

#pragma once

typedef struct sprite_s {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f scale;
    sfVector2f pos;
    sfVector2f origin;
    int animation;
}sprite_t;

typedef struct text_s {
    sfText *t_fps;
    sfText *s_fps;
    sfText *t_time;
    sfText *s_time;
    sfText *t_plane;
    sfText *s_plane;
    sfFont *font;
} text_t;

typedef struct window_s {
    sfVideoMode mode;
    sfRenderWindow *window;
    sfEvent event;
} window_t;

typedef struct load_game_s {
    sprite_t background;
    sfMusic *music;
} load_game_t;

typedef struct option_id_s {
    float timer;
    float frame_counter;
    int fps;
    int missing;
    sfClock *clock;
    sfTime elapsedTime;
} option_id_t;

typedef struct timer_anim_s {
    sfClock *clock;
    sfTime elapsedTime;
    float timer;
} timer_anim_t;

typedef struct gestion_keyboard_s {
    int hitbox;
    int radian;
    int iud;
    int start;
    int enties;
} gestion_keyboard_t;

typedef struct tower_s {
    int x;
    int y;
    float radian;
    int colision;
    sprite_t sprite;
    sprite_t radar;
    float rotation;
    struct tower_s *next;
} tower_t;

typedef struct plane_s {
    float x;
    float y;
    int start_x;
    int start_y;
    float arrival_x;
    float arrival_y;
    float speed;
    float delay;
    int activate;
    int boom;
    sfRectangleShape *hitbox;
    sfVector2f velocity;
    sprite_t france;
    sprite_t sprite;
    sprite_t rip;
    struct plane_s *next;
} plane_t;

typedef struct game_s {
    window_t settings;
    load_game_t *set;
    plane_t *plane;
    tower_t *tower;
    option_id_t option_id;
    text_t text;
    gestion_keyboard_t key;
    timer_anim_t clock;
    int nb_plane;
} game_t;
