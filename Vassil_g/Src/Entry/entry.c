/*
** entry.c for  in /home/vassil_g/rendu/42sh/Private/Src/Entry
** 
** Made by vassil_g
** Login   <vassil_g@epitech.net>
** 
** Started on  Tue May 20 15:36:14 2014 vassil_g
** Last update Thu May 22 17:05:06 2014 vassil_g
*/

#include "parsing.h"

char			*entry()
{
  char		*tmp;

  write(1, "$> ", 3);
  if (!(tmp = get_next_line(0)))
    exit(0);
  return (tmp);
}
