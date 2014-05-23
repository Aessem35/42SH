/*
** msh_unsetenv.c for Minishell1 in /home/vassil_g/Minishell1/Source/Builtin
** 
** Made by vassil_g
** Login   <vassil_g@epitech.net>
** 
** Started on  Mon Feb  3 12:03:21 2014 vassil_g
** Last update Mon Feb 10 19:04:02 2014 vassil_g
*/

#include <stdlib.h>
#include "my.h"
#include "my_msh.h"

t_mysh_er		unset_variable(t_envp *envp)
{
  t_envl	*envl;
  unsigned	len;
  unsigned	i;

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
  return (SUCCESS);
}

t_mysh_er		msh_unsetenv(t_envp *envp, t_usr_entry *entry)
{
  t_envl	*envl;
  t_envl	*tmp;

  if (!entry->arg[1])
    return (BI_UENV_USE);
  envl = envp->envl;
  while (envl)
    {
      if (my_env_strcpr_name(envl->name, entry->arg[1]))
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
