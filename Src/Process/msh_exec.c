/*
** msh_exec.c for  in /home/vassil_g/rendu/42sh/Private/Src/Process
** 
** Made by vassil_g
** Login   <vassil_g@epitech.net>
** 
** Started on  Thu May 22 16:59:08 2014 vassil_g
** Last update Sun May 25 20:30:31 2014 vassil_g
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "mysh.h"

t_mysh_er	msh_p_prcs(t_struct_linker *job_list, pid_t pid)
{
  int		signal;

  if (waitpid(pid, &signal, 0) != pid)
    return (EXEC_NF);
  if (add_to_job_list(job_list, signal))
    return (MA_ERROR);
  if (signal == 256)
    return (EXEC_NF);
  return (SUCCES);
}

char   		**make_arg_tab(t_sh_token *token, t_uint32 size)
{
  char		**ret;
  t_uint32	n;

  n = 0;
  if (!(ret = malloc(sizeof (char *) * (size + 1))))
    return (NULL);
  while (n < size)
    {
      ret[n] = token->str;
      token = token->next;
      ++n;
    }
  ret[size] = NULL;
  return (ret);
}

void	      	msh_c_prcs(t_sh_token *token, t_envp *envp)
{
  char		**arg;

  if (!(arg = make_arg_tab(token->up, token->up_size)))
    exit(EXIT_FAILURE);
  execve(token->str, arg, envp->env);
  free(arg);
  exit(EXIT_FAILURE);
}

t_mysh_er	msh_exec(t_struct_linker *job_list,
			 t_sh_token *entry, t_envp *envp)
{
  pid_t		fork_r;

  if ((fork_r = fork()) == 0)
    msh_c_prcs(entry, envp);
  else if (fork_r == -1)
    return (EXEC_FORK_FAILURE);
  return (msh_p_prcs(job_list, fork_r));
}
