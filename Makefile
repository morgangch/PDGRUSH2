##
## EPITECH PROJECT, 2025
## Rush2
## File description:
## Makefile
##

name = execute

CFLAGS = -Wall -Wextra -std=gnu17

SRC = main_test/main.c \

OBJ = $(SRC:.c=.o)

all: $(name)

$(name): $(OBJ)
	$(CC) -o $(name) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(name)

re: fclean all
