/*
** process_entry.c for  in /home/vassil_g/rendu/42sh/Private/Src/Process
** 
** Made by vassil_g
** Login   <vassil_g@epitech.net>
** 
** Started on  Thu May 22 16:53:17 2014 vassil_g
** Last update Thu May 22 17:00:49 2014 vassil_g
*/

#include "mysh.h"

t_mysh_er		process_entry(t_sh_token *token, t_envp *envp)
{
  t_uint32	ret;

  if ((ret = get_exec_path(envp, token)))
    return (ret);
  return (msh_exec(token, envp));
}
