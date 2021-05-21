#include "interface.h"
#include <QDebug>

TInterface::TInterface(QWidget * parent) : QWidget(parent)
{
    setWindowTitle("Работа №7");
    setFixedSize(320, 160);
    canvas = nullptr;
    g = nullptr;

    lb_matrix = new QLabel(this);
    lb_activeVertex = new QLabel(this);
    lb_activeVertex->setText("Активная вершины: ");
    lb_activeVertex->setGeometry(10, 20, 150, 30);
    sp_activeVertex = new QSpinBox(this);
    sp_activeVertex->setMinimum(1);
    sp_activeVertex->setGeometry(170, 20, 140,30);
    sp_activeVertex->setDisabled(true);
    lb_matrix->setText("Матрица состояний:");
    lb_matrix->setGeometry(10, 70, 150, 30);
    btn_matrix = new QPushButton(this);
    btn_matrix->setText("Выбрать файл");
    btn_matrix->setGeometry(170, 70, 140,30);
    btn_show = new QPushButton(this);
    btn_show->setText("Отображение графа");
    btn_show->setGeometry(10,120,300,30);

    connect(btn_matrix, SIGNAL(pressed()), this, SLOT(OpenFileStateMatrix()));
    connect(btn_show, SIGNAL(pressed()), this, SLOT(OpenCanvas()));
    connect(sp_activeVertex, SIGNAL(valueChanged(int)), this, SLOT(ChangeActiveVertex(int)));
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
        int activeVertex = sp_activeVertex->value();
        int num_state = 0;
        QIntValidator v(this);
        int pos = 0;
        if(!data.atEnd())
        {
            QString line = data.readLine();
            line = line.trimmed();
            QStringList NumList = line.split(" ");
            num_state = NumList.size();
            QVector<qint16> tmp;
            for(int i = 0;i < num_state;i++)
            {
                if(!v.validate(NumList[i], pos))
                {
                    flag = false;
                    QMessageBox::warning(this, "Неправильный формат файла", "Элементами матрицы состояния могут быть только целые числа");
                    break;
                }
                else
                    tmp.push_back(NumList[i].toInt());
            }
            matrix.push_back(tmp);

            if(flag == true)
            {
                while(!data.atEnd())
                {
                    QString line = data.readLine();
                    line = line.trimmed();
                    QStringList NumList = line.split(" ");
                    if(NumList.size() == num_state)
                    {
                        QVector<qint16> tmp;
                        for(int i = 0;i < num_state;i++)
                        {
                            if(!v.validate(NumList[i], pos))
                            {
                                flag = false;
                                QMessageBox::warning(this, "Неправильный формат файла", "Элементами матрицы состояния могут быть только целые числа");
                                break;
                            }
                            else
                                tmp.push_back(NumList[i].toInt());
                        }
                        if(flag == false)
                        {
                            break;
                        }
                        matrix.push_back(tmp);
                    }
                    else
                    {
                        flag = false;
                        QMessageBox::warning(this,"Неправильный формат файла", "Число состояний каждой вершины должно быть одинаковым");
                        break;
                    }
                }
                if (flag == true && matrix.size() > 0)
                {
                    TMatrix tmp_matrix(matrix.size(), num_state, matrix);
                    //                  qDebug() << tmp.getX();
                    //                  qDebug() << tmp.getY();
                    //                  for(int i = 0; i < tmp.getX();i++)
                    //                  {
                    //                      for(int j = 0;j < tmp.getY();j ++)
                    //                          qDebug() << tmp.at(i, j);
                    //                  }


                    if(tmp_matrix.Is_State_Matrix())
                    {
                        sp_activeVertex->setMaximum(matrix.size());
                        sp_activeVertex->setEnabled(true);
                        if(g == nullptr)
                        {
                            g = new TStateGraph(tmp_matrix,activeVertex -1);
                        }
                        else
                        {
                            g->setActiveVertex(activeVertex -1);
                            g->setCount(matrix.size());
                            g->setMatrix(tmp_matrix);
                        }
                        emit ChangeGraph(*g);
                    }
                    else
                        QMessageBox::warning(this, "Неправильный формат файла", "Файл не содержит матрицу состояния");
                }
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
            connect(this,SIGNAL(ChangeGraph(TStateGraph)), canvas, SLOT(ChangeGraph(TStateGraph)));
            connect(canvas, SIGNAL(ChangeActiveVertex(int)), this, SLOT(SetActiveVertex(int)));
            canvas->setWindowTitle("Граф состояний");
            canvas->show();
        }
        else
            QMessageBox::warning(this, "Сообщение", "Файл не выбран");
    }
}

void TInterface::CloseCanvas()
{
    disconnect(canvas, SIGNAL(closing()), this, SLOT(CloseCanvas()));
    disconnect(this, SIGNAL(ChangeGraph(TStateGraph)), canvas, SLOT(ChangeGraph(TStateGraph)));
    disconnect(canvas, SIGNAL(ChangeActiveVertex(int)), this, SLOT(SetActiveVertex(int)));
    canvas = nullptr;
}

void TInterface::ChangeActiveVertex(int a)
{
    if(g != nullptr)
    {
        g->setActiveVertex(a - 1);
        emit ChangeGraph(*g);
    }
}

void TInterface::SetActiveVertex(int activate)
{
    sp_activeVertex->setValue(activate + 1);
}
