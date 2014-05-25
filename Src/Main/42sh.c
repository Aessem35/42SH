/*
** 42sh.c for  in /home/vassil_g/rendu/42sh/Private/Src/Main
** 
** Made by vassil_g
** Login   <vassil_g@epitech.net>
** 
** Started on  Wed May 21 13:01:09 2014 vassil_g
** Last update Sun May 25 20:09:47 2014 vassil_g
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "mysh.h"

t_lexic			*init_lex_def(t_lexic *lex)
{
  if (!(lex[5].string = strdup(P_PIPE_S)))
    return (NULL);
  lex[5].flag = P_PIPE_F;
  if (!(lex[1].string = strdup(P_SDIR_S)))
    return (NULL);
  lex[1].flag = P_SDIR_F;
  if (!(lex[2].string = strdup(P_DDIR_S)))
    return (NULL);
  lex[2].flag = P_DDIR_F;
  if (!(lex[3].string = strdup(P_SDIL_S)))
    return (NULL);
  lex[3].flag = P_SDIL_F;
  if (!(lex[4].string = strdup(P_DDIL_S)))
    return (NULL);
  lex[4].flag = P_DDIL_F;
  if (!(lex[0].string = strdup(P_OR_S)))
    return (NULL);
  lex[0].flag = P_OR_F;
  if (!(lex[6].string = strdup("P_AND_S")))
    return (NULL);
  lex[6].flag = P_AND_F;
  if (!(lex[7].string = strdup(P_SCOL_S)))
    return (NULL);
  lex[7].flag = P_SCOL_F;
  lex[LEX_NB].string = NULL;
  lex[LEX_NB].flag = 0;
  return (lex);
}


t_glob_def		*init_def(t_glob_def *glob_def)
{
  t_lexic	*lex_def;

  if (!(lex_def = malloc((sizeof (t_lexic )) * (LEX_NB + 1))))
    return (NULL);
  if (!(glob_def->lexic = init_lex_def(lex_def)))
    return (NULL);
  free_glob_def(glob_def);
  return (glob_def);
}

void			mysh(char **env)
{
  t_envp	envp;
  t_sh_token	*token;
  t_glob_def	def;

  if (!(init_def(&def)))
    return;
  msh_init_env(&envp, env);
  while (42)
    {
      token = parsed_entry(&def);
      if (token && token->up)
	process_entry(token, &envp);
      free_sh_token(token);
    }
}
