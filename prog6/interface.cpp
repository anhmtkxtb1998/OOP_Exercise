#include "interface.h"

TInterface::TInterface(QWidget * parent) : QWidget(parent)
{
    setWindowTitle("Работа №6");
    setFixedSize(320, 120);
    canvas = nullptr;
    g = nullptr;

    lb_matrix = new QLabel(this);
    lb_matrix->setText("Матрица смежности:");
    lb_matrix->setGeometry(10, 20, 150, 30);
    btn_matrix = new QPushButton(this);
    btn_matrix->setText("Выбрать файл");
    btn_matrix->setGeometry(170, 20, 140,30);
    btn_show = new QPushButton(this);
    btn_show->setText("Отображение графа");
    btn_show->setGeometry(10,70,300,30);

    connect(btn_matrix, SIGNAL(pressed()), this, SLOT(OpenFile()));
    connect(btn_show, SIGNAL(pressed()), this, SLOT(OpenCanvas()));
}

TInterface::~TInterface()
{
    delete lb_matrix;
    delete btn_matrix;
    delete btn_show;
    delete canvas;
}

void TInterface::closeEvent(QCloseEvent * event)
{
    if(canvas != nullptr)
    {
        disconnect(canvas, SIGNAL(closing()),this,SLOT(CloseCanvas()));
        disconnect(this,SIGNAL(ChangeGraph(TGraph *)), canvas, SLOT(SetGraph(TGraph *)));
        canvas->close();
    }
    event->accept();
}

void TInterface::OpenFile()
{
    QString file_name = QFileDialog::getOpenFileName(this, "Выберите файл с матрицей смежности");
    QFile file(file_name);
    if(!file.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::warning(this,"Message", "Файл не был открыт");
    }
    else
    {
        QTextStream data(&file);
        QVector< QVector<qint16> > matrix;
        bool flag = true;
        int matrixsize = 0;

        if (!data.atEnd())
        {
            QString line = data.readLine();
            line = line.trimmed();
            QStringList NumList = line.split(" ");
            matrixsize = NumList.size();
            QVector<qint16> tmp;
            for(int i = 0;i < matrixsize;i++)
            {
                tmp.push_back(NumList[i].toInt());
            }
            matrix.push_back(tmp);
        }
        else
        {
            QMessageBox::warning(this,"Message", "Пустой файл");
        }

        for (int i=1; i<matrixsize; i++)
        {
            if(!data.atEnd())
            {
                QString line = data.readLine();

                line = line.trimmed();
                QStringList NumList = line.split(" ");
                if(NumList.size() == matrixsize)
                {
                    QVector<qint16> tmp;
                    for(int i = 0;i < matrixsize;i++)
                    {
                        tmp.push_back(NumList[i].toInt());
                    }
                    matrix.push_back(tmp);
                }
                else
                {
                    flag = false;
                    QMessageBox::warning(this,"Source file error","Matrix size must correspond to the parameter selected!");
                    break;
                }
            }
            else
            {
                flag = false;
                QMessageBox::warning(this,"Source file error","Matrix size must correspond to the parameter selected!");
                break;
            }
        }

        if(!data.atEnd())
        {
            flag = false;
            QMessageBox::warning(this,"Source file error","Matrix size must correspond to the parameter selected!");
        }

        if (flag == true)
        {
            TMatrix tmp(matrix.size(), matrixsize, matrix);
            if(tmp.Is_Adjacency_Matrix())
            {
                if(g == nullptr)
                {
                   g = new TGraph(tmp);
                }
                else
                {
                    g->setCount(matrixsize);
                    g->setMatrix(tmp);
                }
                emit ChangeGraph(g);
            }
            else
                QMessageBox::warning(this, "Source file error", "The data for the matrix is not correct");
        }
        file.close();
    }
}

void TInterface::OpenCanvas()
{
    if(canvas == nullptr)
    {
        if(g != nullptr)
        {
            canvas = new TCanvas(g);
            connect(canvas, SIGNAL(closing()),this,SLOT(CloseCanvas()));
            connect(this,SIGNAL(ChangeGraph(TGraph *)), canvas, SLOT(ChangeGraph(TGraph *)));
            canvas->show();
        }
        else
            QMessageBox::warning(this, "Message", "Файл не выбран");
    }

}

void TInterface::CloseCanvas()
{
    disconnect(canvas, SIGNAL(closing()),this,SLOT(CloseCanvas()));
    canvas = nullptr;
}
