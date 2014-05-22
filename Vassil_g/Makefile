##
## Makefile for  in /home/vassil_g/rendu/42sh/Private
## 
## Made by vassil_g
## Login   <vassil_g@epitech.net>
## 
## Started on  Tue May 20 15:51:02 2014 vassil_g
## Last update Thu May 22 17:03:18 2014 vassil_g
##

NAME		= test

SRC		= Src/
PARSER		= $(SRC)Parser/
COMMON		= $(SRC)Common/
ENTRY		= $(SRC)Entry/
MAIN		= $(SRC)Main/
ENV		= $(SRC)Env/
PROCESS		= $(SRC)Process/

FILE		= $(MAIN)main.c \
		$(MAIN)42sh.c \
		$(SRC)print_token.c \
		$(COMMON)free_sh_token.c \
		$(COMMON)init_linker.c \
		$(COMMON)insert_struct.c \
		$(COMMON)my_addr_strlen.c \
		$(COMMON)tokenize.c \
		$(COMMON)free_token.c \
		$(ENTRY)entry.c \
		$(PARSER)new_sh_token.c \
		$(PARSER)p_main.c \
		$(PARSER)tokenize_lex.c \
		$(PARSER)tokenize_param.c \
		$(PARSER)get_next_line.c \
		$(ENV)msh_init_env.c \
		$(ENV)free_env.c \
		$(ENV)msh_getenv_v.c \
		$(PROCESS)get_exec_path.c \
		$(PROCESS)msh_exec.c \
		$(PROCESS)process_entry.c \

OBJ		= $(FILE:.c=.o)

CFLAGS		= -I Inc/
CFLAGS		+= -g3
CFLAGS		+= -Wextra -Wall

CC		= gcc
RM		= rm -vf

all		: $(NAME)

$(NAME)		: $(OBJ)
		@($(CC) -o $(NAME) $(OBJ) $(CFLAGS))

clean		:
		@($(RM) $(OBJ))

fclean		: clean
		@($(RM) $(NAME))

re		: fclean all
