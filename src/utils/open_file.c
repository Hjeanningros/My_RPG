/*
** EPITECH PROJECT, 2020
** my defender
** File description:
** init text
*/

#include "../../include/macro.h"
#include "../../include/game.h"
#include "../../include/prototype.h"
#include <stdio.h>
#include <sys/stat.h>

char *open_file(const char *filename)
{
    int fd;
    char *buffer = NULL;
    struct stat st;

    fd = open(filename, O_RDONLY);
    stat(filename, &st);
    if (stat == 0)
        return (NULL);
    buffer = malloc(sizeof(char) * st.st_size + 1);
    read(fd, buffer, st.st_size);
    buffer[st.st_size] = '\0';
    return (buffer);
}