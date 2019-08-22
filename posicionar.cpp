#include "posicionar.h"
#include "print.h"
using namespace std;
//Coloca o barco na tabela, recebendo o tamanho e o local para colocar
void posicionarsub (Subm* subm, int nlinhas, int ncol, vector<vector<int>> &mat){
    printSub(*subm);
    mat[subm->posX][subm->posY] = 7;
    mat[subm->posX-1][subm->posY+1] = 2;
    mat[subm->posX-1][subm->posY] = 2;
    mat[subm->posX-1][subm->posY-1] = 2;
    mat[subm->posX+1][subm->posY-1] = 2;
    mat[subm->posX+1][subm->posY] = 2;
    mat[subm->posX+1][subm->posY+1] = 2;
    mat[subm->posX][subm->posY-1] = 2;
    mat[subm->posX][subm->posY+1] = 2;
    
}
void posicionar(Boat* boat, int nlinhas, int ncol, vector<vector<int>> &mat){
    printArmada(*boat);
    for(size_t i = 0; i < boat->size; i++)
    {   
        //verifica a orientação do barco para encontrar a forma de fazer o preenchimento
        if (boat->orient == 1){    
            //caso seja vertical
            mat.at(boat->posX+i).at(boat->posY) = 1;
            mat.at(boat->posX+i).at(boat->posY-1) = 2;
            mat.at(boat->posX+i).at(boat->posY+1) = 2;
            if(i == 0){
                mat.at(boat->posX).at(boat->posY) = 5;
                mat.at(boat->posX-1).at(boat->posY-1) = 2;
                mat.at(boat->posX-1).at(boat->posY) = 2;
                mat.at(boat->posX-1).at(boat->posY+1) = 2;
            }
            else if(i == boat->size-1)
            {
                mat.at(boat->posX+i).at(boat->posY) = 6;
                mat.at(boat->posX+1+i).at(boat->posY) = 2;
                mat.at(boat->posX+1+i).at(boat->posY-1) = 2;
                mat.at(boat->posX+1+i).at(boat->posY+1) = 2;
            }
            
        }
        else{
            //caso seja horizontal
            mat.at(boat->posX).at(boat->posY+i) = 1;
            mat.at(boat->posX-1).at(boat->posY+i) = 2;
            mat.at(boat->posX+1).at(boat->posY+i) = 2;
            if(i == 0){
                mat.at(boat->posX).at(boat->posY) = 3;
                mat.at(boat->posX-1).at(boat->posY-1) = 2;
                mat.at(boat->posX).at(boat->posY-1) = 2;
                mat.at(boat->posX+1).at(boat->posY-1) = 2;
            }
            else if(i == boat->size-1)
            {
                mat.at(boat->posX).at(boat->posY+i) = 4;
                mat.at(boat->posX-1).at(boat->posY+1+i) = 2;
                mat.at(boat->posX).at(boat->posY+1+i) = 2;
                mat.at(boat->posX+1).at(boat->posY+1+i) = 2;
            }
        }
    }
    
}