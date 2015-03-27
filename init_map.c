/*
** init_map.c for  in /home/messao_y/clientzappy
** 
** Made by messao_y
** Login   <messao_y@epitech.net>
** 
** Started on  Mon Jul  7 04:52:20 2014 messao_y
** Last update Tue Jul  8 01:30:59 2014 messao_y
*/

#include "clientg.h"

extern struct s_actions exec_cmd[];

void		init_ress(t_scene *scene, char *cmd)
{
  char  **tab;
  int x;
  int y;

  tab = my_str_to_wordtab(cmd);
  x = atoi(tab[1]);
  y = atoi(tab[2]);
  scene->map[x + y * scene->map_x]->nou = atoi(tab[3]);
  scene->map[x + y * scene->map_x]->lin = atoi(tab[4]);
  scene->map[x + y * scene->map_x]->der = atoi(tab[5]);
  scene->map[x + y * scene->map_x]->sib = atoi(tab[6]);
  scene->map[x + y * scene->map_x]->men = atoi(tab[7]);
  scene->map[x + y * scene->map_x]->phi = atoi(tab[8]);
  scene->map[x + y * scene->map_x]->thy = atoi(tab[9]);
}

void		init_map(t_scene *scene, char *cmd)
{
  char		**tab;
  int     x;
  int     y;
  
  tab = my_str_to_wordtab(cmd);
  scene->map_x = atoi(tab[1]);
  scene->map_y = atoi(tab[2]);
  scene->cam_x = 0;
  scene->cam_y = 0;  
  if (init_sdl(scene) == -1)
    exit(1);
  scene->map = malloc((scene->map_x * scene->map_y) * sizeof(*scene->map));
  for (y = 0; y < scene->map_y; y++)
    for (x = 0; x < scene->map_x; x++)
      {
        scene->map[x + y * scene->map_x] = 
        malloc(sizeof(*scene->map[x + y * scene->map_x]));
      }
  init_sprites(scene);
}

int		init_data(t_scene *scene, char *cmd)
{
  int		i;
  
  printf("%s\n",cmd);
  for (i = 0; exec_cmd[i].cmd && 
	 strncmp(cmd, exec_cmd[i].cmd, exec_cmd[i].len) != 0; i++);
  if (exec_cmd[i].cmd)
    exec_cmd[i].f(scene, cmd);
  return (0);
}
