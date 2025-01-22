##
## EPITECH PROJECT, 2025
## Rush2
## File description:
## Makefile
##

name = execute
test_name = unit_tests

CFLAGS = -Wall -Wextra -std=gnu17 -Iinclude

SRC = main_test/main.c \
	new.c \
	player.c \
	point.c \
	vertex.c \
	int.c \
	array.c \
	char.c \
	float.c \
	list.c \

TESTSRC = $(wildcard tests/*.c) \
		new.c \
		player.c \
		point.c \
		vertex.c \
		int.c \
		array.c \
		char.c \
		float.c \

OBJ = $(SRC:.c=.o)
TESTOBJ = $(TESTSRC:.c=.o)

all: $(name)

$(name): $(OBJ)
	$(CC) -o $(name) $(OBJ)

clean:
	$(RM) $(OBJ) $(TESTOBJ)

fclean: clean
	$(RM) $(name) $(test_name) *.gc*

re: fclean all

tests_run:
	$(CC) -o $(test_name) $(TESTSRC) --coverage -lcriterion $(CFLAGS)
	./$(test_name)
	gcovr --exclude tests/

tests_re: fclean tests_run

.PHONY: all clean fclean re tests_run