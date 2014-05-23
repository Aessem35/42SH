/*
** exec.c for 42sh in /home/loteri_a/rendu/42sh/42SH/SRC
** 
** Made by 
** Login   <loteri_a@epitech.net>
** 
** Started on  Mon Apr 28 16:59:51 2014 loteri_a
** Last update Fri May 23 09:32:46 2014 vassil_g
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "../LIB/config.h"

int	exec(char *command, char **envp)
{

  int	pid;
  int	i;
  char *cmd[] = {{"ls"}, {"-l"}};
  char	*dest;

  i = strlen(dest) + strlen(command);
  dest = malloc(sizeof(*dest *  i));
  if (dest == NULL)
    return (-1);
  dest = strcat(dest, command);
  printf("dest : %s\n" , dest);
  pid = fork();
  if (pid == 0)
    {
      execve("/bin/ls", cmd, envp);
    }
  else
    wait(pid);
  return (0);
}
