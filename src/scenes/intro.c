/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** menu.c
*/

#include "../../include/game.h"
#include "../../include/macro.h"
#include "../../include/prototype.h"

int i_event(gui_t *game)
{
    sfEvent e;

    while (sfRenderWindow_pollEvent(game->window, &e)) {
        if (e.type == sfEvtClosed)
            sfRenderWindow_close(game->window);
        if (e.type == sfEvtMouseButtonPressed) {
            game->info->mouse->click = TRUE;
        } else {
            game->info->mouse->click = FALSE;
        }
        if (game->dialogue[INTRO_TXT][game->text[INTRO_TXT]->index] != NULL &&
            game->stat_intro == 1 && game->info->mouse->click == TRUE) {
            game->text[INTRO_TXT]->index += 1;
            if (game->dialogue[INTRO_TXT][game->text[INTRO_TXT]->index] ==
                NULL) {
                game->stat_intro = 2;
            }
        }
    }
    return (1);
}

int i_display(gui_t *game)
{
    static int i = 0;

    displayer(game->window, game->object[IMG_INTRO]);
    displayer(game->window, game->object[BAND_TOP]);
    displayer(game->window, game->object[BAND_BOT]);
    if (game->stat_intro == 1) {
        if (game->lang == 1) {
            display_dialogue(INTRO_TXT_ENG, game);
            i = 1;
        }
        else {
            display_dialogue(INTRO_TXT, game);
            i = 1;
        }
    }
    if (game->stat_intro >= 2)
        logo(game);
    return (1);
}

int i_update(gui_t *game)
{
    static int i = 0;
    static int j = 0;
    if (i == 16 && game->stat_intro == 0) {
        first_part_intro(game);
        i = 0;
    }
    if (i >= 5 && game->stat_intro == 2) {
        second_part_intro(game);
        i = 0;
    }
    if (game->stat_intro == 3) {
        ++j;
        if (j >= 1000) {
            game->info->scene = FOREST_MAP;
            j = 0;
        }
    }
    i++;
    return (1);
}

int loop_intro2(gui_t *game)
{
    double elapsed2 = 0;
    elapsed2 = sfTime_asMilliseconds(sfClock_getElapsedTime(game->dispTimer));
    if (elapsed2 >= (1.0 / 30.0) * 1000.0) {
        sfRenderWindow_clear(game->window, sfBlack);
        sfClock_restart(game->dispTimer);
        if (!i_display(game))
            return (0);
        sfRenderWindow_display(game->window);
    }
    return (1);
}

int loop_intro(gui_t *game)
{
    double elapsed1 = 0;

    sfRenderWindow_setMouseCursorVisible(game->window, sfTrue);
    sfRenderWindow_setView(game->window, game->info->view);
    if (!i_event(game))
        return (0);
    elapsed1 = sfTime_asMicroseconds(sfClock_getElapsedTime(game->updateTimer))
                    + game->info->updateRest;
    sfClock_restart(game->updateTimer);
    while (elapsed1 >= (1.0 / 60.0) * 100000.0) {
        if (!i_update(game))
            return (0);
        elapsed1 -= (1.0 / 60.0) * 100000.0;
    }
    game->info->updateRest = elapsed1;
    if (!loop_intro2(game)) {
        return (0);
    }
    return (1);
}