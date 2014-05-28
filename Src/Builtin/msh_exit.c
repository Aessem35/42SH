/*
** msh_exit.c for  in /home/vassil_g/rendu/42sh/Public/42SH/Vassil_g/Src/Builtin
** 
** Made by vassil_g
** Login   <vassil_g@epitech.net>
** 
** Started on  Fri May 23 10:09:19 2014 vassil_g
** Last update Wed May 28 10:16:04 2014 vassil_g
*/

#include <stdlib.h>
#include "mysh.h"

t_mysh_er		msh_exit(t_envp *envp, t_sh_token *token)
{
  t_uint32	val;

  free_env(envp);
  val = EXIT_SUCCESS;
  if (token->up_size == 2)
    val = atoi(token->up->next->str);
  free_sh_token(token);
  free_glob_def(NULL);
  exit(val);
  return (SUCCES);
}
