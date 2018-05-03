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

        cout<<"\nDigite o tamanho maximo da 1� Matriz: linha[] ";
        cin>>tamanholinh;
        cout<<"\nDigite o tamanho maximo da 1� Matriz: colun[] :";
        cin>>tamanhocol;

        cout<<"\n\nDigite o tamanho maximo da 2� Matriz: linha[] ";
        cin>>tamanholinh2;
        cout<<"\nDigite o tamanho maximo da 2� Matriz: colun[] :";
        cin>>tamanhocol2;

        jmatrix p(tamanholinh,tamanhocol),p2(tamanholinh2,tamanhocol2),aux(tamanholinh+tamanhocol2,tamanhocol+tamanhocol2);


        cout<<"\n\n";
        cout<<"\n Digite o tamanho da linha da 1�Matriz :";
        cin>>linhatrix;
        cout<<"\n Digite o tamanho da coluna da 1�Matriz :";
        cin>>colunatrix;
        if(!p.setlc(linhatrix,colunatrix))
        {
            cout<<"\nTamanho invalido..programa abortado!";
            break;
        }

        p.lemat();

        cout<<"\n\n Digite o tamanho da linha da 2�Matriz :";
        cin>>linhatrix2;
        cout<<"\n Digite o tamanho da coluna da 2�Matriz :";
        cin>>colunatrix2;
        if(!p2.setlc(linhatrix2,colunatrix2))
        {
            cout<<"\nTamanho invalido..programa abortado!";
            break;
        }
        p2.lemat();


        cout<<"\n\t\t Menu  \n";
        cout<< "\n Digite a opera��o que voc� deseja realizar\n";
        //cout<< " 1.	Leia uma matriz com tamanho definido pelo usu�rio : " ;
        //cout<< "\n 2.	Pesista uma matriz em arquivo texto : " ;
        //cout<< "\n 3.	Recupere uma matriz de um arquivo texto : " ;
        //cout<< "\n 4.	Apage o arquivo texto de uma matriz : " ;
        cout<< "\n 5.	Calcule e persista a matriz resultante da soma de duas matrizes : " ;
        cout<< "\n 6.	Calcule e persista a matriz resultante da subtracao de duas matrizes : " ;
        cout<< "\n 7.	Calcule e persista a matriz resultante da multiplicacao de duas matrizes : " ;
        cout<< "\n 8.	Determine se uma matriz � triangular superior : " ;
        cout<< "\n 9.	Determine se uma matriz � triangular inferior : " ;
        cout<< "\n 10.	Determine se uma matriz � sim�trica : " ;
        cout<< "\n 11.	Determine se uma matriz � anti-sim�trica : " ;
        cout<< "\n 12.	Determine se uma matriz � identidade : " ;
        cout<< "\n 13.	Calcule e persista a matriz transposta : " ;
        cout<< "\n 14.	Calcule a potencia��o de uma matriz e persista a matriz resultante : " ;
        cout<< "\n 15.	Calcule e persista a matriz resultante da multiplica�ao de uma matriz por k : " ;
        cout<< "\n 16.	Determine se duas matrizes s�o iguais : " ;
        cout<< "\n 17.   Determine se duas matrizes s�o diferentes : " ;
        cout<< "\n Sua escolha � : ";
        cin >> escolha;




    }


}
