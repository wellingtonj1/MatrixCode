//                         !!!!!!!      IN CONSTRUCTION !!!!!!!
#ifndef JMATRIX_H
#define JMATRIX_H
#include <string>
class jmatrix
{
private:
    int** matrix;
    int ql,qc,l,c;

    public:
    jmatrix(int nl,int nc);//finalizado
    bool setmatij(int i,int j,int x);//finalizado
    bool lemat();//finalizado
    bool setlc(int x,int y);
    int getmatij(int i,int j);//finalizado
    void imprimemat();//finalizado
    bool imprimemat(int x,int y);//finalizado
    void soma(jmatrix j,jmatrix k);
    ~jmatrix();//finalizado
};
#endif
