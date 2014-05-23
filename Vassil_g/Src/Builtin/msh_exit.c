/*
** msh_exit.c for  in /home/vassil_g/rendu/42sh/Public/42SH/Vassil_g/Src/Builtin
** 
** Made by vassil_g
** Login   <vassil_g@epitech.net>
** 
** Started on  Fri May 23 10:09:19 2014 vassil_g
** Last update Fri May 23 11:11:00 2014 vassil_g
*/

#include <stdlib.h>
#include "mysh.h"

t_mysh_er		msh_exit(t_envp *envp, t_sh_token *token)
{
  if (token->up_size == 2 && envp)
    exit(atoi(token->up->next->str));
  else
    exit(EXIT_SUCCESS);
  return (SUCCES);
}
