/*
** check_if_builtin.c for  in /home/vassil_g/rendu/42sh/Public/42SH/Src/Process
** 
** Made by vassil_g
** Login   <vassil_g@epitech.net>
** 
** Started on  Sun May 25 18:20:27 2014 vassil_g
** Last update Sun May 25 18:44:54 2014 vassil_g
*/

#include <string.h>
#include "mysh.h"

t_int32                 check_if_builtin(char *str)
{
  if (strcmp(str, "env") == 0)
    return (BUILTIN_ENV);
  if (strcmp(str, "exit") == 0)
    return (BUILTIN_EXIT);
  if (strcmp(str, "getenv") == 0)
    return (BUILTIN_GETENV);
  if (strcmp(str, "setenv") == 0)
    return (BUILTIN_SETENV);
  if (strcmp(str, "unsetenv") == 0)
    return (BUILTIN_UNSETENV);
  if (strcmp(str, "cd") == 0)
    return (BUILTIN_CD);
  if (strcmp(str, "clear") == 0)
    return (BUILTIN_CLEAR);
  return (-1);
}
