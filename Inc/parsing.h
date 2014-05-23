/*
** Parsing.h for  in /home/vassil_g/rendu/42sh/Private/Inc
** 
** Made by vassil_g
** Login   <vassil_g@epitech.net>
** 
** Started on  Tue May 20 11:00:45 2014 vassil_g
** Last update Thu May 22 15:54:53 2014 vassil_g
*/

#ifndef PARSING_H_
# define PARSING_H_

#include "my_types.h"

#define P_PIPE_F	(1 << 0)
#define P_PIPE_S	("|")

#define P_SDIR_F	(1 << 1)
#define P_SDIR_S	(">")

#define P_DDIR_F	(1 << 2)
#define P_DDIR_S	(">>")

#define P_SDIL_F	(1 << 3)
#define P_SDIL_S	("<")

#define P_OR_F		(1 << 4)
#define	P_OR_S		("||")

#define LEX_NB		5

#define	P_MAGIC_F	(1 << 5)
#define P_MAGIC_C	('`')
#define P_QUOT		('"')

typedef	struct	s_lexic
{
  char			*string;
  t_uint32		flag;
}t_lexic;

typedef struct	s_glob_def
{
  t_lexic		*lexic;
  t_lexic		*param;
}t_glob_def;

typedef	struct	s_sh_token	t_sh_token;
struct	s_sh_token
{
  t_sh_token		*next;
  t_sh_token		*up;
  t_uint32		up_size;
  char			*str;
  t_uint32		flag;
};

typedef	struct	s_any_struct	t_any_struct;
struct	s_any_struct
{
  t_any_struct		*next;
  t_any_struct		*prev;
};

typedef	struct	s_struct_linker	t_struct_linker;
struct	s_struct_linker
{
  t_any_struct		*first;
  t_any_struct		*last;
  t_uint32		size;
};


#define	SIMPLE		(1 << 0)
#define	DOUBLE		(1 << 1)
#define BEG		(1 << 2)
#define END		(1 << 3)

t_uint32		insert_struct(t_struct_linker *, t_any_struct *, t_uint32 mode);
t_sh_token		*new_sh_token(char *, char *, t_uint32);
t_sh_token		*tokenize_lex(char *, t_glob_def *, char);
t_uint32		tokenize_param(t_struct_linker *, t_glob_def *, char *, char *);
char			*entry();
t_sh_token		*parser(char *, t_glob_def *, char );
char			*get_next_line(const int);
void			init_linker(t_struct_linker *);


#endif /*!PARSING_H_*/
