/*
** EPITECH PROJECT, 2020
** my defender
** File description:
** init text
*/

#include "../../include/macro.h"
#include "../../include/game.h"
#include "../../include/prototype.h"
#include <stdio.h>
#include <sys/stat.h>

static const char *DIALOGUE[NB_DIALOGUE] = {
    "text/dialogue/fr/intro.txt",
    "text/dialogue/fr/pnj_begin.txt",
    "text/dialogue/fr/pnj_stuff_before.txt",
    "text/dialogue/fr/pnj_stuff_after.txt",
    "text/dialogue/fr/pnj_entry_village.txt",
    "text/dialogue/fr/forgeron_mission.txt",
    "text/dialogue/fr/forgeron_mission_complete.txt",
    "text/dialogue/fr/marchand.txt",
    "text/dialogue/fr/pnj_foret_brulee.txt",
    "text/dialogue/fr/first_battle_before.txt",
    "text/dialogue/fr/first_battle_after.txt",
    "text/dialogue/fr/always_battle.txt",
    "text/dialogue/fr/boss_final.txt",
    "text/dialogue/fr/mineur.txt",
    "text/dialogue/fr/all_iron.txt",
    "text/dialogue/english/intro_eng.txt",
    "text/dialogue/english/pnj_begin_eng.txt",
    "text/dialogue/english/pnj_stuff_before_eng.txt",
    "text/dialogue/english/pnj_stuff_after_eng.txt",
    "text/dialogue/english/pnj_entry_village_eng.txt",
    "text/dialogue/english/forgeron_mission_eng.txt",
    "text/dialogue/english/forgeron_mission_complete_eng.txt",
    "text/dialogue/english/marchand_eng.txt",
    "text/dialogue/english/pnj_foret_brulee_eng.txt",
    "text/dialogue/english/first_battle_before_eng.txt",
    "text/dialogue/english/first_battle_after_eng.txt",
    "text/dialogue/english/always_battle_eng.txt",
    "text/dialogue/english/boss_final_eng.txt",
    "text/dialogue/english/mineur_eng.txt",
    "text/dialogue/english/all_iron_eng.txt",
    "text/dialogue/fr/popup_popo.txt",
    "text/dialogue/english/popup_popo_eng.txt",
    "text/dialogue/fr/popoup_equipement.txt",
    "text/dialogue/english/popoup_equipement_eng.txt",
};

int init_dialogue(gui_t *game)
{
    int i = 0;
    FILE *fd = NULL;

    game->dialogue = malloc(sizeof(char **) * (NB_DIALOGUE + 1));
    if (game->dialogue == NULL) {
        return 0;
    }
    for (; i < NB_DIALOGUE; i++) {
        fd = fopen(DIALOGUE[i], "r");
        game->dialogue[i] = my_str_to_word_array(open_file(DIALOGUE[i]), '\n');
        if (game->dialogue == NULL)
            return (0);
    }
    game->dialogue[i] = NULL;
    game->object[POPUP]->position = (sfVector2f){300, 760};
    sfSprite_setPosition(game->object[POPUP]->sprite,
    game->object[POPUP]->position);
    return (1);
}

int init_text(gui_t *game)
{
    int i = 0;
    sfFont *font =
    sfFont_createFromFile("text/font/saranaigame-bold-webfont.ttf");

    game->text = malloc(sizeof(csfml_text_t *) * (NB_TEXT + 1));
    if (game->text == NULL)
        return 0;
    for (; i < NB_TEXT; i++) {
        game->text[i] = malloc(sizeof(csfml_text_t));
        game->text[i]->text = sfText_create();
        game->text[i]->position = (sfVector2f){10, 10};
        game->text[i]->color = sfWhite;
        game->text[i]->character_size = 20;
        game->text[i]->font = font;
        game->text[i]->index = 0;
    }
    game->text[i] = NULL;
    return (1);
}