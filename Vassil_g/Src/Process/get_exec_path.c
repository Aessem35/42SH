/*
** get_exec_path.c for  in /home/vassil_g/rendu/42sh/Private/Src/Process
** 
** Made by vassil_g
** Login   <vassil_g@epitech.net>
** 
** Started on  Thu May 22 16:42:49 2014 vassil_g
** Last update Fri May 23 10:29:47 2014 vassil_g
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "mysh.h"

/*
t_mysh_er			check_builtin(char *cmd)
{
  if (my_str_cpr(cmd, "env"))
    return (BUILTIN_ENV);
  else if (my_str_cpr(cmd, "cd"))
    return (BUILTIN_CD);
  else if (my_str_cpr(cmd, "setenv"))
    return (BUILTIN_SETENV);
  else if (my_str_cpr(cmd, "unsetenv"))
    return (BUILTIN_UNSETENV);
  else if (my_str_cpr(cmd, "clear"))
    return (BUILTIN_CLEAR);
  else if (my_str_cpr(cmd, "exit"))
    return (BUILTIN_EXIT);
  else if (my_str_cpr(cmd, "getenv"))
    return (BUILTIN_GETENV);
  return (SUCCES);
}
*/

char	       		*check_path(t_token *path_list, char *cmd)
{
  struct stat	buff;
  char		*test;

  while (path_list)
    {
      test = append_str_var(path_list->str, cmd, '/');
      if (stat(test, &buff) == 0)
	return (test);
      free(test);
      path_list = path_list->next;
    }
  return (NULL);
}

t_mysh_er		check_exec(t_envp *envp, t_sh_token *entry)
{
  t_token	*path_list;
  char		*path;
  char		*tmp;

  if (!(path = msh_getenv_v(envp->envl, "PATH"))) //|| !*path) ??
    return (EXEC_NOPATH);
  if (!(path_list = tokenize(NULL, path, ":", SIMPLE | END)))
    return (MA_ERROR);
  if ((tmp = check_path(path_list, entry->up->str)))
    {
      free(entry->str);
      entry->str = tmp;
      free_token(path_list);
      return (SUCCES);
    }
  free_token(path_list);
  return (EXEC_NF);
}

t_mysh_er	       	get_exec_path(t_envp *envp, t_sh_token *token)
{
  t_mysh_er	builtin;

  /*  if ((builtin = check_builtin(entry->cmd)) > 0) Nothing to do there
      return (builtin); */
  if (!token || !token->up || !token->up->str)
    return (EXEC_NF);
  return (check_exec(envp, token));
}
