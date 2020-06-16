/*
** EPITECH PROJECT, 2018
** game.h
** File description:
** game.h for Defender
*/

#ifndef PROTOTYPE_H
#define PROTOTYPE_H

#include "game.h"

//init
int init_music(gui_t *);

// sceneManager
int loop_global(gui_t *);

//tools
void displayer(sfRenderWindow *, csfml_object_t *);
void move_parallax(gui_t *);
char **my_str_to_word_array(char *, char);
char *open_file(const char *);
int load_scenes(gui_t *);
int load_save(gui_t *);
int my_getnbr(char const *);
int my_intlen(int);
int write_in_save(gui_t *);
int display_dialogue(int, gui_t *);
char *int_to_str(int);
void move_rect(csfml_object_t *);
void logo(gui_t *);
void write_norme(gui_t *, int);
void write_norme_sec(gui_t *, int);
void write_norme_forth(gui_t *, int);
void write_norme_third(gui_t *, int);
int player_mvt(gui_t *, csfml_object_t *);
int tab_len(char **);
int check_colision(gui_t *game, unsigned int x, unsigned int y);
void transition(gui_t *);
int check_opasity(gui_t *game, unsigned int x, unsigned int y);
int check_pnj(gui_t *game, unsigned int x, unsigned int y);
int speak_to_pnj(gui_t *game);
char *my_strcat(char *str1, char *str2);
unsigned int my_strlen(char const *str);
void b_english(gui_t *, sfMouseButtonEvent);
void b_french(gui_t *, sfMouseButtonEvent);
void switch_scene_and_get_click(gui_t *, sfEvent);
void click_to_speak(gui_t *, sfEvent);
void event_mvt(gui_t *, sfEvent);
void check_fight(gui_t *);
void first_part_intro(gui_t *game);
void second_part_intro(gui_t *game);
void b_armor1(gui_t *game, sfMouseButtonEvent e);
void b_potion(gui_t *game, sfMouseButtonEvent e);
void b_armor2(gui_t *game, sfMouseButtonEvent e);
void update_text_inv(gui_t *game);
int end_black_bar(gui_t *game);
int music_end(gui_t *game);
int setting_button(gui_t *game, sfEvent e);
void change_opasity(gui_t *g);
void can_speak(gui_t *game);
void my_putstr(char const *str);

//particles
void set(sfUint8 *pixel, sfUint8 red, sfUint8 green, sfUint8 blue);
void copy(sfUint8 *from, sfUint8 *to);
bool check(sfUint8 *pixel, sfUint8 red, sfUint8 green, sfUint8 blue);
void les_braiz(sfUint8 *buffer, size_t i);
void draw_particles(sfRenderWindow *win, sfUint8 *buffer);
void update_particles(gui_t *);

//buttons
void b_play(gui_t *, sfMouseButtonEvent);
void b_quit(gui_t *, sfMouseButtonEvent);
void b_settings(gui_t *, sfMouseButtonEvent);
void b_mouse(gui_t *, csfml_object_t *);
void b_on_off_music(gui_t *, csfml_object_t *, sfMouseButtonEvent);
void b_on_off_sound(gui_t *, csfml_object_t *, sfMouseButtonEvent);
void b_plus_mouse(gui_t *, csfml_object_t *);
void b_minus_mouse(gui_t *, csfml_object_t *);
void b_plus_music(gui_t *, csfml_object_t *, sfMouseButtonEvent);
void b_minus_music(gui_t *, csfml_object_t *, sfMouseButtonEvent);
void button_x2(gui_t *, csfml_object_t *, sfMouseButtonEvent);
void button_x4(gui_t *, csfml_object_t *, sfMouseButtonEvent);
void button_x8(gui_t *, csfml_object_t *, sfMouseButtonEvent);
int button_back(gui_t *, csfml_object_t *);
void b_attack(gui_t *game, sfMouseButtonEvent e, battle_t *battle);
void b_boostattack(gui_t *game, sfMouseButtonEvent e, battle_t *battle);
void b_escape(gui_t *game, sfMouseButtonEvent e, battle_t *battle);
void b_resume(gui_t *game, sfMouseButtonEvent e);
void b_keyp(gui_t *game, sfMouseButtonEvent e);
void b_settingsp(gui_t *game, sfMouseButtonEvent e);
void b_quitp(gui_t *game, sfMouseButtonEvent e);
void b_key(gui_t *game, sfMouseButtonEvent e);
void b_back(gui_t *game, csfml_object_t *object, sfMouseButtonEvent e);
int button_back_rules(gui_t *game, csfml_object_t *object);
void b_save1(gui_t *game, sfMouseButtonEvent e);
void b_save2(gui_t *game, sfMouseButtonEvent e);
void b_save3(gui_t *game, sfMouseButtonEvent e);

