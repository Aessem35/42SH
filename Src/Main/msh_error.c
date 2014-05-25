/*
** msh_error.c for  in /home/vassil_g/rendu/42sh/Public/42SH/Src/Main
** 
** Made by vassil_g
** Login   <vassil_g@epitech.net>
** 
** Started on  Sun May 25 20:06:17 2014 vassil_g
** Last update Sun May 25 20:34:21 2014 vassil_g
*/

#include <stdio.h>
#include "mysh.h"
#include "msh_er.h"

void            error_cd(t_mysh_er func_r)
{
  if (func_r & BI_CD_NOPWD)
    dprintf(2, "%s", BI_CD_NOPWD_MSG);
  else if (func_r & BI_CD_NOOLDPWD)
    dprintf(2, "%s", BI_CD_NOOLDPWD_MSG);
  else if (func_r & BI_CD_INVAOLDPWD)
    dprintf(2, "%s", BI_CD_INVAOLDPWD_MSG);
  else if (func_r & BI_CD_NOHOME)
    dprintf(2, "%s", BI_CD_NOHOME_MSG);
  else if (func_r & BI_CD_INVAHOME)
    dprintf(2, "%s", BI_CD_INVAHOME_MSG);
  else if (func_r & BI_CD_INVAFOLDER)
    dprintf(2, "%s", BI_CD_INVAFOLDER_MSG);
}

void            msh_error(t_mysh_er func_r, t_sh_token *entry)
{
  if (!func_r)
    return;
  error_cd(func_r);
  if (func_r & MA_ERROR)
    dprintf(2, "%s", MA_ERROR_MSG);
  if (func_r & BI_UENV_USE)
    dprintf(2, "%s", BI_UENV_USE_MSG);
  if (func_r & BI_UENV_NF)
    dprintf(2, "%s : %s", entry->next->str, BI_UENV_NF_MSG);
  if (func_r & BI_SENV_USE)
    dprintf(2, "%s", BI_SENV_USE_MSG);
  if (func_r & ESTWT_MA_ERROR)
    dprintf(2, "%s", ESTWT_MA_ERROR_MSG);
  if (func_r & STWT_MA_ERROR)
    dprintf(2, "%s", STWT_MA_ERROR_MSG);
  if (func_r & EXEC_NF)
    dprintf(2, "%s : %s", entry->str, EXEC_NF_MSG);
  if (func_r & EXEC_NOPATH)
    dprintf(2, "%s", EXEC_NOPATH_MSG);
  if (func_r & BI_ENV_USE)
    dprintf(2, "%s : %s", entry->next->str, BI_ENV_USE_MSG);
  if (func_r & EXEC_FORK_FAILURE)
    dprintf(2, "%s", EXEC_FORK_FAILURE_MSG);
}

