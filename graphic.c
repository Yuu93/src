/*
** graphic.c for graphic in /home/messao_y/clientzappy
** 
** Made by messao_y
** Login   <messao_y@epitech.net>
** 
** Stfd_set   readf;arted on  Sun Jun 29 19:53:10 2014 messao_y
** Last update Tue Jul  8 01:30:25 2014 messao_y
*/

#include "clientg.h"

void  move_cam(t_scene *scene, int direction)
{
  if (direction == 1 && scene->cam_x > 0)
    scene->cam_x--;
  else if (direction == 2 && scene->cam_x < scene->map_x - CAM)
    scene->cam_x++;
  else if (direction == 3 && scene->cam_y > 0)
    scene->cam_y--;
  else if (direction == 4 && scene->cam_y < scene->map_y - CAM)
    scene->cam_y++;
}

void 	init_ground(t_scene *scene)
{
  SDL_Surface *outbox;

  scene->ground = malloc(1 * sizeof(*scene->ground));
  scene->ground[0] = malloc(sizeof(*scene->ground[0]));
  scene->ground[0]->sprite = IMG_Load("sprites/ground.bmp");
  scene->ground[0]->filename = strdup("sprites/ground.bmp");
  outbox = IMG_Load("sprites/outbox.png");
  scene->rect.x = 0;
  scene->rect.y = 0;
  SDL_BlitSurface(outbox, NULL, scene->screen, &scene->rect);
}

void init_ressources(t_scene *scene)
{
  scene->ress = malloc(6 * sizeof(*scene->ress));
  scene->ress[0] = malloc(sizeof(*scene->ress[0]));
  scene->ress[0]->sprite = IMG_Load("sprites/lin.png");
   scene->ress[1] = malloc(sizeof(*scene->ress[1]));
  scene->ress[1]->sprite = IMG_Load("sprites/der.png");
   scene->ress[2] = malloc(sizeof(*scene->ress[2]));
  scene->ress[2]->sprite = IMG_Load("sprites/sib.png");
   scene->ress[3] = malloc(sizeof(*scene->ress[3]));
  scene->ress[3]->sprite = IMG_Load("sprites/men.png");
   scene->ress[4] = malloc(sizeof(*scene->ress[4]));
  scene->ress[4]->sprite = IMG_Load("sprites/phi.png");
   scene->ress[5] = malloc(sizeof(*scene->ress[5]));
  scene->ress[5]->sprite = IMG_Load("sprites/thy.png");
     scene->ress[6] = malloc(sizeof(*scene->ress[6]));
  scene->ress[6]->sprite = IMG_Load("sprites/nou.png");
}

void 	init_sprites(t_scene *scene)
{
  init_ground(scene);
  init_ressources(scene);
}

int		init_sdl(t_scene *s)
{
  if (SDL_Init(SDL_INIT_VIDEO) == -1)
    return (-1);
  s->screen = SDL_SetVideoMode(40 * CAM + 100, 40 * CAM + 100, 32, SDL_HWSURFACE);
  if (s->screen == NULL)
    return (-1);
SDL_WM_SetCaption(WINDOWNAME, NULL);
  return (0);
}
