/*
** EPITECH PROJECT, 2020
** RPG
** File description:
** save
*/

#include "../../include/game.h"
#include "../../include/macro.h"
#include "../../include/prototype.h"

int save_event(gui_t *game)
{
    sfEvent e;

    while (sfRenderWindow_pollEvent(game->window, &e)) {
        if (e.type == sfEvtClosed)
            sfRenderWindow_close(game->window);
        if (e.type == sfEvtMouseButtonPressed) {
            game->info->mouse->click = TRUE;
            b_save1(game, e.mouseButton);
            b_save2(game, e.mouseButton);
            b_save3(game, e.mouseButton);
        } else {
            game->info->mouse->click = FALSE;
        }
    }
    return (1);
}

int save_display(gui_t *game)
{
    for (int i = PARA_1_CP; i <= PARA_5; i++) {
        displayer(game->window, game->object[i]);
    }
    for (int i = BG_SAVE; i <= SAVE3; i++) {
        displayer(game->window, game->object[i]);
    }
    return (1);
}

int save_update(gui_t *game)
{
    for (int i = BG_SAVE; i <= SAVE3; i++) {
        sfSprite_setTextureRect(game->object[i]->sprite,
        game->object[i]->rect);
    }
    move_parallax(game);
    for (int i = SAVE1; i <= SAVE3; i++) {
        b_mouse(game, game->object[i]);
    }
    return (1);
}

int loop_save2(gui_t *game)
{
    double elapsed2 = 0;
    elapsed2 = sfTime_asMilliseconds(sfClock_getElapsedTime(game->dispTimer));
    if (elapsed2 >= (1.0 / 30.0) * 1000.0) {
        sfRenderWindow_clear(game->window, sfBlack);
        sfClock_restart(game->dispTimer);
        if (!save_display(game))
            return (0);
        sfRenderWindow_display(game->window);
    }
    return (1);
}

int loop_save(gui_t *game)
{
    double elapsed1 = 0;

    sfRenderWindow_setMouseCursorVisible(game->window, sfTrue);
    sfRenderWindow_setView(game->window, game->info->view);
    if (!save_event(game))
        return (0);
    elapsed1 = sfTime_asMicroseconds(sfClock_getElapsedTime(game->updateTimer))
                    + game->info->updateRest;
    sfClock_restart(game->updateTimer);
    while (elapsed1 >= (1.0 / 60.0) * 100000.0) {
        if (!save_update(game))
            return (0);
        elapsed1 -= (1.0 / 60.0) * 100000.0;
    }
    game->info->updateRest = elapsed1;
    if (!loop_save2(game)) {
        return (0);
    }
    return (1);
}