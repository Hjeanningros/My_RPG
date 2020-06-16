/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** load saves
*/

#include "../../include/game.h"
#include "../../include/macro.h"
#include "../../include/prototype.h"

void fill_saves_sec(gui_t *game, char **tab)
{
    game->player->hp = my_getnbr(tab[19]);
    game->player->attack = my_getnbr(tab[20]);
    game->player->next_attack = my_getnbr(tab[21]);
    game->player->armor = my_getnbr(tab[22]);
    game->player->money = my_getnbr(tab[23]);
    game->player->status = my_getnbr(tab[24]);
    game->player->state = my_getnbr(tab[25]);
    game->adv = my_getnbr(tab[26]);
    game->player->pos_x = my_getnbr(tab[27]);
    game->player->pos_y = my_getnbr(tab[28]);
    game->object[FOREST]->rect = (sfIntRect){my_getnbr(tab[29]),
    my_getnbr(tab[30]), WIN_WIDTH, WIN_HEIGHT};
    game->lang = my_getnbr(tab[31]);
}

void fill_saves(gui_t *game, char **tab)
{
    game->info->scene = my_getnbr(tab[0]);
    game->info->last_scene = my_getnbr(tab[1]);
    game->info->music_bg = my_getnbr(tab[2]);
    game->info->music = my_getnbr(tab[3]);
    game->info->sound = my_getnbr(tab[4]);
    game->inventory->armor1 = my_getnbr(tab[6]);
    game->inventory->armor2 = my_getnbr(tab[7]);
    game->inventory->iron = my_getnbr(tab[8]);
    game->inventory->nb_iron = my_getnbr(tab[9]);
    game->inventory->potion = my_getnbr(tab[10]);
    game->inventory->nb_potion = my_getnbr(tab[11]);
    game->battle1->finish = my_getnbr(tab[12]);
    game->battle2->finish = my_getnbr(tab[13]);
    game->battle3->finish = my_getnbr(tab[14]);
    game->battle4->finish = my_getnbr(tab[15]);
    game->player->lvl = my_getnbr(tab[16]);
    game->player->pv = my_getnbr(tab[17]);
    game->player->pv_max = my_getnbr(tab[18]);
    fill_saves_sec(game, tab);
}

int load_save(gui_t *game)
{
    char *buffer = NULL;
    char **tab = NULL;

    if (game->info->save == 1)
        buffer = open_file("saves/save1.txt");
    else if (game->info->save == 2)
        buffer = open_file("saves/save2.txt");
    else
        buffer = open_file("saves/save3.txt");
    tab = my_str_to_word_array(buffer, ' ');
    fill_saves(game, tab);
}