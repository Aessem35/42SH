/*
** free_sh_token.c for  in /home/vassil_g/rendu/42sh/Public/42SH/Vassil_g
** 
** Made by vassil_g
** Login   <vassil_g@epitech.net>
** 
** Started on  Thu May 22 18:11:56 2014 vassil_g
** Last update Thu May 22 18:12:02 2014 vassil_g
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
