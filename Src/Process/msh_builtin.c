/*
** msh_builtin.c for Minishell1 in /home/vassil_g/Minishell1
** 
** Made by vassil_g
** Login   <vassil_g@epitech.net>
** 
** Started on  Mon Feb  3 11:52:09 2014 vassil_g
** Last update Wed May 28 10:19:37 2014 vassil_g
*/

#include "mysh.h"

void	     init_builtin(t_mysh_er (**func)(t_envp *envp, t_sh_token *token))
{
  func[BUILTIN_ENV] = &msh_env;
  func[BUILTIN_SETENV] = &msh_setenv;
  func[BUILTIN_UNSETENV] = &msh_unsetenv;
  func[BUILTIN_CD] = &msh_cd;
  func[BUILTIN_EXIT] = &msh_exit;
  func[BUILTIN_GETENV] = &msh_getenv;
}

t_mysh_er    msh_builtin(t_struct_linker *job_list, t_int32 w_builtin,
			 t_sh_token *token, t_envp *envp)
{
  t_mysh_er	(*func[6])(t_envp *envp, t_sh_token *token);
  t_uint32	ret;

  ret = 0;
  init_builtin(func);
  if (w_builtin == BUILTIN_CLEAR)
    msh_clear();
  else
    add_to_job_list(job_list, ret = func[w_builtin](envp, token));
  return (ret);
}
