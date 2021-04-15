#include "model.h"

quint32 TModel::time_solving = 20;
quint32 TModel::time_failure = 30;

TModel::TModel()
{
   init();
   p_timer = new QTimer(this);
   connect(p_timer, SIGNAL(timeout()), this, SLOT(tact()));
   p_timer->start(1000);
}

TModel::~TModel()
{
    lst_com.clear();
    delete p_timer;
}

void TModel::init()
{
    lst_com.clear();
    for (int i = 1; i < 6; i++)
    {
        TParamdata data;
        data.order = i;
        data.time_solving = time_solving;
        data.time_failure = time_failure;
        TStatedata state;
        state.isbusy = false;
        state.time_remaning = time_solving;
        state.time_failure = time_failure;
        TComputer * tmp = new TComputer(data, state);
        lst_com.append(tmp);
    }
}

void TModel::paramRequest(int order)
{
    TEvent msg(PARAMREQUEST);
    TComputer * tmp = lst_com[order-1];
    msg.data.p = tmp->get_param();
    emit sendModelEvent(msg);
}

void TModel::stateRequest(int order)
{
    TEvent msg(STATEREQUEST);
    TComputer * tmp = lst_com[order-1];
    msg.data.p.order = order;
    msg.data.s = tmp->get_state();
    emit sendModelEvent(msg);
}

void TModel::tact()
{
    for (int i = 0;i < 5;i++)
    {
        TStatedata tmp_state = lst_com[i]->get_state();
        if (tmp_state.isbusy && tmp_state.time_failure > 0)
        {
            tmp_state.time_remaning -=1;
            tmp_state.time_failure -=1;
            if ( tmp_state.time_remaning == 0)
            {
               tmp_state.isbusy = false;
               tmp_state.time_remaning = lst_com[i]->get_param().time_solving;
            }
        }
        if (tmp_state.time_failure <= 0)
        {
            tmp_state.isbusy = true;
            tmp_state.time_failure -=1;
        }
        if (tmp_state.time_failure < -1)
        {
            tmp_state.time_failure = lst_com[i]->get_param().time_failure;
            tmp_state.isbusy = false;
        }
        lst_com[i]->setstate(tmp_state);
    }
}

void TModel::recevieModelEvent(TEvent msg)
{
    switch (msg.type)
    {
    case PARAMREQUEST:
        paramRequest(msg.data.p.order);
        break;

    case PARAMMESSAGE:
    {
        QMessageBox msb;
        QString m;
        if(!lst_com[msg.data.p.order-1]->get_state().isbusy)
        {
        lst_com[msg.data.p.order-1]->setparam(msg.data.p);
        TStatedata state = lst_com[msg.data.p.order-1]->get_state();
        state.time_remaning = msg.data.p.time_solving;
        state.time_failure = msg.data.p.time_failure;
        lst_com[msg.data.p.order-1]->setstate(state);
         m = "Успешно изменил параметры компьютера № " + QString().setNum(msg.data.p.order);
        }
        else
            m = "Компьютер № " + QString().setNum(msg.data.p.order) + " занят. Не успешно изменял параметры";

        msb.setText(m);
        msb.exec();
    }
        break;
    case PARAM_RESET:
    {
        QMessageBox msb;
        QString m;
        if(!lst_com[msg.data.p.order-1]->get_state().isbusy)
        {
        TParamdata data;
        data.order = msg.data.p.order;
        data.time_solving = time_solving;
        data.time_failure = time_failure;
        TStatedata state;
        state.isbusy = false;
        state.time_remaning = time_solving;
        state.time_failure = time_failure;
        lst_com[msg.data.p.order -1] ->setparam(data);
        lst_com[msg.data.p.order-1]->setstate(state);
        paramRequest(msg.data.p.order);
        stateRequest(msg.data.p.order);
        m = "Успешно изменил параметры компьютера № " + QString().setNum(msg.data.p.order);
        }
        else
            m = "Компьютер № " + QString().setNum(msg.data.p.order) + " занят. Не успешно изменял параметры";

        msb.setText(m);
        msb.exec();
    }
    break;
    case STATEREQUEST:
        stateRequest(msg.data.p.order);
        break;

    case RESET:
    {
        init();
        paramRequest(1);
        stateRequest(1);
    }
        break;

    case REQUEST_PROBLEM:
    {
        QMessageBox msb;
        QString m;
        int order;
        bool flag = true;
        for (int i =0; i< 5;i++)
        {
            if (!lst_com[i]->get_state().isbusy)
                flag = false;
        }
        if (flag == true)
            m = "Невозможно выполнить задачу №" + QString().setNum(msg.data.order_problem);
        else
        {
            do
            {
                order = QRandomGenerator::global()->generate() % lst_com.size() + 1;
            } while(lst_com[order-1]->get_state().isbusy);

            TStatedata tmp_state = lst_com[order-1]->get_state();
            tmp_state.isbusy = true;
            tmp_state.time_remaning = lst_com[order-1]->get_param().time_solving;
            lst_com[order-1]->setstate(tmp_state);
            m = "Задача №" + QString().setNum(msg.data.order_problem) + "выполняется компьютером №" + QString().setNum(order);
        }
        msb.setText(m);
        msb.exec();
    }
        break;

    default:
        break;
    }
}





