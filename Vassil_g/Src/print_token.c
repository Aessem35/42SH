/*
** print_token.c for  in /home/vassil_g/rendu/42sh/Private/Src
** 
** Made by vassil_g
** Login   <vassil_g@epitech.net>
** 
** Started on  Tue May 20 16:17:17 2014 vassil_g
** Last update Thu May 22 17:41:05 2014 vassil_g
*/

#include <stdio.h>
#include "parsing.h"

void		print_token(t_sh_token *token)
{
  while (token)
    {
      printf("[%s] [size = %u]", token->str, token->up_size);
      if (token->up)
	{
	  printf("\n->");
	  print_token(token->up);
	  printf("\n");	
	}
      token = token->next;
    }
}
