#ifndef PEOPLE_H
#define PEOPLE_H

#include <vector>
#include <QString>
#include <QDebug>


class card{
public:
    int num;
    int huase;
    int ifChose;
    QString path;
    card(int nn, int hh): num(nn), huase(hh){
        ifChose = 0;
        if(num == 16){
            path = ":/image/PokerImage/smalljoker.png";
            return;
        }
        if(num == 17){
            path = ":/image/PokerImage/bigjoker.png";
            return;
        }

        std::string k = ":/image/PokerImage/poker_t_";

        std::string nnn[] = {"0","1","1","2","3","4","5","6","7","8","9","10","11","12","13","1"};

        std::string hhh[] = {"0","1","3","2","4"};
        k += hhh[huase];
        k += "_v_";
        k += nnn[num];
        k += ".png";
        path = QString::fromStdString(k);

    }
};

class people
{
public:
    people(int pp);
    ~people();
    int paixu;
    std::vector<card> handC;
    std::vector<card> throwC;
    std::vector<card> dizhuC;

    void addCard(int j, card c);
    void bianchengdizhu();
    void addCard(int j, std::vector<card> cards);
    int ICan(std::vector<card> his, std::vector<card> my);

};

#endif // PEOPLE_H
