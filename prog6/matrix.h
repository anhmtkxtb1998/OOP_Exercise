#ifndef TMATRIX_H
#define TMATRIX_H
#include<QObject>
#include<QVector>

class TMatrix
{
    int x, y;
    QVector<QVector<qint16>> Matrix;
public:
    TMatrix();
    TMatrix(int, int, QVector<QVector<qint16>>);
    TMatrix(const TMatrix&);
    qint16 at(int, int);
    bool Is_Adjacency_Matrix();
    ~TMatrix();
};

#endif // TMATRIX_H
