/*
** insert_struct.c for  in /home/vassil_g/rendu/42sh/Private/Src/Common
** 
** Made by vassil_g
** Login   <vassil_g@epitech.net>
** 
** Started on  Tue May 20 14:49:16 2014 vassil_g
** Last update Thu May 22 17:35:54 2014 vassil_g
*/

#include <stdlib.h>
#include "parsing.h"

void			beg_simple_link(t_struct_linker *linker, t_any_struct *any)
{
  if (!(linker->first))
    {
      linker->first = any;
      linker->last = any;
    }
  else
    {
      any->next = linker->first;
      linker->first = any;
    }
  ++linker->size;
}

void			beg_double_link(t_struct_linker *linker, t_any_struct *any)
{
  if (!(linker->first))
    {
      linker->first = any;
      linker->last = any;
    }
  else
    {
      any->next = linker->first;
      linker->first->prev = any->next;
      linker->first = any;
    }
 ++linker->size;
}

void			end_simple_link(t_struct_linker *linker, t_any_struct *any)
{
  if (!(linker->first))
    {
      linker->first = any;
      linker->last = any;
    }
  else
    {
      linker->last->next = any;
      linker->last = any;
    }
 ++linker->size;
}

void			end_double_link(t_struct_linker *linker, t_any_struct *any)
{
  if (!(linker->first))
    {
      linker->first = any;
      linker->last = any;
    }
  else
    {
      linker->last->next = any;
      any->prev = linker->last;
      linker->last = any;
    }
  ++linker->size;
}

t_uint32		insert_struct(t_struct_linker *linker, t_any_struct *any, t_uint32 mode)
{
  if (!(any))
    return (0);
  if (mode & BEG)
    {
      if (mode & SIMPLE)
	beg_simple_link(linker, any);
      else if (mode & DOUBLE)
	beg_double_link(linker, any);
    }
  else if (mode & END)
    {
      if (mode & SIMPLE)
	end_simple_link(linker, any);
      else if (mode & DOUBLE)
	end_double_link(linker, any);
    }
  return (1);
}
