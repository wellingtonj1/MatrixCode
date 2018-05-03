#include "jmatrix.h"
#include "jmatrix.cpp"

#include <iostream>

using namespace std;

int main()
{
    int escolha,tamanholinh,tamanholinh2,tamanhocol2,tamanhocol,linhatrix,colunatrix,linhatrix2,colunatrix2;
    string continua="sim";
    while(continua=="sim")
    {

        cout<<"\nDigite o tamanho maximo da 1º Matriz: linha[] ";
        cin>>tamanholinh;
        cout<<"\nDigite o tamanho maximo da 1º Matriz: colun[] :";
        cin>>tamanhocol;

        cout<<"\n\nDigite o tamanho maximo da 2º Matriz: linha[] ";
        cin>>tamanholinh2;
        cout<<"\nDigite o tamanho maximo da 2º Matriz: colun[] :";
        cin>>tamanhocol2;

        jmatrix p(tamanholinh,tamanhocol),p2(tamanholinh2,tamanhocol2),aux(tamanholinh+tamanhocol2,tamanhocol+tamanhocol2);


        cout<<"\n\n";
        cout<<"\n Digite o tamanho da linha da 1ºMatriz :";
        cin>>linhatrix;
        cout<<"\n Digite o tamanho da coluna da 1ºMatriz :";
        cin>>colunatrix;
        if(!p.setlc(linhatrix,colunatrix))
        {
            cout<<"\nTamanho invalido..programa abortado!";
            break;
        }

        p.lemat();

        cout<<"\n\n Digite o tamanho da linha da 2ºMatriz :";
        cin>>linhatrix2;
        cout<<"\n Digite o tamanho da coluna da 2ºMatriz :";
        cin>>colunatrix2;
        if(!p2.setlc(linhatrix2,colunatrix2))
        {
            cout<<"\nTamanho invalido..programa abortado!";
            break;
        }
        p2.lemat();


        cout<<"\n\t\t Menu  \n";
        cout<< "\n Digite a operação que você deseja realizar\n";
        //cout<< " 1.	Leia uma matriz com tamanho definido pelo usuário : " ;
        //cout<< "\n 2.	Pesista uma matriz em arquivo texto : " ;
        //cout<< "\n 3.	Recupere uma matriz de um arquivo texto : " ;
        //cout<< "\n 4.	Apage o arquivo texto de uma matriz : " ;
        cout<< "\n 5.	Calcule e persista a matriz resultante da soma de duas matrizes : " ;
        cout<< "\n 6.	Calcule e persista a matriz resultante da subtracao de duas matrizes : " ;
        cout<< "\n 7.	Calcule e persista a matriz resultante da multiplicacao de duas matrizes : " ;
        cout<< "\n 8.	Determine se uma matriz é triangular superior : " ;
        cout<< "\n 9.	Determine se uma matriz é triangular inferior : " ;
        cout<< "\n 10.	Determine se uma matriz é simétrica : " ;
        cout<< "\n 11.	Determine se uma matriz é anti-simétrica : " ;
        cout<< "\n 12.	Determine se uma matriz é identidade : " ;
        cout<< "\n 13.	Calcule e persista a matriz transposta : " ;
        cout<< "\n 14.	Calcule a potenciação de uma matriz e persista a matriz resultante : " ;
        cout<< "\n 15.	Calcule e persista a matriz resultante da multiplicaçao de uma matriz por k : " ;
        cout<< "\n 16.	Determine se duas matrizes são iguais : " ;
        cout<< "\n 17.   Determine se duas matrizes são diferentes : " ;
        cout<< "\n Sua escolha é : ";
        cin >> escolha;




    }


}
