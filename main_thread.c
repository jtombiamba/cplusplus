#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>
#include <pthread.h>
#include <unistd.h>

typedef struct foo_s
{
  FILE* fd;
  int a;
  int b;
  int c;

} foo_t;

typedef struct bubblesort_s
{
  FILE* fd;
  int  n;
  int *x;

} bubblesort_t;



void *foo(/*int fd, int a, int b, int c*/void * args)
{
  foo_t * my_foo = (foo_t*) args;
  printf("inside\n");
  //FILE * fd;
  //fd = fopen("toto.txt", "w");  
  int i;
  int r = -1;
    for (i = 0; i < my_foo->c; i ++)
   {
      while(r!=0)
	{
	  r = my_foo->a%my_foo->b;
	 
	  my_foo->a = my_foo->b;
	  my_foo->b = r;
	  fprintf(my_foo->fd, "a = %d;b = %d; r = %d\n", my_foo->a, my_foo->b, r);
	  if(r==0 || r==1) break;
	}
      fprintf(my_foo->fd, "\n\n");
      }
  printf("outside\n");
  fclose(my_foo->fd);  
}



void *bubblesort(/*int fd, int n, int x[]*/void * args)
{
  bubblesort_t * my_bub = (bubblesort_t*) args;

  printf("inside\n");
  //FILE * fd = fopen("tata.txt", "w");
  int i, j, k, m, M;
  int finish = 0;

  while(finish!=1)
    {
      finish = 1;
      for (j = 0; j < my_bub->n - 1; j ++)
	{
	  m = my_bub->x[j];
	  for (i = 1; i < my_bub->n; i ++)
	    {
	      if(m > my_bub->x[i])
		{
		  M = m;	
		  m = my_bub->x[i];
		  my_bub->x[i] = M;
	
		  //my_bub->x[i] = M;
		  //my_bub->x[j] = m;
		  finish = 0;
		  for(k = 0; k < my_bub->n ; k ++)
		    {
		      fprintf(my_bub->fd, "%d ", my_bub->x[k]);
		    }
		  fprintf(my_bub->fd, "\n\n");
		  break;
		}
	    }
	}
    }
  printf("outside\n");
  fclose(my_bub->fd);
}


int main(int argc, char ** argv)
{

  int  x[10], i;
  //GOOD STUFF, GENERATE RANDOM NUMBERS
  srand(time(0)); //INITIALISE BASES(here I choose time());
  for(i = 0; i < 10; i ++) x[i] =  rand()%500; //choose random numbers with maximum numbers at 500
  foo_t * my_foo = malloc(sizeof(foo_t));
  bubblesort_t * my_bub = malloc(sizeof(bubblesort_t));
  
  //FILE *fd = fopen("toto.txt", "w");

  my_foo-> a = atoi(argv[1]);
  my_foo-> b = atoi(argv[2]);
  my_foo-> c = 4;
  my_foo->fd = fopen("tiki.txt", "w");

  my_bub -> n = 10;
  my_bub-> x = x;
  my_bub->fd = fopen("taka.txt", "w");


  pthread_t thread1;
  pthread_t thread2;
  
  //fd = fopen("toto.txt", "w");

  //if(fd != NULL)
  // {
  //    printf("Ici nous sommes hors des threads\n");
  //  }

  pthread_create(&thread1, NULL, foo, my_foo);
  pthread_create(&thread2, NULL, bubblesort, my_bub);

  pthread_join(thread1, NULL);
  pthread_join(thread2, NULL);
  
  //fclose(fd);
  
  return EXIT_SUCCESS;
}
