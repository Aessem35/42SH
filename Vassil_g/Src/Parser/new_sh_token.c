/*
** new_token.c for  in /home/vassil_g/rendu/42sh/Private/Src/Parser
** 
** Made by vassil_g
** Login   <vassil_g@epitech.net>
** 
** Started on  Tue May 20 15:23:43 2014 vassil_g
** Last update Thu May 22 17:32:09 2014 vassil_g
*/

#include <stdlib.h>
#include "string.h"
#include "parsing.h"

t_sh_token		*new_sh_token(char *beg, char *end, t_uint32 flag)
{
  t_sh_token	*token;
  t_uint32	len;

  if (beg >= end || !(token = malloc(sizeof (t_sh_token))))
    return (NULL);
  len = (end - beg);
  if (!(token->str = malloc(len + 1)))
    {
      free(token);
      return (NULL);
    }
  token->next = NULL;
  token->up = NULL;
  token->up_size = 0;
  token->flag = flag;
  strncpy(token->str, beg, len);
  token->str[len] = '\0';
  return (token);
}
