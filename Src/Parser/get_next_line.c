/*
** get_next_line.c for get_next_line in /home/vassil_g/rendu/get_next_line-2018-vassil_g
** 
** Made by vassil_g
** Login   <vassil_g@epitech.net>
** 
** Started on  Tue Nov 19 15:28:00 2013 vassil_g
** Last update Sun May 25 22:41:11 2014 vassil_g
*/

#include <stdlib.h>
#include <unistd.h>

int		     fill_buffer(int fd, int *i, int *max, char *buff)
{
  if (*i != *max)
    return (2);
  *i = 0;
  *max = read(fd, buff, 4095);
  buff[4095] = 0;
  if (*max < 1)
    {
      *max = 0;
      return (0);
    }
  return (1);
}

char			*refill_str(char *src, int *size_src, int size_dest)
{
  int		i;
  char		*dest;

  i = 0;
  if (!(dest = malloc(sizeof(char) * (*size_src + size_dest + 1))))
    return (NULL);
  dest[*size_src + size_dest] = 0;
  while (src[i])
    {
      dest[i] = src[i];
      ++i;
    }
  *size_src += size_dest;
  free(src);
  return (dest);
}

int			lenght(char *str)
{
  int		 len;

  len = 0;
  while (*str && *str != '\n')
    {
      if ((*str >= ' ' && *str <= '~') || *str == '\t')
	++len;
      ++str;
    }
  return (len);
}

char		 	*init_str(char *buff, int i, int *len, int *n)
{
  char		*str;

  *n = 0;
  *len = lenght(buff + i);
  if (!(str = malloc(*len + 1)))
    return (NULL);
  str[*len] = 0;
  return (str);
}

char			*get_next_line(const int fd)
{
  static char   buff[4095 + 1];
  static int    i;
  static int    max;
  int		n;
  int		 len;
  char		*str;

  n = 0;
  if (!(fill_buffer(fd, &i, &max, buff)) ||
      !(str = init_str(buff, i, &len, &n)))
    return (NULL);
  while ((buff[i] && buff[i] != '\n'))
    {
      if ((buff[i] >= ' ' && buff[i] <= '~') || buff[i] == '\t')
	str[n++] = buff[i];
      if (++i == max)
	{
	  if (fill_buffer(fd, &i, &max, buff))
	    str = refill_str(str, &len, lenght(buff + i));
	  else
	    return (str);
	}
    }
  ++i;
  return (str);
}
