/*
** msh_builtin.c for Minishell1 in /home/vassil_g/Minishell1
** 
** Made by vassil_g
** Login   <vassil_g@epitech.net>
** 
** Started on  Mon Feb  3 11:52:09 2014 vassil_g
** Last update Sun Mar  9 21:39:58 2014 vassil_g
*/

#include "my_msh.h"

void	     init_builtin(t_mysh_er (**func)(t_envp *envp, t_usr_entry *entry))
{
  func[BUILTIN_ENV - 1] = &msh_env;
  func[BUILTIN_SETENV - 1] = &msh_setenv;
  func[BUILTIN_UNSETENV - 1] = &msh_unsetenv;
  func[BUILTIN_CD - 1] = &msh_cd;
  func[BUILTIN_EXIT - 1] = &msh_exit;
  func[BUILTIN_GETENV -1] = &msh_getenv;
}

t_mysh_er    msh_builtin(t_mysh_er w_builtin, t_envp *envp, t_usr_entry *entry)
{
  t_mysh_er	(*func[6])(t_envp *envp, t_usr_entry *entry);

  init_builtin(func);
  if (w_builtin == BUILTIN_CLEAR)
    msh_clear();
  else
    return (func[w_builtin - 1](envp, entry));
  return (SUCCES);
}
