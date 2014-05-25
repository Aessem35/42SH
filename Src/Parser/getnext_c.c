/*
** getnext_c.c for  in /home/vassil_g/rendu/42sh/Public/42SH/Src/Parser
** 
** Made by vassil_g
** Login   <vassil_g@epitech.net>
** 
** Started on  Sun May 25 17:02:24 2014 vassil_g
** Last update Sun May 25 17:05:12 2014 vassil_g
*/

char			*getnext_c(char *str, char c)
{
  while (*str && *str != c)
    ++str;
  return (str);
}
