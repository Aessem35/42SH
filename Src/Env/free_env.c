/*
** free_env.c for  in /home/vassil_g/rendu/42sh/Private/Src/Env
** 
** Made by vassil_g
** Login   <vassil_g@epitech.net>
** 
** Started on  Wed May 21 13:34:23 2014 vassil_g
** Last update Fri May 23 15:49:51 2014 vassil_g
*/

#include <stdlib.h>
#include "mysh.h"

void            free_env(t_envp *envp)
{
  t_envl	*tmp;
  t_envl        *envl;
  t_uint32	i;

  envl = envp->envl;
  i = 0;
  while (envl)
    {
      tmp = envl;
      envl = envl->next;
      free(tmp);
    }
  while (envp->env[i])
    {
      free(envp->env[i]);
      ++i;
    }
  free(envp->env);
}
