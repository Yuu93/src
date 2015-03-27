/*
** client.h for  in /home/messao_y/rendu/PSU_2013_myftp
** 
** Made by messao_y
** Login   <messao_y@epitech.net>
** 
** Started on  Sat Apr 12 22:45:03 2014 messao_y
** Last update Tue Jul  8 01:27:40 2014 coskun_a
*/

#ifndef _CLIENTG_H
# define _CLIENTG_H

# include <netinet/in.h>
# include <SDL/SDL.h>
# include <SDL/SDL_image.h>

# define MSG "GRAPHIC\n"
# define WINDOWNAME "ZAPPY - CLIENT GRAPHIQUE"
# define CAM 10
# define BORDERSIZE 50
# define BLKSIZE 40

typedef struct		s_sock
{
  int			s;
  struct sockaddr_in	sin;
  int			port;
}			t_sock;

typedef struct    sprite_s
{
  char      *filename;
  SDL_Rect    rect;
  SDL_Surface   *sprite;
  struct sprite_s *next;
}     sprite_t;

typedef struct 		s_stone
{
  int			    nou;
  int	       	lin;
  int	       	der;
  int	       	sib;
  int	       	men;
  int	       	phi;
  int	       	thy;
  int			    egg;
}			t_stone;

typedef struct		s_scene
{
  int		map_x;
  int		map_y;
  int   cam_x;
  int   cam_y;
  SDL_Rect  rect;
  SDL_Surface *screen;
  sprite_t  **ground;
  sprite_t **ress;
  t_stone  	**map;
}			t_scene;

typedef struct  s_elem
{
  int data;
  void    (*fct_print)(int, t_scene *);
}   t_elem;


typedef struct		s_actions
{
  char		*cmd;
  int		len;
  void		(*f)();
}			t_actions;

// GETNEXTLINE
char		*getnextline(int);

// INIT_CO
char		*xgethostbyname(char *);
void		init_fd(t_sock *, fd_set *);
int		init_socket(t_sock *, char *, int);
int		init_connexion(t_sock *, char *, char *);

// INIT_MAP
void		init_ress(t_scene *, char *);
void		init_map(t_scene *, char *);
int		init_data(t_scene *, char *);

// GRAPHIC
void  move_cam(t_scene *, int);
void  init_ressources(t_scene *);
void  init_ground(t_scene *);
int		init_sdl(t_scene *);
void  init_sprites(t_scene *);

// STRTOWORDTAB
int count_word(char *);
int count_char(char *);
char		**my_str_to_wordtab(char *);

// PRINT
void  print_map(t_scene *);
void    print_all(t_scene *);
void  print_celldetails(t_scene *, int, int);

// PRINTCELL
int check_coord(int, int, int);
void   print_number(t_scene *scene, int i);
void print_one(int, t_scene *);
void print_two(int, t_scene *);
void print_three(int, t_scene *);

#endif /* !_CLIENT_H */
