##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## makefile
##

SRC	=	src/game.c						\
		src/menu.c						\
		src/error.c						\
		src/window/window.c				\
		src/window/window2.c			\
		src/window/displays.c			\
		src/window/displays2.c			\
		src/set_objects/set.c			\
		src/set_objects/set2.c			\
		src/set_objects/set3.c			\
		src/set_objects/set4.c			\
		src/animations/anim_player.c	\
		src/animations/anim_back.c		\
		src/map_gestion/get_map.c		\
		src/map_gestion/reset_map.c		\
		src/map_gestion/collisions.c	\
		src/event/menu_event.c			\
		src/event/settings_event.c		\
		src/event/game_event.c

NAME	=	my_runner

OBJ	=	$(SRC:.c=.o)

MY	=	my.h

all:	exec_lib $(NAME)

exec_lib:
		cd lib/my/ && make

clean:
	rm -f $(OBJ)

$(NAME):	$(OBJ)
	gcc -o $(NAME) src/main.c $(OBJ) -Llib/ -lmy -lcsfml-graphics \
	-lcsfml-audio -lcsfml-system -lcsfml-window -g -Wparentheses \
	-Wsign-compare -Wpointer-sign -Wuninitialized -Wunused-but-set-variable

fclean: clean
	rm -f $(NAME)
	rm -f *.c~
	rm -f *.out
	rm -f vgcore*
	rm -f *.gcda
	rm -f *.gcno
	rm -f unit_tests*

lib_fclean:
		cd lib/my/ && make fclean

push_fclean: fclean
		cd lib/my/ && make fclean

re:	fclean all

tests_run: exec_lib
	gcc -o unit_tests $(SRC) tests/*.c -Llib/ -lmy --coverage -lcriterion
	./unit_tests
	gcovr --exclude tests
	gcovr -b --exclude tests
