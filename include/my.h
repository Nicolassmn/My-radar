/*
** EPITECH PROJECT, 2023
** header
** File description:
** lol
*/

#pragma once

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/System/Clock.h>
#include <stdio.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <stdarg.h>
#include <time.h>
#include <ncurses.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stddef.h>
#include <signal.h>
#include <math.h>
#include "mystruct.h"

#define SFCF sfTexture_createFromFile
#define SFWC sfRenderWindow_create
#define SFPOLL sfRenderWindow_pollEvent
#define SMCF sfMusic_createFromFile
#define STAS sfTime_asSeconds
#define MODE game->settings.mode
#define WINDOW game->settings.window
#define EVENT game->settings.event
#define TOWER game->tower
#define PLANE game->plane
#define START_X plane->start_x
#define START_Y plane->start_y
#define END_X plane->arrival_x
#define END_Y plane->arrival_y
#define BACKGROUND game->set->background
#define SET game->set
#define SPEED plane->speed
#define CO_X plane->x
#define CO_Y plane->y
#define VELOCITY plane->velocity
#define ABS(n) (((n) < 0) ? -(n) : (n))
#define PI 3.14
#define ELAP game->option_id.elapsedTime
#define ENTITIES game->key.enties

void aircraft(game_t *game);
int description(char *filename);
int my_strcmp(char const *s1, char const *s2);
int my_strlen(char *str);
bool my_str_isnum(char const *str);
void parting(game_t *game, FILE *fd);
char **my_str_to_word_array(char const *str);
void load_tower(game_t *game);
void load_plane(game_t *game);
void init_window(game_t *game);
void load_aircraft(game_t *game);
void set_sprite(sfSprite *sprite, sfTexture *texture,
    sfVector2f scale, sfVector2f pos);
double str_to_double(const char *str);
void clear_all(game_t *game);
void moving_plane(plane_t *plane);
char *my_put_nbr(unsigned int nb);
void colision(game_t *game);
void orientation(plane_t *plane);
char *my_strdup(char const *src);
int my_atoi(char *str);
void hitbox(plane_t *plane, game_t *game);
void determinat_speed(plane_t *plane);
void display_text(game_t *game);
void gestion_poll_event(game_t *game);
