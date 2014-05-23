/*
** msh_cd.c for  in /home/vassil_g/rendu/42sh/Public/42SH/Vassil_g/Src/Builtin
** 
** Made by vassil_g
** Login   <vassil_g@epitech.net>
** 
** Started on  Fri May 23 10:54:04 2014 vassil_g
** Last update Fri May 23 16:18:24 2014 vassil_g
*/

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "mysh.h"

t_mysh_er		cd_setenv(t_envp *envp, char *pwd)
{
  t_envl        *envl;
  char          *tmp;

  if (!(envl = msh_getenv_l(envp->envl, "OLDPWD")))
    return (BI_CD_NOOLDPWD);
  if (!(tmp = msh_getenv_v(envp->envl, "PWD")) || !*tmp)
    return (BI_CD_NOPWD);
  free(envl->name);
  if (!(envl->name = append_str_var("OLDPWD", tmp, '=')))
    return (MA_ERROR);
  envp->env[envl->env_nb] = envl->name;
  envl = msh_getenv_l(envp->envl, "PWD");
  free(envl->name);
  if (!(envl->name = append_str_var("PWD", pwd, '=')))
    return (MA_ERROR);
  envp->env[envl->env_nb] = envl->name;
  free(pwd);
  return (SUCCES);
}

t_mysh_er		cd_gohome(t_envp *envp)
{
  char		*tmp;

  if (!(tmp = msh_getenv_v(envp->envl, "HOME")))
    return (BI_CD_NOHOME);
  if (chdir(tmp) == -1)
    return (BI_CD_INVAHOME);
  if (!(tmp = strdup(tmp)))
    return (MA_ERROR);
  return (cd_setenv(envp, tmp));
}

t_mysh_er		cd_rewind(t_envp *envp)
{
  char		*tmp;

  if (!(tmp = msh_getenv_v(envp->envl, "OLDPWD")))
    return (BI_CD_NOOLDPWD);
  else if (chdir(tmp) == -1)
    return (BI_CD_INVAOLDPWD);
  if (!(tmp = strdup(tmp)))
    return (MA_ERROR);
  return (cd_setenv(envp, tmp));
}

t_mysh_er		init_pwd(t_envp *envp, t_sh_token *token, char **pwd)
{
  if (*(token->str) == '/')
    {
      if (!(*pwd = strdup(token->str)))
	return (MA_ERROR);
    }
  else if (*(token->str) == '~')
    {
      if (!(*pwd = msh_getenv_v(envp->envl, "HOME")))
	return (BI_CD_NOHOME);
      else if (!(*pwd = append_str_var(*(pwd) + 1, token->str, '/')))
	return (MA_ERROR);
    }
  else
    {
      if (!(*pwd = msh_getenv_v(envp->envl, "PWD")))
	return (BI_CD_NOPWD);
      else if (!(*pwd = append_str_var(*pwd, token->str, '/')))
	return (MA_ERROR);
    }
  return (SUCCES);
}

t_mysh_er		msh_cd(t_envp *envp, t_sh_token *token)
{
  char		*pwd;
  t_mysh_er	er;

  if (token->up_size < 2)
    return (cd_gohome(envp));
  else if (strcmp(token->up->next->str, "-") == 0)
    return (cd_rewind(envp));
  if ((er = init_pwd(envp, token->up->next, &pwd)) > 0)
    return (er);
  if (chdir(pwd) == -1)
    {
      free(pwd);
      return (BI_CD_INVAFOLDER);
    }
  else if (!(pwd = epure_path(pwd)))
    return (MA_ERROR);
  return (cd_setenv(envp, pwd));
}
