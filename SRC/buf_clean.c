/*
** buf_clean.c for 42sh in /home/loteri_a/rendu/42sh/42SH/SRC
** 
** Made by 
** Login   <loteri_a@epitech.net>
** 
** Started on  Thu Apr 24 09:52:31 2014 
** Last update Thu Apr 24 10:23:07 2014 
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include "../LIB/config.h"

char    *buf_clean(char *str)
{
  int   k;

  k = 0;
  while (k++ <= CMD)
    str[k] = 0;
  return (str);
}
