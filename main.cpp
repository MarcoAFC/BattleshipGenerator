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
    cout << "Digita o numero de tabuleiros a serem criados: ";
    int numTab;
    cin>>numTab;
    vector<vector<int>> mat;
    mat.resize(nlinhas+2, vector<int>(ncol+2));
    //iniciando ela com zero
    while(numTab > 0)
        {for(int i = 0;i < nlinhas; ++i)
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
        numTab--;
    }
    return 0;
}


//Até agora, feito a criação dinâmica de matrizes, com entrada de dados pelo usuário.
//(mudar para a entrada proposta pelo trabalho)