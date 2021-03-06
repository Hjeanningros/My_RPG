/*
** EPITECH PROJECT, 2018
** sceneManager.c
** File description:
** sceneManager.c for JAM
*/

#include "../../include/game.h"
#include "../../include/macro.h"
#include "../../include/scene.h"

int loop_global(gui_t *game)
{
    game->window =
    sfRenderWindow_create((sfVideoMode){WIN_WIDTH, WIN_HEIGHT, 64},
    "Skarim", sfClose, NULL);
    while (sfRenderWindow_isOpen(game->window)) {
        if (!SCENE[game->info->scene].loop_scene(game))
            return (0);
    }
    return (1);
}