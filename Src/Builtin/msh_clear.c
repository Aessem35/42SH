/*
** msh_clear.c for Minishell1 in /home/vassil_g/Minishell1/Source/Builtin
** 
** Made by vassil_g
** Login   <vassil_g@epitech.net>
** 
** Started on  Mon Feb  3 12:03:43 2014 vassil_g
** Last update Fri May 23 10:12:09 2014 vassil_g
*/

#include <unistd.h>
#include <string.h>

void            msh_clear()
{
  write(1, "\033[H\033[2J", strlen("\033[H\033[2J"));
}
