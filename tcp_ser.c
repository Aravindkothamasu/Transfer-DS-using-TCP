#include"tcp_header.h"
void main()
{
  int sfd,nsfd,r,len,fd,i;
  char s[30];
  struct sockaddr_in v,v1;

  /*****************socket*******************/

  sfd = socket(AF_INET,SOCK_STREAM,0);				//socket function
  if(sfd<0)
  {
    perror("socket");
    return;
  }
  perror("socket");

  /*******************bind********************/
  v.sin_family = AF_INET;
  v.sin_port = htons(4567);
  v.sin_addr.s_addr = inet_addr("0.0.0.0");

  len = sizeof(v);

  r = bind(sfd,(struct sockaddr *)&v,len);			//binding the socket
  if(r < 0)
  {
    perror("bind");
    return;
  }
  perror("bind");

  /******************listen*******************/

  r = listen(sfd,5);						//listen function	

  if(r!=0)
  {
    perror("listen");
    return;
  }
  perror("listen");

  /*****************accept*******************/

  printf("\n\n\t\tServer is Waiting at I.P = [192.168.1._] at Port no:[4567] \n\n\n");
  while(8)
  {
    nsfd = accept(sfd,(struct sockaddr *)&v,&len);			//accept function 
    perror("accept");
    setsockopt(nsfd,SOL_SOCKET,SO_REUSEADDR,&len,sizeof(len));	//setsockopt-for reuse the same socket no.

    /**************** Sending DS   *************/
    if(fork() == 0)							//child creation 
    {
      printf("getpid = %d\n",getpid());
      printf("**************\n");
      read(nsfd,&p,sizeof(p));
      ser_lo(nsfd);	
    }
  }
}
