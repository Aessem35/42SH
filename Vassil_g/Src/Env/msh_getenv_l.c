/*
** msh_getenv.c for Minishell1 in /home/vassil_g/Minishell1/Source
** 
** Made by vassil_g
** Login   <vassil_g@epitech.net>
** 
** Started on  Fri Feb  7 17:57:27 2014 vassil_g
** Last update Sat Feb  8 16:15:43 2014 vassil_g
*/

#include <stdlib.h>
#include "my_msh.h"

t_envl		*msh_getenv_l(t_envl *envl, char *name)
{
  while (envl)
    {
      if (my_env_strcpr_name(envl->name, name))
	return (envl);
      envl = envl->next;
    }
  return (NULL);
}
