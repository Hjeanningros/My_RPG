/*
** EPITECH PROJECT, 2018
** init.h
** File description:
** init.h for Defender
*/

#ifndef INIT_H
#define INIT_H

#include "macro.h"
#include "game.h"

int init_game(gui_t *game);
int init_images(gui_t *game);
int init_musics(gui_t *game);
int init_info(gui_t *game);
int init_player(gui_t *game);
int init_menu(gui_t *game);
int init_settings(gui_t *game);
int init_text(gui_t *game);
int init_dialogue(gui_t *game);
int init_battle(gui_t *game);
int init_forest(gui_t *game);
int init_fondu(gui_t *game);
int init_intro(gui_t *game);
int init_particles(gui_t *game);
int init_inventory(gui_t *game);
int init_pause(gui_t *game);
int init_save(gui_t *game);
int init_choose_language(gui_t *game);
int init_battle_1(gui_t *game);
int init_battle_2(gui_t *game);
int init_battle_3(gui_t *game);
int init_battle_4(gui_t *game);
int init_battle_5(gui_t *game);
int init_end(gui_t *game);

struct tor_s {
    int (*tor)(gui_t *game);
} tor_t;

const struct tor_s INIT[NB_INIT] =
    {{&init_game},
    {&init_images},
    {&init_musics},
    {&init_info},
    {&init_player},
    {&init_menu},
    {&init_settings},
    {&init_text},
    {&init_dialogue},
    {&init_forest},
    {&init_battle},
    {&init_fondu},
    {&init_intro},
    {&init_particles},
    {&init_inventory},
    {&init_pause},
    {&init_save},
    {&init_choose_language},
    {&init_battle_1},
    {&init_battle_2},
    {&init_battle_3},
    {&init_battle_4},
    {&init_battle_5},
    {&init_end},
};

#endif //INIT_H
