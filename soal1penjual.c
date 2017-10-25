#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <string.h>


char weapon[6][10] ={"MP4A1", "PM2-V1", "SPR-3", "SS2-V5", "SPG1-V3","MINE"};
int quantity[6] = {NULL,0,0,0,0,0,0}    ;

void ListSenjata () {
    int i;
    for (i=0; i<6; i++){
        if (quantity[i+1]>0) 
            printf("%s: %d\n", weapon[i], quantity[i+1]);
        
    }
}

void tambahStock (){
    char name[10];
    int amount;
    int i;
    printf ("Masukkan nama senjata dan jumlah: ");
    scanf ("%s %d", &name, &amount);
     
    for (i=0; i<6; i++){
       // printf ("%s %s ", weapon[i], name);
       if( strcmp (weapon[i],name)==0){
            quantity[i+1] += amount;
            printf ("Jumlah senjata saat ini %s: %d\n", weapon[i], quantity[i+1]);
       }    
    }
    
}
int main (){
    int menu;
    int i;
    key_t key = 1234;
    int shmid = shmget(key, 6*sizeof(int), IPC_CREAT | 0666);
    *quantity = shmat(shmid, NULL, 0);
    //printf ("%d ", quantity[3]);
    //printf ("%d ", quantity[6]);
    shmdt(*quantity);
    shmctl(shmid, IPC_RMID, NULL);
    
    
    
    while (1){
        for (i=0; i<6; i++)
            printf("%s: %d\n", weapon[i], quantity[i+1]);
        
       
        printf ("1. Stock senjata\n2. tambah stock senjata\n");
        printf ("Pilih Menu 1 atau 2: ") ;
        scanf ("%d", &menu);
        switch (menu){
            case 1:
                ListSenjata();
                break;
            case 2 :
                tambahStock();
                break;
        }
    }
}
