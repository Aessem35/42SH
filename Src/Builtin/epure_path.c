/*
** cd_dots.c for Minishell in /home/vassil_g/Minishell1/Source/Builtin
** 
** Made by vassil_g
** Login   <vassil_g@epitech.net>
** 
** Started on  Sun Mar  9 22:45:45 2014 vassil_g
** Last update Sun May 25 20:16:37 2014 vassil_g
*/

#include <stdlib.h>
#include <string.h>
#include "mysh.h"

t_token			*remove_node(t_struct_linker *linker, t_token *token)
{
  t_token	*ret;

  ret = token->next;
  if (token == (t_token *)linker->first)
    linker->first = (t_any_struct *)token->next;
  else
    token->prev->next = token->next;
  if (token == (t_token *)linker->last)
    linker->last = (t_any_struct *)token->prev;
  else
    token->next->prev = token->prev;
  free(token->str);
  free(token);
  return (ret);
}

void			clean_path(t_struct_linker *linker)
{
  t_token	*token;

  token = (t_token *)linker->first;
  while (token)
    {
      if (strcmp(token->str, ".") == 0)
	token = remove_node(linker, token);
      else if (strcmp(token->str, "..") == 0)
	{
	  if (token->prev)
	    remove_node(linker, token->prev);
	  token = remove_node(linker, token);
	}
      else
	token = token->next;
    }
}

char			*make_string(t_token *token)
{
  char		*ret;
  t_uint32	len;

  len = 0;
  while (token)
    {
      len += (strlen(token->str) + 1);
      token = token->next;
    }
  ret = malloc(len + 1);
  return (ret);
}

char			*rebuild_path(t_struct_linker *linker)
{
  char		*ret;
  t_token	*token;
  t_uint32	n;

  n = 0;
  token = (t_token *)linker->first;
  if (!(ret = make_string(token)))
    return (NULL);
  while (token)
    {
      ret[n] = '/';
      ++n;
      strcpy(&ret[n], token->str);
      n += strlen(token->str);
      token = token->next;
    }
  return (ret);
}

char			*epure_path(char *path)
{
  t_struct_linker	linker;
  char			*ret;

  init_linker(&linker);
  if (!(tokenize(&linker, path, "/", DOUBLE | END)))
    return (NULL);
  clean_path(&linker);
  ret = rebuild_path(&linker);
  free_token((t_token *)linker.first);
  free(path);
  return (ret);
}
