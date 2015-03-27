/*
** getnextline.c for getnextline in /home/messao_y/clientzappy
** 
** Made by messao_y
** Login   <messao_y@epitech.net>
** 
** Started on  Sat Jul  5 14:06:19 2014 messao_y
** Last update Mon Jul  7 04:31:10 2014 messao_y
*/


#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "clientg.h"

#define BUFF_SIZE 42

static char     buff[BUFF_SIZE];
static int      in_buf = 0;
static int      start;


static int      read_from_file(int fd)
{
  in_buf = read(fd, buff, BUFF_SIZE);
  start = 0;
  return (in_buf);
}

static char     *add_to_line(char *line, int cur)
{
  char         *new;
  int          old_len;

  if (( new = malloc((old_len = (line ? strlen(line) : 0)) + cur + 1)) == NULL)
    return (NULL);
  if (line)
    {
      memcpy(new, line, old_len);
      free(line);
    }
  memcpy(new + old_len, buff + start, cur);
  new[old_len + cur] = 0;
  start += cur + 1;
  return (new);
}

char            *getnextline(int fd)
{
  int          cur;
  char         *line;

  for (line = 0, cur = 0; ; cur++)
    {
      if (start >= in_buf)
	{
	  if (!read_from_file(fd))
	    return (line);
	  cur = 0;
	}
      if (buff[start + cur] == '\n')
	{
	  line = add_to_line(line, cur);
	  return (line);
	}
      if (start + cur == in_buf - 1)
	line = add_to_line(line, cur + 1);
    }
}
