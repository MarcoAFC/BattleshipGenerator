#include "../include/posicionar.h"
#include "../include/encontrarpos.h"
#include "../include/print.h"
#include "../include/rdtsc.h"
#include <string>

using namespace std;

int main(int argc, char *argv[])
{

    int nlinhas = 10; 
    int ncol = 10;
    int numTab = 1;
    if(argc == 1){
        cout<<"To generate your battleship tables, please refer to the following argument usage:\n";
        cout<<"./BattleOn [<options>] <number_of_puzzles>\n";
        cout<<"Options are:\n  --rows <num>  Choose the number of rows in the matrix in the range [7, 16].\n";
        cout<<"  --cols <num>  Choose the number of columns in the matrix in the range [7, 16].\n";
        cout<<"You must input:\n number_of_puzzles  To represent the number of puzzles being generated in the range [1, 100]";
    }
    else if(argc > 6){
        cout<<"Too many arguments, please refer to the following argument usage:\n";
        cout<<"./BattleOn [<options>] <number_of_puzzles>\n";
        cout<<"Options are:\n  --rows <num>  Choose the number of rows in the matrix in the range [7, 16].\n";
        cout<<"  --cols <num>  Choose the number of columns in the matrix in the range [7, 16].\n";
        cout<<"You must input:\n number_of_puzzles  To represent the number of puzzles being generated in the range [1, 100]";
    }
    else{
        for(auto i{1}; i < argc; i++){
            string str = argv[i];
            for (char & c : str){
                c = std::tolower(c);
            }
            if (str == "--r" || str == "--row" || str == "-r" || str == "-row"){
                int col = 0;
                if (i+1 == argc){
                    cout<<"Please insert a number of rows!\n";
                }
                try {
                    col = std::stoi( argv[++i] );
                }
                catch( const std::invalid_argument& e ){
                    cout<<"Invalid value for row!\n";
                }
                if (col < 7 || col > 16){
                    cout<<"Number of rows out of range!\n";
                }
                else{
                    ncol = col;
                }
            }
            else if (str == "--c" || str == "--col" || str == "-col" || str == "-c"){
                int lin = 0;
                if (i+1 == argc){
                    cout<<"Please insert the corresponding number of rows!\n";
                }
                try {
                    lin = std::stoi( argv[++i] );
                }
                catch( const std::invalid_argument& e ){
                    cout<<"Invalid value for row!\n";
                }
                if (lin < 7 || lin > 16){
                    cout<<"Number of rows out of range!\n";
                }
                else{
                    nlinhas = lin;
                }
            }
            else{
                int tab = 0;
                try {
                    tab = std::stoi( argv[i] );
                }
                catch( const std::invalid_argument& e ){
                    cout<<"Invalid value for number of puzzles!\n";
                }
                if ( tab < 1 or tab > 100 ){
                    cout<<"The requested number of puzzles is out of the acceptable range!\n";
                }
                numTab = tab;
            }

        }    
    }
    vector<vector<int>> mat;
    mat.resize(nlinhas+2, vector<int>(ncol+2));
    while(numTab > 0){
        //iniciando ela com zero
        for(int i = 0;i <= nlinhas; ++i)
        {
            for(int j = 0;j <= ncol; ++j)
            {
                mat[i][j] = 0;
            }
        }
        bool tabValido = true;
        //gerando a primeira peça
        // battleship
        Boat* bs1 = new Boat(4, randomGen(0,1));
        encontrarPosicao(bs1, nlinhas, ncol, mat, tabValido);
        Boat* ds1 = new Boat(3, randomGen(0,1));
        encontrarPosicao(ds1, nlinhas, ncol, mat, tabValido);
        Boat* ds2 = new Boat(3, randomGen(0,1));
        encontrarPosicao(ds2, nlinhas, ncol, mat, tabValido);
        Boat* cs1 = new Boat(2, randomGen(0,1));
        encontrarPosicao(cs1, nlinhas, ncol, mat, tabValido);
        Boat* cs2 = new Boat(2, randomGen(0,1));
        encontrarPosicao(cs2, nlinhas, ncol, mat, tabValido);
        Boat* cs3 = new Boat(2, randomGen(0,1));
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