/*
** my_addr_strlen.c for Minishell1 in /home/vassil_g/Minishell1/Source/Common
** 
** Made by vassil_g
** Login   <vassil_g@epitech.net>
** 
** Started on  Mon Feb  3 14:20:16 2014 vassil_g
** Last update Mon Feb  3 15:44:14 2014 vassil_g
*/

unsigned int	my_addr_strlen(char **str)
{
  int		i;

  i = 0;
  while (str[i])
    ++i;
  return (i);
}
