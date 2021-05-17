#ifndef TMATRIX_H
#define TMATRIX_H

#include <QVector>

class TMatrix
{
    int x, y;
    QVector<QVector<qint16>> Matrix;
public:
    TMatrix();
    TMatrix(int, int, QVector<QVector<qint16>>);
    TMatrix(const TMatrix&);
    ~TMatrix();
    int getX();
    int getY();
    qint16 at(int, int);
    bool Is_Adjacency_Matrix();
    bool Is_State_Matrix();
    void ConvertStateMatrix();
};

#endif // TMATRIX_H
