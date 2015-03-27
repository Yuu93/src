##
## Makefile for Project in /home/messao_y//Directory
## 
## Made by antoine coskun
## Login   <messao_y@epitech.net>
## 
## Started on  Fri Nov  9 11:30:12 2012 antoine coskun
## Last update Thu Jul 10 05:17:53 2014 messao_y
##

SRC= main.c \
	 init_co.c \
	 init_map.c \
	 getnextline.c \
	 actions.c \
	 graphic.c \
	 print.c \
	 printcell.c \
	 my_str_to_wordtab.c

NAME=    clientg

OBJ=	 $(SRC:.c=.o)

CC=	 gcc -Wall -W -Wshadow -g

LDFLAGS= -lSDL -lSDL_gfx -lSDL_image -lSDL_ttf

RM=	 rm -f

all:	 $(NAME)

re:	 fclean all

$(NAME): $(OBJ)
	 $(CC) $(OBJ) -o $(NAME) $(LDFLAGS)

clean:
	 rm -f $(OBJ)

fclean:		clean
	 rm -f $(NAME)

.PHONY: all clean fclean re
