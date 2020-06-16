/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** init and update particles booost attack
*/

#include <unistd.h>
#include <time.h>
#include "../../include/game.h"
#include "../../include/prototype.h"

#define SIZE 1000
#define BUFFER_SIZE (SIZE * SIZE * 4)
#define R 0
#define G 1
#define B 2
#define A 3

int init_particles(gui_t *game)
{
    game->buffer = malloc(sizeof(sfUint8 *) * (WIN_HEIGHT * WIN_WIDTH * 4));
    if (!game->buffer)
        return (0);
    (void)game->buffer;
    srand(0);
    for (int i = 0; i < 100; ++i)
        update_particles(game);
    return (1);
}

void update_particles(gui_t *game)
{
    for (int j = 0; j < 10; ++j)
        set(&game->buffer[BUFFER_SIZE / 2 - rand() % 150 * 4], 0, 0, 255);
    for (int j = 0; j < 10; ++j)
        set(&game->buffer[BUFFER_SIZE / 2 - rand() % 150 * 4], 255, 0, 0);
    for (size_t i = 0; i < BUFFER_SIZE - SIZE * 4; i += 4) {
        if (check(&game->buffer[i], 0, 0, 255))
            les_braiz(game->buffer, i);
        else if (check(&game->buffer[i], 255, 0, 0))
            les_braiz(game->buffer, i);
    }
}