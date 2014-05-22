/*
** tokenize_lex.c for  in /home/vassil_g/rendu/42sh/Private/Src/Parser
** 
** Made by vassil_g
** Login   <vassil_g@epitech.net>
** 
** Started on  Tue May 20 14:48:32 2014 vassil_g
** Last update Thu May 22 17:37:41 2014 vassil_g
*/

#include <stdlib.h>
#include <string.h>
#include "parsing.h"

t_sh_token			*tokenize_lex(char *str, t_glob_def *def, char end)
{
  char			*beg;
  t_struct_linker	linker;
  t_uint32		j;
  t_uint32		i;

  init_linker(&linker);
  beg = NULL;
  i = 0;
  while (str[i] && str[i] != end)
    {
      j = 0;
      while (def->lexic[j].string && strncmp(def->lexic[j].string, &str[i], strlen(def->lexic[j].string)) != 0)
	++j;
      if (beg && def->lexic[j].string)
	{
          insert_struct(&linker, (t_any_struct *)new_sh_token(beg, &(str[i]), def->lexic[j].flag), SIMPLE | END);
          beg = NULL;
        }
      else if (!(def->lexic[j].string) && !beg)
	beg = &(str[i]);
      ++i;
    }
  if (beg)
    insert_struct(&linker, (t_any_struct *)new_sh_token(beg, &(str[i]), def->lexic[j].flag), SIMPLE | END);
  return ((t_sh_token *)linker.first);
}

