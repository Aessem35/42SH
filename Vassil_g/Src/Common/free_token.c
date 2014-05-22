/*
** free_token.c for  in /home/vassil_g/rendu/42sh/Private/Src/Common
** 
** Made by vassil_g
** Login   <vassil_g@epitech.net>
** 
** Started on  Thu May 22 16:03:54 2014 vassil_g
** Last update Thu May 22 16:05:21 2014 vassil_g
*/

#include <stdlib.h>
#include "mysh.h"

void			free_token(t_token *token)
{
  t_token	*tmp;

  while (token)
    {
      tmp = token;
      token = token->next;
      if (tmp->str)
	free(tmp->str);
      free(tmp);
    }
}
