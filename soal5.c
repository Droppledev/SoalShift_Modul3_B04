#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
pthread_t tid[100];

void *read_words (void *arg ) {
    FILE *novel = fopen ("Novel.txt", "r");
    char x[128];
    char *string = (char *) arg;
    int count =0;
    
    while (fscanf(novel, "%s", x) == 1) {
        if (strstr (string, x))
            count++;
    }
    printf ("%d\n", count);
    
}

int main (int argc, char *argv[]){
    int i;
    char *str;
    for (i=1; i<argc ; i++){
        str =  argv[i];
        pthread_create (&(tid[i]), NULL, &read_words, (void *) str);
    }
     
    for (i=1; i<argc ; i++){
        pthread_join(tid[i],NULL);
    }
    
}
// Kekurangan ada pada "Fina,", koma ikut terbaca.
