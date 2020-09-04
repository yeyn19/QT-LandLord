#include "people.h"

#include "people.h"
#include <algorithm>
#include <vector>

people::people(int pp): paixu(pp)
{

}

people::~people(){
    handC.clear();
    throwC.clear();
    dizhuC.clear();
}

void people::addCard(int j, card c){
        if(j == 1)    handC.push_back(c);
        if(j == 2)    throwC.push_back(c);
        if(j == 3)    dizhuC.push_back(c);
};

void people::bianchengdizhu(){
    for(auto i : dizhuC){
        int nn = i.num;
        int hh = i.huase;
        handC.push_back(card(nn,hh));
    }
}

void people::addCard(int j,std::vector<card> news){
    for(auto i : news){
        if(j == 1)    handC.push_back(i);
        if(j == 2)    throwC.push_back(i);
        if(j == 3)    dizhuC.push_back(i);
    }
}

int zhadan(std::vector<card> my){
    if(my.size() != 4) return -1;
    int c = my[0].num;
    if (my[1].num != c || my[2].num != c || my[3].num != c){
        return -1;
    }
    return c;
}

int wangzha(std::vector<card> my){
    if (my.size() != 2) return -1;
    if (my[0].num >= 16 && my[1].num >= 16) return 1;
    return 0;
}

int duizi(std::vector<card> my){
    if (my.size() != 2) return -1;
    if (my[0].num == my[1].num) return my[0].num;
    return -1;
}

int sandaiyi(std::vector<card> my){
    if (my.size() != 4) return -1;
    if(my[0].num == my[1].num && my[0].num == my[2].num) return my[0].num;
    else if (my[3].num == my[2].num && my[3].num == my[4].num) return my[3].num;
    return -1;
}

int sandaier(std::vector<card> my){
    if (my.size() != 5) return -1;
    if(my[0].num == my[1].num && my[0].num == my[2].num && my[3].num == my[4].num) return my[0].num;
    else if (my[0].num == my[1].num && my[3].num == my[2].num && my[3].num == my[4].num) return my[3].num;
    return -1;
}

int shunzi(std::vector<card> my){
    if (my.size() < 5) return -1;
    int form = -1;
    for(auto i : my){
        if (i.num == 15) return -1;
        if(form != -1){
            if (i.num != form +1) return -1;
        }
        form = i.num;
    }
    return my[0].num;
}



int sanlian(std::vector<card> my){
    if (my.size() != 3) return -1;
    if (my[0].num != my[1].num || my[0].num != my[2].num) return -1;
    return my[0].num;
}

bool comp(card a, card b){
    return a.num < b.num;
}

int people::ICan(std::vector<card> his, std::vector<card> my){
    int hz = his.size();
    int mz = my.size();
    std::sort(his.begin(),his.end(),comp);
    std::sort(my.begin(),my.end(),comp);
    if (wangzha(his) == 1){
        return false;
    }
    if (wangzha(my) == 1) return 9;

    //single card
    if (hz == 1){
        if (mz == 1){
            return his[0].num < my[0].num;
        }
        else if (zhadan(my) != -1) return 8;
        else return false;
    }

    //two
    if (hz == 2){
        if (mz == 2){
            if (duizi(my) > his[0].num) return 2;
            else return false;
        }
        else if (zhadan(my) != -1) return 8;
        return false;
    }

    //three
    if (hz == 3){
        if (mz == 3){
            if (sanlian(my) > his[0].num) return 3;
            else return false;
        }
        else if (zhadan(my) != -1) return 8;
        return false;
    }

    //four
    if (hz == 4){
        if (zhadan(his) != -1) {
            if (zhadan(my) > zhadan(his)) return 8;
            else return false;
        }
        else if (zhadan(my) != -1) return 8;
        else if ((his[0].num == his[1].num && his[0].num == his[2].num)
                 || (his[1].num == his[2].num && his[1].num == his[3].num)) {
            if ((my[0].num == my[1].num && my[0].num == my[2].num)
               || (my[1].num == my[2].num && my[1].num == my[3].num)) {
                if( my[1].num > his[1].num){
                    return 3;
                }
                else return false;
                //qDebug()<< "3 + 1";
            }
            else return false;
        }
        else {
            qDebug() << "4 card error";
            return false;
        }
    }

    if (hz == 5){
        if (zhadan(my) != -1) return 8;
        if (my.size() != 5) return false;
        if (shunzi(his) != -1){
            if(shunzi(my) > shunzi(his)){
                return 4;
            }
            else return false;
        }
        else if (sandaier(his) != -1){
            if(sandaier(my) > sandaier(his)){
                return 3;
            }
            else return false;
        }
        return false;
    }
};
