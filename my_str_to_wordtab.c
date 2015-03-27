/*
** my_str_to_wordtab.c for client graphique in /home/messao_y/clientzappy
** 
** Made by messao_y
** Login   <messao_y@epitech.net>
** 
** Started on  Tue Jul  8 00:58:25 2014 messao_y
** Last update Tue Jul  8 01:28:06 2014 messao_y
*/

#include "clientg.h"


int count_word(char *str)
{
  int i;
  int n;

  i = 0;
  n = 1;
  while (str[i] != '\0' && str[i] != '\n')
    {
      if (str[i] == ' ' && str[i + 1] != '\0')
  n++;
      i++;
    }
  return (n);
}

int count_char(char *str)
{
  int c;

  c = 0;
  while ((str[c] != ' ') && (str[c] != '\0') && (str[c] != '\n'))
    c++;
  c += 1;
  return (c);
}

char  **my_str_to_wordtab(char *str)
{
  char  **tab;
  int i;
  int b;
  int a;

  b = 0;
  i = 0;
  a = 0;
  tab = malloc(sizeof(*tab) * ((count_word(str) + 1)));
  while (str[i] != '\n' && str[i] != '\0')
    {
      if (str[i] == ' ' || str[i] == '\n')
  {
    while (str[i] == ' ')
      i++;
    a = a + 1;
    b = 0;
  }
      tab[a] = malloc(sizeof(**tab) * ((count_char(str + i) + 1)));
      while ((str[i] != ' ')  && (str[i] != '\n') && (str[i] != '\0'))
  tab[a][b++] = str[i++];
      tab[a][b] = '\0';
    }
  tab[a + 1] = 0;
  return (tab);
}