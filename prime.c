#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *prime(void *p); 

int main(int argc, char *argv[]) {

   
   if(argc < 2) {
      printf("command Line Input");
      exit(1);
   }
 


   pthread_t tid;       
   pthread_attr_t attr;

   printf("Prime Numbers: ");

   
   pthread_attr_init(&attr);
   
   pthread_create(&tid,&attr,prime,argv[1]);

   pthread_join(tid,NULL);
   printf("\nComplete\n");

}

void *prime(void *p) {
   int i,j,upper = atoi(p);
   for(i = 2; i < upper; i++) {
   int a = 0;
      for(j = 2; j < i; j++) {
         int result = i % j;
         
         if(result == 0) {
            a = 1;
            break;
         }
      }
      if(a == 0) {
         printf("%d ", i);
      }
   }
   pthread_exit(0);
}
