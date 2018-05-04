#include "jmatrix.h"
#include "jmatrix.cpp"

#include <stdlib.h>
#include <iostream>

using namespace std;

int main()
{
    int escolha,tamanholinh,tamanholinh2,tamanhocol2,tamanhocol,linhatrix,colunatrix,linhatrix2,colunatrix2;
    string continua="sim";
    string repete="s";

    cout<<"\Estabele�a o tamanho limite da 1� Matriz: linha[] :";
    cin>>tamanholinh;
    cout<<"\nEstabele�a o tamanho limite  da 1� Matriz: colun[] :";
    cin>>tamanhocol;

    cout<<"\n\nEstabele�a o tamanho limite  da 2� Matriz: linha[] :";
    cin>>tamanholinh2;
    cout<<"\nEstabele�a o tamanho limite  da 2� Matriz: colun[] : ";
    cin>>tamanhocol2;

    jmatrix p(tamanholinh,tamanhocol),p2(tamanholinh2,tamanhocol2);

    while(repete=="s")
    {
        jmatrix aux(tamanholinh+tamanhocol2,tamanhocol+tamanhocol2);
        system("cls");
        cout<<" \n 1�Limite linha = " <<tamanholinh<<"\n 1�Limite coluna = "<<tamanhocol<<"\n 2�Limite linha = "<<tamanholinh2;
        cout<<" \n 2�Limite coluna = "<<tamanhocol2 << "\n\n";
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

        switch(escolha)
        {
            case 5:
            {
                cout<<"\n";
                aux.soma(p,p2);
                aux.imprimemat();
                cout<<"\n";
                break;
            }
            case 6:
            {
                cout<<"\n";
                aux.sub(p,p2);
                aux.imprimemat();
                cout<<"\n";
                break;
            }
            case 7:
            {
                cout<<"\n";
                aux.multip(p,p2);
                aux.imprimemat();
                cout<<"\n";
                break;
            }
            case 8:
            {
                int digito1;
                cout<<"\nDeseja realizar essa opera��o com a 1� ou com a 2� ? digite 1 ou 2 ! :";
                cin>>digito1;
                if(digito1==1)
                {
                    if(p.triangsup())
                    {
                        cout<< "\n � triangular superior !!!";
                    }
                    else
                    {
                        cout<< "\n N�o � triangular superior !!!";
                    }
                }
                if(digito1==2)
                {
                    if(p2.trianginf())
                    {
                        cout<< "\n � triangular superior !!!";
                    }
                    else
                    {
                        cout<< "\n N�o � triangular superior !!!";
                    }
                }
                break;
            }
            case 9:
            {
                int digito;
                cout<<"\nDeseja realizar essa opera��o com a 1� ou com a 2� ? digite 1 ou 2 ! :";
                cin>>digito;
                if(digito==1)
                {
                    if(p.trianginf())
                    {
                        cout<< "\n � triangular inferior !!!";
                    }
                    else
                    {
                        cout<< "\n N�o � triangular inferior !!!";
                    }
                }
                if(digito==2)
                {
                    if(p2.trianginf())
                    {
                        cout<< "\n � triangular inferior !!!";
                    }
                    else
                    {
                        cout<< "\n N�o � triangular inferior !!!";
                    }
                }

                break;
            }

            default:
            {
                cout<<"\nSe n�o digitares o numero certo te mandarei tomar no cuca !!! \n";
            }

        }

        cout<<"\nDeseja continuar ? s ou n ? ";
        cin>>repete;
        system("cls");
    }

}
