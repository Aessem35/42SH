/*
** path_pars.c for 42sh in /home/loteri_a/42SH/SRC
** 
** Made by loteri_a
** Login   <loteri_a@epitech.net>
** 
** Started on  Tue May 20 15:17:27 2014 loteri_a
** Last update Tue May 20 16:40:49 2014 loteri_a
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int	pth_lnght(char *env, int c)
{
  int	z;

  z = c;
  while (env[c] != ':' || env[c] != '\0')
    c++;
  c = c - z;
  return (c);
}

char	**path_fill(char **path, char *env, int line, int max)
{
  int	blk;
  int	c;
  int	k;
  int	base;

  blk = 0;
  c = 0;
  k = 0;
  base = 0;
  while (env[c++] != '/');
  while (env[c] != '\0')
    {
      base = pth_lnght(env, c);
      path[blk] = malloc(sizeof(*path) * base);
      memset(path[blk], 0, base);
      while (env[c] != ':' || env[c] != '\0')
	path[blk][k++] == env[c++];
      c++;
      blk++;
      k = 0;
    }
  memset(path[blk], 0, base);
  return (path);
}

char	**path_pars(char **envp)
{
  char	**path;
  int	line;
  int	block;
  int	c;

  line = 0;
  block = 1;
  c = 0;
  while (envp[line][0] != 'P' && envp[line][2] != 'T')
    line++;
  while (envp[line][c] != '\0')
    if (envp[line][c++] == ':')
      block++;
  path = malloc(sizeof(path) * (block + 1));
  c = 0;
  path_fill(path, envp[line], line, block);
  return (path);
}
