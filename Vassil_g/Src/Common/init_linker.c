/*
** init_linker.c for  in /home/vassil_g/rendu/42sh/Private/Src/Common
** 
** Made by vassil_g
** Login   <vassil_g@epitech.net>
** 
** Started on  Tue May 20 16:15:27 2014 vassil_g
** Last update Tue May 20 16:16:05 2014 vassil_g
*/

#include <stdlib.h>
#include "parsing.h"

void			init_linker(t_struct_linker *linker)
{
  linker->first = NULL;
  linker->last = NULL;
  linker->size = 0;
}
