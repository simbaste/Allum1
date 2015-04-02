/*
** main.c for  in /home/simomb_s/semestre2/rendu/CPE_2014/Allum1
**
** Made by stephanedarcy simomba
** Login   <simomb_s@epitech.net>
**
** Started on  Mon Feb  2 10:52:22 2015 stephanedarcy simomba
** Last update Sun Feb 22 20:38:01 2015 stephanedarcy simomba
*/

#include <stdio.h>
#include "my.h"

void	intro1(t_my *val)
{
  int	i;
  char	*str;

  i = 0;
  my_putstr("\e[00;5;35m\t(1) = debutant\n\t(2) = Intermediaire ");
  my_putstr("\n\t(3) = Professionnel.\n\e[0;0;39m");
  my_putstr("\e[00;5;35m\tchoix= \e[0;0;39m");
  str = my_get_next_line(0);
  val->niveau = my_getnbr(str);
  while ((val->niveau < 1 || val->niveau > 3) && i < 50)
    {
      my_putstr("\e[00;5;35m\tnombre invalide!!!\n\tVeuillez ");
      my_putstr("rentrer une valeure correct.\n\e[0;0;39m");
      my_putstr("\e[00;5;35m\tchoix= \e[0;0;39m");
      str = my_get_next_line(0);
      val->niveau = my_getnbr(str);
      i++;
    }
  free(str);
  if (i == 50)
    exit(0);
}

int	my_level1(t_my *val, int *size)
{
  int	i;
  char	*str;

  i = 0;
  my_putstr("\e[00;5;35m\tAvec combien de lignes souhaitez vous jouer ?");
  my_putstr("\n\tVotre nombre doit être compris entre 2 et 100\n\e[0;0;39m");
  my_putstr("\e[00;5;35m\tchoix= \e[0;0;39m");
  str = my_get_next_line(0);
  *size = my_getnbr(str);
  while ((*size < 2 || *size > 100) && i < 50)
    {
      my_putstr("\e[00;5;35m\tnombre invalide!!!\n\tVeuillez ");
      my_putstr("rentrer une valeure correct.\n\e[0;0;39m");
      my_putstr("\e[00;5;35m\tchoix= \e[0;0;39m");
      str = my_get_next_line(0);
      *size = my_getnbr(str);
      i++;
    }
  if (init(val, *size) == -1)
    return (-1);
  aff_allum1(val->line, *size);
  free(str);
  if (i == 50)
    exit(0);
  return (0);
}

int	texte()
{
  t_my	val;
  int	size;
  int	c;

  val.line = NULL;
  msg1();
  c = 2;
  while (c != 5)
    {
      c = 2;
      intro1(&val);
      if ((my_level1(&val, &size)) == -1)
	return (-1);
      while (c != 5 && c != 7)
	{
	  fun1(&val, size);
	  if (victoir(val.line, size) == 1)
	    fun2(&c);
	  else
	    fun3(&val, size, &c);
	}
    }
  return (0);
}
