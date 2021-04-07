#include "model.h"
quint32 TModel::time_sloving = 20;
quint32 TModel ::time_failure = 30;
TModel::TModel()
{
   Init();
   p_timer = new QTimer(this);
   connect(p_timer, SIGNAL(timeout()), this, SLOT(Tact()));
   p_timer->start(1000);
}
TModel::~TModel(){
    lst_com.clear();
    delete p_timer;
}
void TModel::Init(){
    lst_com.clear();
    for(int i = 1; i < 6; i++){

        TParamdata data;
        data.order = i;
        data.time_sloving = time_sloving;
        data.time_failure = time_failure;
        TStatedata state;
        state.isbusy = false;
        state.time_remaning = time_sloving;
        state.time_failure = time_failure;
        TComputer * tmp = new TComputer(data, state);
        lst_com.append(tmp);
    }

}
void TModel::Paramrequest(int order){
    TEvent msg(PARAMREQUEST);
    TComputer * tmp = lst_com[order-1];
    msg.data.p = tmp->get_param();
    emit sendModelEvent(msg);
}
void TModel::Staterequest(int order){
    TEvent msg(STATEREQUEST);
    TComputer * tmp = lst_com[order-1];
    msg.data.p.order = order;
    msg.data.s = tmp->get_state();
    emit sendModelEvent(msg);
}

void TModel::Tact(){
    for(int i = 0;i < 5;i++){
       TStatedata tmp_state = lst_com[i]->get_state();
       if(tmp_state.isbusy && tmp_state.time_failure > 0){
           tmp_state.time_remaning -=1;
           tmp_state.time_failure -=1;
        if( tmp_state.time_remaning == 0){
            tmp_state.isbusy = false;
            tmp_state.time_remaning = lst_com[i]->get_param().time_sloving;
        }
       }
      if(tmp_state.time_failure <= 0)
      {
          tmp_state.isbusy = true;
          //tmp_state.time_remaning = lst_com[i]->get_param().time_sloving;
          tmp_state.time_failure -=1;
      }
      if(tmp_state.time_failure < -10)
       {
          tmp_state.time_failure = lst_com[i]->get_param().time_failure;
          tmp_state.isbusy = false;
      }
      lst_com[i]->setstate(tmp_state);
    }
}

void TModel::recevieModelEvent(TEvent msg){
    switch (msg.type) {
    case PARAMREQUEST:
        Paramrequest(msg.data.p.order);
        break;
    case PARAMMESSAGE:
    {
        lst_com[msg.data.p.order-1]->setparam(msg.data.p);
        TStatedata state = lst_com[msg.data.p.order-1]->get_state();
        state.time_remaning = msg.data.p.time_sloving;
        state.time_failure = msg.data.p.time_failure;
        lst_com[msg.data.p.order-1]->setstate(state);
    }
        break;
    case STATEREQUEST:
        Staterequest(msg.data.p.order);
        break;
    case RESET:
    {
        Init();
        Paramrequest(1);
        Staterequest(1);
    }
        break;
     case REQUEST_PROBLEM:
    {
        qsrand(QTime::currentTime().msec());
        QMessageBox msb;
        QString m;
        int order;
        bool flag = true;
        for(int i =0; i< 5;i++){
            if(!lst_com[i]->get_state().isbusy)
                flag = false;
        }
        if(flag == true)
            m = "Can't recevie request " + QString().setNum(msg.data.order_problem);
        else{
            do{
             order = qrand() % lst_com.size() + 1;
            }while(lst_com[order-1]->get_state().isbusy);
             TStatedata tmp_state = lst_com[order-1]->get_state();
             tmp_state.isbusy = true;
             tmp_state.time_remaning = lst_com[order-1]->get_param().time_sloving;
             lst_com[order-1]->setstate(tmp_state);
             m = "Recevie request " + QString().setNum(msg.data.order_problem) + " by computer " +QString().setNum(order);
        }
        msb.setText(m);
        msb.exec();
    }
        break;

    }
}





