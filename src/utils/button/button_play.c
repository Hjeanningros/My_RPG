/*
** EPITECH PROJECT, 2020
** my defender
** File description:
** button play
*/

#include "../../../include/game.h"
#include "../../../include/macro.h"
#include "../../../include/prototype.h"

void b_play(gui_t *game, sfMouseButtonEvent e)
{
    sfFloatRect rec;
    rec = sfSprite_getGlobalBounds(game->object[B_PLAY]->sprite);

    if (sfFloatRect_contains(&rec, e.x, e.y)) {
        game->info->last_scene = MENU;
        game->info->trans = TRUE;
        game->info->scene = SAVE;
    }
}

void b_key(gui_t *game, sfMouseButtonEvent e)
{
    sfFloatRect rec;
    rec = sfSprite_getGlobalBounds(game->object[B_KEY]->sprite);

    if (sfFloatRect_contains(&rec, e.x, e.y)) {
        game->info->last_scene = MENU;
        game->info->trans = TRUE;
        game->info->scene = KEYS;
    }
}

void b_back(gui_t *game, csfml_object_t *object, sfMouseButtonEvent e)
{
    sfFloatRect rec;
    rec = sfSprite_getGlobalBounds(object->sprite);

    if (sfFloatRect_contains(&rec, e.x, e.y)) {
        game->info->scene = game->info->last_scene;
    }
}

int button_back_rules(gui_t *game, csfml_object_t *object)
{
    sfFloatRect rec;
    sfVector2i vec = sfMouse_getPositionRenderWindow(game->window);

    rec = sfSprite_getGlobalBounds(object->sprite);
    if (sfFloatRect_contains(&rec, (float)vec.x, (float)vec.y)) {
        object->scale.x = 1.1;
        object->scale.y = 1.1;
    } else {
        object->scale.x = 1;
        object->scale.y = 1;
    }
    return (1);
}