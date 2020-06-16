/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** end scene
*/

#include "../../include/game.h"
#include "../../include/macro.h"
#include "../../include/prototype.h"

int e_event(gui_t *game)
{
    sfEvent e;
    static int i = 0;
    if (i == 0 && game->info->sound == TRUE) {
        music_end(game);
        i = 1;
    }
    while (sfRenderWindow_pollEvent(game->window, &e)) {
        if (e.type == sfEvtClosed) {
            sfRenderWindow_close(game->window);
        }
        if (e.type == sfEvtMouseButtonPressed) {
            write_in_save(game);
            game->info->scene = MENU;
            sfMusic_stop(game->music[VIVAALGERIE]);
            i = 0;
        }
    }
    return (1);
}

int e_display(gui_t *game)
{
    displayer(game->window, game->object[BG_END]);
    displayer(game->window, game->object[BAND_END_TOP]);
    displayer(game->window, game->object[BAND_END_BOT]);
    return (1);
}

int e_update(gui_t *game)
{
    static int j = 0;
    end_black_bar(game);
    if (j == 90) {
        move_rect(game->object[BG_END]);
        j = 0;
    }
    j++;
    sfSprite_setPosition(game->object[BAND_END_TOP]->sprite,
    game->object[BAND_END_TOP]->position);
    sfSprite_setPosition(game->object[BAND_END_BOT]->sprite,
    game->object[BAND_END_BOT]->position);
    sfSprite_setTextureRect(game->object[BG_END]->sprite,
    game->object[BG_END]->rect);
    return (1);
}

int loop_end2(gui_t *game)
{
    double elapsed2 = 0;
    elapsed2 = sfTime_asMilliseconds(sfClock_getElapsedTime(game->dispTimer));
    if (elapsed2 >= (1.0 / 30.0) * 1000.0) {
        sfRenderWindow_clear(game->window, sfBlack);
        sfClock_restart(game->dispTimer);
        if (!e_display(game))
            return (0);
        sfRenderWindow_display(game->window);
    }
    return (1);
}

int loop_end(gui_t *game)
{
    double elapsed1 = 0;

    sfRenderWindow_setMouseCursorVisible(game->window, sfTrue);
    sfRenderWindow_setView(game->window, game->info->view);
    if (!e_event(game))
        return (0);
    elapsed1 = sfTime_asMicroseconds(sfClock_getElapsedTime(game->updateTimer))
                    + game->info->updateRest;
    sfClock_restart(game->updateTimer);
    while (elapsed1 >= (1.0 / 60.0) * 100000.0) {
        if (!e_update(game))
            return (0);
        elapsed1 -= (1.0 / 60.0) * 100000.0;
    }
    game->info->updateRest = elapsed1;
    if (!loop_end2(game)) {
        return (0);
    }
    return (1);
}