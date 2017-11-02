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
int status;


void *pemain1(void *arg){
    int i,pilih;
    printf("Masukkan banyak lubang yang ingin Pemain 1 isi (maks 4)  > ");
    scanf("%d",&banyak);
    printf("Pilih %d lubang sekaligus untuk dimasukkan ranjau (1-16) > ", banyak);
    for (i=0;i<banyak;){
        scanf("%d",&pilih);
        if (holeP1[pilih-1]==1){
            printf("Lubang %d sudah diberi ranjau, pilih lubang lain !\n", pilih);
        }
        else {
            holeP1[pilih-1] = 1;
            i++;
        }
    }
    printf("Pemain 2 menebak lubang sebanyak 4 kali > ");
    for (i=0;i<4;i++){
        scanf("%d",&pilih);
        if (holeP1[pilih-1]==1){
            printf("Pemain 2 terkena ranjau !\n");
            poinP1++;
        }
        else{
            printf("Pemain 2 selamat !\n");
            poinP2++;
        }
    }
    status =1;
    
}

void *pemain2(void *arg){
      while(status != 1)
    {

    }

    int i,pilih;
    printf("Masukkan banyak lubang yang ingin Pemain 2 isi (maks 4) > ");
    scanf("%d",&banyak);
    printf("Pilih %d lubang sekaligus untuk dimasukkan ranjau (1-16) > ", banyak);
    for (i=0;i<banyak;){
 
        scanf("%d",&pilih);
        if (holeP2[pilih-1]==1){
            printf("Lubang %d sudah diberi ranjau, pilih lubang lain !\n", pilih);
        }
        else {
            holeP2[pilih-1] = 1;
            i++;
        }
    }
    printf("Pemain 1 menebak lubang sebanyak 4 kali > ");
    for (i=0;i<4;i++){
        scanf("%d",&pilih);
        if (holeP2[pilih-1]==1){
            printf("Pemain 1 terkena ranjau !\n");
            poinP2++;
        }
        else{
            printf("Pemain 1 selamat !\n");
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
        status =0;
        if (poinP1==10 || poinP2 == 10 || cekAllRanjau(holeP1) || cekAllRanjau(holeP2)) break;
        else{
            pthread_create (&(tid[0]), NULL, &pemain1, NULL);
            pthread_create (&(tid[1]), NULL, &pemain2, NULL);
            
            pthread_join (tid[0],NULL);
            pthread_join (tid[1],NULL);
        }
    }
    
}
