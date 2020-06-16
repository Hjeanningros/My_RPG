/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** write save norme
*/

#include "../../include/game.h"
#include "../../include/macro.h"
#include "../../include/prototype.h"

void write_norme_forth(gui_t *game, int fp)
{
    write(fp, " ", 1);
    write(fp, int_to_str(game->player->pos_x), my_intlen(game->player->pos_x));
    write(fp, " ", 1);
    write(fp, int_to_str(game->player->pos_y), my_intlen(game->player->pos_y));
    write(fp, " ", 1);
    write(fp, int_to_str(game->object[FOREST]->rect.left),
    my_intlen(game->object[FOREST]->rect.left));
    write(fp, " ", 1);
    write(fp, int_to_str(game->object[FOREST]->rect.top),
    my_intlen(game->object[FOREST]->rect.top));
    write(fp, " ", 1);
}

void write_norme_third(gui_t *game, int fp)
{
    write(fp, int_to_str((int)game->player->pv),
    my_intlen((int)game->player->pv));
    write(fp, " ", 1);
    write(fp, int_to_str((int)game->player->pv_max),
    my_intlen((int)game->player->pv_max));
    write(fp, " ", 1);
    write(fp, int_to_str(game->player->hp), my_intlen(game->player->hp));
    write(fp, " ", 1);
    write(fp, int_to_str(game->player->attack),
    my_intlen(game->player->attack));
    write(fp, " ", 1);
    write(fp, int_to_str(game->player->next_attack),
    my_intlen(game->player->next_attack));
    write(fp, " ", 1);
    write(fp, int_to_str(game->player->armor), my_intlen(game->player->armor));
    write(fp, " ", 1);
    write(fp, int_to_str(game->player->money), my_intlen(game->player->money));
}

void write_norme_sec(gui_t *game, int fp)
{
    write(fp, " ", 1);
    write(fp, int_to_str(game->inventory->iron), 1);
    write(fp, " ", 1);
    write(fp, int_to_str(game->inventory->nb_iron),
    my_intlen(game->inventory->nb_iron));
    write(fp, " ", 1);
    write(fp, int_to_str(game->inventory->potion), 1);
    write(fp, " ", 1);
    write(fp, int_to_str(game->inventory->nb_potion),
    my_intlen(game->inventory->nb_potion));
    write(fp, " ", 1);
    write(fp, int_to_str(game->battle1->finish), 1);
    write(fp, " ", 1);
    write(fp, int_to_str(game->battle2->finish), 1);
    write(fp, " ", 1);
}

void write_norme(gui_t *game, int fp)
{
    write(fp, int_to_str(game->info->last_scene),
    my_intlen(game->info->last_scene));
    write(fp, " ", 1);
    write(fp, int_to_str(game->info->music_bg), 1);
    write(fp, " ", 1);
    write(fp, int_to_str(game->info->music), 1);
    write(fp, " ", 1);
    write(fp, int_to_str(game->info->sound), 1);
}