#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

pthread_t tid[2];
char str[1500]; // untuk nyimpen seluruh kata yang ada di dalam file
char arr[250][30]; // untuk dipecah-pecah

int main (int argc, char argv[]){
    FILE* novel = fopen("Novel.txt","r");
    while (fgets(str,1500,novel)!=NULL){
        
    }
    int i;

} 
