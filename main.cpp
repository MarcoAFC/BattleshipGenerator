#include "posicionar.h"
#include "encontrarpos.h"
#include "print.h"
using namespace std;

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
    

    for(int i = 1;i <= nlinhas; ++i){
        for(int j = 1;j <= ncol; ++j)
        {
            cout << mat[i][j]<<" ";
        }
    cout << "\n";
    }
    printMatrix(mat, nlinhas, ncol);
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