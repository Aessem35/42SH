/*
** 42sh.c for 42sh in /home/loteri_a/rendu/42sh/42SH/SRC
** 
** Made by 
** Login   <loteri_a@epitech.net>
** 
** Started on  Wed Apr 23 19:26:49 2014 
** Last update Tue May 20 14:29:45 2014 
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include "../LIB/config.h"

int	main(int ac, char **av, char **envp)
{
  int   size;
  char  buff[1024];

  write(1, "$> ", 3);
  buf_clean(buff);
  while (42)
    while ((size = read(0 , buff, 1023)) > 0)
      {
	exec(envp);
	write(1, buff, 1023);
	buf_clean(buff);
	write(1, "$> ", 3);
      }
 return 0;
}
