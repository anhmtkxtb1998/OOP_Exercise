#include "interface.h"

TInterface::TInterface(QWidget * parent) : QWidget(parent)
{
    setWindowTitle("Работа №6");
    setFixedSize(320, 160);
    canvas = nullptr;
    g = nullptr;

    lb_matrix = new QLabel(this);
    lb_activate = new QLabel(this);
    lb_activate->setText("Активной вершины: ");
    lb_activate->setGeometry(10, 20, 150, 30);
    sp_activate = new QSpinBox(this);
    sp_activate->setMinimum(1);
    sp_activate->setGeometry(170, 20, 140,30);
    lb_matrix->setText("Матрица смежности:");
    lb_matrix->setGeometry(10, 70, 150, 30);
    btn_matrix = new QPushButton(this);
    btn_matrix->setText("Выбрать файл");
    btn_matrix->setGeometry(170, 70, 140,30);
    btn_show = new QPushButton(this);
    btn_show->setText("Отображение графа");
    btn_show->setGeometry(10,120,300,30);

    connect(btn_matrix, SIGNAL(pressed()), this, SLOT(OpenFileStateMatrix()));
    connect(btn_show, SIGNAL(pressed()), this, SLOT(OpenCanvas()));
    connect(sp_activate, SIGNAL(valueChanged(int)), this, SLOT(ChangeActiveEdge(int)));

}

TInterface::~TInterface()
{
    delete g;
    delete lb_matrix;
    delete btn_matrix;
    delete btn_show;
    delete canvas;
}

void TInterface::closeEvent(QCloseEvent * event)
{
    if(canvas != nullptr)
    {
        canvas->close();
    }
    event->accept();
}

void TInterface::OpenFileStateMatrix()
{
    QString file_name = QFileDialog::getOpenFileName(this, "Выберите файл с матрицей состояния");
    QFile file(file_name);
    if(!file.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::warning(this, "Сообщение", "Файл не был открыт");
    }
    else
    {
        QTextStream data(&file);
        bool flag = true;
        QVector< QVector<qint16> > matrix;
        int activate = sp_activate->value();
        int num_state = 0;
        if(!data.atEnd())
        {
            QString line = data.readLine();
            line = line.trimmed();
            QStringList NumList = line.split(" ");
            num_state = NumList.size();
            QVector<qint16> tmp;
            for(int i = 0;i < NumList.size();i++)
                 tmp.push_back(NumList[i].toInt());
            matrix.push_back(tmp);
            while(!data.atEnd())
            {
                QString line = data.readLine();
                line = line.trimmed();
                QStringList NumList = line.split(" ");
                if(NumList.size() == num_state)
                {
                    QVector<qint16> tmp;
                    for(int i = 0;i < NumList.size();i++)
                        tmp.push_back(NumList[i].toInt());
                    matrix.push_back(tmp);
                }
                else
                {
                    flag = false;
                    QMessageBox::warning(this,"Сообщение", "Число состояний каждой вершины должны одинаковым");
                    break;
                }
            }
             if (flag == true && matrix.size() > 0)
              {
                  TMatrix tmp(matrix.size(), matrix[0].size(), matrix);
                  if(tmp.Is_State_Matrix())
                  {
                    sp_activate->setMaximum(matrix.size());
                    if(g == nullptr)
                      {
                         g = new TDerivesample(tmp,activate -1);
                      }
                    else
                      {
                         g->SetActivate(activate -1);
                         g->setCount(matrix.size());
                         g->setMatrix(tmp);
                      }
                     emit ChangeGraph(*g);
                  }
                  else
                    QMessageBox::warning(this, "Сообщение", "Матрица состояния не правильная!!");

              }
        }
         else
         {
             QMessageBox::warning(this, "Сообщение", "Файл пустой");
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
            canvas = new TCanvas(*g);
            connect(canvas, SIGNAL(closing()),this,SLOT(CloseCanvas()));
            connect(this,SIGNAL(ChangeGraph(TDerivesample)), canvas, SLOT(ChangeGraph(TDerivesample)));
            connect(canvas, SIGNAL(ChangeActivateEdge(int)), this, SLOT(SetActivateEdge(int)));
            canvas->setWindowTitle("Ориентированный граф");
            canvas->show();
        }
        else
            QMessageBox::warning(this, "Сообщение", "Файл не выбран");
    }
}

void TInterface::CloseCanvas()
{
    disconnect(canvas, SIGNAL(closing()), this, SLOT(CloseCanvas()));
    disconnect(this, SIGNAL(ChangeGraph(TDerivesample)), canvas, SLOT(ChangeGraph(TDerivesample)));
    disconnect(canvas, SIGNAL(ChangeActivateEdge(int)), this, SLOT(SetActivateEdge(int)));
    canvas = nullptr;
}
void TInterface::ChangeActiveEdge(int a)
{
    if(g != nullptr)
    {
        g->SetActivate(a - 1);
        emit ChangeGraph(*g);
    }
}
void TInterface::SetActivateEdge(int activate)
{
    sp_activate->setValue(activate + 1);
}
