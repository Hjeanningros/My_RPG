/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** init_gui
*/

#include "../../include/macro.h"
#include "../../include/game.h"
#include <stdio.h>
#include <stdlib.h>

static const char *TEXTURES[NB_TEXTURES] = {
    "./assets/Menu/Menu.png",
    "./assets/Menu/ButtonPlay.png",
    "./assets/Menu/ButtonSettings.png",
    "./assets/Menu/ButtonQuit.png",
    "./assets/Menu/Keys.png",
    "./assets/Menu/Parallax1.png",
    "./assets/Menu/Parallax1.png",
    "./assets/Menu/Parallax2.png",
    "./assets/Menu/Parallax2.png",
    "./assets/Menu/Parallax3.png",
    "./assets/Menu/Parallax3.png",
    "./assets/Menu/Parallax4.png",
    "./assets/Menu/Parallax4.png",
    "./assets/Menu/Parallax5.png",
    "./assets/Menu/Parallax5.png",
    "./assets/settings/Settings.png",
    "./assets/settings/Volume.png",
    "./assets/settings/ButtonOnOff.png",
    "./assets/settings/ButtonOnOff.png",
    "./assets/settings/ButtonPlus.png",
    "./assets/settings/ButtonMinus.png",
    "./assets/settings/ButtonBack.png",
    "./assets/settings/ButtonRes.png",
    "./assets/settings/ButtonRes.png",
    "./assets/settings/ButtonRes.png",
    "./assets/player/lv1_idle.png",
    "./assets/player/lv1_run.png",
    "./assets/player/lv2_idle.png",
    "./assets/player/lv2_run.png",
    "./assets/player/lv3_idle.png",
    "./assets/player/lv3_run.png",
    "./assets/popup.png",
    "./assets/fondu.png",
    "./assets/map_foret_2_black.jpg",
    "./assets/Battle/BG_attack.png",
    "./assets/Battle/Button_attack.png",
    "./assets/Battle/Button_boostattack.png",
    "./assets/Battle/Button_escape.png",
    "./assets/Battle/heal1.png",
    "./assets/Battle/heal2.png",
    "./assets/Battle/heal1.png",
    "./assets/Battle/heal2.png",
    "./assets/Battle/left_attack_enemies.png",
    "./assets/Battle/idle_blinking.png",
    "./assets/Battle/attack.png",
    "./assets/Battle/hurt.png",
    "./assets/Battle/boost.png",
    "./assets/hugo.jpg",
    "./assets/band.jpg",
    "./assets/band.jpg",
    "./assets/inventory/Inventaire.png",
    "./assets/inventory/perso_inv.png",
    "./assets/inventory/Armor1.png",
    "./assets/inventory/Potion.png",
    "./assets/inventory/iron.png",
    "./assets/inventory/Armor2.png",
    "./assets/death.png",
    "./assets/pause/Pause.png",
    "./assets/pause/ButtonKeys.png",
    "./assets/pause/ButtonQuitP.png",
    "./assets/pause/ButtonResume.png",
    "./assets/pause/ButtonSettingsP.png",
    "./assets/keybinding/Keybinding.png",
    "./assets/save/select_save.png",
    "./assets/save/save1.png",
    "./assets/save/save2.png",
    "./assets/save/save3.png",
    "./assets/language/choose_language.png",
    "./assets/language/french_flag.png",
    "./assets/language/english_flag.png",
    "./assets/Battle1/left_idle.png",
    "./assets/Battle1/left_hurt.png",
    "./assets/Battle1/left_attack.png",
    "./assets/Battle2/left_idle.png",
    "./assets/Battle2/left_hurt.png",
    "./assets/Battle2/left_attack.png",
    "./assets/Battle3/left_idle.png",
    "./assets/Battle3/left_hurt.png",
    "./assets/Battle3/left_attack.png",
    "./assets/Battle/armor_1_attack.png",
    "./assets/Battle/armor_1_hurt.png",
    "./assets/Battle/armor_1_idle.png",
    "./assets/Battle/armor_1_boost.png",
    "./assets/Battle/armor_2_attack.png",
    "./assets/Battle/armor_2_hurt.png",
    "./assets/Battle/armor_2_idle.png",
    "./assets/Battle/armor_2_boost.png",
    "./assets/Battle4/left_idle.png",
    "./assets/Battle4/left_hurt.png",
    "./assets/Battle4/left_attack.png",
    "./assets/Battle5/left_idle.png",
    "./assets/Battle5/left_hurt.png",
    "./assets/Battle5/left_attack.png",
    "./assets/Skarim_logo.png",
    "./assets/end/End.png",
    "./assets/band.jpg",
    "./assets/band.jpg",
};

int init_images(gui_t *game)
{
    int i = 0;
    game->object = malloc(sizeof(csfml_object_t *) * (NB_TEXTURES + 1));
    if (game->object == NULL)
        return (0);
    for (; i < NB_TEXTURES; i++) {
        game->object[i] = malloc(sizeof(csfml_object_t));
        game->object[i]->sprite = sfSprite_create();
        game->object[i]->texture = sfTexture_createFromFile(TEXTURES[i], NULL);
        game->object[i]->scale = (sfVector2f){1, 1};
        game->object[i]->position = (sfVector2f){0, 0};
        if (!game->object[i]->sprite || !game->object[i]->texture)
            return (0);
        sfSprite_setTexture(game->object[i]->sprite, game->object[i]->texture,
                            sfTrue);
    }
    game->object[i] = NULL;
    return (1);
}