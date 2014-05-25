/*
** tokenize_param.c for  in /home/vassil_g/rendu/42sh/Private/Src/Parser
** 
** Made by vassil_g
** Login   <vassil_g@epitech.net>
** 
** Started on  Tue May 20 15:16:17 2014 vassil_g
** Last update Sun May 25 23:28:14 2014 vassil_g
*/

#include <stdlib.h>
#include <string.h>
#include "parsing.h"

t_uint32        get_sep(char *sep, char str)
{
  t_uint32      j;

  j = 0;
  while (sep[j] && sep[j] != str)
    ++j;
  return (j);
}

char		*insert(t_struct_linker *linker, char *beg, char *end)
{
  if (!(insert_struct(linker, (t_any_struct *)new_sh_token(beg, end, 0),
		      SIMPLE | END)))
      return (beg);
  return (NULL);
}

t_uint32	case_quote(t_struct_linker *linker, char *str)
{
  t_uint32	i;

  i = 0;
  while (str[i] && str[i] != P_QUOT_C)
    ++i;
  if (!str[i])
    return (1);
  insert(linker, str, &str[i]);
  return (i + i);
}

t_uint32	tokenize_param(t_struct_linker *linker, char *str, char *sep)
{
  char          *beg;
  t_uint32      j;
  t_uint32      i;

  beg = NULL;
  i = 0;
  while (str[i])
    {
      if (str[i] == P_QUOT_C)
	{
	  if (beg)
	    beg = insert(linker, beg, &(str[i]));
	  i += case_quote(linker, &str[i + 1]);
	  continue;
	}
      j = get_sep(sep, str[i]);
      if (beg && sep[j])
	beg = (insert(linker, beg, &(str[i])));
      else if (!(sep[j]) && !beg)
	beg = &(str[i]);
      ++i;
    }
  if (beg)
    insert(linker, beg, &(str[i]));
  return (1);
}
