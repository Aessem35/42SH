/*
** signal_handler.c for  in /home/vassil_g/rendu/42sh/Public/42SH/Src/Main
** 
** Made by vassil_g
** Login   <vassil_g@epitech.net>
** 
** Started on  Sun May 25 22:22:08 2014 vassil_g
** Last update Sun May 25 22:45:26 2014 vassil_g
*/

#include "signal.h"

void		sig_handler(int sig)
{
  (void)(sig);
}

void		init_signal()
{
  signal(SIGINT ,sig_handler);
  signal(SIGSEGV ,sig_handler);
  signal(SIGFPE ,sig_handler);
  signal(SIGBUS ,sig_handler);
  signal(SIGQUIT ,sig_handler);
  signal(SIGILL ,sig_handler);
  signal(SIGABRT ,sig_handler);
  signal(SIGSYS ,sig_handler);
  signal(SIGALRM ,sig_handler);
  signal(SIGUSR1 ,sig_handler);
  signal(SIGUSR2 ,sig_handler);
}

void		uninit_signal()
{
  signal(SIGINT ,SIG_DFL);
  signal(SIGSEGV ,SIG_DFL);
  signal(SIGFPE ,SIG_DFL);
  signal(SIGBUS ,SIG_DFL);
  signal(SIGQUIT ,SIG_DFL);
  signal(SIGILL ,SIG_DFL);
  signal(SIGABRT ,SIG_DFL);
  signal(SIGSYS ,SIG_DFL);
  signal(SIGALRM ,SIG_DFL);
  signal(SIGUSR1 ,SIG_DFL);
  signal(SIGUSR2 ,SIG_DFL);
}
