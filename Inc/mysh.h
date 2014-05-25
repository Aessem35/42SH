/*
** mysh.h for  in /home/vassil_g/rendu/42sh/Private/Inc
** 
** Made by vassil_g
** Login   <vassil_g@epitech.net>
** 
** Started on  Wed May 21 12:52:58 2014 vassil_g
** Last update Sun May 25 20:35:34 2014 vassil_g
*/

#ifndef MYSH_H_
# define MYSH_H_

#include "msh_er.h"
#include "parsing.h"

#define BUILTIN_ENV	(0)
#define BUILTIN_EXIT	(1)
#define BUILTIN_GETENV	(2)
#define BUILTIN_SETENV	(3)
#define BUILTIN_CD	(4)
#define BUILTIN_UNSETENV (5)
#define BUILTIN_CLEAR	(6)

typedef t_uint32	t_mysh_er;

typedef struct s_envl	t_envl;
struct s_envl
{
  t_envl		*next;
  char                  *name;
  char                  *value;
  unsigned int          env_nb;
};

typedef struct s_envp
{
  char                  **env;
  t_envl                *envl;
}t_envp;

typedef struct s_job	t_job;
struct s_job
{
  t_job			*next;
  t_job			*prev;
  int			signal;
};

typedef	struct s_token	t_token;
struct s_token
{
  t_token		*next;
  t_token		*prev;
  char			*str;
};

/*
** SRC/MAIN
*/
void			mysh(char **);

/*
** SRC/ENV
*/
t_mysh_er               msh_init_env(t_envp *, char **);
t_envl                  *msh_getenv_l(t_envl *, char *);
char                    *msh_getenv_v(t_envl *, char *);
t_mysh_er		add_in_list(t_envp *, char *, t_uint32);
void                    free_env(t_envp *);
t_sh_token		*parsed_entry(t_glob_def *);
void			print_token(t_sh_token *);

/*
** SRC/COMMON
*/
char                    *append_str_var(char *, char *, char);
t_uint32		my_addr_strlen(char **);
void			free_token(t_token *);
void			free_sh_token(t_sh_token *);
void			free_glob_def(t_glob_def *);
t_token			*tokenize(t_struct_linker *, char *, char *, t_uint32);

/*
** SRC/PROCESS
*/
void			process_entry(t_sh_token *, t_envp *);
t_mysh_er		get_exec_path(t_envp *, t_sh_token *);
t_mysh_er		msh_exec(t_struct_linker *, t_sh_token *, t_envp *);
t_uint32		test_job(t_struct_linker *, t_uint32);
t_mysh_er		add_to_job_list(t_struct_linker *, int);
t_mysh_er		msh_builtin(t_struct_linker *, t_int32, t_sh_token *, t_envp *);
void			free_jobs(t_job *);
t_int32			check_if_builtin(char *);
void			msh_error(t_mysh_er, t_sh_token *);

/*
** SRC/BUILTIN
*/
t_mysh_er		msh_env(t_envp *, t_sh_token *);
t_mysh_er		msh_exit(t_envp *, t_sh_token *);
t_mysh_er		msh_getenv(t_envp *, t_sh_token *);
t_mysh_er		msh_setenv(t_envp *, t_sh_token *);
t_mysh_er		msh_unsetenv(t_envp *, t_sh_token *);
t_mysh_er		msh_cd(t_envp *, t_sh_token *);
void			msh_clear();
char			*epure_path(char *);

#endif /*!MYSH_H_*/
