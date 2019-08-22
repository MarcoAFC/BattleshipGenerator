#include "print.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
void printMatrix(vector<vector<int>> mat, int nlinhas, int ncol){
    //lê a primeira linha, pega o índice atual e fecha o arquivo
    ifstream fileIn;
    fileIn.open("matrix.txt");
    string linha;
    getline(fileIn, linha);
    stringstream pegaIndice(linha);
    int indice = 0;
    pegaIndice >> indice;
    //fecha o arquivo de entrada

    //abre o arquivo para saída no modo de sobreescrever
    ofstream overwrite;
    string content = "";
    for (int i = 0; fileIn.eof() != true; i++){
        content += fileIn.get();
    }
    content.erase(content.end()-1);  
    overwrite.open("matrix.txt");
    overwrite<<indice+1<<endl;
    overwrite<<content;
    //fecha a sobreescrita
    overwrite.close();
    fileIn.close();
    //abre novamente, colocando a saída no final do arquivo
    ofstream file("matrix.txt", ofstream::app);
    file<<nlinhas<<" "<<ncol<<endl;
    //imprimir o cabeçalho adequado
    if(nlinhas >= 10){
        for (int i = 0; i < 22; i++){
            file<<" ";
        }
        for (int i = 0; i < nlinhas-9; i++)
        {
            file<<"1 ";
        }
        file<<endl;
    }
    file<<"    ";
    for(int i = 0; i < nlinhas; i++){
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
    file<<endl;
    file.close();
}