#include"tcp_header.h"

L *hptr;
L *last;
L sa;

void gola(void) 
{
  printf("1)Single Linked List\n2)Double Linked List\n3)Cirular linked List\n"); 
  scanf(" %d",&(p.type));

  printf("0)Send\n1)Recieve...\n");
  scanf(" %d",&(p.mode));

  printf("Enter file name....     ");
  scanf(" %[^\n]",p.filename);	
  if(p.mode == 0)								/*****    Send to Server    ****/
    createee();
}

void ser_lo(int nsfd)
{
  if((p.mode) == 1)
  {
    createee();
    write(nsfd,&p,sizeof(p));
    sendu(nsfd);
  }
  else
    rx(nsfd);
}	

void sendu(int nsfd)							/**********  Sending   **********/
{
  L *q=hptr;
  L *o=hptr;
  while(q)
  {
    write(nsfd,q,sizeof(L));
    q = q->next;
    if(q == o)				//For circular
      break;
  }
}

void rx(int nsfd)						/************  Recieve **********/
{
  int c=0,FileDes = open(p.filename,O_RDWR | O_CREAT | O_TRUNC,0664);
  char buf[150];
  if(FileDes < 0)
  {
    printf("\n\n\t\tError in Creating \".%s.\" file...\n\n",p.filename);
    exit(0);
  }

  printf("Recieving...Please wait %d\n",p.count);
  do{
    read(nsfd,&sa,sizeof(L));
    bzero(buf,sizeof(buf));
    sprintf(buf," %d   %d  %d  %d    %s  %f\n",sa.da,sa.mo,sa.yr,sa.no,sa.name,sa.marks);
    write(FileDes,buf,strlen(buf));
    ds_create();
    c++;
  }while(c!=(p.count));

  if(p.type == 3)
    last -> next = hptr;		
  printf("Linked list Recieved ..\n\nProcessing Plz wait..\n");
  printing();
}

void ds_create(void)						/**************    ADD END   ************/
{
  L *n = malloc(sizeof(L));

  n->no = sa.no;
  n->marks = sa.marks;
  n->da = sa.da;
  n->mo = sa.mo;
  n->yr = sa.yr;
  strcpy(n->name,sa.name);

  if(hptr == 0)
    hptr = last = n;
  else
  {
    n->next =0;
    last->next = n;
    n->prev = 0;		

    if(p.type > 1)
      n->prev = last;
    last = n;
  }
}

void createee(void)							/****     Create a DS    *****/
{
  FILE *fp = fopen(p.filename,"r");
  if(fp == NULL)
  {
    printf("\"%s\"  file is not present...\n",p.filename);
    exit(0);
  }
  char r[20];
  while(fscanf(fp,"%d %s %s %f",&sa.no,r,sa.name,&sa.marks) != -1)
  {
    extract(r);
    ds_create();
  }

  if(p.type == 3)
    last -> next = hptr;

  printing();
  p.count = count_node();

  printf("No.of nodes = %d\n",p.count);
}

void printing(void)							/*********  print   ********/
{
  L *ptr = hptr;
  L *o =hptr;
  while(ptr)
  {
    pri(ptr);
    ptr = ptr->next;
    if(o == ptr)
      break;
  }
}	

void pri(L *ptr)
{
  ((ptr->da) < 10) ? printf("0") : 0 ;
  printf("%d ",ptr->da);
  ((ptr->mo) < 10) ? printf("0") : 0 ;
  printf("%d ",ptr->mo);
  printf("%d %d %s %f\n",(ptr->yr) , ptr->no , ptr->name , ptr->marks);
}

int count_node(void)
{
  L *q = hptr;
  L *o = hptr;
  int c;
  for(c = 1 ; q=q->next ; c++)
    if(o == q)
      break;
  return c;
}

void extract(char *r)
{
  int i,t=0,j=0; 
  int *k = &(sa.da);
  for(i=0 ; r[i] ; i++) 
  { 
    if (r[i] == '/') 
    { 
      *(k++) = t;
      t = 0; 
      continue;			
    } 
    if(r[i+1] == 0) 
    { 
      t = t*10 + (r[i]-48); 
      *k = t; 
      continue;  
    } 
    t = t*10 + (r[i]-48); 
  }  
}


void search_ds(int op)
{
  L *k = hptr;
  L *i = hptr;
  int num;
  char o[20];
  (op == 1) ? scanf(" %s",o) : scanf(" %d",&num); 
  while(k)
  {
    if(op == 1)
    {if(strcmp(o,k->name) == 0)
      printf("\t");
      pri(k);}
    else if(op ==2)
      if(num == k->no)
	pri(k);
    k = k->next;
    if(k->next == i || k == 0) break;
  }
}
