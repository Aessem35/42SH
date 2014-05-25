/*
** process_entry.c for  in /home/vassil_g/rendu/42sh/Private/Src/Process
** 
** Made by vassil_g
** Login   <vassil_g@epitech.net>
** 
** Started on  Thu May 22 16:53:17 2014 vassil_g
** Last update Sun May 25 20:13:29 2014 vassil_g
*/

#include <string.h>
#include "mysh.h"

t_mysh_er		process_entry(t_sh_token *token, t_envp *envp)
{
  t_int32		ret;
  t_mysh_er		er;
  t_struct_linker	job_list;

  init_linker(&job_list);
  while (token)
    {
      er = 0;
      if (token->up && token->flag & P_SEPARATOR_L)
	{
	  if ((ret = check_if_builtin(token->up->str)) >= 0)
	    {
	      if (test_job(&job_list, token->flag))
		er |= msh_builtin(&job_list, ret, token, envp);
	    }
	  else if ((ret = get_exec_path(envp, token)))
	    er |= ret;
	  else
	    if (token->flag & P_SCOL_F || test_job(&job_list, token->flag))
	      er |= msh_exec(&job_list, token, envp);
	}
      msh_error(er, token->up);
      token = token->next;
    }
  free_jobs((t_job *)job_list.first);
  return (SUCCES);
}
