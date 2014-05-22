/*
** tokenize.c for  in /home/vassil_g/rendu/42sh/Private/Src/Common
** 
** Made by vassil_g
** Login   <vassil_g@epitech.net>
** 
** Started on  Thu May 22 15:59:09 2014 vassil_g
** Last update Thu May 22 16:22:38 2014 vassil_g
*/

#include <stdlib.h>
#include <string.h>
#include "mysh.h"

t_token         *token_in_range(char *beg, char *end)
{
  t_token       *token;
  t_uint32      len;

  if (beg >= end || !(token = malloc(sizeof(t_token))))
    return (NULL);
  len = (end - beg);
  if (!(token->str = malloc(sizeof(char) * (len + 1))))
    {
      free(token);
      return (NULL);
    }
  token->next = NULL;
  token->prev = NULL;
  strncpy(token->str, beg, len);
  token->str[len] = '\0';
  return (token);
}

t_uint32        find_sep(char *sep, char str)
{
  t_uint32      j;

  j = 0;
  while (sep[j] && sep[j] ^ str)
    ++j;
  return (j);
}

t_token			*parse_string(t_struct_linker *linker, char *str, char *sep, t_uint32 mode)
{
  char			*beg;
  t_uint32		j;
  t_uint32		i;

  beg = NULL;
  i = 0;
  while (str[i])
    {
      j = find_sep(sep, str[i]);
      if (beg && sep[j])
        {
          if (!(insert_struct(linker, (t_any_struct *)token_in_range(beg, &(str[i])), mode)))
            return (NULL);
          beg = NULL;
        }
      else if (!(sep[j]) && !beg)
        beg = &(str[i]);
      ++i;
    }
  if (beg)
    insert_struct(linker, (t_any_struct *)token_in_range(beg, &(str[i])), mode);
  return ((t_token *)linker->first);
}

t_token			*tokenize(t_struct_linker *linker, char *str, char *sep, t_uint32 mode)
{
  t_struct_linker	if_null;

  if (linker)
    return (parse_string(linker, str, sep, mode));
  else
    init_linker(&if_null);
  return (parse_string(&if_null, str, sep, mode));
}
