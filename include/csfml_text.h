/*
** EPITECH PROJECT, 2020
** my defender
** File description:
** CSFML_TEXT_H
*/

#ifndef CSFML_TEXT
#define CSFML_TEXT

#include <stdbool.h>
#include <SFML/Graphics.h>
#include "game.h"

typedef struct {
    sfVector2f position;
    sfText *text;
    sfColor color;
    int character_size;
    sfFont *font;
    int index;
} csfml_text_t;

#endif /* !CSFML_TEXT */
