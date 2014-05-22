/*
** msh_init_env.c for Minishell1 in /home/vassil_g/Minishell1/Source
** 
** Made by vassil_g
** Login   <vassil_g@epitech.net>
** 
** Started on  Mon Feb  3 14:17:00 2014 vassil_g
** Last update Thu May 22 17:16:39 2014 vassil_g
*/

#include <stdlib.h>
#include <string.h>
#include "mysh.h"


t_mysh_er		add_in_list(t_envp *envp, char *name, unsigned nb)
{
  t_envl	*envl;
  t_envl	*tmp;

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

t_mysh_er		env_cpy(t_envp *envp, char **env)
{
  unsigned int	len;
  unsigned int	i;

  len = my_addr_strlen(env);
  if (!(envp->env = malloc(sizeof (char *) * (len + 1))))
    return (MA_ERROR);
  envp->env[len] = NULL;
  len = 0;
  while (env[len])
    {
      i = 0;
      if (!(envp->env[len] = malloc(sizeof (char) * strlen(env[len]) + 1)))
	return (MA_ERROR);
      add_in_list(envp, envp->env[len], len);
      do
	envp->env[len][i] = env[len][i];
      while (env[len][i++]);
      ++len;
    }
  return (SUCCES);
}

t_mysh_er		msh_init_env(t_envp *envp, char **env)
{
  envp->envl = NULL;
  return (env_cpy(envp, env));
}
