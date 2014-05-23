/*
** append_str_var.c for  in /home/vassil_g/rendu/42sh/Public/42SH/Vassil_g/Src/Common
** 
** Made by vassil_g
** Login   <vassil_g@epitech.net>
** 
** Started on  Fri May 23 10:24:13 2014 vassil_g
** Last update Fri May 23 10:29:09 2014 vassil_g
*/

#include <stdlib.h>
#include <string.h>
#include "my_types.h"

char                    *append_str_var(char *first, char *second, char c)
{
  char          *ret;
  t_uint32      len_first;
  t_uint32      len_second;

  len_first = strlen(first);
  len_second = strlen(second);
  if (!(ret = malloc(sizeof (char) * (len_first + len_second + 2))))
    return (NULL);
  strncpy(ret, first, len_first);
  ret[len_first] = c;
  strncpy(ret + (len_first + 1), second, len_second + 1);
  return (ret);
}
