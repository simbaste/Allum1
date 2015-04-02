/*
** my_put_in_list.c for  in /home/simomb_s/semestre2/test_maison/minishell2
**
** Made by stephanedarcy simomba
** Login   <simomb_s@epitech.net>
**
** Started on  Sun Feb  8 11:01:32 2015 stephanedarcy simomba
** Last update Fri Feb 20 17:41:10 2015 stephanedarcy simomba
*/

#include "my.h"

int		my_put_in_list(t_coord **coord, SDL_Rect pos)
{
  t_coord	*elem;

  if ((elem = malloc(sizeof(t_coord))) == NULL)
    return (-1);
  elem->pos = pos;
  elem->prev = NULL;
  if (*coord != NULL)
    (*coord)->prev = elem;
  elem->next = *coord;
  *coord = elem;
  return (0);
}

int		my_put_end_in_list(t_coord **coord, SDL_Rect pos, int i)
{
  t_coord	*tmp;
  t_coord	*elem;

  tmp = *coord;
  if ((elem = malloc(sizeof(t_coord))) == NULL)
    return (-1);
  elem->pos = pos;
  elem->line = i;
  elem->nb = 0;
  elem->next = NULL;
  if (tmp == NULL)
    {
      *coord = elem;
      return (0);
    }
  while (tmp->next != NULL)
    tmp = tmp->next;
  elem->prev = tmp;
  tmp->next = elem;
  return (0);
}
