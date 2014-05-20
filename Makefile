##
## Makefile for 42sh in /home/loteri_a/rendu/42sh/42SH
## 
## Made by 
## Login   <loteri_a@epitech.net>
## 
## Started on  Thu Apr 24 09:46:42 2014 
## Last update Tue May 20 14:30:04 2014 
##

NAME		=	42sh

SRC		=	SRC/42sh.c \
			SRC/buf_clean.c \
			SRC/exec.c \

OBJ		=	$(SRC:.c=.o)

CFLAGS		=	-Wall -Wextra

all		:	$(NAME) clean

$(NAME)		:	$(OBJ)
			cc -o $(NAME) $(OBJ)

clean		:
			rm -rf $(OBJ)

fclean		:	clean
			rm -rf $(NAME)

re		:	fclean all