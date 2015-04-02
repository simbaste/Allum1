/*
** main.c for  in /home/simomb_s/semestre2/rendu/CPE_2014
**
** Made by stephanedarcy simomba
** Login   <simomb_s@epitech.net>
**
** Started on  Sun Feb 15 14:59:23 2015 stephanedarcy simomba
** Last update Sat Feb 21 22:20:30 2015 stephanedarcy simomba
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"

void		loop_end(t_sdl *sdl, int *c)
{
  while (*c == 0)
    {
      SDL_WaitEvent(&sdl->event2);
      if (sdl->event2.type == SDL_QUIT)
	*c = 2;
      else if (sdl->event2.type == SDL_MOUSEBUTTONUP)
	{
	  if (sdl->event2.button.x >= 562 && sdl->event2.button.x <= 819
	      && sdl->event2.button.y >= 358 && sdl->event2.button.y <= 392)
	    *c = 1;
	  else if (sdl->event2.button.x >= 566 && sdl->event2.button.x <= 768 &&
		   sdl->event2.button.y >= 453 && sdl->event2.button.y <= 480)
	    exit(EXIT_SUCCESS);
	}
    }
}

int		init_sdl(t_sdl *sdl)
{
  sdl->pos.x = 0;
  sdl->pos.y = 0;
  if (SDL_Init(SDL_INIT_VIDEO) == -1)
    return (my_puterror("Erreur d'initialisation de la SDL\n"));
  SDL_WM_SetIcon(SDL_LoadBMP("sdl_icon.bmp"), NULL);
  if ((sdl->ecran = SDL_SetVideoMode(850, 500, 32, SDL_HWSURFACE)) == NULL)
    return (my_puterror("Impossible de charger le mode vidéo\n"));
  SDL_WM_SetCaption("ALUM1_SIMOMB_S", NULL);
  sdl->menu = IMG_Load("menu_img.jpg");
  sdl->img_ft = IMG_Load("font.jpg");
  SDL_BlitSurface(sdl->img_ft, NULL, sdl->ecran, &sdl->pos);
  return (0);
}

int		fg(t_sdl *sdl, t_my *val)
{
  sdl->continuer1 = 0;
  if (init(val, 4) == -1)
    return (my_puterror("error in function init\n"));
  SDL_WaitEvent(&sdl->event);
  if (sdl->event.type == SDL_QUIT)
    sdl->continuer = 0;
  return (0);
}

int		loop_graphic(t_sdl *sdl, t_my *val)
{
  while (sdl->continuer == 0)
    {
      if (fg(sdl, val) == -1)
	return (-1);
      if (sdl->event.type == SDL_QUIT)
	sdl->continuer = 1;
      if (sdl->event.type == SDL_KEYDOWN)
	if (sdl->event.key.keysym.sym == SDLK_ESCAPE)
	  sdl->continuer = 1;
      if (sdl->event.type == SDL_MOUSEBUTTONUP)
	{
	  if (sdl->event.button.x >= 387 && sdl->event.button.x <= 521 &&
	      sdl->event.button.y >= 190 && sdl->event.button.y <= 210)
	    funct(sdl, val, 1);
	  if (sdl->event.button.x >= 357 && sdl->event.button.x <= 546 &&
	      sdl->event.button.y >= 240 && sdl->event.button.y <= 257)
	    funct(sdl, val, 2);
	  if (sdl->event.button.x >= 356 && sdl->event.button.x <= 554 &&
	      sdl->event.button.y >= 289 && sdl->event.button.y <= 307)
	    funct(sdl, val, 3);
	}
      SDL_BlitSurface(sdl->menu, NULL, sdl->ecran, &sdl->pos);
      SDL_Flip(sdl->ecran);
    }
  return (0);
}

int		graphic()
{
  t_sdl		sdl;
  t_my		val;

  val.line = NULL;

  if (init_sdl(&sdl) == -1)
    return (-1);
  sdl.allum = IMG_Load("allumette.jpg");
  sdl.img_ft1 = IMG_Load("font_jeu.jpg");
  sdl.victoire = IMG_Load("victoire.jpg");
  sdl.defaite = IMG_Load("defaite.jpg");
  sdl.continuer = 0;
  sdl.continuer1 = 0;
  loop_graphic(&sdl, &val);
  SDL_FreeSurface(sdl.menu);
  SDL_FreeSurface(sdl.allum);
  SDL_FreeSurface(sdl.img_ft1);
  SDL_FreeSurface(sdl.victoire);
  SDL_FreeSurface(sdl.defaite);
  SDL_FreeSurface(sdl.img_ft);
  SDL_Quit();
  return (0);
}
