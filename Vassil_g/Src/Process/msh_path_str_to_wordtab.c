/*
** msh_path_str_to_wordtab.c for Minishell1 in /home/vassil_g/Minishell1
** 
** Made by vassil_g
** Login   <vassil_g@epitech.net>
** 
** Started on  Sun Feb  9 19:39:33 2014 vassil_g
** Last update Sun Feb  9 21:33:59 2014 vassil_g
*/

#include <stdlib.h>
#include "my_msh.h"

int			path_nb_word(char *str)
{
  int		nb_word;

  nb_word = 0;
  while (*str)
    {
      if (*str != ':')
	{
	  ++nb_word;
	  while (*str != ':' && *str)
	    ++str;
	}
      else
	++str;
    }
  return (nb_word);
}

t_mysh_er		path_make_word(char **src, char **dest)
{
  int		len;
  char		*tmp_src;
  char		*tmp_dest;

  tmp_src = *src;
  len = 0;
  while (tmp_src[len] != ':' && tmp_src[len])
    ++len;
  if (!(tmp_dest = malloc((sizeof (char)) * len + 1)))
    return (MA_ERROR);
  tmp_dest[len] = 0;
  while (*(tmp_src) != ':' && *tmp_src)
    *(tmp_dest++) = *(tmp_src++);
  while (*tmp_src == ':')
    ++tmp_src;
  *src = tmp_src;
  *dest = tmp_dest - len;
  return (SUCCESS);
}

char			**path_str_to_wordtab(char *str)
{
  char		**tab;
  int		nb;
  int		i;

  i = 0;
  if (!(nb = path_nb_word(str)))
    return (NULL);
  if (!(tab = malloc((sizeof (char *)) * (nb + 1))))
    return (NULL);
  tab[nb] = NULL;
  while (i < nb)
    {
      if (path_make_word(&str, &(tab[i++])) == STWT_MA_ERROR)
	return (NULL);
    }
  return (tab);
}
