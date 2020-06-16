/*
** EPITECH PROJECT, 2020
** default
** File description:
** default
*/

#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/System/Clock.h>
#include <SFML/System/Vector2.h>
#include <SFML/Audio.h>
#include <SFML/Graphics/Vertex.h>
#include <SFML/Config.h>
#include <stdlib.h>
#include<stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "csfml_object.h"
#include "csfml_text.h"
#include "player.h"
#include "battle.h"
#include "inventory.h"

typedef enum bool_s
{
    FALSE,
    TRUE
} bool_t;

typedef enum
{
    MENU = 0,
    SETTINGS,
    FOREST_MAP,
    BATTLE,
    INTRO,
    INVENTORY,
    DEATH,
    PAUSE,
    KEYS,
    SAVE,
    LANGUAGE,
    BATTLE1,
    BATTLE2,
    BATTLE3,
    BATTLE4,
    BATTLE5,
    END,
} scene_e;

typedef enum text_s
{
    INTRO_TXT = 0,
    PNJ_BEGIN,
    PNJ_ARMOR_BEFORE,
    PNJ_ARMOR_AFTER,
    PNJ_ENTRY_VILLAGE,
    FORGERON_MISSION,
    FORGERON_MISSION_COMPLETE,
    MARCHAND,
    PNJ_FORET_BRULEE,
    FIRST_BATTLE_BEFORE,
    FIRST_BATTLE_AFTER,
    ALWAYS_BATTLE,
    BOSS_FINAL,
    MINEUR,
    END_MINEUR,
    INTRO_TXT_ENG,
    PNJ_BEGIN_ENG,
    PNJ_ARMOR_BEFORE_ENG,
    PNJ_ARMOR_AFTER_ENG,
    PNJ_ENTRY_VILLAGE_ENG,
    FORGERON_MISSION_ENG,
    FORGERON_MISSION_COMPLETE_ENG,
    MARCHAND_ENG,
    PNJ_FORET_BRULEE_ENG,
    FIRST_BATTLE_BEFORE_ENG,
    FIRST_BATTLE_AFTER_ENG,
    ALWAYS_BATTLE_ENG,
    BOSS_FINAL_ENG,
    MINEUR_ENG,
    END_MINEUR_ENG,
    POPUP_POPO,
    POPUP_POPO_ENG,
    POPUP_STUFF,
    POPUP_STUFF_ENG,
    INV_HP,
    INV_ATTACK,
    INV_ARMOR,
    INV_MONEY,
    INV_SLASH,
    INV_HP_MAX,
    INV_NB_POPO,
    INV_NB_IRON,
} text_t;

typedef enum
{
    BG_MENU = 0,
    B_PLAY,
    B_SETTINGS,
    B_QUIT,
    B_KEY,
    PARA_1_CP,
    PARA_1,
    PARA_2_CP,
    PARA_2,
    PARA_3_CP,
    PARA_3,
    PARA_4_CP,
    PARA_4,
    PARA_5_CP,
    PARA_5,
    BG_SETTINGS,
    VOLUME,
    B_ON_OFF_MUSIC,
    B_ON_OFF_SOUND,
    B_PLUS,
    B_MINUS,
    B_BACK,
    B_RES1,
    B_RES2,
    B_RES3,
    LV1_IDLE,
    LV1_RUN,
    LV2_IDLE,
    LV2_RUN,
    LV3_IDLE,
    LV3_RUN,
    POPUP,
    FONDU,
    FOREST,
    BG_BATTLE,
    BUTTON_ATTACK,
    BUTTON_BOOSTATTACK,
    BUTTON_ESCAPE,
    HEAL_RED_PLAYER,
    HEAL_GREEN_PLAYER,
    HEAL_RED_ENEMIES,
    HEAL_GREEN_ENEMIES,
    ENEMI_LEFT_ATTACK,
    IDLE_BL,
    ATTACK_BL,
    HURT_BL,
    BOOST_BL,
    IMG_INTRO,
    BAND_TOP,
    BAND_BOT,
    BG_INVENTORY,
    PERSO_INV,
    ARMOR_INV,
    POTION_INV,
    IRON_INV,
    SARMOR_INV,
    BG_DEATH,
    BG_PAUSE,
    B_MENU,
    B_QUITP,
    B_RESUME,
    B_SETTINGSP,
    KEYBINDING,
    BG_SAVE,
    SAVE1,
    SAVE2,
    SAVE3,
    BG_LANGUAGE,
    FRENCH_FLAG,
    ENGLISH_FLAG,
    ENEMY_IDLE_1,
    ENEMY_HURT_1,
    ENEMY_ATTACK_1,
    ENEMY_IDLE_2,
    ENEMY_HURT_2,
    ENEMY_ATTACK_2,
    ENEMY_IDLE_3,
    ENEMY_HURT_3,
    ENEMY_ATTACK_3,
    ARMOR1_ATTACK,
    ARMOR1_HURT,
    ARMOR1_IDLE,
    ARMOR1_BOOST,
    ARMOR2_ATTACK,
    ARMOR2_HURT,
    ARMOR2_IDLE,
    ARMOR2_BOOST,
    ENEMY_IDLE_4,
    ENEMY_HURT_4,
    ENEMY_ATTACK_4,
    ENEMY_IDLE_5,
    ENEMY_HURT_5,
    ENEMY_ATTACK_5,
    LOGO,
    BG_END,
    BAND_END_TOP,
    BAND_END_BOT,
} sprite_e;

typedef enum
{
    DEATH_MUSIC = 0,
    PNJ_SOUND,
    BG_MUSIC,
    VIVAALGERIE,
} music_e;

typedef enum
{
    PLAYER_TURN = 0,
    PLAYER_ATTACK,
    PLAYER_BOOST,
    ENEMY_ATTACK,
    REMOVE_ENEMY_HP,
    REMOVE_PLAYER_HP
} battle_status_e;

typedef struct mouse_s
{
    sfVector2i position;
    bool_t click;
    sfMouseButtonEvent pos_click;
} mouse_t;


typedef struct info_s
{
    scene_e scene;
    scene_e last_scene;
    mouse_t *mouse;
    double updateRest;
    sfView *view;
    bool_t music_bg;
    bool_t music;
    bool_t sound;
    bool_t trans;
    float volume;
    int res;
    int save;
} info_t;

typedef struct gui_s
{
    sfRenderWindow *window;
    sfClock *updateTimer;
    sfClock *dispTimer;
    sfMusic **music;
    info_t *info;
    player_t *player;
    inventory_t *inventory;
    csfml_object_t **object;
    csfml_text_t **text;
    sfImage *map;
    sfUint8 *buffer;
    sfColor map_check;
    char ***dialogue;
    battle_t *battle1;
    battle_t *battle2;
    battle_t *battle3;
    battle_t *battle4;
    battle_t *battle5;
    int diag;
    int stat_intro;
    int event;
    int adv;
    int lang;
} gui_t;

#endif //GAME_H
