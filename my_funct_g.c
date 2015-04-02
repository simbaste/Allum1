/*
** my_funct_g.c for  in /home/simomb_s/semestre2/rendu/CPE_2014/CPE_2014_allum1
**
** Made by stephanedarcy simomba
** Login   <simomb_s@epitech.net>
**
** Started on  Fri Feb 20 15:25:57 2015 stephanedarcy simomba
** Last update Sat Feb 21 22:06:47 2015 stephanedarcy simomba
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"

void	my_end(t_sdl *sdl, int nb)
{
  int	c;

  c = 0;
  if (nb == 1)
    SDL_BlitSurface(sdl->defaite, NULL, sdl->ecran, &sdl->tmp->pos);
  else
    SDL_BlitSurface(sdl->victoire, NULL, sdl->ecran, &sdl->tmp->pos);
  SDL_Flip(sdl->ecran);
  loop_end(sdl, &c);
}

void	my_loop2(t_sdl *sdl, int *b)
{
  int	i;

  i = 0;
  sdl->allum_r = IMG_Load("allumette-rouge.jpg");
  while (sdl->tmp != NULL)
    {
      if (sdl->event1.button.x >= sdl->tmp->pos.x && sdl->event1.button.x <=
	  sdl->tmp->pos.x + 10 && sdl->event1.button.y >= sdl->tmp->pos.y &&
	  sdl->event1.button.y <= sdl->tmp->pos.y + 50)
	{
	  *b = 1;
	  if (sdl->line == 0)
	    sdl->line = sdl->tmp->line;
	  if (sdl->tmp->line == sdl->line && sdl->tmp->nb == 0)
	    {
	      sdl->tmp->nb = 1;
	      SDL_BlitSurface(sdl->allum_r, NULL, sdl->ecran, &sdl->tmp->pos);
	      if (i++ == 0)
		sdl->nbr = sdl->nbr + 1;
	    }
	}
      sdl->tmp = sdl->tmp->next;
    }
  SDL_Flip(sdl->ecran);
}

void	cond1(t_sdl *sdl, t_my *val)
{
  if (sdl->line - 1 >= 0)
    val->line[sdl->line - 1] = val->line[sdl->line - 1] - sdl->nbr;
  if (victoir(val->line, 4) == 1)
    {
      my_end(sdl, 1);
      sdl->continuer1 = 1;
    }
  else
    {
      aff(sdl, val);
      if (val->niveau == 3)
	my_ia(val, 4);
      else
	my_allum1(val, 4);
      if (victoir(val->line, 4) == 1)
	{
	  my_end(sdl, 2);
	  sdl->continuer1 = 1;
	}
      else
	aff(sdl, val);
    }
  sdl->line = 0;
  sdl->nbr = 0;
}

int	loop_funct(t_sdl *sdl, t_my *val)
{
  int	b;

  b = 0;
  while (sdl->continuer1 == 0)
    {
      SDL_WaitEvent(&sdl->event1);
      if (sdl->event1.type == SDL_QUIT)
	sdl->continuer1 = 1;
      else if (sdl->event1.type == SDL_MOUSEBUTTONUP)
	{
	  sdl->tmp = sdl->coord;
	  my_loop2(sdl, &b);
	}
      else if (sdl->event1.type == SDL_KEYDOWN)
	{
	  if (sdl->event1.key.keysym.sym == SDLK_ESCAPE)
	    sdl->continuer1 = 1;
	  else if (sdl->event1.key.keysym.sym == SDLK_SPACE)
	    cond1(sdl, val);
	}
      if (b == 0)
	aff(sdl, val);
      SDL_Flip(sdl->ecran);
    }
  return (0);
}

int	funct(t_sdl *sdl, t_my *val, int niveau)
{
  sdl->tmp = NULL;
  sdl->coord = NULL;
  val->niveau = niveau;
  sdl->pos.x = 0;
  sdl->pos.y = 0;
  sdl->nbr = 0;
  sdl->line = 0;
  SDL_BlitSurface(sdl->img_ft1, NULL, sdl->ecran, &sdl->pos);
  loop_funct(sdl, val);
  SDL_Flip(sdl->ecran);
  return (0);
}
