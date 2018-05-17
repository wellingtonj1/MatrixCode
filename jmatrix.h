//                         !!!!!!!      IN CONSTRUCTION !!!!!!!
#ifndef JMATRIX_H
#define JMATRIX_H
#include <iostream>
class jmatrix
{
private:
    int** matrix;
    int ql,qc,l,c;

    public:
    jmatrix(int nl,int nc);//finalizado
    bool setmatij(int i,int j,int x);//finalizado
    bool lemat();//finalizado
    bool setlc(int x,int y);//finalizado
    int getmatij(int i,int j);//finalizado
    void imprimemat();//finalizado
    bool imprimemat(int x,int y);//finalizado
    bool soma(jmatrix j,jmatrix k);//finalizado
    bool sub(jmatrix x,jmatrix y);//finalizado
    bool multip(jmatrix x,jmatrix y);//finalizado
    bool trianginf();//finalizado
    bool triangsup();//finalizado
    bool simetrica(jmatrix x);
    bool identidade();
    void transp(jmatrix x);
	bool operator == (jmatrix x);
	bool antisimetrica();
	bool potencia(jmatrix x,jmatrix y,unsigned int pot);
	void vetcopia(jmatrix x);
	void multiplica(jmatrix x,jmatrix y);

	~jmatrix();



};
#endif
