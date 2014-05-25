/*
** free_jobs.c for  in /home/vassil_g/rendu/42sh/Public/42SH/Src/Process
** 
** Made by vassil_g
** Login   <vassil_g@epitech.net>
** 
** Started on  Sun May 25 18:45:35 2014 vassil_g
** Last update Sun May 25 18:51:38 2014 vassil_g
*/

#include <stdlib.h>
#include "mysh.h"

void		free_jobs(t_job *job)
{
  t_job		*tmp;

  while (job)
    {
      tmp = job;
      job = job->next;
      free(tmp);
    }
}
