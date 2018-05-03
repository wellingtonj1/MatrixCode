#include "jmatrix.h"
#include <iostream>
#include <cmath>

using namespace std;

jmatrix::jmatrix(int nl,int nc)
{
    int i;
    matrix=new int*[nl];
    for(i=0;i<nl;i++)
    {
        matrix[i]=new int[nc];
    }
    ql=nl;
    qc=nc;
    l=c=0;
}
bool jmatrix::setmatij(int i,int j,int x)
{
    if(i>=ql||j>=qc)
    {
        cout<<"\nTamanho invalido inserido!\n";
        return false;
    }
    matrix[i][j]=x;
    return true;
}


int jmatrix::getmatij(int i,int j)
{
    if(i>l||j>=c)
    {
        cout<<"\nTamanho invalido inserido!\n";
        return 0;
    }
    return matrix[i][j];
}

bool jmatrix::lemat()
{
    if(l>ql||c>qc)
    {
        cout<<"\n\tTamanho invalido inserido!\n";
        return false;
    }
    else
    {
    int i,k;
    cout<< "\n";
    for(i=0;i<l;i++)
    {
        for(k=0;k<c;k++)
        {
            cin>>matrix[i][k];
        }
    }
    return true;
    }
}

bool jmatrix::imprimemat(int x,int y)
{
    if(x>=l||y>=c)
    {
        cout<<"\nTamanho invalido inserido!\n";
        return false;
    }
    cout<<matrix[x][y];
    return true;

}

void jmatrix::imprimemat()
{
    int i,k;
    for(i=0;i<l;i++)
    {
        for(k=0;k<c;k++)
        {
            cout<<matrix[i][k];
        }
    }
}

bool jmatrix::setlc(int x,int y)
{
    if(x>ql||y>qc)
    {
        return false;
    }
    l=x;
    c=y;
    return true;

}

/*void jmatrix::soma(jmatrix j,jmatrix k)
{
    for(int i=0;i<j.l;i++)
    {
        for(int d=0;d<k.l;i++)
        {
            matrix[i]=j.matrix[i]+k.matrix[i];
        }
    }
}
*/

jmatrix::~jmatrix()
{
    for(int i=0;i<ql;i++)
    {
        delete[]matrix[i];
    }
    delete[]matrix;
}
