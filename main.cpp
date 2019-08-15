#include <iostream> 
#include <stdlib.h>

using namespace std;

class Boat{
    //Classe que armazena os parâmetros dos barcos para criar menos variáveis
    public:
    int size;
    int orient;
    int posX = -1;
    int posY = -1;
    //Construtor que guarda automaticamente os dados pela chamada da função
    Boat(int size, int orient){
        this->size = size;
        this->orient = orient;
    }
};

//Coloca o barco na tabela, recebendo o tamanho e o local para colocar
void posicionar(Boat* boat, int nlinhas, int ncol, int** mat){
    for(size_t i = 0; i < boat->size; i++)
    {   
        //verifica a orientação do barco para encontrar a forma de fazer o preenchimento
        if (boat->orient == 1){    
            //caso seja vertical
            //verifica se está em alguma das bordas
            if((boat->posX+i == 0 || boat->posX + i + 1 == nlinhas) || (boat->posY == 0 || boat->posY == ncol)){
                //verifica em qual das bordas está e faz o posicionamento
                //se esta encostado no lado esquerdo ou do lado direito
                if(boat->posX+i == 0 || boat->posX+i + 1 == nlinhas){
                    //para colocar o caracter de inicio ou fim
                    if(i == 0){
                        mat[boat->posX+i][boat->posY] = 3;
                    }
                    else if(i == boat->size-1){
                        mat[boat->posX+i][boat->posY] = 4;
                    }
                    //se está encostado em cima
                    if (boat->posY == 0){
                        mat[boat->posX+i][boat->posY+1] = 2;
                    }
                    //se está encostado em baixo
                    else if(boat->posY == ncol){
                        mat[boat->posX+i][boat->posY-1] = 2;
                    }
                    //se não está encostado
                    else{
                        mat[boat->posX+i][boat->posY+1] = 2;
                        mat[boat->posX+i][boat->posY-1] = 2;
                    }
                }
                //se está encostado em cima
                else if(boat->posY == 0){
                    mat[boat->posX+i][boat->posY] = 1;
                    mat[boat->posX+i][boat->posY+1] = 2;
                    if(i == 0){
                        //preenche a borda do comeco do barco e coloca o numero especial do fim
                        mat[boat->posX+i][boat->posY] = 3;
                        mat[boat->posX-1+i][boat->posY] = 2;
                        mat[boat->posX-1+i][boat->posY+1] = 2;
                    }
                    else if(i == boat->size-1){
                        //preenche a borda do fim do barco e coloca o numero especial do fim
                        mat[boat->posX+i][boat->posY] = 4;
                        mat[boat->posX+1+i][boat->posY] = 2;
                        mat[boat->posX+1+i][boat->posY+1] = 2;
                    }
                }
                //se está encostado em baixo
                else if(boat->posY == ncol){
                    mat[boat->posX+i][boat->posY] = 1;
                    mat[boat->posX+i][boat->posY-1] = 2;
                    if(i == 0){
                        //preenche a borda do comeco do barco e coloca o numero especial do fim
                        mat[boat->posX+i][boat->posY] = 3;
                        mat[boat->posX-1][boat->posY] = 2;
                        mat[boat->posX-1][boat->posY-1] = 2;
                    }
                    else if(i == boat->size-1){
                        //preenche a borda do fim do barco e coloca o numero especial do fim
                        mat[boat->posX+i][boat->posY] = 4;
                        mat[boat->posX+1+i][boat->posY] = 2;
                        mat[boat->posX+1+i][boat->posY-1] = 2;
                    }
                }
            }
            else{
                //preenchimento da posicao do barco e a borda imediata
                mat[boat->posX+i][boat->posY] = 1;
                mat[boat->posX+i][boat->posY+1] = 2;
                mat[boat->posX+i][boat->posY-1] = 2;
                if(i == 0)
                {
                    //preenche a borda do comeco do barco e coloca o numero especial do fim
                    mat[boat->posX+i][boat->posY] = 3;
                    mat[boat->posX-1+i][boat->posY-1] = 2;
                    mat[boat->posX-1+i][boat->posY] = 2;
                    mat[boat->posX-1+i][boat->posY+1] = 2;
                }
                else if(i == boat->size-1){
                    //preenche a borda do fim do barco e coloca o numero especial do fim
                    mat[boat->posX+i][boat->posY] = 4;
                    mat[boat->posX+1+i][boat->posY-1] = 2;
                    mat[boat->posX+1+i][boat->posY] = 2;
                    mat[boat->posX+1+i][boat->posY+1] = 2;
                }
                
            }
        }
        else{
            //caso seja horizontal
            //verifica se está em alguma das bordas
            if(boat->posX == 0 || boat->posX == nlinhas || boat->posY+i == 0 || boat->posY+i+1 == ncol){
                //verifica em qual das bordas está e faz o posicionamento
                //se esta encostado no lado esquerdo ou do lado direito
                if(boat->posY+i == 0 || i == 0){
                    mat[boat->posX][boat->posY] = 5;
                                        
                }
                else if(boat->posY+i == ncol-1 || i == boat->size-1){
                    mat[boat->posX][boat->posY+i] = 6;
                    
                }
                else{
                    mat[boat->posX][boat->posY+i] = 1;
                }
                if(boat->posX == 0){
                    mat[boat->posX+1][boat->posY+i] = 2;
                }
                else if(boat->posX == nlinhas-1){
                    mat[boat->posX-1][boat->posY+i] = 2;
                }
                else{
                    mat[boat->posX-1][boat->posY+i] = 2;
                    mat[boat->posX+1][boat->posY+i] = 2;
                    
                }
                
            }
            else{
                mat[boat->posX][boat->posY+i] = 1;
                mat[boat->posX-1][boat->posY+i] = 2;
                mat[boat->posX+1][boat->posY+i] = 2;
                if(i == 0)
                {
                    //preenche a borda do comeco do barco e coloca o numero especial do fim
                    mat[boat->posX][boat->posY+i] = 5;
                    mat[boat->posX-1][boat->posY-1+i] = 2;
                    mat[boat->posX][boat->posY-1+i] = 2;
                    mat[boat->posX+1][boat->posY-1+i] = 2;
                }
                else if(i == boat->size-1){
                    //preenche a borda do fim do barco e coloca o numero especial do fim
                    mat[boat->posX][boat->posY+i] = 6;
                    mat[boat->posX-1][boat->posY+1+i] = 2;
                    mat[boat->posX][boat->posY+1+i] = 2;
                    mat[boat->posX+1][boat->posY+1+i] = 2;
                }
                
                
            }
        }
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

    int **mat = new int*[nlinhas];
 
    for(int i = 0;i < nlinhas; ++i)
        mat[i] = new int[ncol];
 
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
    cout << "orientação: "<< bs1->orient <<endl;
    //orient = orientação, onde 0 é vertical e 1 horizontal
    //se a orientação for vertical, posiciona da maneira a seguir
    if(bs1->orient == 0){
        bs1->posX = rand() %(nlinhas);
        bs1->posY = rand() %(ncol-3);
        //bs1->posX = 0;
        //bs1->posY = 0; 
        cout << bs1->posX <<endl;
        cout << bs1->posY <<endl; //verificação
        posicionar(bs1, nlinhas, ncol, mat);
        
    }
    //se a orientação for horizontal, posiciona da maneira a seguir
    if(bs1->orient == 1){
        bs1->posX = rand() %(nlinhas-3);
        bs1->posY = rand() %(ncol); 
        cout << bs1->posX <<endl;
        cout << bs1->posY <<endl; //verificação
        posicionar(bs1, nlinhas, ncol, mat);
    }

       for(int i = 0;i < nlinhas; ++i)
        {
        for(int j = 0;j < ncol; ++j)
          {
             cout << mat[i][j]<<" ";
          }
        cout << "\n";
        }
    //liberar memória
   /* for(int i = 0;i < nlinhas; ++i)
        delete []mat[i];
 
    delete []mat; */    
    delete bs1;
    return 0;
}

//Até agora, feito a criação dinâmica de matrizes, com entrada de dados pelo usuário.
//(mudar para a entrada proposta pelo trabalho)