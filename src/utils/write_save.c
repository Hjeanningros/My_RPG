/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** write save
*/

#include "../../include/game.h"
#include "../../include/macro.h"
#include "../../include/prototype.h"

void write_in_save_forth(gui_t *game, int fp)
{
    write(fp, " ", 1);
    write(fp, int_to_str(game->player->status), 1);
    write(fp, " ", 1);
    write(fp, int_to_str(game->player->state), 1);
    write(fp, " ", 1);
    write(fp, int_to_str(game->adv), my_intlen(game->adv));
    write_norme_forth(game, fp);
    if (game->lang == 1)
        write(fp, "1", 2);
    else if (game->lang == 0)
        write(fp, "0", 2);
    close (fp);
}

void write_in_save_third(gui_t *game, int fp)
{
    write(fp, int_to_str(game->battle3->finish), 1);
    write(fp, " ", 1);
    write(fp, int_to_str(game->battle4->finish), 1);
    write(fp, " ", 1);
    write(fp, int_to_str(game->player->lvl), 1);
    write(fp, " ", 1);
    write_norme_third(game, fp);
    write_in_save_forth(game, fp);
}

void write_in_save_sec(gui_t *game, int fp)
{
    write(fp, " ", 1);
    write(fp, int_to_str((int)game->info->volume),
    my_intlen((int)game->info->volume));
    write(fp, " ", 1);
    write(fp, int_to_str(game->inventory->armor1), 1);
    write(fp, " ", 1);
    write(fp, int_to_str(game->inventory->armor2), 1);
    write_norme_sec(game, fp);
    write_in_save_third(game, fp);
}

int write_in_save(gui_t *game)
{
    int fp;
    if (game->info->save == 1)
        fp = open("saves/save1.txt", O_WRONLY);
    else if (game->info->save == 2)
        fp = open("saves/save2.txt", O_WRONLY);
    else
        fp = open("saves/save3.txt", O_WRONLY);
    if (fp < 0)
        return (0);
    write(fp, "2", 1);
    write(fp, " ", 1);
    write_norme(game, fp);
    write_in_save_sec(game, fp);
    return (1);
}