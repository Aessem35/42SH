/*
** exec.c for 42sh in /home/loteri_a/rendu/42sh/42SH/SRC
** 
** Made by 
** Login   <loteri_a@epitech.net>
** 
** Started on  Mon Apr 28 16:59:51 2014 
** Last update Tue May 20 15:24:48 2014 richar_2
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
  char *const cmd[2][2] = {{"ls"}, {"-l"}};
  char	*dest;
  
  dest = "/bin/";
  i = strlen(dest) + strlen(command);
  dest = malloc(sizeof(*dest *  i));
  if (dest == NULL)
    return (-1);
  dest = strcat(dest, command); 
  printf("dest : %s\n" , dest);
  pid = fork();
  if (pid)
    {
      execve("/bin/ls", cmd, envp);
    }
  wait(pid);
  return (0);
}
