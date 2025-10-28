#include "colisao.h"


int colisao(char mapa[18][12], int x, int y){



    for(int i = 0; i < 12; i++){
        for(int j = 0; j < 18; j++){

            if(mapa[j][i] == '1' || mapa[j][i] == '2' || mapa[j][i] == '4' || mapa[j][i] == '5'){

                if(x+32 > j*32 && x < (j+1)*32 && y+32 > i*32 && y < (i+1)*32){

                        return 1;

                    }

                }
                    if(mapa[j][i] == '3'){

                        if(x+32 > j*32 && x < (j+1)*32 && y+32 > i*32 && y < (i+1)*32){

                       return 2;

                    }

                }

            }
        }

            return 0;

}
