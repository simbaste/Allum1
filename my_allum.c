/*
** my_allum.c for  in /home/simomb_s/semestre2/rendu/CPE_2014/Allum1
**
** Made by stephanedarcy simomba
** Login   <simomb_s@epitech.net>
**
** Started on  Wed Feb  4 05:15:34 2015 stephanedarcy simomba
** Last update Sat Feb 21 22:13:52 2015 stephanedarcy simomba
*/

#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "my.h"

t_my	*my_loop(t_my *val, int size)
{
  int	i;

  i = 0;
  val->j = 0;
  while (i < size)
    {
      if (val->line[i] >= 1)
	val->v[(val->j)++] = i;
      i++;
    }
  return (val);
}

t_my	*final(t_my *val, int size)
{
  int	ll;
  int	i;

  i = 0;
  ll = random() % (size - 1);
  while (val->line[ll] == 0)
    {
      ll = random() % (size - 1);
      if (i++ == size)
	return (val);
    }
  val->j = val->line[ll] - (random() % val->line[ll]);
  while (val->j < 0 || val->j == val->line[ll])
    val->j = val->line[ll] - ((random() + ((random() % 42)))
			      % val->line[ll]) - 1;
  val->line[ll] = val->j;
  return (val);
}

t_my	*last2(t_my *val)
{
  if (val->line[val->v[0]] == 1)
    val->line[val->v[1]] = 0;
  else if (val->line[val->v[1]] == 1)
    val->line[val->v[0]] = 0;
  else if (val->line[val->v[0]] > 3 && val->line[val->v[1]] <= 3)
    {
      if (val->line[val->v[1]] == 3)
	val->line[val->v[0]] = val->line[val->v[0]] - (val->line[val->v[0]] - 3);
      else if (val->line[val->v[1]] == 2)
	val->line[val->v[0]] = val->line[val->v[0]] - (val->line[val->v[0]] - 2);
    }
  else if (val->line[val->v[1]] > 3 && val->line[val->v[0]] <= 3)
    {
      if (val->line[val->v[0]] == 3)
	val->line[val->v[1]] = val->line[val->v[1]] - (val->line[val->v[1]] - 3);
      else if (val->line[val->v[0]] == 2)
	val->line[val->v[1]] = val->line[val->v[1]] - (val->line[val->v[1]] - 2);
    }
  else
    val->line[val->v[1]] = val->line[val->v[1]] - 1;
  return (val);
}

void	my_allum1(t_my *val, int size)
{
  srandom(time(0) * getpid());
  val = my_loop(val, size);
  if (val->j == 2 && val->niveau)
    val = last2(val);
  else if (val->j == 1 && val->line[val->v[0]] >= 2)
    val->line[val->v[0]] = val->line[val->v[0]] - (val->line[val->v[0]] - 1);
  else if (val->j == 1)
    val->line[val->v[0]] = 0;
  else
    val = final(val, size);
}

int	init(t_my *val, int size)
{
  int	i;
  int	j;

  i = 0;
  j = 1;
  if ((val->line = malloc(size * sizeof(*val->line))) == NULL)
    return (-1);
  while (i < size)
    {
      val->line[i] = j;
      j = j + 2;
      i++;
    }
  return (0);
}
