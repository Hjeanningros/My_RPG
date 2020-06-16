##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile Defender
##

REDDARK=\033[31;2m
RED=\033[31;1m
GREEN=\033[32;1m
YEL=\033[33;1m
BLUE=\033[34;1m
PINK=\033[35;1m
CYAN=\033[36;1m
RES=\033[0m

SRC =	src/main.c 								\
		src/init/init_gui.c 					\
		src/init/init_music.c 					\
		src/init/init_image.c 					\
		src/init/init_battle.c 					\
		src/init/init_menu.c					\
		src/init/init_text.c 					\
		src/init/init_player.c 					\
		src/init/init_forest.c 					\
		src/init/init_intro.c 					\
		src/init/init_end.c 					\
		src/init/init_particles.c 				\
		src/scenes/scene_manager.c 				\
		src/scenes/battle.c 					\
		src/scenes/death.c 						\
		src/scenes/menu.c 						\
		src/scenes/intro.c 						\
		src/scenes/end.c 						\
		src/utils/display.c 					\
		src/utils/load_save.c 					\
		src/utils/write_save.c 					\
		src/utils/write_save_sec.c 				\
		src/utils/particles.c 					\
		src/utils/draw_particles.c 				\
		src/utils/getline.c 					\
		src/utils/int_to_str.c 					\
		src/utils/my_get_nbr.c					\
		src/utils/button/button_play.c			\
		src/utils/button/button_quit.c			\
		src/utils/button/button_settings.c		\
		src/utils/parallax.c					\
		src/utils/transition.c					\
		src/utils/button/button_mouse.c			\
		src/init/init_settings.c				\
		src/scenes/settings.c					\
		src/scenes/forest.c						\
		src/utils/button/button_sound.c			\
		src/utils/button/button_battle.c		\
		src/utils/button/button_volume.c		\
		src/utils/button/button_music.c			\
		src/utils/button/button_res.c			\
		src/utils/button/button_back.c			\
		src/utils/my_str_to_word_array.c 		\
		src/utils/open_file.c					\
		src/utils/display_dialogue.c			\
		src/utils/inventory_stuff.c			\
		src/utils/player_mvt.c					\
		src/utils/move_rect.c					\
		src/utils/change_opasity.c				\
		src/utils/can_speak.c				\
		src/utils/eng_and_fr.c					\
		src/utils/tab_len.c						\
		src/battle1/update_player.c				\
		src/battle1/update_status.c				\
		src/battle1/update_enemy.c				\
		src/battle1/display_status.c			\
		src/utils/check_pixel.c					\
		src/utils/speak_to_pnj.c				\
		src/init/init_inventory.c				\
		src/scenes/inventory.c					\
		src/utils/my_strcat.c					\
		src/utils/my_strlen.c					\
		src/utils/event_forest.c				\
		src/utils/part_intro.c					\
		src/scenes/pause.c						\
		src/utils/button/button_pause.c			\
		src/init/init_pause.c					\
		src/scenes/keys.c						\
		src/init/init_save.c					\
		src/scenes/save.c						\
		src/utils/button/button_save.c			\
		src/init/init_choose_language.c			\
		src/scenes/choose_language.c			\
		src/scenes/first_battle.c				\
		src/init/init_first_battle.c			\
		src/scenes/second_battle.c				\
		src/init/init_second_battle.c			\
		src/battle2/update_player.c				\
		src/battle2/update_status.c				\
		src/battle2/update_enemy.c				\
		src/battle2/display_status.c			\
		src/scenes/third_battle.c				\
		src/init/init_third_battle.c			\
		src/battle3/update_player.c				\
		src/battle3/update_status.c				\
		src/battle3/update_enemy.c				\
		src/battle3/display_status.c			\
		src/scenes/fourth_battle.c				\
		src/init/init_fourth_battle.c			\
		src/battle4/update_player.c				\
		src/battle4/update_status.c				\
		src/battle4/update_enemy.c				\
		src/battle4/display_status.c			\
		src/scenes/final_battle.c				\
		src/init/init_final_battle.c			\
		src/battle5/update_player.c				\
		src/battle5/update_status.c				\
		src/battle5/update_enemy.c				\
		src/battle5/display_status.c			\
		src/utils/black_bar_end.c				\
		src/utils/music_end.c					\
		src/utils/setting_function.c			\
		src/utils/my_putstr.c


OBJ = $(SRC:.c=.o)

NAME = my_rpg


$(NAME):	$(OBJ)
	gcc -o $(NAME) $(SRC) -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -g
	@echo -e "$(RED)$(NAME) $(GREEN)[✘]$(RES)"

all: 	$(NAME)

clean:
	rm -f $(OBJ)


fclean: clean
		rm -f $(NAME)

re:		fclean all