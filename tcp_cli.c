#include"tcp_header.h"
void main(int argc,char **argv)
{
  if(argc != 3)
  {
    printf("Syntax : [./client] [I.P of Server] [Port no.]\n");
    return;
  }

  int sfd,r,len,fd,op;
  struct sockaddr_in v;
  char s[30];

  gola();
  /*************socket**************/

  sfd = socket(AF_INET,SOCK_STREAM,0);
  if(sfd < 0)
  {
    perror("socket");
    return;
  }
  perror("socket");

  /*************connect******************/

  v.sin_port = htons(atoi(argv[2]));
  v.sin_family = AF_INET;
  v.sin_addr.s_addr = inet_addr(argv[1]);
  len = sizeof(v);
  r = connect(sfd,(struct sockaddr *)&v,len);
  if (r < 0)
  {
    perror("connect");
    return;
  }	
  perror("connect");
  /**************** Reciveing DS   ***********/

  write(sfd,&p,sizeof(p));	

  sleep(2);	

  if(p.mode == 0)
    sendu(sfd);
  else if(p.mode == 1)
  {
    read(sfd,&p,sizeof(p));
    sleep(2);
    rx(sfd);
  }

  /*	while(8)
	{
	printf("\n\t\t\tPlease select the Option...\n\t\t\t");
	printf("[1].Search via Name\n\t\t\t[2].Roll.no\n");	
	scanf(" %d",&op);
	printf("Enter data\n");
	search_ds(op);		
	}		*/
}	
