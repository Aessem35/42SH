/*
** exec.c for 42sh in /home/loteri_a/rendu/42sh/42SH/SRC
** 
** Made by 
** Login   <loteri_a@epitech.net>
** 
** Started on  Mon Apr 28 16:59:51 2014 
** Last update Tue May 20 14:38:03 2014 
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "../LIB/config.h"

int	exec(char **envp)
{
  int	pid;
  char *const cmd[2][2] = {{"ls"}, {"-l"}};

  pid = fork();
  if (pid)
    {
      execve("/bin/ls", cmd, envp);
    }
  wait(pid);
  return (0);
}
