/*
** print.c for cg in /home/messao_y/clientzappy
**
** Made by antoine coskun
** Login   <messao_y@epitech.net>
**
** Started on  Thu Jul  10 05:16:40 2014 antoine coskun
** Last update Thu Jul  10 05:16:40 2014 antoine coskun
*/

#include "clientg.h"

int ress_pos(int x, int y, char f, char bool)
{
  if (f < 2 && !bool)
    return(x + 1);
  if (f >= 2 && !bool)
    return(x + 26);
  if ((f == 0 || f == 2) && bool)
    return (y + 1);
  return(y + 26);
}


void  set_rect(t_scene *scene, int x, int y)
{
  scene->rect.x = x;
  scene->rect.y = y;
}

void  print_stones(t_scene *scene)
{
  int x;
  int y;
  int i;
  int j;
  int xx;
  int yy;
  int *tabress;
  char  f;

xx = 50;
yy = 50;
  for (y = scene->cam_y; y < scene->cam_y + CAM; y++, xx = 50, yy += BLKSIZE)
    for (f = 0, x = scene->cam_x; x < scene->cam_x + CAM; x++, f = 0, xx+= BLKSIZE)
      {
        tabress = (int *)scene->map[x + y * scene->map_x];
        set_rect(scene, xx, yy);
        SDL_BlitSurface(scene->ground[0]->sprite, NULL, scene->screen, &scene->rect);
        for (i = 0; i < 7; i++)
          for (j = tabress[i]; j; j--, f++)
            {
              set_rect(scene, ress_pos(xx, yy, f, 0), ress_pos(xx, yy, f, 1));
              SDL_BlitSurface(scene->ress[i - 1]->sprite, NULL, scene->screen,
                  &scene->rect);
            }
      }
}

void  print_celldetails(t_scene *scene, int x, int y)
{
  SDL_Surface *outbox;
  SDL_Surface *win;
  int          i;

  printf("%d %d\n", x, y);
  if (x > 50 && x < 450 && y > 50 && y < 450)
  {
    x = x - BORDERSIZE + scene->cam_x * BLKSIZE;
    y = y - BORDERSIZE + scene->cam_y * BLKSIZE;
    i = check_coord(x, y, scene->map_x);
    win = IMG_Load("sprites/win.png");
    scene->rect.x =  125;
    scene->rect.y = 5;
    SDL_BlitSurface(win, NULL, scene->screen, &scene->rect);
    print_number(scene, i);
    SDL_Flip(scene->screen);
  }
    else
    {
      outbox = IMG_Load("sprites/outbox.png");
       set_rect(scene, 0, 0);
      SDL_BlitSurface(outbox, NULL, scene->screen, &scene->rect);
    }
}

void		print_all(t_scene *scene)
{
     print_stones(scene);
     SDL_Flip(scene->screen);
}