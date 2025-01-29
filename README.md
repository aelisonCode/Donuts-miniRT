TO_DO:
	- add cylinder, other ???
	- add other object and put_pixel the furthest to the nearest
	- add fond (for shadow)
	- do shadow
	- select object and control it to : translate, rotate,.....


MAKEFILE:
  - compile le tout et les inclus pour etre utilise
  - place les fichiers objets dans le dossier obj, avec leur dossier associe
  - verifie la norm avec "make n"
  - compile en mode debug et creer executable "no leaks" : "make grind"
  - execute programme avec/sans arguments : \
      "make run" : compile et execute le programme \
      "make run ARG=..." : compile et execute avec un ou des arguments \
      "make v" : compile en mode debug et execute avec valgrind \
    
INCLUDE:
- libft bonus: la libft et les listes simplement chaine
- ft_printf: contient les options: %p %c %s %d %i %u %x %X %%

Main actuel:
 - Cree la window, ptr sur mlx
 - close window et free corectement en appuiyant sur echappe ou la croix
