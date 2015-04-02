##
## Makefile for Makefile in /home/simomb_s/semestre1/tests_maison/TP_systeme_unix/TP1
##
## Made by stephanedarcy simomba
## Login   <simomb_s@epitech.net>
##
## Started on  Mon Nov 24 10:58:02 2014 stephanedarcy simomba
## Last update Sat Feb 21 22:28:17 2015 stephanedarcy simomba
##

SRC	= main.c\
	  my_getnbr.c\
	  graphic.c\
	  my_ia.c\
	  my_put_in_list.c\
	  my_fonc.c\
	  texte.c\
	  my_func.c\
	  my_funct_g.c\
	  my_fun.c\
	  my_aff.c\
	  aff_g.c\
	  my_aff1.c\
	  my_allum.c\
	  my_put_nbr.c\
	  my_get_next_line.c

OBJ	= $(SRC:.c=.o)

 CFLAGS	+= -W -Wall -Wextra
 CFLAGS	+=

NAME	= allum1

all	: $(NAME) TEXTE

TEXTE	:
	@echo -e "\e[00;5;32m   _____            __             _____ .__ .__            _________                           .__ .__            __   .__                           __"
	@echo -e "  /     \  _____   |  | __  ____ _/ ____\|__||  |    ____   \_   ___ \   ____    _____  ______  |__||  |  _____  _/  |_ |__|  ____    ____     ____  |  | __"
	@echo -e " /  \ /  \ \__  \  |  |/ /_/ __ \ \   __\|  ||  |  _/ __ \  /    \  \/  /  _ \  /     \ \____ \ |  ||  |  \__  \ \   __\|  | /  _ \  /    \   /  _ \ |  |/ /"
	@echo -e "/    Y    \ / __ \_|    < \  ___/ |  |   |  ||  |__\  ___/  \     \____(  <_> )|  Y Y  \|  |_> >|  ||  |__ / __ \_|  |  |  |(  <_> )|   |  \ (  <_> )|    <"
	@echo -e "\____|__  /(____  /|__|_ \ \___  >|__|   |__||____/ \___  >  \______  / \____/ |__|_|  /|   __/ |__||____/(____  /|__|  |__| \____/ |___|  /  \____/ |__|_ \ "
	@echo -e "        \/      \/      \/     \/                       \/          \/               \/ |__|                   \/                        \/               \/ \e[0;0;39m"

$(NAME)	: $(OBJ)
	cc -o $(NAME) $(OBJ) $(CFLAGS) -lSDL -lSDL_image -lncurses

clean	:
	rm -rf $(OBJ)

fclean	: clean
	rm -rf $(NAME)

re	: fclean all

.PHONY	: all clean fclean re
