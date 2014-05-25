/*
** main.c for  in /home/vassil_g/rendu/42sh/Private/Src/Main
** 
** Made by vassil_g
** Login   <vassil_g@epitech.net>
** 
** Started on  Thu May 22 11:13:10 2014 vassil_g
** Last update Sun May 25 22:33:23 2014 vassil_g
*/

#include "mysh.h"

int		main(int argc, char *argv[], char **envp)
{
  init_signal();
  mysh(envp);
  return (0);
}
