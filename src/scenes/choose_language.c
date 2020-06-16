/*
** EPITECH PROJECT, 2020
** RPG
** File description:
** choose_language
*/

#include "../../include/game.h"
#include "../../include/macro.h"
#include "../../include/prototype.h"

int lang_event(gui_t *game)
{
    sfEvent e;

    while (sfRenderWindow_pollEvent(game->window, &e)) {
        if (e.type == sfEvtClosed)
            sfRenderWindow_close(game->window);
        if (e.type == sfEvtMouseButtonPressed) {
            game->info->mouse->click = TRUE;
            b_french(game, e.mouseButton);
            b_english(game, e.mouseButton);
        } else {
            game->info->mouse->click = FALSE;
        }
    }
    return (1);
}

int lang_display(gui_t *game)
{
    for (int i = PARA_1_CP; i <= PARA_5; i++) {
        displayer(game->window, game->object[i]);
    }
    for (int i = BG_LANGUAGE; i <= ENGLISH_FLAG; i++) {
        displayer(game->window, game->object[i]);
    }
    return (1);
}

int lang_update(gui_t *game)
{
    for (int i = BG_LANGUAGE; i <= ENGLISH_FLAG; i++) {
        sfSprite_setTextureRect(game->object[i]->sprite,
        game->object[i]->rect);
    }
    move_parallax(game);
    return (1);
}

int loop_language2(gui_t *game)
{
    double elapsed2 = 0;
    elapsed2 = sfTime_asMilliseconds(sfClock_getElapsedTime(game->dispTimer));
    if (elapsed2 >= (1.0 / 30.0) * 1000.0) {
        sfRenderWindow_clear(game->window, sfBlack);
        sfClock_restart(game->dispTimer);
        if (!lang_display(game))
            return (0);
        sfRenderWindow_display(game->window);
    }
    return (1);
}

int loop_language(gui_t *game)
{
    double elapsed1 = 0;

    sfRenderWindow_setMouseCursorVisible(game->window, sfTrue);
    sfRenderWindow_setView(game->window, game->info->view);
    if (!lang_event(game))
        return (0);
    elapsed1 = sfTime_asMicroseconds(sfClock_getElapsedTime(game->updateTimer))
                    + game->info->updateRest;
    sfClock_restart(game->updateTimer);
    while (elapsed1 >= (1.0 / 60.0) * 100000.0) {
        if (!lang_update(game))
            return (0);
        elapsed1 -= (1.0 / 60.0) * 100000.0;
    }
    game->info->updateRest = elapsed1;
    if (!loop_language2(game)) {
        return (0);
    }
    return (1);
}