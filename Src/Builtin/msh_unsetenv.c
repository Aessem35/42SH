/*
** msh_unsetenv.c for  in /home/vassil_g/rendu/42sh/Public/42SH/Vassil_g/Src/Builtin
** 
** Made by vassil_g
** Login   <vassil_g@epitech.net>
** 
** Started on  Fri May 23 10:45:50 2014 vassil_g
** Last update Fri May 23 10:49:25 2014 vassil_g
*/

#include <string.h>
#include <stdlib.h>
#include "mysh.h"

t_mysh_er		unset_variable(t_envp *envp)
{
  t_envl	*envl;
  t_uint32	len;
  t_uint32	i;

  i = 0;
  envl = envp->envl;
  len = my_addr_strlen(envp->env) - 1;
  free(envp->env);
  if (!(envp->env = malloc(sizeof (char *) * (len + 1))))
    return (MA_ERROR);
  envp->env[len] = NULL;
  while (i < len)
    {
      envl->env_nb = i;
      envp->env[i] = envl->name;
      ++i;
      envl = envl->next;
    }
  return (SUCCES);
}

t_mysh_er		msh_unsetenv(t_envp *envp, t_sh_token *token)
{
  t_envl	*envl;
  t_envl	*tmp;

  if (token->up_size != 2)
    return (BI_UENV_USE);
  envl = envp->envl;
  while (envl)
    {
      if (strncmp(envl->name, token->up->next->str, strlen(token->up->next->str)) == 0)
	{
	  if (envl->env_nb == 0)
	    envp->envl = envp->envl->next;
	  tmp->next = envl->next;
	  free(envl->name);
	  free(envl);
	  return (unset_variable(envp));
	}
      tmp = envl;
      envl = envl->next;
    }
  return (BI_UENV_NF);
}
