/*
** main.c for  in /home/simomb_s/semestre2/rendu/CPE_2014/Allum1
**
** Made by stephanedarcy simomba
** Login   <simomb_s@epitech.net>
**
** Started on  Mon Feb  2 10:52:22 2015 stephanedarcy simomba
** Last update Sat Feb 21 21:44:19 2015 stephanedarcy simomba
*/

#include <stdlib.h>
#include "my.h"

void	intro(t_my *val)
{
  char	*str;

  my_putstr("\t(1) = debutant\n\t(2) = Intermediaire ");
  my_putstr("\n\t(3) = Professionnel.\n");
  my_putstr("\tchoix= ");
  str = my_get_next_line(0);
  val->niveau = my_getnbr(str);
  while (val->niveau < 1 || val->niveau > 3)
    {
      my_putstr("\tnombre invalide!!!\n\tVeuillez ");
      my_putstr("rentrer une valeure correct.\n");
      my_putstr("\tchoix= ");
      str = my_get_next_line(0);
      val->niveau = my_getnbr(str);
    }
  free(str);
}

int	my_level(t_my *val, int *size)
{
  if (init(val, *size) == -1)
    return (-1);
  aff_allum(val->line, *size);
  return (0);
}

int	my_game(t_my val)
{
  int	size;
  int	c;

  c = 2;
  size = 4;
  val.niveau = 3;
  while (c != 5)
    {
      c = 2;
      if ((my_level(&val, &size)) == -1)
	return (-1);
      while (c != 5 && c != 7)
	{
	  func1(&val, size);
	  if (victoir(val.line, size) == 1)
	    func2(&c);
	  else
	    func3(&val, size, &c);
	}
    }
  return (0);
}

int	main(int ac, char **av)
{
  t_my	val;

  val.line = NULL;
  if (ac > 1 && my_strcmp(av[1], "-t") == 0)
    texte();
  else if (ac > 1 && my_strcmp(av[1], "-g") == 0)
    graphic();
  else
    if (my_game(val) == -1)
      return (-1);
  return (0);
}
