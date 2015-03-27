/*
** printcell.c for  in /home/messao_y/clientzappy
**
** Made by messaoudene youcef
** Login   <messao_y@epitech.net>
**
** Started on  Sat Jul  15 22:29:22 2014 messaoudene youcef
** Last update Sat Jul  15 22:29:22 2014 messaoudene youcef
*/

#include "clientg.h"

int check_coord(int xx, int yy, int line)
{

  int          x;
  int          y;
  int          i;

  i = 0;
  x = 0;
  y = 0;
  while (x < xx)
    {
      if (x % BLKSIZE == 0)
           i++;
      x++;
    }
  while (y < yy)
    {
       if (y % BLKSIZE == 0)
        i = i + line;
     y++;
   }
   return (i - line);
}

void print_one(int x, t_scene *scene)
{
  SDL_Surface *win;

	scene->rect.y =  15;
 if (x == 1)
   scene->rect.x =  150;
  else if (x == 2)
    scene->rect.x =  185;
  else if (x == 3)
     scene->rect.x =  225;
  else if (x == 4)
    scene->rect.x =  265;
  else if (x == 5)
    scene->rect.x =  305;
  else if (x == 6)
    scene->rect.x =  345;
  win = IMG_Load("sprites/1.png");
  SDL_BlitSurface(win, NULL, scene->screen, &scene->rect);
}

void print_two(int x, t_scene *scene)
{
  SDL_Surface *win;

 	scene->rect.y =  15;
 if (x == 1)
   scene->rect.x =  150;
  else if (x == 2)
    scene->rect.x =  185;
  else if (x == 3)
     scene->rect.x =  225;
  else if (x == 4)
    scene->rect.x =  265;
  else if (x == 5)
    scene->rect.x =  305;
  else if (x == 6)
    scene->rect.x =  345;
  win = IMG_Load("sprites/2.png");
  SDL_BlitSurface(win, NULL, scene->screen, &scene->rect);
}

void print_three(int x, t_scene *scene)
{
  SDL_Surface *win;

	scene->rect.y =  15;
 if (x == 1)
   scene->rect.x =  150;
  else if (x == 2)
    scene->rect.x =  185;
  else if (x == 3)
     scene->rect.x =  225;
  else if (x == 4)
    scene->rect.x =  265;
  else if (x == 5)
    scene->rect.x =  305;
  else if (x == 6)
    scene->rect.x =  345;
  win = IMG_Load("sprites/3.png");
  SDL_BlitSurface(win, NULL, scene->screen, &scene->rect);
}

const t_elem    number[] = {
  {1, print_one},
  {2, print_two}, 
  {3, print_three},
};

void   print_number(t_scene *scene, int i)
{
  int k;

    k = 0;
    while (number[k].data) 
        {
            if (scene->map[i - 1]->lin == number[k].data)
                number[k].fct_print(1, scene);
            if (scene->map[i - 1]->der == number[k].data)
                number[k].fct_print(2, scene);
            if (scene->map[i - 1]->sib == number[k].data)
                number[k].fct_print(3, scene);
            if (scene->map[i - 1]->men == number[k].data)
                number[k].fct_print(4, scene);
            if (scene->map[i - 1]->phi == number[k].data)
                number[k].fct_print(5, scene);
            if (scene->map[i - 1]->thy == number[k].data)
                number[k].fct_print(6, scene);
            k++;
        }
}
