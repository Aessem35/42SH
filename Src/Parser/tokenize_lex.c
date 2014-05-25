/*
** tokenize_lex.c for  in /home/vassil_g/rendu/42sh/Private/Src/Parser
** 
** Made by vassil_g
** Login   <vassil_g@epitech.net>
** 
** Started on  Tue May 20 14:48:32 2014 vassil_g
** Last update Sun May 25 23:04:03 2014 vassil_g
*/

#include <stdlib.h>
#include <string.h>
#include "parsing.h"

void			init_var(t_uint32 *i, t_uint32 *flag, char **beg)
{
  *i = 0;
  *flag = P_SCOL_F;
  *beg = NULL;
}

t_uint32		get_op(char *str, t_lexic *lex)
{
  t_uint32	j;

  j = 0;
  while (lex[j].string &&
	 strncmp(lex[j].string, str, strlen(lex[j].string)) != 0)
    ++j;
  return (j);
}

char			*case_skip(char *str, t_uint32 *i)
{
  if (!(*(str = getnext_c(&str[*i + 1], str[*i]))))
    return (NULL);
  *i = 1;
  return (str);
}

char			*insert_lex(t_struct_linker *linker, char *beg,
				char *end, t_uint32 flag)
{
  insert_struct(linker,
		(t_any_struct *)new_sh_token(beg, end, flag), SIMPLE | END);
  return (NULL);
}

t_sh_token		*tokenize_lex(t_struct_linker *linker,
				      char *str, t_glob_def *def, char end)
{
  char			*beg;
  t_uint32		j;
  t_uint32		i;
  t_uint32		flag;

  init_var(&i, &flag, &beg);
  while (str[i] && str[i] != end)
    {
      if (str[i] == P_MAGIC_C || str[i] == P_QUOT_C)
	if (!(str = case_skip(str, &i)))
	  return (NULL);
      j = get_op(&str[i], def->lexic);
      if (beg && def->lexic[j].string)
	{
	  beg = insert_lex(linker, beg, &str[i], flag);
	  i += strlen(def->lexic[j].string) - 1;
	  flag = def->lexic[j].flag;
        }
      else if (!(def->lexic[j].string) && !beg)
	beg = &(str[i]);
      ++i;
    }
  if (beg)
    insert_lex(linker, beg, &str[i], flag);
  return ((t_sh_token *)linker->first);
}

