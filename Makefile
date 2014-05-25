##
## Makefile for  in /home/vassil_g/rendu/42sh/Public/42SH/Vassil_g
## 
## Made by vassil_g
## Login   <vassil_g@epitech.net>
## 
## Started on  Thu May 22 18:11:44 2014 vassil_g
## Last update Sun May 25 23:04:17 2014 vassil_g
## Last update Sun May 25 21:57:34 2014 richar_2
##

NAME		= 42sh

SRC		= Src/
PARSER		= $(SRC)Parser/
COMMON		= $(SRC)Common/
ENTRY		= $(SRC)Entry/
MAIN		= $(SRC)Main/
ENV		= $(SRC)Env/
PROCESS		= $(SRC)Process/
BUILTIN		= $(SRC)Builtin/

FILE		= $(MAIN)main.c \
		$(MAIN)42sh.c \
		$(MAIN)msh_error.c \
		$(MAIN)signal_handler.c \
		$(COMMON)free_sh_token.c \
		$(COMMON)init_linker.c \
		$(COMMON)insert_struct.c \
		$(COMMON)my_addr_strlen.c \
		$(COMMON)tokenize.c \
		$(COMMON)free_token.c \
		$(COMMON)free_glob_def.c \
		$(COMMON)append_str_var.c \
		$(ENTRY)entry.c \
		$(PARSER)new_sh_token.c \
		$(PARSER)p_main.c \
		$(PARSER)tokenize_lex.c \
		$(PARSER)tokenize_param.c \
		$(PARSER)getnext_c.c \
		$(PARSER)get_next_line.c \
		$(ENV)msh_init_env.c \
		$(ENV)free_env.c \
		$(ENV)msh_getenv_v.c \
		$(ENV)add_in_list.c \
		$(ENV)msh_getenv_l.c \
		$(PROCESS)get_exec_path.c \
		$(PROCESS)msh_exec.c \
		$(PROCESS)process_entry.c \
		$(PROCESS)msh_builtin.c \
		$(PROCESS)test_job.c \
		$(PROCESS)add_to_job_l.c \
		$(PROCESS)free_jobs.c \
		$(PROCESS)check_if_builtin.c \
		$(BUILTIN)msh_env.c \
		$(BUILTIN)msh_exit.c \
		$(BUILTIN)msh_clear.c \
		$(BUILTIN)msh_getenv.c \
		$(BUILTIN)msh_setenv.c \
		$(BUILTIN)msh_unsetenv.c \
		$(BUILTIN)msh_cd.c \
		$(BUILTIN)epure_path.c \

OBJ		= $(FILE:.c=.o)

CFLAGS		= -I Inc/
CFLAGS		+= -Wall -Wextra

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
