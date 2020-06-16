/*
** EPITECH PROJECT, 2020
** RPG
** File description:
** key
*/

#include "../../include/game.h"
#include "../../include/macro.h"
#include "../../include/prototype.h"

int k_event(gui_t *game)
{
    sfEvent e;

    while (sfRenderWindow_pollEvent(game->window, &e)) {
        if (e.type == sfEvtClosed)
            sfRenderWindow_close(game->window);
        if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
            game->info->scene = game->info->last_scene;
        }
        if (e.type == sfEvtMouseButtonPressed) {
            b_back(game, game->object[B_BACK], e.mouseButton);
            game->info->mouse->click = TRUE;
        } else {
            game->info->mouse->click = FALSE;
        }
    }
    return (1);
}

int k_display(gui_t *game)
{
    displayer(game->window, game->object[KEYBINDING]);
    displayer(game->window, game->object[B_BACK]);
    return (1);
}

int k_update(gui_t *game)
{
    button_back_rules(game, game->object[B_BACK]);
    return (1);
}

int loop_keys2(gui_t *game)
{
    double elapsed2 = 0;
    elapsed2 = sfTime_asMilliseconds(sfClock_getElapsedTime(game->dispTimer));
    if (elapsed2 >= (1.0 / 30.0) * 1000.0) {
        sfRenderWindow_clear(game->window, sfBlack);
        sfClock_restart(game->dispTimer);
        if (!k_display(game))
            return (0);
        sfRenderWindow_display(game->window);
    }
    return (1);
}

int loop_keys(gui_t *game)
{
    double elapsed1 = 0;

    sfRenderWindow_setMouseCursorVisible(game->window, sfTrue);
    sfRenderWindow_setView(game->window, game->info->view);
    if (!k_event(game))
        return (0);
    elapsed1 = sfTime_asMicroseconds(sfClock_getElapsedTime(game->updateTimer))
                    + game->info->updateRest;
    sfClock_restart(game->updateTimer);
    while (elapsed1 >= (1.0 / 60.0) * 100000.0) {
        if (!k_update(game))
            return (0);
        elapsed1 -= (1.0 / 60.0) * 100000.0;
    }
    game->info->updateRest = elapsed1;
    if (!loop_keys2(game)) {
        return (0);
    }
    return (1);
}