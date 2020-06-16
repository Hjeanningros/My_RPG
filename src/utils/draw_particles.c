/*
** EPITECH PROJECT, 2020
** RPG
** File description:
** particulse
*/

#include <stdlib.h>
#include "../../include/game.h"
#include "../../include/prototype.h"

void draw_particles(sfRenderWindow *win, sfUint8 *buffer)
{
    sfTexture *texture = sfTexture_create(WIN_WIDTH, WIN_HEIGHT);
    sfSprite *sprite = sfSprite_create();

    if (!texture || !sprite)
        exit(84);
    sfTexture_updateFromPixels(
        texture, buffer,
        WIN_WIDTH, WIN_HEIGHT,
        0, 0
    );
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setPosition(sprite, (sfVector2f){0, 310});
    sfRenderWindow_drawSprite(win, sprite, NULL);
    sfTexture_destroy(texture);
    sfSprite_destroy(sprite);
}