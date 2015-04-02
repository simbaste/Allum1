/*
** my_allum.c for  in /home/simomb_s/semestre2/rendu/CPE_2014/Allum1
**
** Made by stephanedarcy simomba
** Login   <simomb_s@epitech.net>
**
** Started on  Wed Feb  4 05:15:34 2015 stephanedarcy simomba
** Last update Sat Feb 21 22:10:05 2015 stephanedarcy simomba
*/

#include "my.h"

t_my	*my_loop1(t_my *val, int size)
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

int	check1(t_my *val)
{
  int	i;
  int	j;
  int	k;

  i = 0;
  j = 0;
  k = 0;
  if (val->j % 2 == 1)
    {
      while (i < val->j)
	{
	  if (val->line[val->v[i]] == 1)
	    j++;
	  else
	    k = i;
	  i++;
	}
      if (j >= (val->j - 1))
	{
	  val->line[val->v[k]] = 1;
	  return (1);
	}
    }
  return (0);
}

int	check2(t_my *val)
{
  int	i;
  int	j;
  int	k;

  i = 0;
  j = 0;
  k = 0;
  if (val->j % 2 == 0)
    {
      while (i < val->j)
	{
	  if (val->line[val->v[i]] == 1)
	    j++;
	  else
	    k = i;
	  i++;
	}
      if (j >= (val->j - 1))
	{
	  val->line[val->v[k]] = 0;
	  return (1);
	}
    }
  return (0);
}

void	my_ia(t_my *val, int size)
{
  int	i;
  int	s;

  i = 0;
  s = 0;
  val = my_loop1(val, size);
  if (check1(val) != 1)
    if (check2(val) != 1)
      {
	while (i < size)
	  s = s ^ val->line[i++];
	i = 0;
	if (s == 0)
	  val->line[val->v[0]] = 0;
	else
	  while (i < size)
	    {
	      if ((val->line[i] ^ s) < val->line[i])
		{
		  val->line[i] = val->line[i] ^ s;
		  i = size;
		}
	      i++;
	    }
      }
}

int	victoir(int *line, int size)
{
  int	j;
  int	i;

  j = 0;
  i = 0;
  while (i < size)
    {
      if (line[i] != 0)
	j++;
      i++;
    }
  if (j == 0)
    return (1);
  return (0);
}
