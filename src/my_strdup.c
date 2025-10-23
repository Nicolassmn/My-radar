/*
** EPITECH PROJECT, 2023
** rgnuoz
** File description:
** rgnuoz
*/

#include <stdlib.h>

static int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return i;
}

static char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    for (; src[i] != '\0'; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return dest;
}

char *my_strdup(char const *src)
{
    char *dest = malloc(sizeof(char) * (my_strlen(src)));

    my_strcpy(dest, src);
    return dest;
}
