/*
** EPITECH PROJECT, 2020
** RPG
** File description:
** button save
*/

#include "../../../include/game.h"
#include "../../../include/macro.h"
#include "../../../include/prototype.h"

void b_save1(gui_t *game, sfMouseButtonEvent e)
{
    sfFloatRect rec;
    rec = sfSprite_getGlobalBounds(game->object[SAVE1]->sprite);

    if (sfFloatRect_contains(&rec, e.x, e.y)) {
        game->info->last_scene = MENU;
        game->info->save = 1;
        game->info->trans = TRUE;
        game->info->scene = LANGUAGE;
        load_save(game);
    }
}

void b_save2(gui_t *game, sfMouseButtonEvent e)
{
    sfFloatRect rec;
    rec = sfSprite_getGlobalBounds(game->object[SAVE2]->sprite);

    if (sfFloatRect_contains(&rec, e.x, e.y)) {
        game->info->last_scene = MENU;
        game->info->save = 2;
        game->info->trans = TRUE;
        game->info->scene = LANGUAGE;
        load_save(game);
    }
}

void b_save3(gui_t *game, sfMouseButtonEvent e)
{
    sfFloatRect rec;
    rec = sfSprite_getGlobalBounds(game->object[SAVE3]->sprite);

    if (sfFloatRect_contains(&rec, e.x, e.y)) {
        game->info->last_scene = MENU;
        game->info->save = 3;
        game->info->trans = TRUE;
        game->info->scene = LANGUAGE;
        load_save(game);
    }
}