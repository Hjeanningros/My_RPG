/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** init_gui
*/

#include "../../include/macro.h"
#include "../../include/game.h"
#include "../../include/prototype.h"

void move_up(gui_t *game, csfml_object_t *map)
{
    if (!check_colision(game, game->player->pos_x, game->player->pos_y - 10) &&
        !check_pnj(game, game->player->pos_x, game->player->pos_y + 10)) {
        game->player->status = RUN;
        game->player->sprite[game->player->status +
            (game->player->lvl * 2)]->rect.top = 0;
        map->rect.top -= 5;
        game->player->pos_y -= 5;
    }
}

void move_down(gui_t *game, csfml_object_t *map)
{
    if (!check_colision(game, game->player->pos_x, game->player->pos_y + 50) &&
        !check_pnj(game, game->player->pos_x, game->player->pos_y + 50)) {
        game->player->status = RUN;
        game->player->sprite[game->player->status +
            (game->player->lvl * 2)]->rect.top = 240;
        map->rect.top += 5;
        game->player->pos_y += 5;
    }
}

void move_left(gui_t *game, csfml_object_t *map)
{
    if (!check_colision(game, game->player->pos_x - 50, game->player->pos_y) &&
        !check_pnj(game, game->player->pos_x - 50, game->player->pos_y)) {
        game->player->status = RUN;
        game->player->sprite[game->player->status +
            (game->player->lvl * 2)]->rect.top = 480;
        map->rect.left -= 5;
        game->player->pos_x -= 5;
    }
}

void move_right(gui_t *game, csfml_object_t *map)
{
    if (!check_colision(game, game->player->pos_x + 50, game->player->pos_y) &&
        !check_pnj(game, game->player->pos_x + 50, game->player->pos_y)) {
        game->player->status = RUN;
        game->player->sprite[game->player->status +
            (game->player->lvl * 2)]->rect.top = 720;
        map->rect.left += 5;
        game->player->pos_x += 5;
    }
}

int player_mvt(gui_t *game, csfml_object_t *map)
{
    int com[] = {1, 2, 3, 4};
    void (*funct[])(gui_t *, csfml_object_t *) = {move_up, move_down, move_left,
                                                move_right};

    if (game->event != 0) {
        for (int i = 0; i < 4; i++) {
            if (game->event == com[i]) {
                funct[i](game, map);
            }
        }
        change_opasity(game);
    } else if (game->event == 0) {
        game->player->status = IDLE;
        game->player->sprite[IDLE + (game->player->lvl * 2)]->rect.top =
            game->player->sprite[RUN + (game->player->lvl * 2)]->rect.top;
        change_opasity(game);
    }
}