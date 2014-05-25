/*
** test_job.c for  in /home/vassil_g/rendu/42sh/Public/42SH/Src/Process
** 
** Made by vassil_g
** Login   <vassil_g@epitech.net>
** 
** Started on  Sun May 25 17:12:03 2014 vassil_g
** Last update Sun May 25 19:06:30 2014 vassil_g
*/

#include "mysh.h"

t_uint32		test_job(t_struct_linker *job_list, t_uint32 flag)
{
  t_uint32	prev;

  if (!job_list->last || !((t_job *)job_list->last)->signal)
    prev = 0;
  else
    prev = 1;
  if (flag & P_OR_F)
    {
      if (prev)
	return (1);
      return (0);
    }
  else if (flag & P_AND_F)
    {
      if (prev)
	return (0);
      return (1);
    }
  return (1);
}
