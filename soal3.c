#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>


pthread_t tid[3];
int statusL = 100;
int statusK = 100;


void *lohan (void *arg) {
    
    while(1){
        if (statusL <= 0 || statusL >100 || statusK <= 0 || statusK >100){
            break;
        }
        else{
            sleep(10);
            statusL-=15;
        }
    }
    
}

void *kepiting (void *arg) {
    while(1){
        if (statusL <= 0 || statusL >100 || statusK <= 0 || statusK >100){
            break;
        }
        else{
            sleep(20);
            statusK-=10;
        }
    }
    
}

void cekStatus(){
    printf("\n-----------Status-----------");
    printf("\nStatus Lohan= %d\n",statusL);
    printf("Status Kepiting = %d\n\n",statusK);
}

int main(){
    system("clear");
    pthread_create (&(tid[0]), NULL, &lohan, NULL);
    pthread_create (&(tid[1]), NULL, &kepiting, NULL);
    
    while(1){
        if (statusL <= 0 || statusL >100 || statusK <= 0 || statusK >100) break;
        else{
           int pil;
           char c;
            
            printf("1. Beri Makan Lohan\n");
            printf("2. Beri Makan Kepiting\n");
            printf("3. Cek Status\n");
            printf("-------------------------\n");
            printf("Pilih Nomor (1-3) > ");
            scanf("%d",&pil);
            if (statusL <= 0 || statusL >100 || statusK <= 0 || statusK >100) break;
            else {
                if (pil==1){
                    printf("\nLohan diberi makan !\n");
                    printf("Status lohan bertambah 10 !");
                    statusL+=10;
                    cekStatus();
                    
                }
                else if (pil==2){
                    printf("\nKepiting diberi makan !\n");
                    printf("Status kepiting bertambah 10 !");
                    statusK+=10;
                    cekStatus();
                }
                else if (pil==3){
                    cekStatus();
                }
                else{
                    printf("\nPilihan yang dimasukkan salah\n");

                } 
            }
            
        }
        
    }
    printf("Game Berakhir !\n");
}
