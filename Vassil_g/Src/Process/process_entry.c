/*
** process_entry.c for  in /home/vassil_g/rendu/42sh/Private/Src/Process
** 
** Made by vassil_g
** Login   <vassil_g@epitech.net>
** 
** Started on  Thu May 22 16:53:17 2014 vassil_g
** Last update Fri May 23 11:29:25 2014 vassil_g
*/

#include <string.h>
#include "mysh.h"

/*
** Mode dégeulasse
*/
t_int32			check_if_builtin(char *str)
{
  if (strcmp(str, "env") == 0)
    return (0);
  if (strcmp(str, "exit") == 0)
    return (1);
  if (strcmp(str, "getenv") == 0)
    return (2);
  if (strcmp(str, "setenv") == 0)
    return (3);
  if (strcmp(str, "unsetenv") == 0)
    return (4);
  if (strcmp(str, "cd") == 0)
    return (5);
  if (strcmp(str, "clear") == 0)
    return (6);
  return (-1);
}

t_mysh_er		exec_builtin(t_sh_token *token, t_envp *envp, t_int32 n)
{
  if (n == 0)
    return (msh_env(envp, token));
  if (n == 1)
    return (msh_exit(envp, token));
  if (n == 2)
    return (msh_getenv(envp, token));
  if (n == 3)
    return (msh_setenv(envp, token));
  if (n == 4)
    return (msh_unsetenv(envp, token));
  if (n == 5)
    return (msh_cd(envp, token));
  if (n == 6)
    msh_clear();
  return (SUCCES);
}

t_mysh_er		process_entry(t_sh_token *token, t_envp *envp)
{
  t_int32	ret;

  if ((ret = check_if_builtin(token->up->str)) >= 0)
    return (exec_builtin(token, envp, ret));
  else if ((ret = get_exec_path(envp, token)))
    return (ret);
  else
    return (msh_exec(token, envp));
}
