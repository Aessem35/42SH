/*
** msh_getenv_v.c for  in /home/vassil_g/rendu/42sh/Private/Src/Env
** 
** Made by vassil_g
** Login   <vassil_g@epitech.net>
** 
** Started on  Thu May 22 16:45:56 2014 vassil_g
** Last update Thu May 22 17:16:37 2014 vassil_g
*/

#include <stdlib.h>
#include <string.h>
#include "mysh.h"

char		*msh_getenv_v(t_envl *envl, char *name)
{
  while (envl)
    {
      if (strncmp(envl->name, name, strlen(name)) == 0)
	  return (envl->name + strlen(name) + 1);
      envl = envl->next;
    }
  return (NULL);
}
