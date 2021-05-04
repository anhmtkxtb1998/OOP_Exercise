#include "interface.h"

TInterface::TInterface(QWidget * parent) : QWidget(parent)
{
  setWindowTitle("Работа №6");
  setFixedSize(300, 300);
  canvas = nullptr;
  g = nullptr;
  lb_size = new QLabel(this);
  lb_size->setText("Число вершин: ");
  lb_size->setGeometry(10, 20, 130, 30);
  size_ = new QSpinBox(this);
  size_->setGeometry(150, 20, 130,30);
  size_->setMinimum(1);
  lb_matrix = new QLabel(this);
  lb_matrix->setText("Матрица смежности");
  lb_matrix->setGeometry(10, 70, 130, 30);
  btn_matrix = new QPushButton(this);
  btn_matrix->setText("Выбирай файл");
  btn_matrix->setGeometry(150, 70, 130,30);
  btn_show = new QPushButton(this);
  btn_show->setText("Отображение графа");
  btn_show->setGeometry(10,120,280,30);

  connect(btn_matrix, SIGNAL(pressed()), this, SLOT(OpenFile()));
  connect(btn_show, SIGNAL(pressed()), this, SLOT(OpenCanvas()));

}

TInterface::~TInterface(){
    delete lb_matrix;
    delete size_;
    delete lb_size;
    delete btn_matrix;
    delete btn_show;
    delete canvas;
}
void TInterface::closeEvent(QCloseEvent * event){
    if(canvas != nullptr){
        disconnect(canvas, SIGNAL(closing()),this,SLOT(CloseCanvas()));
        disconnect(this,SIGNAL(ChangeGraph(TGraph *)), canvas, SLOT(SetGraph(TGraph *)));
        canvas->close();
    }
    event->accept();
}
void TInterface::OpenFile()
{
    QString file_name = QFileDialog::getOpenFileName(this,"Open source file", QDir::homePath());
    QFile file(file_name);
    if(!file.open(QFile::ReadOnly| QFile::Text))
    {
        QMessageBox::warning(this,"Message","File not open");
    }
    else
    {
        QTextStream data(&file);
        QVector< QVector<qint16> > matrix;
        bool flag = true;
        int matrixsize = size_->value();
        while(!data.atEnd())
        {
            QString line = data.readLine();
            if(!line.isEmpty())
            {
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
                }
            }
            if(flag == false)
                break;
        }
        if( flag == true)
        {
            TMatrix tmp(matrixsize, matrixsize,matrix);
            if(tmp.Is_Adjacency_Matrix())
            {
                if(g == nullptr)
                {
                   g = new TGraph(matrixsize, tmp);
                }
                else
                {
                    g->setCount(matrixsize);
                    g->setMatrix(tmp);
                }
                emit ChangeGraph(g);
            }
            else
               QMessageBox::warning(this,"Source file error", "The data for the matrix is not correct");
        }


    }

}
void TInterface::OpenCanvas(){

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
            QMessageBox::warning(this, "Message", "Not source file");
    }

}
void TInterface::CloseCanvas(){
    disconnect(canvas, SIGNAL(closing()),this,SLOT(CloseCanvas()));
    canvas = nullptr;
}
