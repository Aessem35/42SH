/*
** test.c for detruety in /home/richar_2/Documents/minshell
** 
** Made by 
** Login   <richar_2@epitech.net>
** 
** Started on  Thu Mar 13 16:43:26 2014 
** Last update Tue Mar 18 17:49:44 2014 
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char	*epur_str(char *str, int size)
{
  char	*strs;
  int	i;
  
  strs = malloc(1 *sizeof(size));
  if (strs == NULL)
    return (NULL);
  i = 0;
  while (i != size)
    {     
      strs[i] = str[i];
      
      if (strs[i] == '\t')
	strs[i] = ' ';
      i++;
    }
  write(1, strs, size);
  return strs;
}		

int	main(int ac, char **av, char **envp)
{
  int	size;
  char	buff[1024];
  
  write(1, "$> ", 3);
  while ((size = read(0 , buff, 1023)) > 0)
    {
      epur_str(buff , size);
      write(1, "$> ", 3);
    }
  return 0;
}

  
