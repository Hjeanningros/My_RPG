/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** menu.c
*/

#include "../../include/game.h"
#include "../../include/macro.h"
#include "../../include/prototype.h"

int f_event(gui_t *game)
{
    sfEvent e;
    if (game->info->music_bg == TRUE && game->info->music == TRUE) {
        sfMusic_setLoop(game->music[BG_MUSIC], true);
        sfMusic_play(game->music[BG_MUSIC]);
        game->info->music_bg = FALSE;
    }
    while (sfRenderWindow_pollEvent(game->window, &e)) {
        switch_scene_and_get_click(game, e);
        if (game->diag != -1) {
            can_speak(game);
            click_to_speak(game, e);
        }
        event_mvt(game, e);
    }
    return (1);
}

int f_display(gui_t *game)
{
    displayer(game->window, game->object[FOREST]);
    displayer(game->window, game->player->sprite[game->player->status +
    (game->player->lvl * 2)]);
    if (game->diag != -1)
        display_dialogue(game->diag, game);
    return (1);
}

int f_update(gui_t *g)
{
    static int i = 0; static int y = 0;
    if (i == 60) {
        move_rect(g->player->sprite[g->player->status + (g->player->lvl * 2)]);
        i = 0;
    }
    if (g->diag == -1 && y >= 10) {
        player_mvt(g, g->object[FOREST]);
        if (g->event == 5) {
            speak_to_pnj(g);
        }
        y = 0;
    }
    sfSprite_setTextureRect(g->player->sprite[g->player->status +
            (g->player->lvl * 2)]->sprite, g->player->sprite[g->player->status +
            (g->player->lvl * 2)]->rect);
    sfSprite_setTextureRect(g->object[FOREST]->sprite,
                g->object[FOREST]->rect);
    y++;
    i++;
    return (1);
}

int loop_forest2(gui_t *game)
{
    double elapsed2 = 0;
    elapsed2 = sfTime_asMilliseconds(sfClock_getElapsedTime(game->dispTimer));
    if (elapsed2 >= (1.0 / 30.0) * 1000.0) {
        sfRenderWindow_clear(game->window, sfBlack);
        sfClock_restart(game->dispTimer);
        if (!f_display(game))
            return (0);
        sfRenderWindow_display(game->window);
    }
    return (1);
}

int loop_forest(gui_t *game)
{
    double elapsed1 = 0;

    sfRenderWindow_setMouseCursorVisible(game->window, sfTrue);
    sfRenderWindow_setView(game->window, game->info->view);
    if (!f_event(game))
        return (0);
    elapsed1 = sfTime_asMicroseconds(sfClock_getElapsedTime(game->updateTimer))
                    + game->info->updateRest;
    sfClock_restart(game->updateTimer);
    while (elapsed1 >= (1.0 / 60.0) * 100000.0) {
        if (!f_update(game))
            return (0);
        elapsed1 -= (1.0 / 60.0) * 100000.0;
    }
    game->info->updateRest = elapsed1;
    if (!loop_forest2(game)) {
        return (0);
    }
    return (1);
}