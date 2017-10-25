#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
pthread_t tid[100];

char str[1500]; // untuk nyimpen seluruh kata yang ada di dalam file
char arr[250][30]; // untuk dipecah-pecah
int jumlahkata = 0;

int find(char *string){
    int i,counter=0;
    for (i=0;i<jumlahkata;i++){
        if (strcmp(arr[i],string)==0){
            counter++;
        }
    }
    return counter;
}

void *read_words (void *arg) {
    char x[128];
    char *string = (char *) arg;

    printf("%s : %d\n",string,find(string));
    
}

int main (int argc, char *argv[]){
    int i,j,k;
    j=k=0;
    FILE* novel = fopen("Novel.txt","r");
    while (fgets(str,1500,novel)!=NULL){
        for (i=0;str[i]!='\0';i++){
            if (str[i]==' ' || str[i]==',' || str[i]=='.'){
                j++;
                k=0;
            }
            else {
                arr[j][k] = str[i];
                k++;
            }
        }
        j++; // jumlah kata = jumlah spasi + 1;
        jumlahkata = j;
    }
    fclose(novel);
    
    char *kata;
    for (i=1; i<argc ; i++){
        kata =  argv[i];
        pthread_create (&(tid[i]), NULL, &read_words, (void *) kata);
    }
     
    for (i=1; i<argc ; i++){
        pthread_join(tid[i],NULL);
    }
}
