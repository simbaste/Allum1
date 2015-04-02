/*
** my_func.c for  in /home/simomb_s/semestre2/rendu/CPE_2014/Allum1
**
** Made by stephanedarcy simomba
** Login   <simomb_s@epitech.net>
**
** Started on  Wed Feb  4 04:58:22 2015 stephanedarcy simomba
** Last update Sun Feb 22 20:29:05 2015 stephanedarcy simomba
*/

#include <stdlib.h>
#include "my.h"

void	my_func(t_my *val, int size)
{
  int	i;
  char	*str;

  i = 0;
  my_putstr("\n\tquelle ligne souhaitez ");
  my_putstr("vous modifier ? ");
  str = my_get_next_line(0);
  val->ll = (my_getnbr(str) - 1);
  while ((val->ll < 0 || val->ll >= size || val->line[val->ll] == 0) && i < 50)
    {
      my_putstr("\tnombre invalide!!!");
      my_putstr("\n\tquelle ligne souhaitez vous ");
      my_putstr("vous modifier ? ");
      str = my_get_next_line(0);
      val->ll = (my_getnbr(str) - 1);
      i++;
    }
  free(str);
  if (i == 50)
    exit(0);
}

void	func1(t_my *val, int size)
{
  int	i;
  char	*str;

  i = 0;
  my_func(val, size);
  my_putstr("\tCombien d'allumettes souhaitez vous ");
  my_putstr("supprimer ? ");
  str = my_get_next_line(0);
  val->nb = my_getnbr(str);
  while ((val->nb <= 0 || val->nb > val->line[val->ll]) && i < 50)
    {
      my_putstr("\tnombre invalide!!!\n");
      my_putstr("\tCombien d'allumettes souhaitez ");
      my_putstr("vous supprimer ? ");
      str = my_get_next_line(0);
      val->nb = my_getnbr(str);
      i++;
    }
  val->line[val->ll] = val->line[val->ll] - val->nb;
  aff_allum(val->line, size);
  free(str);
  if (i == 50)
    exit(0);
}

void	func2(int *c)
{
  char	*str;

  my_putstr("\tDésolé vous venez de perdre ");
  my_putstr("la partie\n\n");
  my_putstr("\t(5) = quitter\n");
  my_putstr("\t(7) = continuer\n");
  my_putstr("\tchoix= ");
  str = my_get_next_line(0);
  *c = my_getnbr(str);
  while (*c != 5 && *c != 7)
    {
      my_putstr("\tnombre invalide!!!\n");
      my_putstr("\t (5) = Quitter\n\t(7) = ");
      my_putstr("Continuer\n");
      my_putstr("\tchoix= ");
      str = my_get_next_line(0);
      *c = my_getnbr(str);
    }
  free(str);
}

void	func3(t_my *val, int size, int *c)
{
  char	*str;

  my_ia(val, size);
  my_putstr("\t IA viens de jouer ...\n");
  aff_allum(val->line, size);
  if (victoir(val->line, size) == 1)
    {
      my_putstr("\tFélicitation vous venez de gagner ");
      my_putstr("la partie\n\n");
      my_putstr("\t(5) = quitter\n");
      my_putstr("\t(7) = continuer\n");
      my_putstr("\tchoix= ");
      str = my_get_next_line(0);
      *c = my_getnbr(str);
      while (*c != 5 && *c != 7)
	{
	  my_putstr("\tnombre invalide!!!\n");
	  my_putstr("\t (5) = Quitter\n\t(7) = Continuer\n");
	  my_putstr("\tchoix= ");
	  str = my_get_next_line(0);
	  *c = my_getnbr(str);
	}
      free(str);
    }
}
