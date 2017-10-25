#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
pthread_t tid[100];
int statusL, statusK;

int main(){
    while(1){
        int pil;
        system("cls");
        printf("1. Beri Makan Lohan\n");
        printf("2. Beri Makan Kepiting\n");
        printf("3. Cek Status\n");
        printf("-------------------------\n");
        printf("Pilih Nomor (1-3) > ");
        scanf("%d",&pil);
        if (pil==1){
            //
        }
        else if (pil==2){
            //
        }
        else if (pil==3){
            //
        }
        else{
            printf("Pilihan yang dimasukkan salah\n");
        }
    }
}
