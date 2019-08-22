#include "encontrarpos.h"

    /*!
     * Generates random positions in the matrix to find a pplace suitable for the submarine,
     * keeps running until one is found, then calls posicionarSub() to place the submarine.
     * \param Pointer to the submarine being placed.
     * \param X dimension size of the matrix.
     * \param Y dimension size of the matrix.
     * \param The matrix.
     */
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

    /*!
     * Generates random position in the matrix to find a suitable spot for the boat according to its size and orientation,
     * keeps running until a suitable position is found and then calls the posicionar() function to place the boat in the matrix.
     * \param Pointer to the boat being placed.
     * \param X dimension size of the matrix.
     * \param Y dimension size of the matrix.
     * \param The matrix.
     */

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