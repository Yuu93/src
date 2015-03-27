/*
** main.c for client graphique in /home/messao_y/clientzappy
** 
** Made by messao_y
** Login   <messao_y@epitech.net>
** 
** Started on  Sat Jul  5 11:31:49 2014 messao_y
** Last update Mon Jul  7 23:44:12 2014 messao_y
*/

#include <unistd.h>
#include "clientg.h"

void  loop(t_sock sock, fd_set readf, t_scene *scene)
{
  struct timeval  tv;
  SDL_Event   event;

  tv.tv_sec = 0;
  tv.tv_usec = 0;
  while (!(SDL_PollEvent (&event) && event.type == SDL_QUIT))
    {
      if (event.type == SDL_MOUSEBUTTONDOWN)
        if (event.button.button == SDL_BUTTON_LEFT)
           print_celldetails(scene, event.button.x, event.button.y);
      if (event.type == SDL_KEYDOWN)
        {
          if (event.key.keysym.sym == SDLK_LEFT)
            move_cam(scene, 1);
          if (event.key.keysym.sym == SDLK_RIGHT)
            move_cam(scene, 2);
          if (event.key.keysym.sym == SDLK_UP)
            move_cam(scene, 3);
          if (event.key.keysym.sym == SDLK_DOWN)
            move_cam(scene, 4);
          usleep(20000);
        }
      init_fd(&sock, &readf);
      if (select(sock.s + 1, &readf, NULL, NULL, &tv) == -1)
        exit(1);
      if (FD_ISSET(sock.s, &readf))
        printf("do action\n");
         print_all(scene);
    }
}

int		main(int ac, char **av)
{
  t_sock	sock;
  t_scene	scene;
  fd_set    readf;
  char		*cmd;

  if (ac == 3)
    {
      if ((init_connexion(&sock, av[1], av[2])) == -1)
	     return (-1);
      send(sock.s, MSG, strlen(MSG), 0);
 for(; (cmd = getnextline(sock.s)) && strcmp(cmd, "tna test") != 0; free(cmd))
      init_data(&scene, cmd);
   print_all(&scene);
   loop(sock, readf, &scene);
    }
  return (0);
}
