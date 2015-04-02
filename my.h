/*
** my.h for  in /home/simomb_s/semestre2/rendu/CPE_2014
**
** Made by stephanedarcy simomba
** Login   <simomb_s@epitech.net>
**
** Started on  Sun Feb 15 16:54:51 2015 stephanedarcy simomba
** Last update Sat Feb 21 21:38:21 2015 stephanedarcy simomba
*/

#ifndef __MY_H__
# define __MY_H__

# include <SDL/SDL.h>
# include <SDL/SDL_image.h>

# define NBR_READ 9
# define MY_ABS(x) ((x) < 0) ? (-x) : (x)

typedef struct	s_my
{
  int		*line;
  int		ll;
  int		nb;
  int		j;
  int		niveau;
  int		v[100];
}		t_my;

typedef struct	s_var
{
  int		i;
  int		j;
  int		k;
  int		l;
  int		m;
  int		n;
  int		nbr;
}		t_var;

typedef struct		s_coord
{
  SDL_Rect		pos;
  int			line;
  int			nb;
  struct s_coord	*next;
  struct s_coord	*prev;
}			t_coord;

typedef struct		s_sdl
{
  SDL_Surface		*ecran;
  SDL_Surface		*menu;
  SDL_Surface		*img_ft;
  SDL_Surface		*img_ft1;
  SDL_Surface		*allum;
  SDL_Surface		*victoire;
  SDL_Surface		*defaite;
  SDL_Event		event;
  SDL_Event		event1;
  SDL_Event		event2;
  SDL_Rect		pos;
  SDL_Surface		*allum_r;
  t_coord		*coord;
  t_coord		*tmp;
  int			line;
  int			nb;
  int			nbr;
  int			continuer;
  int			continuer1;
}			t_sdl;

int	my_puterror(char *str);
void	my_putchar(char c);
int	my_putstr(char *str);
int	my_getnbr(char *str);
int	my_put_nbr(int nb);
int	my_strcmp(char *s1, char *s2);
int	my_strlen(char *str);
void	func1(t_my *val, int size);
void	fun1(t_my *val, int size);
void	func2(int *c);
void	fun2(int *c);
void	func3(t_my *val, int size, int *c);
void	fun3(t_my *val, int size, int *c);
void	aff_allum(int *line, int size);
void	aff_allum1(int *line, int size);
int	victoir(int *line, int size);
void	msg1();
void	my_ia(t_my *val, int size);
void	my_allum1(t_my *val, int size);
int	funct(t_sdl *sdl, t_my *val, int niveau);
int	init(t_my *val, int size);
t_my	*my_loop(t_my *val, int size);
void	loop_end(t_sdl *sdl, int *c);
t_my	*last2(t_my *val);
t_my	*final(t_my *val, int size);
int	texte();
int	aff(t_sdl *sdl, t_my *val);
int	graphic();
char	*my_get_next_line(const int fd);
int	my_put_in_list(t_coord **coord, SDL_Rect pos);
int	my_put_end_in_list(t_coord **coord, SDL_Rect pos, int i);

#endif /* !__MY_H__ */
