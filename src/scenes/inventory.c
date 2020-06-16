/*
** EPITECH PROJECT, 2020
** RPG
** File description:
** inventory
*/

#include "../../include/game.h"
#include "../../include/macro.h"
#include "../../include/prototype.h"

int inv_event(gui_t *game)
{
    sfEvent e;

    while (sfRenderWindow_pollEvent(game->window, &e)) {
        if (e.type == sfEvtClosed)
            sfRenderWindow_close(game->window);
        if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
            game->info->scene = FOREST_MAP;
        }
        if (e.type == sfEvtMouseButtonPressed) {
            b_armor1(game, e.mouseButton);
            b_potion(game, e.mouseButton);
            b_armor2(game, e.mouseButton);
            game->info->mouse->click = TRUE;
        } else {
            game->info->mouse->click = FALSE;
        }
    }
    return (1);
}

int inv_display(gui_t *game)
{
    displayer(game->window, game->object[BG_INVENTORY]);
    displayer(game->window, game->object[PERSO_INV]);
    if (game->inventory->potion == TRUE) {
        displayer(game->window, game->object[POTION_INV]);
        sfRenderWindow_drawText(game->window, game->text[INV_NB_POPO]->text,
        NULL);
    }
    if (game->inventory->armor1 == TRUE)
        displayer(game->window, game->object[ARMOR_INV]);
    if (game->inventory->iron == TRUE) {
        displayer(game->window, game->object[IRON_INV]);
        sfRenderWindow_drawText(game->window, game->text[INV_NB_IRON]->text,
        NULL);
    }
    if (game->inventory->armor2 == TRUE)
        displayer(game->window, game->object[SARMOR_INV]);
    for (int i = INV_HP; i <= INV_HP_MAX; i++) {
        sfRenderWindow_drawText(game->window, game->text[i]->text, NULL);
    }
    return (1);
}

int inv_update(gui_t *game)
{
    update_text_inv(game);
    game->object[PERSO_INV]->rect = (sfIntRect){750 * (game->player->lvl), 0,
    750, 750};
    b_mouse(game, game->object[ARMOR_INV]);
    b_mouse(game, game->object[POTION_INV]);
    b_mouse(game, game->object[SARMOR_INV]);
    b_mouse(game, game->object[IRON_INV]);
    for (int i = PERSO_INV; i <= SARMOR_INV; i++) {
        sfSprite_setTextureRect(game->object[i]->sprite, game->object[i]->rect);
    }
    return (1);
}

int loop_inventory2(gui_t *game)
{
    double elapsed2 = 0;
    elapsed2 = sfTime_asMilliseconds(sfClock_getElapsedTime(game->dispTimer));
    if (elapsed2 >= (1.0 / 30.0) * 1000.0) {
        sfRenderWindow_clear(game->window, sfBlack);
        sfClock_restart(game->dispTimer);
        if (!inv_display(game))
            return (0);
        sfRenderWindow_display(game->window);
    }
    return (1);
}

int loop_inventory(gui_t *game)
{
    double elapsed1 = 0;

    sfRenderWindow_setMouseCursorVisible(game->window, sfTrue);
    sfRenderWindow_setView(game->window, game->info->view);
    if (!inv_event(game))
        return (0);
    elapsed1 = sfTime_asMicroseconds(sfClock_getElapsedTime(game->updateTimer))
                    + game->info->updateRest;
    sfClock_restart(game->updateTimer);
    while (elapsed1 >= (1.0 / 60.0) * 100000.0) {
        if (!inv_update(game))
            return (0);
        elapsed1 -= (1.0 / 60.0) * 100000.0;
    }
    game->info->updateRest = elapsed1;
    if (!loop_inventory2(game)) {
        return (0);
    }
    return (1);
}