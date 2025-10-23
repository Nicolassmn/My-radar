##
## EPITECH PROJECT, 2023
## header*
## File description:
## lolm
##

SRC     =	src/myradar.c						\
			src/my_strcmp.c						\
			src/aircraft.c						\
			src/parting.c						\
			src/description.c					\
			src/function.c						\
			src/colision.c						\
			src/plane.c							\
			src/str_to_double.c					\
			src/put_nbr_to_str.c				\
			src/my_atoi.c						\
			src/my_strdup.c						\
			src/clear_sprite.c					\
			src/poll_event.c					\
			src/my_str_to_word_array.c			\

OBJ		=	$(SRC:.c=.o)
NAME	=	myradar

CC		=	gcc
CFLAGS	=	-Wextra -Wall -W -I ./include/ -lm -g
CSFML	=	-lcsfml-graphics -lcsfml-system -lcsfml-audio -lcsfml-window

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(CFLAGS) $(CSFML)

clean:
	rm -f *.c~ $(OBJ)

fclean: clean
	rm -f $(NAME)

debug: CFLAGS += -g
debug: all

re: fclean all

.PHONY: all clean fclean re debug
