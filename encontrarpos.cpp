#include "encontrarpos.h"
void encontrarPosSub(Subm* sub, int nlinhas, int ncol, vector<vector<int>> &mat){
    srand((unsigned int)time(NULL));
    bool valido = false;
    while(valido == false){
        sub->posX = rand() %((nlinhas)-1);
        sub->posX++;
        sub->posY = rand() %((ncol)-1);
        sub->posY++;
        if(mat.at(sub->posX).at(sub->posY) == 0){
            valido = true;
            posicionarsub(sub, nlinhas, ncol, mat);
        }
    }
}

void encontrarPosicao(Boat* boat, int nlinhas, int ncol, vector<vector<int>> &mat){
    srand((unsigned int)time(NULL));
    bool valido = false;
    while(valido == false){
        if(boat->orient == 1){
            boat->posX = rand() %((nlinhas)-(boat->size-1));
            boat->posX++;
            boat->posY = rand() %((ncol));
            boat->posY++;
            for(int i = 0; i < boat->size; ++i){
                if(mat[boat->posX+i][boat->posY] == 0){
                    valido = true;
                }
                else{
                    valido = false;
                    break;
                }
            }
        }
        else if(boat->orient == 0){
            boat->posX = rand() %nlinhas;
            boat->posX++;
            boat->posY = rand() %(ncol-(boat->size-1));
            boat->posY++;
            for(int i = 0; i < boat->size; ++i){
                if(mat[boat->posX][boat->posY+i] == 0){
                    valido = true;
                }
                else{
                    valido = false;
                    break;
                }
            }
        }
        else{
            boat->posX = rand() %nlinhas;
            boat->posY = rand() %ncol;
            if(mat[boat->posX][boat->posY] == 0){
                valido = true;
            }
        }
    }
    if(valido == true){
        posicionar(boat, nlinhas, ncol, mat);
    }
}