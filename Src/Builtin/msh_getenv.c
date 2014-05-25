/*
** msh_getenv.c for  in /home/vassil_g/rendu/42sh/Public/42SH/Vassil_g/Src/Builtin
** 
** Made by vassil_g
** Login   <vassil_g@epitech.net>
** 
** Started on  Fri May 23 10:19:30 2014 vassil_g
** Last update Sun May 25 20:16:52 2014 vassil_g
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "mysh.h"

t_mysh_er		msh_getenv(t_envp *envp, t_sh_token *token)
{
  t_envl	*envl;

  envl = envp->envl;
  if (token->up_size != 2)
    return (SUCCES);
  while (envl)
    {
      if (strncmp(envl->name, token->up->next->str,
		  strlen(token->up->next->str)) == 0)
	{
	  printf("%s\n", envl->name);
	  return (SUCCES);
	}
      envl = envl->next;
    }
  return (BI_UENV_NF);
}
