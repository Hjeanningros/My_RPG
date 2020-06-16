/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** menu.c
*/

#include "../../include/game.h"
#include "../../include/macro.h"
#include "../../include/prototype.h"

void check_fight(gui_t *game)
{
    if (game->diag == PNJ_ARMOR_BEFORE || game->diag == PNJ_ARMOR_BEFORE_ENG)
        game->info->scene = BATTLE2;
    if (game->diag == FIRST_BATTLE_BEFORE || game->diag ==
    FIRST_BATTLE_BEFORE_ENG)
        game->info->scene = BATTLE1;
    if (game->diag == MINEUR || game->diag == MINEUR_ENG)
        game->info->scene = BATTLE3;
    if (game->diag == ALWAYS_BATTLE || game->diag == ALWAYS_BATTLE_ENG)
        game->info->scene = BATTLE4;
    if (game->diag == BOSS_FINAL || game->diag == BOSS_FINAL_ENG)
        game->info->scene = BATTLE5;
}

void event_mvt(gui_t *game, sfEvent e)
{
    if (e.type == sfEvtKeyPressed) {
        if (sfKeyboard_isKeyPressed(sfKeyZ))
            game->event = 1;
        if (sfKeyboard_isKeyPressed(sfKeyS))
            game->event = 2;
        if (sfKeyboard_isKeyPressed(sfKeyQ))
            game->event = 3;
        if (sfKeyboard_isKeyPressed(sfKeyD))
            game->event = 4;
        if (sfKeyboard_isKeyPressed(sfKeyE))
            game->event = 5;
    } else if (e.type == sfEvtKeyReleased) {
        game->event = 0;
    }
}

void click_to_speak(gui_t *game, sfEvent e)
{
    if (game->dialogue[game->diag][game->text[game->diag]->index] != NULL
        && game->info->mouse->click == TRUE) {
        game->text[game->diag]->index += 1;
        if (game->dialogue[game->diag][game->text[game->diag]->index] == NULL) {
            game->text[game->diag]->index = 0;
            check_fight(game);
            game->diag = -1;
        }
    }
}

void switch_scene_and_get_click(gui_t *game, sfEvent e)
{
    if (e.type == sfEvtClosed)
        sfRenderWindow_close(game->window);
    if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
        game->info->scene = PAUSE;
    }
    if (sfKeyboard_isKeyPressed(sfKeyA)) {
        game->info->scene = INVENTORY;
    }
    if (e.type == sfEvtMouseButtonPressed) {
        game->info->mouse->click = TRUE;
    } else {
        game->info->mouse->click = FALSE;
    }
}