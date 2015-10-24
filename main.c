#include <stdio.h>
#include <stdlib.h>
#include "sjf.h"



struct s_processi{
    int tExe;
    int tAttesa ;
    int tRestante; 
};
typedef struct s_processi process;

void menu();
void ordinaDatiExe(process *dato, int dim);
void ordinaDatiWait(process *dato, int dim);

int main(int argc, char** argv) {
    int nProcessi;
    int ctrl = 1;
    int somma = 0;
    int i=0;
    int k=0;
    float media = 0;
    process *array;
    
    printf("Inserisci il numero dei processi: ");
    scanf("%d",&nProcessi);
    
    array = (process *)malloc(nProcessi*sizeof(nProcessi));
    
    for(i=0;i<nProcessi;i++){
        array[i].tAttesa = 0;
    }
    for(i=0;i<nProcessi;i++){
        printf("Inserisci il tempo di esecuzione: ");
        scanf("%d",&array[i].tExe);
    }
    //printf("Inserisci il tempo di esecuzione: ");
    //scanf("%d",&array[0].tExe);
    ordinaDatiExe(array,nProcessi);
    
    for(i=0;somma || ctrl;){
        somma = 0;
        ctrl = 0;
        if(array[i].tExe == 0)
            i++;
        array[i].tExe --;
        for(k=1;k<nProcessi;k++){
            somma += array[k-1].tExe;
            array[k].tAttesa ++;
        }
       
        ordinaDatiExe(array,nProcessi);
    }
    ordinaDatiWait(array,nProcessi); 
    
    for(i=0;i<nProcessi-1;i++){
        media += array[i].tAttesa;
    }
    media /= nProcessi; 
    
    printf("Media = %f",media);
    
    return (EXIT_SUCCESS);
}

void menu(){

printf(" ▄▄▄▄▄▄▄▄▄▄▄  ▄▄▄▄▄▄▄▄▄▄▄  ▄▄▄▄▄▄▄▄▄▄▄ \n");
printf("▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌\n");
printf("▐░█▀▀▀▀▀▀▀▀▀  ▀▀▀▀▀█░█▀▀▀ ▐░█▀▀▀▀▀▀▀▀▀ \n");
printf("▐░▌                ▐░▌    ▐░▌          \n");
printf("▐░█▄▄▄▄▄▄▄▄▄       ▐░▌    ▐░█▄▄▄▄▄▄▄▄▄ \n");
printf("▐░░░░░░░░░░░▌      ▐░▌    ▐░░░░░░░░░░░▌\n");
printf(" ▀▀▀▀▀▀▀▀▀█░▌      ▐░▌    ▐░█▀▀▀▀▀▀▀▀▀ \n");
printf("          ▐░▌      ▐░▌    ▐░▌          \n");
printf(" ▄▄▄▄▄▄▄▄▄█░▌ ▄▄▄▄▄█░▌    ▐░▌          \n");
printf("▐░░░░░░░░░░░▌▐░░░░░░░▌    ▐░▌          \n");
printf(" ▀▀▀▀▀▀▀▀▀▀▀  ▀▀▀▀▀▀▀      ▀           \n");

}

void ordinaDatiExe(process *dato, int dim){
    int i,j;
    process temp;
    
    for(i=0;i<dim-1;i++){
        for(j=0;j<dim-1;j++){
            if(dato[j].tExe > dato[j+1].tExe){
                temp=dato[j];
                dato[j]=dato[j+1];
                dato[j+1]=temp;
            }
        }
    }
}

void ordinaDatiWait(process *dato, int dim){
    int i,j;
    process temp;
    
    for(i=0;i<dim-1;i++){
        for(j=0;j<dim-1;j++){
            if(dato[j].tAttesa > dato[j+1].tAttesa){
                temp=dato[j];
                dato[j]=dato[j+1];
                dato[j+1]=temp;
            }
        }
    }
}