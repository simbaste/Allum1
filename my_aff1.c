/*
** my_aff.c for  in /home/simomb_s/semestre2/rendu/CPE_2014/Allum1
**
** Made by stephanedarcy simomba
** Login   <simomb_s@epitech.net>
**
** Started on  Wed Feb  4 05:07:04 2015 stephanedarcy simomba
** Last update Sat Feb 21 23:13:02 2015 stephanedarcy simomba
*/

#include <ncurses/curses.h>
#include <termios.h>
#include <term.h>
#include "my.h"

int	clear_term()
{
  char	*res;
  char	*name_term;

  if ((name_term = getenv("TERM")) == NULL)
    return (my_puterror("getenv error !!\n"));
  if ((tgetent(NULL, name_term)) == -1)
    return (my_puterror("tgetent error!!\n"));
  if ((res = tgetstr("cl", NULL)) == NULL)
    return (my_puterror("tgetstr error !!\n"));
  my_putstr(res);
  return (0);
}

void	aligne(int i)
{
  if (i + 1 < 10)
    my_putstr("\t   (");
  else if (i + 1 < 100)
    my_putstr("\t  (");
  else
    my_putstr("\t (");
}

void	aff_allum1(int *line, int size)
{
  int	i;
  int	j;
  int	k;
  int	n;

  i = 0;
  n = size;
  clear_term();
  while (i < size)
    {
      j = 0;
      k = 0;
      my_putstr("\e[00;5;32m");
      aligne(i);
      my_put_nbr(i + 1);
      my_putstr(")");
      while (k++ < n)
	my_putstr(" ");
      if (line[i] > 0)
	while (j++ < line[i])
	  my_putstr("\e[00;5;33m|\e[0;0;39m");
      my_putstr("\n\e[0;0;39m");
      i++;
      n--;
    }
}

void	msg1()
{
  my_putstr("\e[00;5;32m\n\tBIENVENUE SUR ALLUM1\n\n\e[0;0;39m");
  my_putstr("\e[00;5;35m\tChaque joueur peut, sur une ");
  my_putstr("même ranger prendre une ou plusieurs allumettes\n\e[0;0;39m");
  my_putstr("\e[00;5;35m\tLe joueur qui perd est celui ");
  my_putstr("qui prend la dernieère.\n\e[0;0;39m");
  my_putstr("\e[00;5;35m\tchoisisez un niveau de difficulté\n\n\n\e[0;0;39m");
}
