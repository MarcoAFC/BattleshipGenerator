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
    while(numTab > 0){
        //iniciando ela com zero
        for(int i = 0;i < nlinhas; ++i)
        {
            for(int j = 0;j < ncol; ++j)
            {
                mat[i][j] = 0;
            }
        }
        bool tabValido = true;
        //gerando a primeira peça
        // battleship
        Boat* bs1 = new Boat(4, rand() % 2);
        encontrarPosicao(bs1, nlinhas, ncol, mat, tabValido);
        Boat* ds1 = new Boat(3, rand() % 2);
        encontrarPosicao(ds1, nlinhas, ncol, mat, tabValido);
        Boat* ds2 = new Boat(3, rand() % 2);
        encontrarPosicao(ds2, nlinhas, ncol, mat, tabValido);
        Boat* cs1 = new Boat(2, rand() % 2);
        encontrarPosicao(cs1, nlinhas, ncol, mat, tabValido);
        Boat* cs2 = new Boat(2, rand() % 2);
        encontrarPosicao(cs2, nlinhas, ncol, mat, tabValido);
        Boat* cs3 = new Boat(2, rand() % 2);
        encontrarPosicao(cs3, nlinhas, ncol, mat, tabValido);
        Subm* sb1 = new Subm();
        encontrarPosSub(sb1, nlinhas, ncol, mat, tabValido);
        Subm* sb2 = new Subm();
        encontrarPosSub(sb2, nlinhas, ncol, mat, tabValido);
        Subm* sb3 = new Subm();
        encontrarPosSub(sb3, nlinhas, ncol, mat, tabValido);
        Subm* sb4 = new Subm();
        encontrarPosSub(sb4, nlinhas, ncol, mat, tabValido);
        if(tabValido == true){
            printMatrix(mat, nlinhas, ncol);
            printArmada(*bs1);
            printArmada(*ds1);
            printArmada(*ds2);
            printArmada(*cs1);
            printArmada(*cs2);
            printArmada(*cs3);
            printSub(*sb1);
            printSub(*sb2);
            printSub(*sb3);
            printSub(*sb4);
        }
        else{
            cout<<"INVALIDO\n";
            numTab++;
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
        numTab--;
    }
    return 0;
}


//Até agora, feito a criação dinâmica de matrizes, com entrada de dados pelo usuário.
//(mudar para a entrada proposta pelo trabalho)