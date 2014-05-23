/*
** cd_dots.c for Minishell in /home/vassil_g/Minishell1/Source/Builtin
** 
** Made by vassil_g
** Login   <vassil_g@epitech.net>
** 
** Started on  Sun Mar  9 22:45:45 2014 vassil_g
** Last update Sun Mar  9 22:55:39 2014 vassil_g
*/

#include <stdlib.h>
#include "my.h"

unsigned int	step_1(char *str, unsigned int i)
{
  while (i != 0)
    {
      if (str[i] == '/' && str[i - 1] == '.')
        {
          str[i--] = '*';
          str[i--] = '*';
          if (str[i] == '.')
            {
              str[i--] = '*';
              str[i--] = '*';
              while (str[i] != '/')
                str[i--] = '*';
            }
        }
      else
        --i;
    }
  return (i);
}

char            *cd_dots(char *str)
{
  char          *tmp;
  unsigned      i;
  unsigned      j;

  i = 0;
  j = 0;
  if (!(tmp = malloc(my_strlen(str) + 1)))
    return (NULL);
  while (str[i])
    {
      tmp[i] = str[i];
      ++i;
    }
  i = my_strlen(str);
  i = step_1(str, i);
  while (str[j])
    {
      if (str[j] != '*')
        tmp[i++] = str[j];
      ++j;
    }
  tmp[i] = 0;
  free(str);
  return (tmp);
}
