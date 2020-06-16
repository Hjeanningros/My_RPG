/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** init_gui
*/

#include "../../include/macro.h"
#include "../../include/game.h"
#include "../../include/prototype.h"
#include <stdio.h>

int fill_info_struct(gui_t *game)
{
    game->info->mouse = malloc(sizeof(mouse_t));
    if (!game->info->mouse)
        return (0);
    game->info->mouse->click = FALSE;
    game->info->mouse->position = (sfVector2i){0, 0};
    game->info->sound = TRUE;
    return (1);
}

int init_info(gui_t *game)
{
    game->info = malloc(sizeof(info_t));
    if (!game->info)
        return (0);
    game->info->scene = MENU;
    game->info->music_bg = TRUE;
    game->info->music = TRUE;
    game->info->updateRest = 0;
    game->info->view = sfView_create();
    game->info->trans = TRUE;
    game->info->last_scene = MENU;
    game->info->volume = 7;
    game->info->res = 8;
    sfView_setCenter(game->info->view, (sfVector2f){WIN_WIDTH / 2,
                                        WIN_HEIGHT / 2});
    sfView_setSize(game->info->view, (sfVector2f){WIN_WIDTH, WIN_HEIGHT});
    if (fill_info_struct(game) == 0)
        return (0);
    return (1);
}

int init_fondu(gui_t *game)
{
    game->object[FONDU]->rect = (sfIntRect){0, 0, 1920, 1080};
}

int init_game(gui_t *game)
{
    game->map = sfImage_createFromFile("./assets/map_foret_2_col_black.jpg");
    game->window = NULL;
    game->dispTimer = sfClock_create();
    game->updateTimer = sfClock_create();
    game->player = malloc(sizeof(player_t));
    game->battle1 = malloc(sizeof(battle_t));
    game->battle2 = malloc(sizeof(battle_t));
    game->battle3 = malloc(sizeof(battle_t));
    game->battle4 = malloc(sizeof(battle_t));
    game->battle5 = malloc(sizeof(battle_t));
    game->inventory = malloc(sizeof(inventory_t));
    if (!game->player || !game->battle1 || !game->battle2 || !game->battle3 ||
    !game->battle4 ||  !game->battle5 || !game->inventory) {
        return (0);
    }
    return (1);
}

int init_musics(gui_t *game)
{
    game->music = malloc(sizeof(sfMusic *) * (NB_MUSIC + 1));
    if (!game->music || !init_music(game))
        return (0);
    return (1);
}