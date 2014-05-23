/*
** msh_env.c for  in /home/vassil_g/rendu/42sh/Public/42SH/Vassil_g/Src/Builtin
** 
** Made by vassil_g
** Login   <vassil_g@epitech.net>
** 
** Started on  Fri May 23 10:06:53 2014 vassil_g
** Last update Fri May 23 10:07:09 2014 vassil_g
*/

#include <unistd.h>
#include <string.h>
#include "mysh.h"

t_mysh_er                  msh_env(t_envp *envp, t_sh_token *token)
{
  t_envl        *envl;
  t_uint32      n_w;

  envl = envp->envl;
  n_w = 0;
  if (token->up_size == 2)
    {
      if (strcmp(token->up->next->str, "-i") == 0)
        return (SUCCES);
      else if (strcmp(token->up->next->str, "-0") == 0)
        n_w = 1;
      else
        return (BI_ENV_USE);
    }
  while (envl)
    {
      write(1, envl->name, strlen(envl->name));
      envl = envl->next;
      if (!n_w)
        write(1, "\n", 1);
    }
  if (n_w)
    write(1, "\n", 1);
  return (SUCCES);
}

