/*
** p_main.c for  in /home/vassil_g/rendu/42sh/Private/Src/Parser
** 
** Made by vassil_g
** Login   <vassil_g@epitech.net>
** 
** Started on  Tue May 20 11:14:48 2014 vassil_g
** Last update Fri May 23 11:08:49 2014 vassil_g
*/

#include <stdlib.h>
#include "parsing.h"

void			params(t_sh_token *token, t_glob_def *def)
{
  t_struct_linker	linker;

  while (token)
    {
      init_linker(&linker);
      tokenize_param(&linker, def, token->str, " \t");
      token->up_size = linker.size;
      token->up = (t_sh_token *)linker.first;
      token = token->next;
    }
}

t_sh_token		*parser(char *str, t_glob_def *def, char end)
{
  t_sh_token	*token;

  if (!(token = tokenize_lex(str, def, end)))
    return (token);
  params(token, def);
  return (token);
}

t_sh_token		*parsed_entry(t_glob_def *def)
{
  char		*tmp;
  t_sh_token	*token;

  if (!(tmp = entry()))
    return (NULL);
  token = parser(tmp, def, 0);
  free(tmp);
  return (token);
}
