/*
** aff_g.c for  in /home/simomb_s/semestre2/rendu/CPE_2014/CPE_2014_allum1
**
** Made by stephanedarcy simomba
** Login   <simomb_s@epitech.net>
**
** Started on  Fri Feb 20 15:18:02 2015 stephanedarcy simomba
** Last update Sat Feb 21 21:39:35 2015 stephanedarcy simomba
*/

#include <stdlib.h>
#include "my.h"

int		loop_aff(t_sdl *sdl, t_my *val, SDL_Rect pos)
{
  int		x;
  int		i;
  int		j;

  j = 0;
  i = 0;
  x = 425;
  while (i < 4)
    {
      j = 0;
      while (j < val->line[i])
	{
	  if (my_put_end_in_list(&sdl->coord, pos, i + 1) == -1)
	    return (my_puterror("error in function put_end_in_list\n"));
	  SDL_BlitSurface(sdl->allum, NULL, sdl->ecran, &pos);
	  pos.x += 30;
	  j++;
	}
      x -= 30;
      pos.x = x;
      pos.y += 60;
      i++;
    }
  return (0);
}

int		aff(t_sdl *sdl, t_my *val)
{
  SDL_Rect	pos;

  pos.x = 0;
  pos.y = 0;
  SDL_BlitSurface(sdl->img_ft1, NULL, sdl->ecran, &pos);
  pos.x = 425;
  pos.y = 250;
  if (loop_aff(sdl, val, pos) == -1)
    return (-1);
  return (0);
}
