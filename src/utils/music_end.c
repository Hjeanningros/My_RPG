/*
** EPITECH PROJECT, 2020
** RPG
** File description:
** music end
*/

#include "../../include/game.h"
#include "../../include/macro.h"
#include "../../include/prototype.h"

int music_end(gui_t *game)
{
    if (game->info->music == TRUE)
        game->info->music_bg = TRUE;
    sfMusic_pause(game->music[BG_MUSIC]);
    sfMusic_setLoop(game->music[VIVAALGERIE], true);
    sfMusic_play(game->music[VIVAALGERIE]);
}