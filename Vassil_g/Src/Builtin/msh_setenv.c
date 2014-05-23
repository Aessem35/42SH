/*
** msh_setenv.c for  in /home/vassil_g/rendu/42sh/Public/42SH/Vassil_g/Src/Builtin
** 
** Made by vassil_g
** Login   <vassil_g@epitech.net>
** 
** Started on  Fri May 23 10:33:47 2014 vassil_g
** Last update Fri May 23 10:33:48 2014 vassil_g
*/

#include <stdlib.h>
#include "mysh.h"

t_mysh_er		setenv_if_set(t_envp *envp, t_envl *envl, t_sh_token *token)
{
  if (!(envp->env[envl->env_nb] = append_str_var(token->str, token->next->str, '=')))
    return (MA_ERROR);
  free(envl->name);
  envl->name = envp->env[envl->env_nb];
  return (SUCCES);
}

t_mysh_er		new_env_variable(t_envp *envp, t_sh_token *token)
{
  t_uint32	len;
  t_uint32	i;
  t_envl	*envl;

  i = 0;
  envl = envp->envl;
  len = my_addr_strlen(envp->env);
  free(envp->env);
  if (!(envp->env = malloc(sizeof (char *) * (len + 2))))
    return (MA_ERROR);
  envp->env[len + 1] = NULL;
  envp->env[len] = append_str_var(token->str, token->next->str, '=');
  while (envl)
    {
      envp->env[i] = envl->name;
      ++i;
      envl = envl->next;
    }
  add_in_list(envp, envp->env[len], len);
  return (SUCCES);
}

t_mysh_er		msh_setenv(t_envp *envp, t_sh_token *token)
{
  t_envl	*envl;

  envl = envp->envl;
  if (token->up_size != 3)
    return (BI_SENV_USE);
  else if (!(envl = msh_getenv_l(envl, token->up->next->str)))
    return (new_env_variable(envp, token->up->next));
  else
    return (setenv_if_set(envp, envl, token->up->next));
}
