/*
** EPITECH PROJECT, 2018
** scene.h
** File description:
** scene.h for Defender
*/

#ifndef SCENE_H
#define SCENE_H

#include "macro.h"
#include "game.h"

int loop_menu(gui_t *game);
int loop_settings(gui_t *game);
int loop_forest(gui_t *game);
int loop_battle(gui_t *game);
int loop_intro(gui_t *game);
int loop_inventory(gui_t *game);
int loop_death(gui_t *game);
int loop_pause(gui_t *game);
int loop_keys(gui_t *game);
int loop_save(gui_t *game);
int loop_language(gui_t *game);
int loop_battle_1(gui_t *game);
int loop_battle_2(gui_t *game);
int loop_battle_3(gui_t *game);
int loop_battle_4(gui_t *game);
int loop_battle_5(gui_t *game);
int loop_end(gui_t *game);

struct loop_s
{
    int (*loop_scene)(gui_t *game);
} loop_t;

const struct loop_s SCENE[NB_SCENE] = {
        {&loop_menu},
        {&loop_settings},
        {&loop_forest},
        {&loop_battle},
        {&loop_intro},
        {&loop_inventory},
        {&loop_death},
        {&loop_pause},
        {&loop_keys},
        {&loop_save},
        {&loop_language},
        {&loop_battle_1},
        {&loop_battle_2},
        {&loop_battle_3},
        {&loop_battle_4},
        {&loop_battle_5},
        {&loop_end},
};


#endif //SCENE_H