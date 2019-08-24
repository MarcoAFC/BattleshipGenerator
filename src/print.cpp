#include "../include/print.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

    /*!
     * Increments the starting index of the matrix.txt file by 1,
     * proceeds to print the table in matrix form on the file.
     * \param The matrix.
     * \param X dimension size of the matrix.
     * \param Y dimension size of the matrix.
     */
void printMatrix(vector<vector<int>> mat, int nlinhas, int ncol){
    //lê a primeira linha, pega o índice atual e fecha o arquivo
    ifstream fileIn;
    fileIn.open("output/matrix.txt");
    string linha;
    getline(fileIn, linha);
    stringstream pegaIndice(linha);
    int indice = 0;
    pegaIndice >> indice;
    //fecha o arquivo de entrada

    string content = "";
    for (int i = 0; fileIn.eof() != true; i++){
        content += fileIn.get();
    }
    //abre o arquivo para saída no modo de sobreescrever
    content.erase(content.end()-1);
    ofstream overwrite;  
    overwrite.open("output/matrix.txt");
    overwrite<<indice+1<<endl;
    overwrite<<content;
    //fecha a sobreescrita
    overwrite.close();
    fileIn.close();
    //abre novamente, colocando a saída no final do arquivo
    ofstream file("output/matrix.txt", ofstream::app);
    file<<nlinhas<<" "<<ncol<<endl;
    //imprimir o cabeçalho adequado
    if(nlinhas >= 10){
        for (int i = 0; i < 22; i++){
            file<<" ";
        }
        for (int i = 0; i < ncol-9; i++)
        {
            file<<"1 ";
        }
        file<<endl;
    }
    file<<"    ";
    for(int i = 0; i < ncol; i++){
        file<<(i+1)%10<<" ";
    }
    file<<"\n";

    for(int i = 1;i <= nlinhas; ++i){
        for(int j = 1;j <= ncol; ++j){
            if (j == 1){
                if(i < 10){
                    file<<" "<<i<<"[ ";
                }
                else{
                    file<<i<<"[ ";
                }
            }
            if(mat.at(i).at(j) == 0 || mat.at(i).at(j) == 2){
                file<<"· ";
            }
            else if(mat.at(i).at(j) == 1){
                file<<"◼︎ ";
            }
            else if(mat.at(i).at(j) == 3){
                file<<"◀︎ ";
            }
            else if(mat.at(i).at(j) == 4){
                file<<"▶︎ ";
            }
            else if(mat.at(i).at(j) == 5){
                file<<"▲ ";
            }
            else if(mat.at(i).at(j) == 6){
                file<<"▼ ";
            }
            else if(mat.at(i).at(j) == 7){
                file<<"● ";
            }
        }
    file<<endl;
    }
    file<<endl<<endl;
    file.close();
}

    /*!
    * If the first boat is being placed, increments the starting index of the matrix.txt file by 1,
    * otherwise, ignores this step and proceeds to print the boat in the armada.txt file, according to its type and position.
    * \param The boat object being printed.
    */

void printArmada(Boat boat){
    if (boat.size == 4){
        ifstream fileIn;
        fileIn.open("output/armada.txt");
        string linha;
        getline(fileIn, linha);
        stringstream pegaIndice(linha);
        int indice = 0;
        pegaIndice >> indice;
        //fecha o arquivo de entrada

        string content = "";
        for (int i = 0; fileIn.eof() != true; i++){
            content += fileIn.get();
        }
        //abre o arquivo para saída no modo de sobreescrever
        content.erase(content.end()-1);
        ofstream overwrite;  
        overwrite.open("output/armada.txt");
        overwrite<<indice+1<<endl;
        overwrite<<content;
        //fecha a sobreescrita
        overwrite.close();
        fileIn.close();
        }
    ofstream file("output/armada.txt", ios::app);

    if(boat.size == 4){
        file<<endl;
        file<<"B ";
    }
    else if(boat.size == 3){
        file<<"D ";
    }
    else if(boat.size == 2){
        file<<"C ";
    }
    file<<boat.posX<<" "<<boat.posY<<" ";
    if(boat.orient == 1){
        file<<"V"<<endl;
    }
    else{
        file<<"H"<<endl;
    }
    file.close();
}

    /*!
    * Prints the current submarine in the armada.txt file, according to its position.
    * \param The submarine object being printed.
    */

void printSub(Subm sub){
    ofstream file("output/armada.txt", ios::app);
    file<<"S "<<sub.posX<<" "<<sub.posY<<endl;
    file.close();
}