/*
** EPITECH PROJECT, 2023
** header
** File description:
** lol
*/

#include "my.h"


int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    while (s1[i] == s2[i] && s1[i] != '\0') {
        i++;
    }
    return s1[i] - s2[i];
}

bool my_str_isnum(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] != '.' && (str[i] < 48 || str[i] > 57))
            return false;
        i++;
    }
    return true;
}

int my_strlen(char *str)
{
    int i = 0;

    while (str[i])
        i++;
    return i;
}
