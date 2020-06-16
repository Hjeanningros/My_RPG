/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** init_gui
*/

#include "../../include/macro.h"
#include "../../include/game.h"
#include "../../include/prototype.h"

int second_line(int i, gui_t *game)
{
    game->text[i]->position = (sfVector2f){400, 820};
    sfText_setFont(game->text[i]->text, game->text[i]->font);
    sfText_setColor(game->text[i]->text, sfBlack);
    sfText_setString(game->text[i]->text,
                game->dialogue[i][game->text[i]->index + 1]);
    sfText_setCharacterSize(game->text[i]->text, 27);
    sfText_setPosition(game->text[i]->text, game->text[i]->position);
    sfRenderWindow_drawText(game->window, game->text[i]->text, NULL);
}

int display_dialogue(int i, gui_t *game)
{
    static int y = 0;

    displayer(game->window, game->object[POPUP]);
    game->text[i]->position = (sfVector2f){400, 780};
    sfText_setFont(game->text[i]->text, game->text[i]->font);
    sfText_setColor(game->text[i]->text, sfBlack);
    sfText_setString(game->text[i]->text,
                    game->dialogue[i][game->text[i]->index]);
    sfText_setCharacterSize(game->text[i]->text, 27);
    sfText_setPosition(game->text[i]->text, game->text[i]->position);
    sfRenderWindow_drawText(game->window, game->text[i]->text, NULL);
    if (i < tab_len(game->dialogue[i])) {
        second_line(i, game);
    }
    return 1;
}