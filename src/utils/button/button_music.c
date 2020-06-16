/*
** EPITECH PROJECT, 2020
** my defender
** File description:
** button music
*/

#include "../../../include/game.h"
#include "../../../include/macro.h"
#include "../../../include/prototype.h"

void b_on_off_music(gui_t *game, csfml_object_t *object, sfMouseButtonEvent e)
{
    sfFloatRect rec;

    rec = sfSprite_getGlobalBounds(object->sprite);
    if (sfFloatRect_contains(&rec, e.x, e.y) && object->rect.left == 0) {
        object->rect.left = object->rect.width;
        game->info->music = FALSE;
        sfMusic_pause(game->music[BG_MUSIC]);
    } else if (sfFloatRect_contains(&rec, e.x, e.y) &&
    object->rect.left != 0 ) {
        object->rect.left = 0;
        game->info->music = TRUE;
        sfMusic_play(game->music[BG_MUSIC]);
    }
}