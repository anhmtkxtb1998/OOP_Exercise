#include "matrix.h"

TMatrix::TMatrix()
{
    x = 0;
    y = 0;
}

TMatrix::TMatrix(int a, int b,QVector<QVector<qint16>> m)
{
    x = a;
    y = b;
    Matrix = m;
}

TMatrix::TMatrix(const TMatrix& m)
{
    x = m.x;
    y = m.y;
    Matrix = m.Matrix;
}

TMatrix::~TMatrix()
{

}

int TMatrix::getX()
{
    return x;
}

int TMatrix::getY()
{
    return y;
}

qint16 TMatrix::at(int i, int j)
{
    return this->Matrix[i][j];
}

bool TMatrix::Is_Adjacency_Matrix()
{
    if (x != y)
        return false;
    else
    {
        for(int i = 0; i < x; i ++)
        {
            for(int j = 0; j < y; j++)
            {
                if(this->Matrix[i][j] != 0 && this->Matrix[i][j] != 1)
                    return false;
            }
        }
    }
    return true;
}

bool TMatrix::Is_State_Matrix()
{
    if( x < y)
        return false;
    else
    {
        for(int i = 0; i < x;i++)
        {
            for(int j = 0;j < y;j ++)
                if(Matrix[i][j] < 0 | Matrix[i][j] > x)
                    return false;
        }
    }
    return true;
}
void TMatrix::ConvertStateMatrix()
{
    QVector<QVector<qint16>> matrix;
    if(this->Is_State_Matrix())
    {

        for(int i =0;i < x;i++)
        {
            QVector<qint16> tmp;
            for(int  j=0;j < x;j++)
                tmp.push_back(0);
            matrix.push_back(tmp);
        }
        for(int i = 0;i < x;i++)
        {
            for(int j = 0;j < y;j++)
            {
                if(this->at(i,j) !=0)
                  matrix[i][this->at(i,j) -1] = 1;
            }
        }

       Matrix = matrix;
       x = y = matrix.size();

    }

}
