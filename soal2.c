#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>


pthread_t tid[2];
int holeP1[16]={0};
int holeP2[16]={0};
int banyak;
int poinP1,poinP2;
poinP1=poinP2 = 0;


void *pemain1(void *arg){
    int i;
    printf("Masukkan banyak lubang yang ingin Pemain 1 isi > ");
    scanf("%d",&banyak);
    for (i=0;i<banyak;i++){
        printf("Pilih lubang untuk dimasukkan ranjau (1-16) > ");
        scanf("%d",&pilih);
        holeP1[pilih-1] = 1;
    }
    printf("Pemain 2 menebak lubang sebanyak 4 kali > \n");
    for (i=0;i<4;i++){
        scanf("%d",&pilih);
        if (holeP1[pilih-1]==1){
            printf("Pemain 2 terkena ranjau !");
            poinP1++;
        }
        else{
            printf("Pemain 2 selamat !");
            poinP2++
        }
    }
    
}

void *pemain2(void *arg){
    
}

int main(){
    
}
