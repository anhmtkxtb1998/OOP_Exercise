#include "application.h"
#include "polinom.h"
#include "common.h"

TApplication::TApplication(int argc, char *argv[]): QCoreApplication(argc,argv)
{
    TCommParams pars = {QHostAddress("127.0.0.1"), 10000,
                        QHostAddress("127.0.0.1"), 10001};
    comm = new TCommunicator(pars, this);

    connect(comm,SIGNAL(received(QByteArray)),this,SLOT(receive(QByteArray)));
}

void TApplication::receive(QByteArray msg)
{
    QString answer, s;
    number a, b, c, x, v;
    msg >> a >> b >> c;
    Polinom p(a,b,c);
    int pos = msg.indexOf(separator);
    int t = msg.left(pos).toInt();
    switch (t)
    {
        case VALUE_REQUEST:  
        {
            msg = msg.right(msg.length()-pos-1);
            msg >> x;

            if (a.get_value_b() == 0 || b.get_value_b() == 0 || c.get_value_b() == 0 || x.get_value_b() == 0)
            {
                s += "Denominator cant be 0. Reenter.";
                answer << QString().setNum(ERROR) << s;
            }
            else
            {
                if (a.get_value_a() == 0)
                {
                    s += "Value of 'a' cant be 0! Reenter coefficients!";
                    answer << QString().setNum(ERROR) << s;
                }
                else
                {
                    v = p.value(x);
                    s << (QString)x << (QString)v;
                    answer << QString().setNum(VALUE_ANSWER);
                    answer += s;
                }
            }
        }
            break;

        case PRINT_CLASSIC_REQUEST:
        {
            if (a.get_value_b() == 0 || b.get_value_b() == 0 || c.get_value_b() == 0 || x.get_value_b() == 0)
            {
                s += "Denominator cant be 0. Reenter.";
                answer << QString().setNum(ERROR) << s;
            }
            else
            {
                if (a.get_value_a() == 0)
                {
                    s += "Value of 'a' cant be 0! Reenter coefficients!";
                    answer << QString().setNum(ERROR) << s;
                }
                else
                {
                    p.setPrintMode(EPrintModeClassic);
                    s<<p;
                    answer<<QString().setNum(PRINT_ANSWER)<<s;
                }
            }
        }
            break;

        case PRINT_CANONIC_REQUEST:
        {
            if (a.get_value_b() == 0 || b.get_value_b() == 0 || c.get_value_b() == 0 || x.get_value_b() == 0)
            {
                s += "Denominator cant be 0. Reenter.";
                answer << QString().setNum(ERROR) << s;
            }
            else
            {
                if (a.get_value_a() == 0)
                {
                    s += "Value of 'a' cant be 0! Reenter coefficients!";
                    answer << QString().setNum(ERROR) << s;
                }
                else
                {
                    p.setPrintMode(EPrintModeCanonic);
                    s << p;
                    answer << QString().setNum(PRINT_ANSWER)<<s;
                }
            }
        }
        break;

        case ROOT_REQUEST:
        {
            if (a.get_value_b() == 0 || b.get_value_b() == 0 || c.get_value_b() == 0 || x.get_value_b() == 0)
            {
                s += "Denominator cant be 0. Reenter.";
                answer << QString().setNum(ERROR) << s;
            }
            else
            {
                if (a.get_value_a() == 0)
                {
                    s += "Value of 'a' cant be 0! Reenter coefficients!";
                    answer << QString().setNum(ERROR) << s;
                }
                else
                {
                    number roots[2];
                    int numroots = p.roots(roots);
                    if (numroots == 0)
                        s += "The equation has no solutions!";
                    else
                    {
                        if (numroots == 1)
                        {
                            s += "The equation has one solution: x1 = ";
                            s << roots[0];
                        }
                        else
                        {
                            s += "The equation has two solutions: x1 = ";
                            s << roots[0];
                            s += ", x2 = ";
                            s << roots[1];
                        }
                    }
                    answer << QString().setNum(ROOT_ANSWER) << s;
                }
            }
        }
            break;

        default:
            return;
    }
    comm->send(QByteArray().append(answer));
}
