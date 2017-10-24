#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

pthread_t tid[1000];
 
void faktorial () {
    
    
}


int main (int argc, char argv[]{
    int i;
    
    for (i=1; i<=argc ; i++){
        pthread_create (&(tid[i]), NULL, &faktorial, NULL ) 
    }
    
    for (i=1; i<=argc ; i++){
        pthread_join(tid[i],NULL);
    }
}
