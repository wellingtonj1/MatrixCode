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

bool jmatrix::soma(jmatrix x,jmatrix y)
{
    if(x.l==y.l&&x.c==y.c)
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

		x.matrix=y.matrix=0;
		x.ql=x.qc=y.ql=y.qc=0;
		return true;
    }
    else
    {
        cout<<"\nAs matrizes dijitadas n�o possuem o mesmo n�mero de linhas e de colunas!";

		x.matrix=y.matrix=0;
		x.ql=x.qc=y.ql=y.qc=0;
		return false;
    }
    x.matrix=y.matrix=0;
    x.ql=x.qc=y.ql=y.qc=0;


}

bool jmatrix::sub(jmatrix x,jmatrix y)
{
    if(x.l==y.l&&x.c==y.c)
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

		x.matrix=y.matrix=0;
		x.ql=x.qc=y.ql=y.qc=0;
		return true;
    }
    else
    {
        cout<<"\nAs matrizes dijitadas n�o possuem o mesmo n�mero de linhas e de colunas!";

		x.matrix=y.matrix=0;
		x.ql=x.qc=y.ql=y.qc=0;
		return false;

    }

}

bool jmatrix::multip(jmatrix x,jmatrix y)
{
	if(x.c==y.l)
    {
        for(int i=0;i<x.l;i++)
        {
            for(int k=0;k<y.c;k++)
            {
                matrix[i][k]=0;
                for(int f=0;f<x.c;f++)
                {
					matrix[i][k]+=x.matrix[i][f]*y.matrix[f][k];
                }

            }
        }
		l=x.l;
		c=y.c;

		return true;
    }
    else
    {
		cout<<"\nAs matrizes dijitadas n�o possuem a condi��o necess�ria para serem multiplicadas!";

		x.matrix=y.matrix=0;
		x.ql=x.qc=y.ql=y.qc=0;
		return false;
	}

}
bool jmatrix::trianginf()
{
    for(int i=0; i<l-1;i++)
    {
        for(int k=1+i;k<c;k++)
        {
            if(matrix[i][k]!=0&&!trianginf())
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
            if(matrix[i][k]!=0&&!trianginf())
            {
                return false;
            }
        }
    }
	return true;
}

bool jmatrix::simetrica(jmatrix x)
{
    transp(x);
    int i,j;
    for(i=0;i<l;i++)
    {
        for(j=0;j<c && matrix[i][j]==x.matrix[i][j];j++)
        {
        }
    }

    if(j==c&&i==l)
    {
        return true;
    }
    else
    {
        return false;
	}
	x.matrix=0;
    x.ql=x.qc=0;
}

bool jmatrix::identidade()
{
    for(int i=0;i<l;)
    {
        for(int j=0;j<c;j++,i++)
        {
            if(triangsup()&&trianginf()&&matrix[i][j]==1)
            {
                return true;
            }

        }
    }
    return false;

}

void jmatrix::transp(jmatrix x)
{
    for(int i=0;i<x.l;i++)
    {
        for(int j=0;j<x.c;j++)
        {
            matrix[i][j]=x.matrix[j][i];
        }
    }
    l=x.l;
    c=x.c;
	x.matrix=0;
    x.ql=x.qc=0;
}

bool jmatrix::operator ==(jmatrix x)
{
	if(x.l!=l||x.c!=c)
	{
		return false;
		x.matrix=0;
		x.ql=x.qc=0;
	}
	for(int i=0;i<l;i++)
	{
		for(int j=0;j<c;j++)
		{
			if(matrix[i][j]!=x.matrix[i][j])
			{
				return false;
				x.matrix=0;
				x.ql=x.qc=0;
			}
		}
	}
	return true;
	x.matrix=0;
    x.ql=x.qc=0;
}

bool jmatrix::antisimetrica()
{
	int i,j,k,a,b;
	int aux1=0;
	int aux2=0;
	for(i=0;i<l;i++)
	{
		if(matrix[i][i]!=0)
		{
			return false;
		}
	}
	for(j=0;j<l-1;j++)
	{
		for(k=j+1;k<c;k++)
		{
			aux1+=matrix[j][k];
		}
	}
	for(a=1;a<l;a++)
	{
		for(b=0;b<a;b++)
		{
			aux2+=matrix[a][b];
		}
	}
	if(aux1==-aux2||-aux1==aux2)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool jmatrix::potencia(jmatrix x,jmatrix y,unsigned int pot)
{
	if(x.c!=x.l)
	{
		cout<<"\nNão foi possivel realizar a operação .. o matriz não é quadrada!";
		return false;
	}
    l=x.l;
    c=x.c;
	for(int i=0;i<pot;i++)
    {
        if(i=0)
        {
            multiplica(x,x);
        }
        vetcopia(y);
        multiplica(x,y);
    }
    return true;
}

void jmatrix::vetcopia(jmatrix x)
{
	for(int i=0;x.c;i++)
	{
		for(int k=0;k<x.l;k++)
		{
			matrix[i][k]=x.matrix[i][k];
		}
	}
	ql=x.ql;
	qc=x.qc;
	l=x.l;
	c=x.c;
}

jmatrix::~jmatrix()
{

    for(int i=0;i<ql;i++)
    {
        delete[]matrix[i];
    }
    delete[]matrix;

}

void jmatrix::multiplica(jmatrix x,jmatrix y)
{

    for(int i=0;i<x.l;i++)
    {
        for(int k=0;k<y.c;k++)
        {
            matrix[i][k]=0;
            for(int f=0;f<x.c;f++)
            {
                matrix[i][k]+=x.matrix[i][f]*y.matrix[f][k];
            }
        }
    }
    l=x.l;
    c=y.c;
}
