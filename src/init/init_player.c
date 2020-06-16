/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** init_gui
*/

#include "../../include/macro.h"
#include "../../include/game.h"
#include "../../include/prototype.h"
#include <stdio.h>

int init_player_2(gui_t *game)
{
    int j = 0;

    for (int i = LV1_IDLE; i <= LV3_RUN; i++, j++) {
        game->player->sprite[j] = malloc(sizeof(csfml_object_t));
        if (game->player->sprite[j] == NULL)
            return 0;
        game->player->sprite[j]->sprite =
        sfSprite_copy(game->object[i]->sprite);
        game->player->sprite[j]->texture =
        sfTexture_copy(game->object[i]->texture);
        game->player->sprite[j]->rect = (sfIntRect){0, 0, 240, 240};
        game->player->sprite[j]->position = (sfVector2f){(WIN_WIDTH / 2 - 120),
                                            (WIN_HEIGHT / 2 - 120)};
        game->player->sprite[j]->scale = (sfVector2f){1, 1};
        sfSprite_setTextureRect(game->player->sprite[j]->sprite,
                                game->player->sprite[j]->rect);
    }
    game->player->sprite[j] = NULL;
    return (1);
}

int init_player(gui_t *game)
{
    game->player->pv = 150;
    game->player->pv_max = 150;
    game->player->attack = 30;
    game->player->next_attack = game->player->attack;
    game->player->hp = 0;
    game->player->armor = 0;
    game->player->money = 30;
    game->player->lvl = 0;
    game->player->status = IDLE;
    game->player->state = 0;
    game->player->sprite = malloc(sizeof(csfml_object_t *) * 7);
    if (game->player->sprite == NULL)
        return (0);
    if (!init_player_2(game)) {
        return (0);
    }
    return (1);
}