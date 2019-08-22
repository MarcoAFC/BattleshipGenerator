#include "posicionar.h"
using namespace std;
//Coloca o barco na tabela, recebendo o tamanho e o local para colocar
void posicionar(Boat* boat, int nlinhas, int ncol, vector<vector<int>> &mat){
    cout<<"Boat: "<<boat->posX<<", "<<boat->posY<<", "<< boat->orient<<endl;
    for(size_t i = 0; i < boat->size; i++)
    {   
        //verifica a orientação do barco para encontrar a forma de fazer o preenchimento
        if (boat->orient == 1){    
            //caso seja vertical
            //verifica se está em alguma das bordas
            if((boat->posX+i == 0 || boat->posX + i + 1 == nlinhas) || (boat->posY == 0 || boat->posY == ncol-1)){
                //verifica em qual das bordas está e faz o posicionamento
                //se esta encostado no lado esquerdo ou do lado direito
                if(boat->posX+i == 0 || boat->posX+i + 1 == nlinhas){
                    //para colocar o caracter de inicio ou fim
                    if(i == 0){
                        mat.at(boat->posX+i).at(boat->posY) = 3;
                    }
                    else if(i == boat->size-1){
                        mat.at(boat->posX+i).at(boat->posY) = 4;
                    }
                    //se está encostado em cima
                    if (boat->posY == 0){
                        mat.at(boat->posX+i).at(boat->posY+1) = 2;
                    }
                    //se está encostado em baixo
                    else if(boat->posY == ncol){
                        mat.at(boat->posX+i).at(boat->posY-1) = 2;
                    }
                    //se não está encostado
                    else{
                        mat.at(boat->posX+i).at(boat->posY+1) = 2;
                        mat.at(boat->posX+i).at(boat->posY-1) = 2;
                    }
                }
                //se está encostado em cima
                else if(boat->posY == 0){
                    mat.at(boat->posX+i).at(boat->posY) = 1;
                    mat.at(boat->posX+i).at(boat->posY+1) = 2;
                    if(i == 0){
                        //preenche a borda do comeco do barco e coloca o numero especial do fim
                        mat.at(boat->posX+i).at(boat->posY) = 3;
                        mat.at(boat->posX-1+i).at(boat->posY) = 2;
                        mat.at(boat->posX-1+i).at(boat->posY+1) = 2;
                    }
                    else if(i == boat->size-1){
                        //preenche a borda do fim do barco e coloca o numero especial do fim
                        mat.at(boat->posX+i).at(boat->posY) = 4;
                        mat.at(boat->posX+1+i).at(boat->posY) = 2;
                        mat.at(boat->posX+1+i).at(boat->posY+1) = 2;
                    }
                }
                //se está encostado em baixo
                else if(boat->posY == ncol){
                    mat.at(boat->posX+i).at(boat->posY) = 1;
                    mat.at(boat->posX+i).at(boat->posY-1) = 2;
                    if(i == 0){
                        //preenche a borda do comeco do barco e coloca o numero especial do fim
                        mat.at(boat->posX+i).at(boat->posY) = 3;
                        mat.at(boat->posX-1).at(boat->posY) = 2;
                        mat.at(boat->posX-1).at(boat->posY-1) = 2;
                    }
                    else if(i == boat->size-1){
                        //preenche a borda do fim do barco e coloca o numero especial do fim
                        mat.at(boat->posX+i).at(boat->posY) = 4;
                        mat.at(boat->posX+1+i).at(boat->posY) = 2;
                        mat.at(boat->posX+1+i).at(boat->posY-1) = 2;
                    }
                }
            }
            else{
                //preenchimento da posicao do barco e a borda imediata
                mat.at(boat->posX+i).at(boat->posY) = 1;
                mat.at(boat->posX+i).at(boat->posY+1) = 2;
                mat.at(boat->posX+i).at(boat->posY-1) = 2;
                if(i == 0)
                {
                    //preenche a borda do comeco do barco e coloca o numero especial do fim
                    mat.at(boat->posX+i).at(boat->posY) = 3;
                    mat.at(boat->posX-1+i).at(boat->posY-1) = 2;
                    mat.at(boat->posX-1+i).at(boat->posY) = 2;
                    mat.at(boat->posX-1+i).at(boat->posY+1) = 2;
                }
                else if(i == boat->size-1){
                    //preenche a borda do fim do barco e coloca o numero especial do fim
                    mat.at(boat->posX+i).at(boat->posY) = 4;
                    mat.at(boat->posX+1+i).at(boat->posY-1) = 2;
                    mat.at(boat->posX+1+i).at(boat->posY) = 2;
                    mat.at(boat->posX+1+i).at(boat->posY+1) = 2;
                }
                
            }
        }
        else{
            //caso seja horizontal
            //verifica se está em alguma das bordas
            if(boat->posX == 0 || boat->posX+1 == nlinhas || boat->posY+i == 0 || boat->posY+i+1 == ncol){
                //verifica em qual das bordas está e faz o posicionamento
                //se esta encostado no lado esquerdo ou do lado direito 
                if(boat->posY+i == 0 || i == 0){
                    mat[boat->posX].at(boat->posY) = 5;
                    if (boat->posX > 0 && boat->posY > 0){
                        mat[boat->posX].at(boat->posY-1) = 2;
                        mat.at(boat->posX-1).at(boat->posY-1) = 2;
                    }
                }
                else if(boat->posY+i+1 == ncol || i == boat->size-1){
                    mat[boat->posX][boat->posY+i] = 6;
                }
                else{
                    mat[boat->posX][boat->posY+i] = 1;
                }
                if(boat->posX == 0){
                    mat[boat->posX+1][boat->posY+i] = 2;
                    if(i == 0){
                        mat[boat->posX].at(boat->posY-1) = 2;
                        mat[boat->posX+1].at(boat->posY-1) = 2;
                    }
                    if(i+1 == boat->size){
                        mat[boat->posX][boat->posY+i+1] = 2;
                        mat[boat->posX+1][boat->posY+i+1] = 2;
                    }
                }
                else if(boat->posX+1 == nlinhas){
                    mat.at(boat->posX-1)[boat->posY+i] = 2;
                    if (i+1 == boat->size && boat->posY+i < ncol)
                    {
                        
                         mat.at(boat->posX-1)[boat->posY+i+1] = 2;
                         mat[boat->posX][boat->posY+i+1] = 2;
                    }
                    
                }
                else{
                    mat.at(boat->posX-1)[boat->posY+i] = 2;
                    mat[boat->posX+1][boat->posY+i] = 2;
                    
                }
                
            }
            else{
                mat[boat->posX][boat->posY+i] = 1;
                mat.at(boat->posX-1)[boat->posY+i] = 2;
                mat[boat->posX+1][boat->posY+i] = 2;
                if(i == 0)
                {
                    //preenche a borda do comeco do barco e coloca o numero especial do fim
                    mat[boat->posX][boat->posY+i] = 5;
                    mat.at(boat->posX-1)[boat->posY-1+i] = 2;
                    mat[boat->posX][boat->posY-1+i] = 2;
                    mat[boat->posX+1][boat->posY-1+i] = 2;
                }
                else if(i == boat->size-1){
                    //preenche a borda do fim do barco e coloca o numero especial do fim
                    mat[boat->posX][boat->posY+i] = 6;
                    mat.at(boat->posX-1)[boat->posY+1+i] = 2;
                    mat[boat->posX][boat->posY+1+i] = 2;
                    mat[boat->posX+1][boat->posY+1+i] = 2;
                }   
            }
        }
    }
    
}