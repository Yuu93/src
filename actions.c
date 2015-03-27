/*
** cmd.c for client graphique in /home/messao_y/clientzappy
** 
** Made by messao_y
** Login   <messao_y@epitech.net>
** 
** Started on  Mon Jul  7 23:36:04 2014 messao_y
** Last update Mon Jul  7 23:52:09 2014 messao_y
*/

#include "clientg.h"

struct s_actions	exec_cmd[] =
  {
    {"msz", 3, init_map},
    {"bct", 3, init_ress},
    {0, 0, 0},
  };
