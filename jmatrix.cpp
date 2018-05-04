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
    int i,k,t=1;
    for(i=0;i<l;i++)
    {

        for(k=0;k<c;k++)
        {   if(i==t)
            {
                t++;
                cout<<"\n";
                cout<<matrix[i][k] << " ";
            }
            else
            {
            cout<<matrix[i][k] << " ";
            }
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

void jmatrix::soma(jmatrix x,jmatrix y)
{
    if(x.l==y.l&x.c==y.c)
    {
        for(int i=0;i<x.l;i++)
        {
            for(int k=0;k<x.c;k++)
            {
            matrix[i][k]=x.matrix[i][k]+y.matrix[i][k];
            }
        }
    l=x.l;
    c=x.c;
    }
    else
    {
        cout<<"\nAs matrizes dijitadas não possuem o mesmo número de linhas e de colunas!";
    }
}

void jmatrix::sub(jmatrix x,jmatrix y)
{
    if(x.l==y.l&x.c==y.c)
    {
        for(int i=0;i<x.l;i++)
        {
            for(int k=0;k<x.c;k++)
            {
            matrix[i][k]=x.matrix[i][k]-y.matrix[i][k];
            }
        }
    l=x.l;
    c=x.c;
    }
    else
    {
        cout<<"\nAs matrizes dijitadas não possuem o mesmo número de linhas e de colunas!";
    }
}

void jmatrix::multip(jmatrix x,jmatrix y)
{

    if(x.l==y.c||x.c==y.l)
    {
        for(int i=0;i<x.l;i++)
        {
            for(int k=0;k<y.c;k++)
            {
                for(int f=0;f<x.c;f++)
                {
                   matrix[k][i]+=x.matrix[k][f]*y.matrix[f][i];
                }

            }
        }
    l=x.l;
    c=y.c;
    }
    else
    {
        cout<<"\nAs matrizes dijitadas não possuem a condição necessária para serem multiplicadas!";
    }
}
bool jmatrix::trianginf()
{
    for(int i=0; i<1-l;i++)
    {
        for(int k=1+i; k<c;k++)
        {
            if(matrix[i][k]!=0)
            {
                return false;
            }
        }
    }
    return true;
}

bool jmatrix::triangsup()
{
    for(int i=1; i<l;i++)
    {
        for(int k=0; k<i;k++)
        {
            if(matrix[i][k]!=0)
            {
                return false;
            }
        }
    }
    return true;
}

jmatrix::~jmatrix()
{
    for(int i=0;i<ql;i++)
    {
        delete[]matrix[i];
    }
    delete[]matrix;
}
