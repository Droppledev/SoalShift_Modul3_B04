#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>


pthread_t tid[2];
int holeP1[16]={0};
int holeP2[16]={0};
int banyak= 0;
int banyakRanjauP1= 0;
int banyakRanjauP2= 0;
int poinP1=0;
int poinP2=0;
int status;

int cekStatus(){
    printf("\n---Status---\n");
    printf("Skor P1 = %d\n",poinP1);
    printf("Skor P2 = %d\n",poinP2);
    printf("Banyak ranjau P1 terpasang = %d\n",banyakRanjauP1);
    printf("Banyak ranjau P2 terpasang = %d\n",banyakRanjauP2);
    if (poinP1==10 || poinP2 == 10 || banyakRanjauP1==16 || banyakRanjauP2==16) return 1;
    else return 0;
}

void endOfGame(){
    printf("\nGame Berakhir !\n");
    if (banyakRanjauP1 == 16) printf("Lubang P1 sudah penuh !\n\n");
    else if (banyakRanjauP2 == 16) printf("Lubang P2 sudah penuh!\n\n");
    if (poinP1>poinP2) printf("Pemain 1 Menang !\n");
    else if (poinP1<poinP2) printf("Pemain 2 Menang !\n");
    else printf("Seri !\n");
}


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
            banyakRanjauP1++;
            i++;
        }
    }
    system("clear");
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
    if (cekStatus()){
        endOfGame();
        exit(EXIT_SUCCESS);
    }
    printf("\n");
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
            banyakRanjauP2++;
            i++;
        }
    }
    system("clear");
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
    if (cekStatus()){
        endOfGame();
        exit(EXIT_SUCCESS);
    }
    
}


int main(){
    while(1){
        status =0;
        if (poinP1==10 || poinP2 == 10 || banyakRanjauP1==16 || banyakRanjauP2==16){
            endOfGame();
            break;
            
        }
        else{
            pthread_create (&(tid[0]), NULL, &pemain1, NULL);
            pthread_create (&(tid[1]), NULL, &pemain2, NULL);
            
            pthread_join (tid[0],NULL);
            pthread_join (tid[1],NULL);
        }
    }
    
}
