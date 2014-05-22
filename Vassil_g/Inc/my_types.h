/*
** my_types.h for  in /home/vassil_g/rendu/PSU_2013_minitalk/Include
** 
** Made by vassil_g
** Login   <vassil_g@epitech.net>
** 
** Started on  Fri Mar 21 10:27:30 2014 vassil_g
** Last update Sun May  4 12:41:23 2014 vassil_g
*/

#ifndef MY_TYPES_H_
# define MY_TYPES_H_

#include <stdint.h>

typedef char			t_int8;
typedef unsigned char		t_uint8;

typedef short			t_int16;
typedef unsigned short		t_uint16;

typedef int			t_int32;
typedef unsigned int		t_uint32;

typedef long long		t_int64;
typedef unsigned long long	t_uint64;

#if	UINTPTR_MAX == 0xffffffffffffffff

typedef double			t_realnb;

#else

typedef float			t_realnb;

#endif /* !t_realnb def */

#endif /*!MY_TYPES_H_*/
