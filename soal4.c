#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

pthread_t tid[1000];
int n;

void faktorial (*ar) {
    int j;
    long long result =1;
        for (j=tid[i]; j>=2; j--){
            result *=j; 
         }
         printf ("Hasil %d!= %lld", i, result);
        }
    }
    
    }
    
}


int main (int argc, char *argv[]){
    int i;
    int val;
    
    for (i=1; i<argc ; i++){
        val = atoi (argv[i]);
        pthread_create (&(tid[i]), NULL, &faktorial, (void *) val);

    }
     
    for (i=1; i<argc ; i++){
        pthread_join(tid[i],NULL);
    }
}
