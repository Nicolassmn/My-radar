/*
** EPITECH PROJECT, 2023
** epnf
** File description:
** frn
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int alphanum(char c)
{
    if (c >= '0' && c <= '9')
        return 1;
    if (c >= 'A' && c <= 'Z')
        return 1;
    if (c >= 'a' && c <= 'z')
        return 1;
    if (c == '.')
        return 2;
    return 0;
}

static int size(char const *str)
{
    int i = 0;
    int size = 0;

    while (str[i] != '\0') {
        if ((alphanum(str[i]) == 1) && (alphanum(str[i + 1]) == 0))
            size += 1;
        i++;
    }
    return size;
}

static int my_strlen(char const *str, int k)
{
    int i = 0;

    while (str[k] != '\0' && ((alphanum(str[k]) == 1) || str[k] == '.')) {
        k++;
        i++;
    }
    return i;
}

char **my_str_to_word_array(char const *str)
{
    int j = 0;
    int size_c = 0;
    char **tab = malloc(sizeof(char *) * (size(str) + 1));

    for (int k = 0; str[k] != '\0' && size_c < (size(str)); k++) {
        if (alphanum(str[k]) == 1) {
        tab[size_c] = malloc(sizeof(char) * (my_strlen(str, k) + 1));
        } else
            continue;
        for (; (alphanum(str[k]) == 1 ||
            str[k] == '.') && str[k] != '\0'; j++) {
            tab[size_c][j] = str[k];
            k++;
        }
        tab[size_c][j] = '\0';
        size_c = size_c + 1;
        j = 0;
    }
    tab[size_c] = NULL;
    return tab;
}
