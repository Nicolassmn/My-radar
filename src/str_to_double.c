/*
** EPITECH PROJECT, 2023
** myradar
** File description:
** str_to_double
*/

#include <stdio.h>
#include <stdbool.h>

static bool ch_isnum(char c, int *i)
{
    if (c < '0' || c > '9') {
        (*i)++;
        return false;
    } else
        return true;
}

static void split(double *tmp, int *decimal, int *i, const char *str)
{
    (*i)++;
    while (str[*i] != '\0') {
        if (ch_isnum(str[*i], i) == false)
            continue;
        *tmp = *tmp * 10 + (str[*i] - '0');
        *decimal *= 10;
        (*i)++;
    }
}

double str_to_double(const char *str)
{
    int decimal = 1;
    double tmp = 0;
    int i = 0;
    int sign = 1;

    if (str[i] == '-') {
        sign = -1;
        i++;
    }
    while (str[i] != '.' && str[i] != '\0') {
        if (ch_isnum(str[i], &i) == false)
            continue;
        tmp = tmp * 10 + (str[i] - '0');
        i++;
    }
    if (str[i] == '.')
        split(&tmp, &decimal, &i, str);
    return ((tmp / decimal) * sign);
}
