/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** battle scene
*/

#include "../../include/game.h"
#include "../../include/macro.h"
#include "../../include/prototype.h"

int b_event(gui_t *game)
{
    sfEvent e;

    while (sfRenderWindow_pollEvent(game->window, &e)) {
        if (e.type == sfEvtClosed) {
            sfRenderWindow_close(game->window);
        }
        if (e.type == sfEvtMouseButtonPressed && game->battle1->status
        == PLAYER_TURN) {
            game->info->mouse->click = TRUE;
            b_attack(game, e.mouseButton, game->battle1);
            b_boostattack(game, e.mouseButton, game->battle1);
            b_escape(game, e.mouseButton, game->battle1);
        } else {
            game->info->mouse->click = FALSE;
        }
    }
    return (1);
}

int b_display(gui_t *game)
{
    if (game->info->trans == TRUE)
        transition(game);
    displayer(game->window, game->object[BG_BATTLE]);
    for (int i = BUTTON_ATTACK; i <= HEAL_GREEN_ENEMIES; i++) {
        displayer(game->window, game->object[i]);
    }
    display_status(game);
    if (game->info->trans == TRUE)
        transition(game);
    return (1);
}

int b_update(gui_t *game)
{
    for (int i = BUTTON_ATTACK; i <= HEAL_GREEN_ENEMIES; i++) {
        sfSprite_setTextureRect(game->object[i]->sprite,
        game->object[i]->rect);
    }
    if (game->battle1->status == PLAYER_TURN) {
        b_mouse(game, game->object[BUTTON_ATTACK]);
        b_mouse(game, game->object[BUTTON_BOOSTATTACK]);
        b_mouse(game, game->object[BUTTON_ESCAPE]);
        update_player_turn(game);
    }
    update_different_status(game);
    return (1);

}

int loop_battle2(gui_t *game)
{
    double elapsed2 = 0;
    elapsed2 = sfTime_asMilliseconds(sfClock_getElapsedTime(game->dispTimer));
    if (elapsed2 >= (1.0 / 30.0) * 1000.0) {
        sfRenderWindow_clear(game->window, sfBlack);
        sfClock_restart(game->dispTimer);
        if (!b_display(game))
            return (0);
        sfRenderWindow_display(game->window);
    }
    return (1);
}

int loop_battle(gui_t *game)
{
    double elapsed1 = 0;

    sfRenderWindow_setMouseCursorVisible(game->window, sfTrue);
    sfRenderWindow_setView(game->window, game->info->view);
    if (!b_event(game))
        return (0);
    elapsed1 = sfTime_asMicroseconds(sfClock_getElapsedTime(game->updateTimer))
                    + game->info->updateRest;
    sfClock_restart(game->updateTimer);
    while (elapsed1 >= (1.0 / 60.0) * 100000.0) {
        if (!b_update(game))
            return (0);
        elapsed1 -= (1.0 / 60.0) * 100000.0;
    }
    game->info->updateRest = elapsed1;
    if (!loop_battle2(game)) {
        return (0);
    }
    return (1);
}