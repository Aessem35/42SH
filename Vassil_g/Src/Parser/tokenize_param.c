/*
** tokenize_param.c for  in /home/vassil_g/rendu/42sh/Private/Src/Parser
** 
** Made by vassil_g
** Login   <vassil_g@epitech.net>
** 
** Started on  Tue May 20 15:16:17 2014 vassil_g
** Last update Thu May 22 15:58:12 2014 vassil_g
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

t_uint32	case_magic(t_struct_linker *linker, t_glob_def *def, char *str)
{
  t_uint32	len;
  t_sh_token	*tmp;

  len = 0;
  while (str[len] && str[len] != P_MAGIC_C)
    ++len;
  if (!str[len])
    return (0);
  if (!(insert_struct(linker, (t_any_struct *)new_sh_token(str, &(str[len]), 0), SIMPLE | END)))
    return (0);
  tmp = (t_sh_token *)linker->last;
  tmp->up = parser(str, def, P_MAGIC_C);
  tmp->flag = P_MAGIC_F;
  return (len + 1);
}

t_uint32	tokenize_param(t_struct_linker *linker, t_glob_def *def, char *str, char *sep)
{
  char          *beg;
  t_uint32      j;
  t_uint32      i;

  beg = NULL;
  i = 0;
  while (str[i])
    {
      if (str[i] == P_MAGIC_C)
	{
	  if (beg)
	    {
	      if (!(insert_struct(linker, (t_any_struct *)new_sh_token(beg, &(str[i - 1]), 0), SIMPLE | END)))
		return (0);
	      beg = NULL;
	    }
	  i += case_magic(linker, def, &str[++i]);
	  continue;
	}
      j = get_sep(sep, str[i]);
      if (beg && sep[j])
	{
	  if (!(insert_struct(linker, (t_any_struct *)new_sh_token(beg, &(str[i]), 0), SIMPLE | END)))
	    return (0);
	  beg = NULL;
	}
      else if (!(sep[j]) && !beg)
	beg = &(str[i]);
      ++i;
    }
  if (beg)
    if (!(insert_struct(linker, (t_any_struct *)new_sh_token(beg, &(str[i]), 0), SIMPLE | END)))
      return (0);
  return (1);
}
