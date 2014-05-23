/*
** msh_getenv_l.c for  in /home/vassil_g/rendu/42sh/Public/42SH/Vassil_g/Src
** 
** Made by vassil_g
** Login   <vassil_g@epitech.net>
** 
** Started on  Fri May 23 10:36:13 2014 vassil_g
** Last update Fri May 23 16:10:50 2014 vassil_g
*/

#include <stdlib.h>
#include <string.h>
#include "mysh.h"

t_envl		*msh_getenv_l(t_envl *envl, char *name)
{
  while (envl)
    {
      if (strncmp(envl->name, name, strlen(name)) == 0)
	return (envl);
      envl = envl->next;
    }
  return (NULL);
}
