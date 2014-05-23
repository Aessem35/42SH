/*
** msh_cd.c for Minishell1 in /home/vassil_g/Minishell1/Source/Builtin
** 
** Made by vassil_g
** Login   <vassil_g@epitech.net>
** 
** Started on  Mon Feb  3 12:02:14 2014 vassil_g
** Last update Sun Mar  9 22:46:11 2014 vassil_g
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "my_msh.h"

t_mysh_er		cd_setenv(t_envp *envp, char *pwd)
{
  t_envl	*envl;
  char		*tmp;

  if (!(envl = msh_getenv_l(envp->envl, "OLDPWD")))
    return (BI_CD_NOOLDPWD);
  if (!(tmp = msh_getenv_v(envp->envl, "PWD")) || !*tmp)
    return (BI_CD_NOPWD);
  free(envl->name);
  if (!(envl->name = my_env_strcat("OLDPWD", tmp, '=')))
    return (MA_ERROR);
  envp->env[envl->env_nb] = envl->name;
  envl = msh_getenv_l(envp->envl, "PWD");
  free(envl->name);
  if (!(envl->name = my_env_strcat("PWD", pwd, '=')))
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
  tmp = my_strdub(tmp);
  return (cd_setenv(envp, tmp));
}

t_mysh_er		cd_rewind(t_envp *envp)
{
  char		*tmp;

  if (!(tmp = msh_getenv_v(envp->envl, "OLDPWD")))
    return (BI_CD_NOOLDPWD);
  else if (chdir(tmp) == -1)
    return (BI_CD_INVAOLDPWD);
  tmp = my_strdub(tmp);
  return (cd_setenv(envp, tmp));
}

t_mysh_er		init_pwd(t_envp *envp, t_usr_entry *entry, char **pwd)
{
  if (entry->arg[1][0] == '/')
    {
      if (!(*pwd = my_env_strcat(entry->arg[1], "", 0)))
	return (MA_ERROR);
    }
  else if (entry->arg[1][0] == '~')
    {
      if (!(*pwd = msh_getenv_v(envp->envl, "HOME")))
	return (BI_CD_NOHOME);
      else if (!(*pwd = my_env_strcat(*(pwd) + 1, entry->arg[1], '/')))
	return (MA_ERROR);
    }
  else
    {
      if (!(*pwd = msh_getenv_v(envp->envl, "PWD")))
	return (BI_CD_NOPWD);
      else if (!(*pwd = my_env_strcat(*pwd, entry->arg[1], '/')))
	return (MA_ERROR);
    }
  return (SUCCES);
}

t_mysh_er		msh_cd(t_envp *envp, t_usr_entry *entry)
{
  char		*pwd;
  t_mysh_er	er;

  if (!entry->arg[1])
    return (cd_gohome(envp));
  else if (entry->arg[1][0] == '-' && my_strlen(entry->arg[1]) == 1)
    return (cd_rewind(envp));
  if ((er = init_pwd(envp, entry, &pwd)) > 0)
    return (er);
  if (chdir(pwd) == -1)
    {
      free(pwd);
      return (BI_CD_INVAFOLDER);
    }
  else if (!(pwd = cd_dots(pwd)))
    return (MA_ERROR);
  return (cd_setenv(envp, pwd));
}
