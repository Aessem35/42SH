/*
** msh_er.h for  in /home/vassil_g/rendu/42sh/Private/Inc
** 
** Made by vassil_g
** Login   <vassil_g@epitech.net>
** 
** Started on  Thu May 22 11:21:53 2014 vassil_g
** Last update Wed May 28 10:16:41 2014 vassil_g
*/

#ifndef MSH_ER_H__
# define MSH_ER_H__

/*
** ERROR VALUE
*/
# define SUCCES			(0)
# define MA_ERROR		(1 << 4)
# define BI_UENV_USE		(1 << 5)
# define BI_UENV_NF		(1 << 6)
# define BI_SENV_USE		(1 << 7)
# define ESTWT_MA_ERROR		(1 << 8)
# define STWT_MA_ERROR		(1 << 9)
# define EXEC_NF		(1 << 10)
# define EXEC_NOPATH		(1 << 11)
# define EXEC_FORK_FAILURE	(1 << 12)
# define BI_CD_NOPWD		(1 << 13)
# define BI_CD_NOOLDPWD		(1 << 14)
# define BI_CD_INVAOLDPWD	(1 << 15)
# define BI_CD_NOHOME		(1 << 16)
# define BI_CD_INVAHOME		(1 << 17)
# define BI_CD_INVAFOLDER	(1 << 18)
# define BI_ENV_USE		(1 << 19)


/*
** ERROR MSG
*/
# define MA_ERROR_MSG		"Memory allocation error\n"
# define ESTWT_MA_ERROR_MSG	"ESTWT memory allocation error, you should free memory or behavior of the program will be undefined\n"
# define STWT_MA_ERROR_MSG	"STWT memory allocation error, you should free memory or behavior of the program will be undefined\n"

# define BI_ENV_USE_MSG		"is an invalide option\nUsage : env -'option' (-0, -i)\n"

# define BI_SENV_USE_MSG	"Usage : setenv 'variable name' 'variable value'\n"

# define BI_UENV_USE_MSG	"Usage : unsetenv 'variable name'\n"
# define BI_UENV_NF_MSG		"environment name variable not found\n"

# define EXEC_NF_MSG		"command not found\n"
# define EXEC_NOPATH_MSG	"Environment PATH variable is not set\n"
# define EXEC_FORK_FAILURE_MSG	"Fork critical failure\n"

# define BI_CD_NOPWD_MSG	"Environment variable PWD is not set\n"
# define BI_CD_NOOLDPWD_MSG	"Environment variable OLDPWD is not set\n"
# define BI_CD_INVAOLDPWD_MSG	"Environment variable OLDPWD is invalid\n"
# define BI_CD_NOHOME_MSG	"Environment variable HOME is not set\n"
# define BI_CD_INVAFOLDER_MSG	"No such file or directory\n"
# define BI_CD_INVAHOME_MSG	"Environment variable HOME is invalid\n"

#endif /*!MSH_ER_H__*/
