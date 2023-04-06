##
## EPITECH PROJECT, 2022
## test_map
## File description:
## Makefile
##

TARGET = myrpg

CFLAGS = -Wextra -Wall

LDFLAGS = -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-network -lcsfml-audio

CPPFLAGS = -I./include -I./csfml_engine/include

SRC = ./src/main.c \
	  ./src/map/map_create.c \
	  ./src/map/map_draw.c \
	  ./src/map/map_init.c \
	  ./src/graphic/graphic_draw.c \
	  ./src/graphic/graphic_init.c \
	  ./src/graphic/graphic_event.c \
	  ./src/utils/string.c \
	  ./src/utils/list.c \

OBJ = $(SRC:.c=.o)

all : $(TARGET)

$(TARGET) : $(OBJ)
	@$(CC) -o $(TARGET) $(OBJ) $(CFLAGS) $(LDFLAGS) -g3

clean :
	@$(RM) $(OBJ)

fclean : clean
	@$(RM) $(TARGET)

re : fclean all
