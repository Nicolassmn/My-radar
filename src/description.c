/*
** EPITECH PROJECT, 2023
** sokoban
** File description:
** description
*/

#include "my.h"


int description(char *filename)
{
    struct stat info_fd;
    char buffer[1000];
    int fd = open(filename, O_RDONLY);
    int size = read(fd, buffer, 1000);

    if (stat(filename, &info_fd) == -1)
        exit(84);
    while (size > 0) {
        write(1, buffer, my_strlen(buffer));
        size = read(fd, buffer, 1000);
    }
    write(1, "\n", 1);
    close(fd);
    return 0;
}
