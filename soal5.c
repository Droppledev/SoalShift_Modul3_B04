#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

pthread_t tid[2];
char str[1500]; // untuk nyimpen seluruh kata yang ada di dalam file
char arr[250][30]; // untuk dipecah-pecah

int main (int argc, char argv[]){
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
    }
    fclose(novel);
    for (i=1;i<argc;i++){
        printf("%s = %d\n",argv[i],find(argv,i,j));
    }
    return 0;
} 
