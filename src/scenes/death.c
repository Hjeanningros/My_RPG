/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** battle scene
*/

#include "../../include/game.h"
#include "../../include/macro.h"
#include "../../include/prototype.h"

int d_event(gui_t *game)
{
    sfEvent e; static int i = 0;
    if (i == 0 && game->info->sound == TRUE) {
        if (game->info->music == TRUE)
            game->info->music_bg = TRUE;
        sfMusic_pause(game->music[BG_MUSIC]);
        sfMusic_setLoop(game->music[DEATH_MUSIC], true);
        sfMusic_play(game->music[DEATH_MUSIC]);
        i = 1;
    }
    while (sfRenderWindow_pollEvent(game->window, &e)) {
        if (e.type == sfEvtClosed) {
            sfRenderWindow_close(game->window);
        }
        if (e.type == sfEvtMouseButtonPressed) {
            game->info->scene = FOREST_MAP;
            sfMusic_stop(game->music[DEATH_MUSIC]);
            i = 0;
        }
    }
    return (1);
}

int d_display(gui_t *game)
{
    if (game->info->trans == TRUE)
        transition(game);
    displayer(game->window, game->object[BG_DEATH]);
    if (game->info->trans == TRUE)
        transition(game);
    return (1);
}

int d_update(gui_t *game)
{
    return (1);
}

int loop_death2(gui_t *game)
{
    double elapsed2 = 0;
    elapsed2 = sfTime_asMilliseconds(sfClock_getElapsedTime(game->dispTimer));
    if (elapsed2 >= (1.0 / 30.0) * 1000.0) {
        sfRenderWindow_clear(game->window, sfBlack);
        sfClock_restart(game->dispTimer);
        if (!d_display(game))
            return (0);
        sfRenderWindow_display(game->window);
    }
    return (1);
}

int loop_death(gui_t *game)
{
    double elapsed1 = 0;

    sfRenderWindow_setMouseCursorVisible(game->window, sfTrue);
    sfRenderWindow_setView(game->window, game->info->view);
    if (!d_event(game))
        return (0);
    elapsed1 = sfTime_asMicroseconds(sfClock_getElapsedTime(game->updateTimer))
                    + game->info->updateRest;
    sfClock_restart(game->updateTimer);
    while (elapsed1 >= (1.0 / 60.0) * 100000.0) {
        if (!d_update(game))
            return (0);
        elapsed1 -= (1.0 / 60.0) * 100000.0;
    }
    game->info->updateRest = elapsed1;
    if (!loop_death2(game)) {
        return (0);
    }
    return (1);
}