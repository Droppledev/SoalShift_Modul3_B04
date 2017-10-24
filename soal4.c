#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

pthread_t tid[1000];
int n, greater;
status = 0
void faktorial (*ar) {
    int j;
    long long restult =1;
        for (j=tid[i]; j>=2; j--){
            result *=j; 
         }
         printf ("Hasil %d!= %lld", i, result);
        }
    }
    status =i;
    //printf("\n");
}
    
}


int main (int argc, char argv[]{
    int i;
    n = argc;
    greater =0; 
    for (i=1; i<=argc ; i++){
        pthread_create (&(tid[i]), NULL, &faktorial, NULL );
        if (greater < argv[i]){
            greater = argv[i];//terbesar
        }
    }
     
    for (i=1; i<=argc ; i++){
        pthread_join(tid[i],NULL);
    }
}
