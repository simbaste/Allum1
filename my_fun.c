/*
** my_func.c for  in /home/simomb_s/semestre2/rendu/CPE_2014/Allum1
**
** Made by stephanedarcy simomba
** Login   <simomb_s@epitech.net>
**
** Started on  Wed Feb  4 04:58:22 2015 stephanedarcy simomba
** Last update Sun Feb 22 20:39:27 2015 stephanedarcy simomba
*/

#include <stdlib.h>
#include "my.h"

void	my_fun(t_my *val, int size)
{
  int	i;
  char	*str;

  i = 0;
  my_putstr("\e[00;5;35m\n\tquelle ligne souhaitez ");
  my_putstr("vous modifier ? \e[0;0;39m");
  str = my_get_next_line(0);
  if (!str || !str[0])
    exit (0);
  val->ll = (my_getnbr(str) - 1);
  while ((val->ll < 0 || val->ll >= size || val->line[val->ll] == 0) && i < 50)
    {
      my_putstr("kaka\n");
      my_putstr("\e[00;5;35m\tnombre invalide!!!\e[0;0;39m");
      my_putstr("\e[00;5;35m\n\tquelle ligne souhaitez vous ");
      my_putstr("vous modifier ? \e[0;0;39m");
      str = my_get_next_line(0);
      val->ll = (my_getnbr(str) - 1);
      i++;
    }
  free(str);
  if (i == 50)
    exit(0);
}

void	fun1(t_my *val, int size)
{
  int	i;
  char	*str;

  i = 0;
  my_fun(val, size);
  my_putstr("\e[00;5;35m\tCombien d'allumettes souhaitez vous ");
  my_putstr("supprimer ? \e[0;0;39m");
  str = my_get_next_line(0);
  val->nb = my_getnbr(str);
  while ((val->nb <= 0 || val->nb > val->line[val->ll]) && i < 50)
    {
      my_putstr("kaka\n");
      my_putstr("\e[00;5;35m\tnombre invalide!!!\n\e[0;0;39m");
      my_putstr("\e[00;5;35m\tCombien d'allumettes souhaitez ");
      my_putstr("vous supprimer ? \e[0;0;39m");
      str = my_get_next_line(0);
      val->nb = my_getnbr(str);
      i++;
    }
  val->line[val->ll] = val->line[val->ll] - val->nb;
  aff_allum1(val->line, size);
  free(str);
  if (i == 50)
    exit(0);
}

void	fun2(int *c)
{
  char	*str;

  my_putstr("\e[00;5;38m\tDésolé vous venez de perdre ");
  my_putstr("la partie\n\n\e[0;0;39m");
  my_putstr("\e[00;5;38m\t(5) = quitter\n\e[0;0;39m");
  my_putstr("\e[00;5;38m\t(7) = continuer\n\e[0;0;39m");
  my_putstr("\e[00;5;38m\tchoix= \e[0;0;39m");
  str = my_get_next_line(0);
  *c = my_getnbr(str);
  while (*c != 5 && *c != 7)
    {
      my_putstr("kaka\n");
      my_putstr("\e[00;5;38m\tnombre invalide!!!\n\e[0;0;39m");
      my_putstr("\e[00;5;38m\t (5) = Quitter\n\t(7) = ");
      my_putstr("Continuer\n\e[0;0;39m");
      my_putstr("\e[00;5;38m\tchoix= \e[0;0;39m");
      str = my_get_next_line(0);
      *c = my_getnbr(str);
    }
  free(str);
}

void	fun3(t_my *val, int size, int *c)
{
  char	*str;

  if (val->niveau == 3)
    my_ia(val, size);
  else
    my_allum1(val, size);
  aff_allum1(val->line, size);
  if (victoir(val->line, size) == 1)
    {
      my_putstr("\e[00;5;38m\tFélicitation vous venez de gagner la partie");
      my_putstr("\n\t(5) = quitter\n\t(7) = continuer\n\tchoix\e[0;0;39m");
      str = my_get_next_line(0);
      *c = my_getnbr(str);
      while (*c != 5 && *c != 7)
	{
	  my_putstr("\e[00;5;38m\tnombre invalide!!!\n\e[0;0;39m");
	  my_putstr("\e[00;5;38m\t (5) = Quitter\n\t(7) = ");
	  my_putstr("Continuer\n\e[0;0;39m]");
	  my_putstr("\e[00;5;38m\tchoix= \e[0;0;39m");
	  str = my_get_next_line(0);
	  *c = my_getnbr(str);
	}
      free(str);
    }
  my_putstr("\e[00;5;35m\t IA viens de jouer ...\n\e[0;0;39m");
}
