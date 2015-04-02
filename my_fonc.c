/*
** my_func.c for  in /home/simomb_s/semestre2/rendu/CPE_2014
**
** Made by stephanedarcy simomba
** Login   <simomb_s@epitech.net>
**
** Started on  Sun Feb 15 15:09:07 2015 stephanedarcy simomba
** Last update Fri Feb 20 17:54:09 2015 stephanedarcy simomba
*/

#include <unistd.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str && str[i] != 0)
    i++;
  return (i);
}

void	my_putstr(char *str)
{
  write(1, str, my_strlen(str));
}

int	my_puterror(char *str)
{
  write(2, str, my_strlen(str));
  return (-1);
}

int	my_strcmp(char *s1, char *s2)
{
  if (*s1 == *s2)
    {
      if (*s1 == 0)
	return (0);
      return (my_strcmp(s1 + 1, s2 + 1));
    }
  return (*s1 - *s2);
}
