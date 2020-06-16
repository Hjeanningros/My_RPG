/*
** EPITECH PROJECT, 2020
** default
** File description:
** default
*/

#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/System/Clock.h>
#include <SFML/System/Vector2.h>
#include <SFML/Audio.h>
#include <SFML/Graphics/Vertex.h>
#include <stdlib.h>
#include<stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "csfml_object.h"
#include "csfml_text.h"

typedef enum status_s
{
    IDLE = 0,
    RUN
} status_t;

typedef struct player_s
{
    int lvl;
    float pv;
    float pv_max;
    int hp;
    int attack;
    int next_attack;
    int armor;
    int money;
    int status;
    int state;
    unsigned int pos_x;
    unsigned int pos_y;
    csfml_object_t **sprite;
} player_t;

#endif //PLAYER_H