/*
** 42sh.c for 42sh in /home/loteri_a/rendu/42sh/42SH/SRC
** 
** Made by 
** Login   <loteri_a@epitech.net>
** 
** Started on  Wed Apr 23 19:26:49 2014 
** Last update Thu Apr 24 09:58:07 2014 
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "../LIB/config.h"

int	main(int ac, char **av)
{
  char	cmd[CMD];

  while (42)
    {
      buf_clean(cmd);
      if (read(0, cmd, CMD) == -1)
	exit(-1);
      write(1, cmd, CMD);
    }
}
