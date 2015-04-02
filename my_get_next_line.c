/*
** my_get_next_line.c for  in /home/simomb_s/semestre2/rendu/CPE_2014/Allum1
**
** Made by stephanedarcy simomba
** Login   <simomb_s@epitech.net>
**
** Started on  Wed Feb  4 13:59:01 2015 stephanedarcy simomba
** Last update Fri Feb 20 17:59:27 2015 stephanedarcy simomba
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"

char		*my_realloc(char *str, int size)
{
  int		i;
  char		*src;

  i = 0;
  if ((src = malloc((my_strlen(str)) + size)) == NULL)
    return (NULL);
  while (str[i] != 0)
    {
      src[i] = str[i];
      i++;
    }
  src[i] = '\0';
  free(str);
  return (src);
}

char		*init_str(char *buff)
{
  char		*str;
  int		i;
  int		j;

  i = 0;
  j = 0;
  if ((str = malloc(MY_ABS(NBR_READ) + 2)) == NULL)
    return (NULL);
  if (buff[i] != '\n' || buff[i] != '\0')
    {
      while (i < NBR_READ)
	{
	  if (buff[i] == '\0' || buff[i] == '\n')
	    {
	      i++;
	      while (buff[i] != '\0' && i < NBR_READ)
		str[j++] = buff[i++];
	    }
	  i++;
	}
    }
  return (str);
}

char		*my_get_next_line(const int fd)
{
  static char	buff[MY_ABS(NBR_READ) + 1];
  static char	*str;
  int		n;
  int		j;
  int		i;

  j = 0;
  str = init_str(buff);
  while ((n = read(fd, buff, MY_ABS(NBR_READ))) > 0)
    {
      i = 0;
      while (i < n)
	{
	  if (buff[i] == '\n' || buff[i] == '\0')
	    {
	      str[j] = '\0';
	      return (str);
	    }
	  str[j++] = buff[i++];
	}
      if ((str = my_realloc(str, NBR_READ + 3)) == NULL)
	return (NULL);
    }
  return (NULL);
}
