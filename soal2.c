#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>


pthread_t tid[2];
int holeP1[16]={0};
int holeP2[16]={0};
int banyak;
int poinP1=0;
int poinP2=0;


void *pemain1(void *arg){
    int i,pilih;
    printf("Masukkan banyak lubang yang ingin Pemain 1 isi > ");
    scanf("%d",&banyak);
    for (i=0;i<banyak;){
        printf("Pilih lubang untuk dimasukkan ranjau (1-16) > ");
        scanf("%d",&pilih);
        if (holeP1[pilih-1]==1){
            printf("Lubang sudah diberi ranjau, pilih lubang lain !");
        }
        else {
            holeP1[pilih-1] = 1;
            i++;
        }
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
            poinP2++;
        }
    }
    
}

void *pemain2(void *arg){
    int i,pilih;
    printf("Masukkan banyak lubang yang ingin Pemain 2 isi > ");
    scanf("%d",&banyak);
    for (i=0;i<banyak;){
        printf("Pilih lubang untuk dimasukkan ranjau (1-16) > ");
        scanf("%d",&pilih);
        if (holeP2[pilih-1]==1){
            printf("Lubang sudah diberi ranjau, pilih lubang lain !");
        }
        else {
            holeP2[pilih-1] = 1;
            i++;
        }
    }
    printf("Pemain 1 menebak lubang sebanyak 4 kali > \n");
    for (i=0;i<4;i++){
        scanf("%d",&pilih);
        if (holeP2[pilih-1]==1){
            printf("Pemain 1 terkena ranjau !");
            poinP2++;
        }
        else{
            printf("Pemain 1 selamat !");
            poinP1++;
        }
    }
    
}

int cekAllRanjau(int hole[]){
    int i,flag;
    flag = 1;
    for(i=0;i<16;i++){
        if (hole[i]!=1){
            flag = 0;
            break;
        }
    }
    return flag;
}

int main(){
    while(1){
        if (poinP1==10 || poinP2 == 10 || cekAllRanjau(holeP1) || cekAllRanjau(holeP2)) break;
        else{
            pthread_create (&(tid[0]), NULL, &pemain1, NULL);
            pthread_create (&(tid[1]), NULL, &pemain2, NULL);
            
            pthread_join (tid[0],NULL);
            pthread_join (tid[1],NULL);
        }
    }
    
}
