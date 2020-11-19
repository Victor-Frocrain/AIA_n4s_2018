##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC	=	sources/strstr.c		\
		sources/need_for_steak.c	\
		sources/str_to_word.c		\
		sources/manage_turn.c		\
		sources/manage_speed.c		\

SRC_MAIN=	sources/main.c		\

SRC_TEST=	tests/

OBJ	=	$(SRC:%.c=%.o) $(SRC_MAIN:%.c=%.o)

NAME	=	ai

TEST_NAME=	unit_tests

CFLAGS	=	-I ./include/ -W -Wall -Wextra -Wshadow

CC	=	gcc

TEST_FLAGS=	-lcriterion --coverage

LDFLAGS	=	-L lib/ -lmy -lmy-printf -lget-next-line

RM	=	rm -f

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C lib/my
	make -C lib/my_printf
	make -C lib/get_next_line
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	make -C lib/my clean
	make -C lib/my_printf clean
	make -C lib/get_next_line clean
	$(RM) $(OBJ)

fclean:		clean
	make -C lib/my fclean
	make -C lib/my_printf fclean
	make -C lib/get_next_line fclean
	$(RM) $(NAME)
	$(RM) $(TEST_NAME)

re:		fclean all

tests_run:
	make -C lib/my/
	make -C lib/my_printf/
	$(CC) -o $(TEST_NAME) -I include $(SRC_TEST) $(SRC) $(TEST_FLAGS) $(LDFLAGS)
	./$(TEST_NAME)
	gcovr --exclude tests
