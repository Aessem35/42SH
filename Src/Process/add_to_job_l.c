/*
** add_to_job_l.c for  in /home/vassil_g/rendu/42sh/Public/42SH/Src/Process
** 
** Made by vassil_g
** Login   <vassil_g@epitech.net>
** 
** Started on  Sun May 25 18:12:42 2014 vassil_g
** Last update Sun May 25 18:42:44 2014 vassil_g
*/

#include <stdlib.h>
#include "mysh.h"

t_mysh_er		add_to_job_list(t_struct_linker *linker, int sig)
{
  t_job		*new;

  if (!(new = malloc(sizeof (t_job))))
    return (MA_ERROR);
  new->prev = NULL;
  new->next = NULL;
  new->signal = sig;
  if (!(insert_struct(linker, (t_any_struct *)new, DOUBLE | END)))
    return (MA_ERROR);
  return (SUCCES);
}
