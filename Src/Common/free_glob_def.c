/*
** free_glob_def.c for  in /home/vassil_g/rendu/42sh/Public/42SH/Src/Common
** 
** Made by vassil_g
** Login   <vassil_g@epitech.net>
** 
** Started on  Fri May 23 16:23:28 2014 vassil_g
** Last update Fri May 23 16:23:45 2014 vassil_g
*/

#include <stdlib.h>
#include "parsing.h"

void                    free_glob_def(t_glob_def *new)
{
  static t_glob_def *def;
  t_uint32      n;

  if (!def && new)
    {
      def = new;
      return;
    }
  n = 0;
  while (def->lexic[n].string)
    {
      free(def->lexic[n].string);
      ++n;
    }
  free(def->lexic);
}
