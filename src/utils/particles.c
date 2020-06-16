/*
** EPITECH PROJECT, 2020
** RPG
** File description:
** particles function
*/

#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "../../include/game.h"
#include "../../include/prototype.h"

#define SIZE 1600
#define BUFFER_SIZE (SIZE * SIZE * 4)
#define R 0
#define G 1
#define B 2
#define A 3

void reset(sfUint8 *pixel)
{
    pixel[R] = 0;
    pixel[G] = 0;
    pixel[B] = 0;
    pixel[A] = 0;
}

void set(sfUint8 *pixel, sfUint8 red, sfUint8 green, sfUint8 blue)
{
    pixel[R] = red;
    pixel[G] = green;
    pixel[B] = blue;
    pixel[A] = 255;
}

void copy(sfUint8 *from, sfUint8 *to)
{
    to[R] = from[R];
    to[G] = from[G];
    to[B] = from[B];
    to[A] = from[A];
}

bool check(sfUint8 *pixel, sfUint8 red, sfUint8 green, sfUint8 blue)
{
    return (pixel[R] == red && pixel[G] == green && pixel[B] == blue);
}

void les_braiz(sfUint8 *buffer, size_t i)
{
    buffer[i + A] -= rand() % 4;
    if (i > SIZE + 1 && buffer[i + A] > 30)
        copy(&buffer[i], &buffer[i - SIZE * 4]);
    reset(&buffer[i]);
}
