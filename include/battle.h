/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** battle struct
*/

#ifndef BATTLE_H_
#define BATTLE_H_

#include "macro.h"
#include "game.h"

typedef struct {
    float hp;
    float hp_max;
    int attack;
    int status;
    int enemy_status;
    int finish;
    int start;
} battle_t;

#endif /* !BATTLE_H_ */
