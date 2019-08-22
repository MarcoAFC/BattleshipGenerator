#include <iostream> 
#include <stdlib.h>
#include <vector>
#include "posicionar.h"
using namespace std;

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
int main(int, char **)
{
    srand((unsigned int)time(NULL));
    int nlinhas = 0; 
    int ncol = 0;
    cout << "Digite o numero de linhas e colunas respectivamente: ";
    cin >> nlinhas;
    cin >> ncol;
    vector<vector<int>> mat;
    mat.resize(nlinhas+2, vector<int>(ncol+2));
    //iniciando ela com zero
    for(int i = 0;i < nlinhas; ++i)
    {
        for(int j = 0;j < ncol; ++j)
        {
            mat[i][j] = 0;
        }
    }
    //gerando a primeira peça
    // battleship
    Boat* bs1 = new Boat(4, rand() % 2);
    encontrarPosicao(bs1, nlinhas, ncol, mat);
    Boat* ds1 = new Boat(3, rand() % 2);
    encontrarPosicao(ds1, nlinhas, ncol, mat);
    Boat* ds2 = new Boat(3, rand() % 2);
    encontrarPosicao(ds2, nlinhas, ncol, mat);
    Boat* cs1 = new Boat(2, rand() % 2);
    encontrarPosicao(cs1, nlinhas, ncol, mat);
    Boat* cs2 = new Boat(2, rand() % 2);
    encontrarPosicao(cs2, nlinhas, ncol, mat);
    Boat* cs3 = new Boat(2, rand() % 2);
    encontrarPosicao(cs3, nlinhas, ncol, mat);
    Subm* sb1 = new Subm();
    encontrarPosSub(sb1, nlinhas, ncol, mat);
    Subm* sb2 = new Subm();
    encontrarPosSub(sb2, nlinhas, ncol, mat);
    Subm* sb3 = new Subm();
    encontrarPosSub(sb3, nlinhas, ncol, mat);
    Subm* sb4 = new Subm();
    encontrarPosSub(sb4, nlinhas, ncol, mat);

    //orient = orientação, onde 0 é vertical e 1 horizontal
    //se a orientação for vertical, posiciona da maneira a seguir
    

    for(int i = 1;i <= nlinhas; ++i)
    {
    for(int j = 1;j <= ncol; ++j)
        {
            cout << mat[i][j]<<" ";
        }
    cout << "\n";
    }
//liberar memória
    delete bs1;
    delete ds1;
    delete ds2;
    delete cs1;
    delete cs2;
    delete cs3;
    delete sb1;
    delete sb2;
    delete sb3;
    delete sb4;  
    cout<<"ok\n";
    return 0;
}


//Até agora, feito a criação dinâmica de matrizes, com entrada de dados pelo usuário.
//(mudar para a entrada proposta pelo trabalho)