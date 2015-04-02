/*
** my_aff.c for  in /home/simomb_s/semestre2/rendu/CPE_2014/Allum1
**
** Made by stephanedarcy simomba
** Login   <simomb_s@epitech.net>
**
** Started on  Wed Feb  4 05:07:04 2015 stephanedarcy simomba
** Last update Wed Feb 18 13:40:56 2015 stephanedarcy simomba
*/

#include "my.h"

void	aff_allum(int *line, int size)
{
  int	i;
  int	j;
  int	k;
  int	n;

  i = 0;
  n = size;
  while (i < size)
    {
      j = 0;
      k = 0;
      my_putstr("\t(");
      my_put_nbr(i + 1);
      my_putstr(")");
      while (k++ < n)
	my_putstr(" ");
      if (line[i] > 0)
	while (j++ < line[i])
	  my_putstr("|");
      my_putstr("\n");
      i++;
      n--;
    }
}
