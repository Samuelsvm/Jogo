#include "ler_mapa.h"
#include <stdio.h>



void ler_mapa(int n, char m[18][12]){

    FILE* file;

    if(n ==1){
    file = fopen("mapa1.txt", "r");
    }
    if(n == 2){
    file = fopen("mapa2.txt", "r");
    }

    char aux;

    for(int i = 0; i < 12; i++){
        for(int j = 0; j < 18; j++){

        aux = fgetc(file);
        m[j][i] = aux;

        }
        fgetc(file);

    }
for (int i = 0; i < 12; i++) {
    for (int j = 0; j < 18; j++) {
        printf("%c", m[j][i]);
    }
    printf("\n");
}

        printf("\n");


    fclose(file);

}

