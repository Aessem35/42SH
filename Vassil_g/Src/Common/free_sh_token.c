/*
** free_token.c for  in /home/vassil_g/rendu/42sh/Private/Src/Common
** 
** Made by vassil_g
** Login   <vassil_g@epitech.net>
** 
** Started on  Tue May 20 15:41:31 2014 vassil_g
** Last update Thu May 22 17:06:08 2014 vassil_g
*/

#include <stdlib.h>
#include "parsing.h"

void		free_sh_token(t_sh_token *token)
{
  t_sh_token	*tmp;

  while (token)
    {
      tmp = token;
      if (token->up)
	free_sh_token(token->up);
      token = token->next;
      free(tmp->str);
      free(tmp);
    }
}
