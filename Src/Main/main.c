/*
** main.c for  in /home/vassil_g/rendu/42sh/Private/Src/Main
**
** Made by vassil_g
** Login   <vassil_g@epitech.net>
**
** Started on  Thu May 22 11:13:10 2014 vassil_g
<<<<<<< HEAD
** Last update Sun May 25 22:45:09 2014 vassil_g
=======
** Last update Sun May 25 21:57:00 2014 richar_2
>>>>>>> 40121c9cb2a416040472cb8f342695bbd2049e37
*/

#include "mysh.h"

int		main(int argc, char *argv[], char **envp)
{
  init_signal();
  (void)(argc);
  (void)(argv);
  mysh(envp);
  return (0);
}
