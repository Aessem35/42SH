/*
** tokenize_lex.c for  in /home/vassil_g/rendu/42sh/Private/Src/Parser
** 
** Made by vassil_g
** Login   <vassil_g@epitech.net>
** 
** Started on  Tue May 20 14:48:32 2014 vassil_g
** Last update Sun May 25 20:02:15 2014 vassil_g
*/

#include <stdlib.h>
#include <string.h>
#include "parsing.h"

t_sh_token		*tokenize_lex(char *str, t_glob_def *def, char end)
{
  char			*beg;
  t_struct_linker	linker;
  t_uint32		j;
  t_uint32		i;
  t_uint32		flag;

  init_linker(&linker);
  beg = NULL;
  i = 0;
  flag = P_SCOL_F;
  while (str[i] && str[i] != end)
    {
      j = 0;
      if (str[i] == P_MAGIC_C || str[i] == P_QUOT_C)
	{
	  if (!(*(str = getnext_c(&str[i + 1], str[i]))))
	    return (NULL);
	  i = 1;
	  continue;
	}
      while (def->lexic[j].string && strncmp(def->lexic[j].string, &str[i], strlen(def->lexic[j].string)) != 0)
	++j;
      if (beg && def->lexic[j].string)
	{
          insert_struct(&linker, (t_any_struct *)new_sh_token(beg, &(str[i]), flag), SIMPLE | END);
	  i += strlen(def->lexic[j].string) - 1;
	  flag = def->lexic[j].flag;
          beg = NULL;
        }
      else if (!(def->lexic[j].string) && !beg)
	beg = &(str[i]);
      ++i;
    }
  if (beg)
    insert_struct(&linker, (t_any_struct *)new_sh_token(beg, &(str[i]), flag), SIMPLE | END);
  return ((t_sh_token *)linker.first);
}

