/*
** EPITECH PROJECT, 2020
** RPG
** File description:
** init inventory
*/

#include "../../include/macro.h"
#include "../../include/game.h"
#include <stdio.h>
#include <stdlib.h>

void set_text(gui_t *game)
{
    for (int i = INV_HP; i <= INV_NB_IRON; i++) {
        game->text[i]->color = (sfColor){77, 77, 77, 255};
        game->text[i]->character_size = 100;
    }
    game->text[INV_HP_MAX]->character_size = 70;
    game->text[INV_HP]->character_size = 70;
    game->text[INV_SLASH]->character_size = 70;
    game->text[INV_NB_POPO]->character_size = 50;
    game->text[INV_NB_IRON]->character_size = 50;
    game->text[INV_HP]->position = (sfVector2f){755, 175};
    game->text[INV_ATTACK]->position = (sfVector2f){780, 370};
    game->text[INV_ARMOR]->position = (sfVector2f){1220, 155};
    game->text[INV_MONEY]->position = (sfVector2f){1220, 370};
    game->text[INV_SLASH]->position = (sfVector2f){910, 175};
    game->text[INV_HP_MAX]->position = (sfVector2f){930, 175};
    game->text[INV_NB_POPO]->position = (sfVector2f){290, 750};
    game->text[INV_NB_IRON]->position = (sfVector2f){730, 750};
}

int init_text_inventory(gui_t *game)
{
    set_text(game);
    for (int i = INV_HP; i <= INV_NB_IRON; i++) {
        sfText_setFont(game->text[i]->text, game->text[i]->font);
        sfText_setString(game->text[i]->text, "0");
        sfText_setCharacterSize(game->text[i]->text,
                                game->text[i]->character_size);
        sfText_setColor(game->text[i]->text, game->text[i]->color);
        sfText_setPosition(game->text[i]->text, game->text[i]->position);
    }
    return (1);
}

int init_inventory(gui_t *game)
{
    game->inventory->nb_potion = 0;
    game->inventory->armor1 = FALSE;
    game->inventory->armor2 = FALSE;
    game->inventory->potion = FALSE;
    game->inventory->iron = FALSE;
    game->inventory->nb_iron = 0;
    if (!init_text_inventory(game)) {
        return (0);
    }
    game->object[BG_INVENTORY]->rect = (sfIntRect){0, 0, 1600, 900};
    for (int i = ARMOR_INV; i <= SARMOR_INV; i++) {
        game->object[i]->rect = (sfIntRect){0, 0, 208, 205};
    }
    game->object[PERSO_INV]->rect = (sfIntRect){0, 0, 750, 750};
    game->object[PERSO_INV]->position = (sfVector2f){.x = -55, .y = -60};
    game->object[ARMOR_INV]->position = (sfVector2f){.x = 361, .y = 609};
    game->object[POTION_INV]->position = (sfVector2f){.x = 139, .y = 609};
    game->object[SARMOR_INV]->position = (sfVector2f){.x = 585, .y = 609};
    game->object[IRON_INV]->position = (sfVector2f){.x = 585, .y = 609};
    return (1);
}