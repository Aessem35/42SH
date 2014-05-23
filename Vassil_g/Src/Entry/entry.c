/*
** entry.c for  in /home/vassil_g/rendu/42sh/Private/Src/Entry
** 
** Made by vassil_g
** Login   <vassil_g@epitech.net>
** 
** Started on  Tue May 20 15:36:14 2014 vassil_g
** Last update Fri May 23 11:08:32 2014 vassil_g
*/

#include <stdlib.h>
#include <unistd.h>
#include "parsing.h"

char			*entry()
{
  char		*tmp;

  write(1, "$> ", 3);
  if (!(tmp = get_next_line(0)))
    exit(0);
  return (tmp);
}
