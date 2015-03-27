/*
** initialize.c for client graphique in /home/messao_y/clientzappy
** 
** Made by messao_y
** Login   <messao_y@epitech.net>
** 
** Started on  Sat Jul  5 11:37:36 2014 messao_y
** Last update Sat Jul  5 14:28:42 2014 messao_y
*/

#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "clientg.h"

char			*xgethostbyname(char *name)
{
  struct hostent	*h;
  struct in_addr	addr;
  
  if ((h = gethostbyname(name)) == NULL)
    {
      printf("Host not found\n");
      return (NULL);
    }
      memcpy(h->h_addr, &addr, sizeof(addr));
    return (inet_ntoa(addr));
}

void			init_fd(t_sock *sock, fd_set *readf)
{
  FD_ZERO(readf);
  FD_SET(sock->s, readf);
}

int			init_socket(t_sock *sock, char *host, int port)
{
  if ((sock->s = socket(PF_INET, SOCK_STREAM, 0)) == -1)
    return (-1);
  sock->port = port;
  sock->sin.sin_family = AF_INET;
  sock->sin.sin_port = htons(sock->port);
  sock->sin.sin_addr.s_addr = inet_addr(host);
  return (0);
}

int		  	init_connexion(t_sock *sock, char *host, char *port)
{
  if ((init_socket(sock, xgethostbyname(host), atoi(port))) == -1)
    return (-1);
  if (connect((*sock).s, (struct sockaddr *)&((*sock).sin),
              sizeof(struct sockaddr_in)) < 0)
    {
      printf("Unable to connect!\n");
      return (-1);
    }
  return (0);
}
