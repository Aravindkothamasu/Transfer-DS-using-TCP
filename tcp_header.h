#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<fcntl.h>
#include<dirent.h>
#include<netinet/in.h>
#include<sys/un.h>
#include<signal.h>
#include<arpa/inet.h>

struct my_ds
{
  int type;							//1.SLL 2.DLL 3.CLL
  int mode;							//1.SEND 2.RECIEVE
  int count;							//Count no.of node's
  char filename[20];						//filename to recieve or send
};

typedef struct linked_list							/******   elements    ******/
{
  int no;					
  char name[20];
  float marks;

  int da;
  int mo;
  int yr;

  struct linked_list *next;
  struct linked_list *prev;
}L;

struct my_ds p;

void createee(void);
void rx(int);
void gola(void);
void ser_lo(int);
void ds_create(void);	
void printing(void);
void pri(L *);
void sendu(int );
int count_node(void);
void extract(char *);
void search_ds(int);
typedef unsigned int U32;


