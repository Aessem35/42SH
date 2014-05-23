/*
** add_in_list.c for  in /home/vassil_g/rendu/42sh/Public/42SH/Vassil_g/Src
** 
** Made by vassil_g
** Login   <vassil_g@epitech.net>
** 
** Started on  Fri May 23 10:37:03 2014 vassil_g
** Last update Fri May 23 10:38:29 2014 vassil_g
*/

#include <stdlib.h>
#include "mysh.h"

t_mysh_er               add_in_list(t_envp *envp, char *name, t_uint32 nb)
{
  t_envl        *envl;
  t_envl        *tmp;

  tmp = envp->envl;
  if (!(envl = malloc(sizeof (t_envl))))
    return (MA_ERROR);
  while (tmp && tmp->next)
    tmp = tmp->next;
  envl->next = NULL;
  envl->name = name;
  envl->env_nb = nb;
  if (!(tmp))
    envp->envl = envl;
  else
    tmp->next = envl;
  return (SUCCES);
}