//battle1
int update_player_turn(gui_t *);
int update_player_attack2(gui_t *);
int update_player_attack(gui_t *);
int update_player_boost2(gui_t *);
int update_player_boost(gui_t *);
int update_different_status(gui_t *);
int display_player_turn(gui_t *);
int display_player_attack(gui_t *);
int display_player_boost(gui_t *);
int displayer_enemy_attack(gui_t *);
int display_status(gui_t *);
int update_enemy_attack2(gui_t *);
int update_enemy_attack(gui_t *);
int update_remove_enemy_hp(gui_t *);
int reset_battle_player_die(gui_t *);
int update_player_hp(gui_t *);
int reset_win_1(gui_t *game);

//battle2
int update_player_turn_2(gui_t *);
int update_player_attack2_2(gui_t *);
int update_player_attack_2(gui_t *);
int update_player_boost2_2(gui_t *);
int update_player_boost_2(gui_t *);
int update_different_status_2(gui_t *);
int display_player_turn_2(gui_t *);
int display_player_attack_2(gui_t *);
int display_player_boost_2(gui_t *);
int displayer_enemy_attack_2(gui_t *);
int display_status_2(gui_t *);
int update_enemy_attack2_2(gui_t *);
int update_enemy_attack_2(gui_t *);
int update_remove_enemy_hp_2(gui_t *);
int reset_battle_player_die_2(gui_t *);
int update_player_hp_2(gui_t *);
int reset_win_2(gui_t *game);

//battle3
int update_player_turn_3(gui_t *);
int update_player_attack3_2(gui_t *);
int update_player_attack_3(gui_t *);
int update_player_boost3_2(gui_t *);
int update_player_boost_3(gui_t *);
int update_different_status_3(gui_t *);
int display_player_turn_3(gui_t *);
int display_player_attack_3(gui_t *);
int display_player_boost_3(gui_t *);
int displayer_enemy_attack_3(gui_t *);
int display_status_3(gui_t *);
int update_enemy_attack3_2(gui_t *);
int update_enemy_attack_3(gui_t *);
int update_remove_enemy_hp_3(gui_t *);
int reset_battle_player_die_3(gui_t *);
int update_player_hp_3(gui_t *);
int reset_win_3(gui_t *game);

//battle4
int update_player_turn_4(gui_t *);
int update_player_attack4_2(gui_t *);
int update_player_attack_4(gui_t *);
int update_player_boost4_2(gui_t *);
int update_player_boost_4(gui_t *);
int update_different_status_4(gui_t *);
int display_player_turn_4(gui_t *);
int display_player_attack_4(gui_t *);
int display_player_boost_4(gui_t *);
int displayer_enemy_attack_4(gui_t *);
int display_status_4(gui_t *);
int update_enemy_attack4_2(gui_t *);
int update_enemy_attack_4(gui_t *);
int update_remove_enemy_hp_4(gui_t *);
int reset_battle_player_die_4(gui_t *);
int update_player_hp_4(gui_t *);
int reset_win_4(gui_t *game);

//battle5
int update_player_turn_5(gui_t *);
int update_player_attack5_2(gui_t *);
int update_player_attack_5(gui_t *);
int update_player_boost5_2(gui_t *);
int update_player_boost_5(gui_t *);
int update_different_status_5(gui_t *);
int display_player_turn_5(gui_t *);
int display_player_attack_5(gui_t *);
int display_player_boost_5(gui_t *);
int displayer_enemy_attack_5(gui_t *);
int display_status_5(gui_t *);
int update_enemy_attack5_2(gui_t *);
int update_enemy_attack_5(gui_t *);
int update_remove_enemy_hp_5(gui_t *);
int reset_battle_player_die_5(gui_t *);
int update_player_hp_5(gui_t *);
int reset_win_5(gui_t *game);

// destroy


//text

#endif //PROTOTYPE_H
