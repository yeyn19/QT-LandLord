#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "people.h"
#include <QPainter>
#include <QWidget>
#include <cstdlib>
#include <QDebug>
#include <QRandomGenerator>
#include <time.h>
#include <QJsonValue>
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>
#include <cstdio>
#include <thread>
#include <cassert>
#include <chrono>
#include <stdio.h>
#include <QJsonDocument>
#include <QMediaPlayer>
#include "domp3.h"
#include <QMediaPlaylist>
#include <QSound>

void MainWindow::domp3(int i){
    //QMediaPlayer* player = new QMediaPlayer;
    //connect(player, SIGNAL(positionChanged(qint64)), this, SLOT(positionChanged(qint64)));
    if(i == 1){
        player1->setVolume(80);
        player1->play();
    }
    else if(i == 2){
        player2->setVolume(30);
        player2->play();
    }
    else if(i == 3){
        player3->setVolume(60);
        player3->play();
    }
    else if(i == 4){
        player4->setVolume(30);
        player4->play();
    }
    else if(i == 5){
        player5->setVolume(15);
        player5->play();
    }
    else if(i == 6){
        player6->setVolume(50);
        player6->play();
    }
    else if(i == 7){
        player7->setVolume(30);
        player7->play();
    }
    else if(i == 8){
        player8->setVolume(30);
        player8->play();
    }
    else if(i == 9){
        player9->setVolume(60);
        player9->play();
    }
    else if(i == 10){
        player10->setVolume(100);
        player10->play();
    }
    else if(i == 11){
        player11->setVolume(30);
        player11->play();
    }
    else if(i == 12){
        player12->setVolume(90);
        player12->play();
    }
    else if(i == 13){
        player13->setVolume(30);
        player13->play();
    }
    else if(i == 14){
        player14->setVolume(30);
        player14->play();
    }
    else if(i == 15){
        player15->setVolume(100);
        player15->play();
    }
    else if(i == 16){
        player16->setVolume(30);
        player16->play();
    }
    else if(i == 17){
        player17->setVolume(60);
        player17->play();
    }
    else if(i == 18){
        player18->setVolume(50);
        player18->play();
    }
    else if(i == 19){
        player19->setVolume(30);
        player19->play();
    }
    else if(i == 20){
        player20->setVolume(60);
        player20->play();
    }
    else if(i == 21){
        player21->setVolume(15);
        player21->play();
    }
    else if(i == 22){
        player22->setVolume(30);
        player22->play();
    }
    else if(i == 23){
        player23->setVolume(100);
        player23->play();
    }
    else if(i == 24){
        player24->setVolume(30);
        player24->play();
    }
    else if(i == 25){
        player25->setVolume(30);
        player25->play();
    }
    else if(i == 26){
        player26->setVolume(30);
        player26->play();
    }
    else if(i == 27){
        player27->setVolume(30);
        player27->play();
    }
    else if(i == 28){
        player28->setVolume(30);
        player28->play();
    }
    else if(i == 20){
        player20->setVolume(30);
        player20->play();
    }
    else if(i == 29){
        player29->setVolume(30);
        player29->play();
    }
    else if(i == 30){
        player30->setVolume(30);
        player30->play();
    }


    //delete player;
    /*QSound *a;
    if(i == 1) a = new QSound("/Users/yeyining/landlord/sanbing.mp3");
    a->play();*/
}

void MainWindow::concon(){
    if(me->paixu != 1) return;
    player5->setVolume(20);
    player5->play();
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , ti(new QTimer(this))
    , bgm(new QTimer(this))
    , playlist(new QMediaPlaylist)
    , player1(new QMediaPlayer)
    , player2(new QMediaPlayer)
    , player3(new QMediaPlayer)
    , player4(new QMediaPlayer)
    , player5(new QMediaPlayer)
    , player6(new QMediaPlayer)
    , player7(new QMediaPlayer)
    , player8(new QMediaPlayer)
    , player9(new QMediaPlayer)
    , player10(new QMediaPlayer)
    , player11(new QMediaPlayer)
    , player12(new QMediaPlayer)
    , player13(new QMediaPlayer)
    , player14(new QMediaPlayer)
    , player15(new QMediaPlayer)
    , player16(new QMediaPlayer)
    , player17(new QMediaPlayer)
    , player18(new QMediaPlayer)
    , player19(new QMediaPlayer)
    , player20(new QMediaPlayer)
    , player21(new QMediaPlayer)
    , player22(new QMediaPlayer)
    , player23(new QMediaPlayer)
    , player24(new QMediaPlayer)
    , player25(new QMediaPlayer)
    , player26(new QMediaPlayer)
    , player27(new QMediaPlayer)
    , player28(new QMediaPlayer)
    , player29(new QMediaPlayer)
    , player30(new QMediaPlayer)
{
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    srand(2223);
    ui->setupUi(this);
    ti->setInterval(100);
    ti->start();
    bgm->setInterval(110000);
    //bgm->start();
    readWriteSocket1 = nullptr;
    readWriteSocket2 = nullptr;
    //connect(ti, &QTimer::timeout,this,&MainWindow::con);
    st = -1;
    dizhu = 10;
    ready1 = 0;
    ready2 = 0;
    ready3 = 0;

    formC = 0;
    nextC = 0;

    setButton();
    int xu = 5;

    player1->setMedia(QUrl::fromLocalFile("/Users/yeyining/landlord/sanbing.mp3"));
    player2->setMedia(QUrl::fromLocalFile("/Users/yeyining/landlord/sidingle.mp3"));
    player3->setMedia(QUrl::fromLocalFile("/Users/yeyining/landlord/quantiqili.mp3"));
    player4->setMedia(QUrl::fromLocalFile("/Users/yeyining/landlord/renyishou.mp3"));
    player5->setMedia(QUrl::fromLocalFile("/Users/yeyining/landlord/huanledoudizhu.mp3"));
    player6->setMedia(QUrl::fromLocalFile("/Users/yeyining/landlord/chaojijiabei.mp3"));
    player7->setMedia(QUrl::fromLocalFile("/Users/yeyining/landlord/6zhangpai.mp3"));
    player8->setMedia(QUrl::fromLocalFile("/Users/yeyining/landlord/yaobuqi.mp3"));
    player9->setMedia(QUrl::fromLocalFile("/Users/yeyining/landlord/wang.mp3"));
    player10->setMedia(QUrl::fromLocalFile("/Users/yeyining/landlord/zhadan.mp3"));
    player11->setMedia(QUrl::fromLocalFile("/Users/yeyining/landlord/yizhangpai.mp3"));
    player12->setMedia(QUrl::fromLocalFile("/Users/yeyining/landlord/sandaiyi.mp3"));
    player13->setMedia(QUrl::fromLocalFile("/Users/yeyining/landlord/feiji.mp3"));
    player14->setMedia(QUrl::fromLocalFile("/Users/yeyining/landlord/biaoyan.mp3"));
    player15->setMedia(QUrl::fromLocalFile("/Users/yeyining/landlord/wangzha.mp3"));
    player16->setMedia(QUrl::fromLocalFile("/Users/yeyining/landlord/sanzhangpai.mp3"));
    player17->setMedia(QUrl::fromLocalFile("/Users/yeyining/landlord/sandaiyidui.mp3"));
    player18->setMedia(QUrl::fromLocalFile("/Users/yeyining/landlord/sidaier.mp3"));
    player19->setMedia(QUrl::fromLocalFile("/Users/yeyining/landlord/jiuzhangpai.mp3"));
    player20->setMedia(QUrl::fromLocalFile("/Users/yeyining/landlord/danzhang.mp3"));
    player21->setMedia(QUrl::fromLocalFile("/Users/yeyining/landlord/dedede.mp3"));
    player22->setMedia(QUrl::fromLocalFile("/Users/yeyining/landlord/jixu.mp3"));
    player23->setMedia(QUrl::fromLocalFile("/Users/yeyining/landlord/liandui.mp3"));
    player24->setMedia(QUrl::fromLocalFile("/Users/yeyining/landlord/duizi.mp3"));
    //player5->setVolume(30);
    //if(me->paixu == 1) player5->play();

    //QMediaPlayer* player1 = new QMediaPlayer(QUrl::fromLocalFile("/Users/yeyining/landlord/sanbing.mp3"));
    //QMediaPlayer* player2 = new QMediaPlayer(QUrl::fromLocalFile("/Users/yeyining/landlord/sidingle.mp3"));
    //QMediaPlayer* player3 = new QMediaPlayer(QUrl::fromLocalFile("/Users/yeyining/landlord/quantiqili.mp3"));

    //for(int i = 0; i < 5; i++)    handC.push_back(card(11,2));
    //handC.clear();

    myConnect d(this);
    if(d.exec() == myConnect::Accepted){
        xu = d.xu;
        readWriteSocket1 = d.getReadWriteSocket1();
        readWriteSocket2 = d.getReadWriteSocket2();
        if(readWriteSocket1 == readWriteSocket2){
            //qDebug() << xu <<"buged";
        }
        QObject::connect(readWriteSocket1,SIGNAL(readyRead()),this,SLOT(recvMessage1()));
        QObject::connect(readWriteSocket2,SIGNAL(readyRead()),this,SLOT(recvMessage2()));//sendMessage(1,50);
        //sendMessage(2,50);
    }
    else{
        close();
    }
    if (xu != 1 && xu != 2 && xu != 3) close();
    me = new people(xu);
    chupaizhe = me->paixu;
    //if(me->paixu == 1) domp3(5);
    setButton();
    connect(ti, &QTimer::timeout,this,&MainWindow::con);
    connect(bgm, &QTimer::timeout,this,&MainWindow::concon);
    //bgm->start();
    if(me->paixu == 1){
        playlist->addMedia(QUrl::fromLocalFile("/Users/yeyining/landlord/huanledoudizhu.mp3"));
        playlist->setPlaybackMode(QMediaPlaylist::Loop);

        player5->setPlaylist(playlist);
        player5->setVolume(10);
        player5->play();
    }
    if(xu == 1){
        st = 1;
        setButton();
        std::this_thread::sleep_for(std::chrono::milliseconds(75));
        sendMessage(1,100);
        sendMessage(2,100);
        //startGame();
    }
    /*else {
        std::this_thread::sleep_for(std::chrono::milliseconds(75));
        sendMessage(1,50);
        sendMessage(2,50);
    }*/

    reset();
}

MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow::nextPaixu(){
    return (1+(me->paixu-1)%3) % 3 + 1;
}
int MainWindow::nextRead(){
    if(me->paixu == 1){
        return 1;
    }
    if (me->paixu == 2) return 2;
    return 1;
}

void MainWindow::addCard(int j, card c){
        if(j == 1)    handC.push_back(c);
        if(j == 2)    throwC.push_back(c);
        if(j == 3)    dizhuC.push_back(c);
        if(j == 4)    tempC.push_back(c);
};

void MainWindow::bianchengdizhu(){
    for(auto i : dizhuC){
        int nn = i.num;
        int hh = i.huase;
        handC.push_back(card(nn,hh));
    }
}
void MainWindow::keyPressEvent(QKeyEvent* ev){
    switch(ev->key())
    {
    case Qt::Key_R:
        reset();
        break;
    case Qt::Key_PageUp:
    case Qt::Key_PageDown:
    default:
        QWidget::keyPressEvent(ev);
    }
}

void MainWindow::addCard(int j,std::vector<card> news){
    for(auto i : news){
        if(j == 1)    handC.push_back(i);
        if(j == 2)    throwC.push_back(i);
        if(j == 3)    dizhuC.push_back(i);
        if(j == 4)    tempC.push_back(i);
    }
}

void MainWindow::startGame(){
    ready1 = 0;
    ready2 = 0;
    ready3 = 0;
    formC = 0;
    nextC = 0;
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    fapai();
    //qDebug() << char(me->paixu-1+'A') <<"starts the game";
    qsrand(QTime::currentTime().msec());
    int startPos = qrand() % 3 + 1;
    dizhuCC = 0;
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    if(startPos == 1){
        qiangdizhu(1);
    }
    else if(startPos == 2){
        sendMessage(1,12);
    }
    else sendMessage(2,12);
    //domp3(21);
}

void MainWindow::fapai(){
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    std::vector<card> cards;
    std::vector<card> temp;
    for(int i = 1;i <= 4; i++){
        for(int num = 3; num <= 15; num++){
            cards.push_back(card(num, i));
        }
    }
    cards.push_back(card(16,1));
    cards.push_back(card(17,1));
    int rr[54] = {0};

    for(int i = 0; i < 54; i++){
        rr[i] = qrand() % (i+1);
        card ttt = cards[i];
        cards[i] = cards[rr[i]];
        cards[rr[i]] = ttt;
    }

    //std::random_shuffle(cards.begin(),cards.end());
    /*for(int i = 0; i < 17;i++){
        me->addCard(1,cards[i]);
    }
    for(int i = 17; i < 34; i++){
        temp.push_back(cards[i]);
    }
    sendMessage(1,30,temp);
    temp.clear();
    for(int i = 34; i < 51; i++){
        temp.push_back(cards[i]);
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    sendMessage(2,30,temp);*/
    for(int i = 0 ; i < 17 ;i++){
        addCard(1,cards[i]);

        sendMessage(2,40,cards[i+17]);

        sendMessage(1,40,cards[i+34]);
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
        repaint();
    }
    /*(int i = 0 ; i < 17 ;i++){
        addCard(1,cards[i]);

        sendMessage(2,40,cards[i+17]);

        sendMessage(1,40,cards[i+34]);
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
        repaint();
    }*/
    for(int i = 51; i <= 53; i++){
        addCard(3,cards[i]);
        sendMessage(1,41,cards[i]);
        sendMessage(2,41,cards[i]);
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
        repaint();
    }
    //temp.clear();
    cards.clear();
    nextC = 17;
    formC = 17;
    //std::this_thread::sleep_for(std::chrono::milliseconds(75));
    //sendMessage(1,15);
    //sendMessage(2,15);

    repaint();
}


void MainWindow::qiangdizhu(int i){
    if (i == 1) dizhu = me->paixu + 10;
    st = 2;
    dizhuCC = i;
    //qDebug() << char(me->paixu-1+'A') <<"qiang dizhu:" << dizhuCC;
    setButton();
    repaint();
}

void MainWindow::reset(){
    //qDebug() << char(me->paixu-1+'A') <<"resets the game";
    st = 1;
    nextC = 0;
    formC = 0;
    ready1 = 0;
    ready2 = 0;
    ready3 = 0;
    throwC.clear();
    handC.clear();
    dizhuC.clear();
    tempC.clear();
    chupaizhe = me->paixu;
    dizhuCC = 0;
    dizhu = 10;
    setButton();
    //domp3 *a = new domp3(1);
    //a->start();
    //domp3(1);

    if (me->paixu == 1) startGame();
    domp3(1);

}

void MainWindow::mousePressEvent(QMouseEvent *ev){
    int x = ev->pos().x();
    int y = ev->pos().y();
    if (st != -1 && handC.size() >= 1){
        if (x < startX || (x > startX+(handC.size()-1)*50+215)) return;
        if (y < startY || y > startY + 290) return;
        int ge = (x - startX) / 50;
        if (ge > handC.size()-1){
            ge = handC.size()-1;
        }
        handC[ge].ifChose = 1 - handC[ge].ifChose;

        //handC.insert(handC.begin(),card(11,2));
        //me->addCard(1,card(11,2));

    }
    std::vector<card> tt;
    for(auto i : handC){
        if(i.ifChose){
            tt.push_back(i);
        }
    }

    if(st == 4){
        if(ICan(tempC,tt) != 0){
            qDebug() << "try a"<<ICan(tempC,tt);
            ui->jueding->setEnabled(true);
        }
        else ui->jueding->setEnabled(false);
        //me->handC.push_back(card(11,2));
    }

    tt.clear();
    repaint();
}


void MainWindow::paintEvent(QPaintEvent *ev){
    QPainter painter(this);
    //pp.rotate(90);
    QPixmap pix;

    pix.load(":/image/PokerImage/background.jpg");
    QSize picSize(1500,900);
    pix.scaled(picSize, Qt::KeepAspectRatio);
    painter.drawPixmap(0,-50,1500,900,pix);


    std::string k;
    if(me->paixu == 1) k+= "卢本伟";
    if(me->paixu == 2) k+= "PDD";
    if(me->paixu == 3) k+= "大司马";
    //k += char('A'+me->paixu-1);
    if (st == -1) k+=" PREPARE \n";
    else if (st == 1) k+=" WAITING \n";
    else if (st == 2) k+=" DEALING \n";
    else if (st == 3) k+=" LOOKING \n";
    else if (st == 4) k+=" BE QUICK \n";
    //else if (st == 3) k+=" DEALING \n";
    //if (readWriteSocket1 != nullptr) k += "1 ok\n";
    //if (readWriteSocket2 != nullptr) k += "2 ok\n";

    //1
    ui->label->setText(QString::fromStdString(k));

    /*if(st == 2 || st == 4){
        ui->label_3->setText("Your Turn");
    }
    else{
        ui->label_3->setText("Not Your Turn");
    }
    if(dizhu < 10) {
        k = "dizhu is " + std::to_string(dizhu);
        ui->label_3->setText(QString::fromStdString(k));
    }*/

    //3
    k = "your card num : " + std::to_string(handC.size());
    k+= "\nformer card num: " + std::to_string(formC);
    k+= "\nnext card num: " + std::to_string(nextC);
    ui->label_2->setText(QString::fromStdString(k));

    //QMatrix matrix;
    //matrix.rotate(90);
    if(st == 1 || st == 2){
        for(int i = 0; i < 54 - int(handC.size()) - int(dizhuC.size()) - formC - nextC; i++){
            pix.load(":/image/PokerImage/padding.jpg");
            QSize picSize(110,154);
            pix.scaled(picSize, Qt::KeepAspectRatio);
            painter.drawPixmap(350+10*i,250,110,154,pix);
        }
    }
    if(st != -1){
        //QPixmap pp = QPixmap(":/image/cards/PADDING.png").transformed(matrix, Qt::SmoothTransformation);
        for(int i = 0; i < formC; i++){
            //QPixmap pp = QPixmap(":/image/cards/PADDING.png").transformed(matrix, Qt::SmoothTransformation);
            pix.load(":/image/PokerImage/padding.jpg");
            QSize picSize(110,154);
            pix.scaled(picSize, Qt::KeepAspectRatio);
            //painter.translate(0,140+10*i); //让图片的中心作为旋转的中心
            //painter.rotate(90); //顺时针旋转90度
            //painter.translate(-50,-50); //使原点复原
            painter.drawPixmap(0,100+10*i,110,154,pix);
            //painter.rotate(270);
            //painter.translate(0,-1*(140+10*i));
        }
        for(int i = 0; i < nextC; i++){
            pix.load(":/image/PokerImage/padding.jpg");
            QSize picSize(110,154);
            //pix.transformed(matrix);
            pix.scaled(picSize, Qt::KeepAspectRatio);
            painter.drawPixmap(1150,100+10*i,110,154,pix);
        }
    }

    for(int i = 0; i < int(handC.size()); i++){
        //qDebug() << me->handC[i].path;
        pix.load(handC[i].path);
        if (handC[i].ifChose) painter.drawPixmap(startX+50*i,startY-50,110,154,pix);
        else painter.drawPixmap(startX+50*i,startY,110,154,pix);
    }

    for(int i = 0; i < int(throwC.size()); i++){
        //qDebug() << me->handC[i].path;
        pix.load(throwC[i].path);
        QSize picSize(55,77);
        //pix.transformed(matrix);
        pix.scaled(picSize, Qt::KeepAspectRatio);
        if( i < 30)painter.drawPixmap(170+25*i,350,55,77,pix);
        else painter.drawPixmap(170+25*(i-30),375,55,77,pix);
    }

    for(int i = 0; i < int(tempC.size()); i++){
        //qDebug() << me->handC[i].path;
        pix.load(tempC[i].path);
        QSize picSize(110,154);
        pix.scaled(picSize, Qt::KeepAspectRatio);
        painter.drawPixmap(320+50*i,170,110,154,pix);
    }

    for(int i = 0; i < int(dizhuC.size()); i++){
        if(st == 1 || st == 2)  pix.load(":/image/PokerImage/padding.jpg");
        else pix.load(dizhuC[i].path);
        QSize picSize(110,154);
        pix.scaled(picSize, Qt::KeepAspectRatio);
        painter.drawPixmap(400+110*i,0,110,154,pix);
    }
    //painter.drawLine(0,0,100,100);

    if(me->paixu == 1)pix.load(":/image/PokerImage/lubenwei.png");
    else if(me->paixu == 2)pix.load(":/image/PokerImage/PDD.jpeg");
    else if(me->paixu == 3)pix.load(":/image/PokerImage/dasima.jpeg");
    QSize xSize(240,180);
    pix.scaled(xSize, Qt::KeepAspectRatio);
    painter.drawPixmap(1050,500,240,180,pix);
}

void MainWindow::setButton(){
    //ui->reset->hide();
    if (st == -1){
        ui->buyao->hide();
        ui->jueding->hide();
        ui->jiaodizhu->hide();
        ui->bujiao->hide();
    }
    else if(st == 1){
        ui->buyao->hide();
        ui->jueding->hide();
        ui->jiaodizhu->hide();
        ui->bujiao->hide();
    }
    else if(st == 2){
        ui->buyao->hide();
        ui->jueding->hide();
        ui->bujiao->show();
        ui->jiaodizhu->show();
    }
    else if(st == 3){
        ui->buyao->hide();
        ui->jueding->hide();
        ui->bujiao->hide();
        ui->jiaodizhu->hide();
        //ui->pushButton_8->setEnabled(false);
    }
    else if(st == 4){
        ui->jiaodizhu->hide();
        ui->bujiao->hide();
        ui->buyao->show();
        ui->jueding->show();
        ui->jueding->setEnabled(false);
        if(chupaizhe == me->paixu){
            ui->buyao->setEnabled(false);
        }
        else ui->buyao->setEnabled(true);
    }

};

void MainWindow::sendMessage(int j, int i){
    //qDebug() << char('A' + me->paixu-1) <<"send"<<i;
    QByteArray * array = new QByteArray;
    array->clear();
    array->append(char(me->paixu));
    array->append(char(i));
    if (i >= 1 && i <= 4){
        array->append(char(i));
    }
    else if (i == 50){
        //自己已经准备完毕
        array->append(char(50));
    }
    else if (i == 10){
        //地主产生
        array->append(char(dizhu));
    }
    else if(i == 11){
        //叫地主信息更新
        array->append(char(dizhuCC+5));
        array->append(char(dizhu));
    }
    else if(i == 12){
        //叫地主信息更新
        array->append(char(dizhuCC+5));
        array->append(char(dizhu));
    }
    else if(i == 15){
        //牌数更新
        array->append(char(int(handC.size())+5));
    }
    else if(i == 69){
        //牌数更新
        array->append(char(int(100)));
    }
    else if (i == 100){
        //开始游戏
        array->append(char(100));
    }
    else if (i == 20){
        //重启
        array->append(char(100));
    }
    else if (i == 70){
        //重置当前牌组
        array->append(char(chupaizhe));
    }
    else if (i == 72){
        //下家打牌
        array->append(char(nextPaixu()));
    }
    else if (i == 80){
        //下家打牌
        array->append(char(me->paixu));
    }
    else {
        //qDebug() << char('A' + me->paixu-1) <<"send nothing"<<i;
    }

    if (j == 1){
        readWriteSocket1->write(array->data());
        readWriteSocket1->waitForBytesWritten();
        //readWriteSocket1->waitForReadyRead(0);
    }
    else{
        readWriteSocket2->write(array->data());
        readWriteSocket2->waitForBytesWritten();
        //readWriteSocket1->waitForReadyRead(0);
    }
}

void MainWindow::sendMessage(int j, int i, card cd){
   // qDebug() << char('A' + me->paixu-1) <<"send"<<i;
    QByteArray * array = new QByteArray;
    array->clear();
    array->append(char(me->paixu));
    array->append(char(i));
    array->append(char(cd.num));
    array->append(char(cd.huase));

    if (j == 1){
        readWriteSocket1->write(array->data(),75);
        readWriteSocket1->waitForBytesWritten();
        //readWriteSocket1->waitForReadyRead(0);
    }
    else{
        readWriteSocket2->write(array->data(),75);
        readWriteSocket2->waitForBytesWritten();
        //readWriteSocket1->waitForReadyRead(0);
    }
}

void MainWindow::sendMessage(int j, int i, std::vector<card> cd){
    //qDebug() << char('A' + me->paixu-1) <<"send"<<i;
    QByteArray * array = new QByteArray;
    array->clear();
    array->append(char(me->paixu));
    array->append(char(i));

    array->append(char(cd.size()));
    for(auto i : cd){
        array->append(char(i.num)).append(char(i.huase));
    }


    if (j == 1){
        readWriteSocket1->write(array->data(),50);
        readWriteSocket1->waitForBytesWritten();
        //readWriteSocket1->waitForReadyRead(0);
    }
    else{
        readWriteSocket2->write(array->data(),50);
        readWriteSocket2->waitForBytesWritten();
        //readWriteSocket1->waitForReadyRead(0);
    }
}


std::vector<card> readCard(int i, int start, QByteArray info){
    std::vector<card> cards;

    int cc =start;
    while (cc +2 <= start + 2*i){
        card a = card(int(info[cc]), int(info[cc+1]));
        cards.push_back(a);
        cc += 2;
    }
    return cards;
}

void MainWindow::recvMessage1(){
    QByteArray info;
    //readWriteSocket1->readAll();
    info = readWriteSocket1->readAll();
    //else info = readWriteSocket2->readAll();
    //qDebug() << char('A' + int(info[0])-1) << "to" << char('A'+me->paixu-1);

    if (int(info[1]) == 100) {
        //qDebug() << "start!";
        st = 1;
        setButton();
        if (me->paixu == 1) {
            //qDebug() << char(me->paixu-1+'A') <<"starts the game";
            startGame();
        }
    }
    else if(int(info[1]) == 15){
        if(int(info[0]) == nextPaixu()){
            nextC = int(info[2])-5;
        }
        else formC = int(info[2])-5;
    }
    else if(int(info[1]) == 20){
        reset();
    }
    else if (int(info[1]) == 50){
        ready2 = 1;
        qDebug() << char('A'+me->paixu - 1)<<"find 2 ready";
    }
    else if (int(info[1]) == 10){
        dizhu = int(info[2]);
        if(dizhu == me->paixu){
            //domp3(2);
            //qDebug() << "i am dizhu!";
            st = 4;
            setButton();
            if(handC.size() == 17) addCard(1,dizhuC);
            //addCard(1,card(11,2));
            //repaint()
            std::this_thread::sleep_for(std::chrono::milliseconds(75));
            sendMessage(1,15);
            sendMessage(2,15);
        }
        else{
            st = 3;
            setButton();
        }
        //qDebug() << "dizhu is" << char(dizhu-1+'A');
    }
    else if (int(info[1]) == 11){
        //qDebug() << "receive 11";
        if(int(info[0]) != nextPaixu()){
            dizhu = int(info[3]);
            qiangdizhu(int(info[2])-5 + 1);
        }
    }
    else if (int(info[1]) == 12){
        dizhu = int(info[3]);
        qiangdizhu(int(info[2])-5 + 1);
    }
    else if (int(info[1]) == 69){
        for(auto i : tempC){
            throwC.push_back(i);
        }
    }
    else if (int(info[1]) == 70){
        tempC.clear();
        if(chupaizhe == int(info[2])) qDebug() << "kan wo biao yan !";
        chupaizhe = int(info[2]);
    }
    else if (int(info[1]) == 71){
        addCard(4, card(int(info[2]),int(info[3])));
    }
    else if (int(info[1]) == 72){
        if(throwC.empty()) {
            for(auto i : tempC) throwC.push_back(i);
        }
        if(me->paixu == int(info[2])){
            st = 4;
            setButton();
        }
    }
    else if(int(info[1]) == 80){
        if(int(info[2]) == dizhu || (int(info[2]) != dizhu && me->paixu == dizhu)){
            QMessageBox:: StandardButton result= QMessageBox::information(this, "Title", "YOU LOSE! \n wanna try again?",QMessageBox::Reset|QMessageBox::No);
            switch (result)
            {
            case QMessageBox::Reset:
                ready1 = 1;
                //std::this_thread::sleep_for(std::chrono::milliseconds(75));
                if (me->paixu != 1) reset();
                /*if (me->paixu == 1 && ready2 == 1 && ready3 == 1) {
                    st = 1;
                    sendMessage(1,20);
                    sendMessage(2,20);
                    reset();
                    return;
                }*/
                sendMessage(1,50);
                sendMessage(2,50);
                break;
            case QMessageBox::No:
                close();
                break;
            default:
                break;
            }
        }
        else{
            QMessageBox:: StandardButton result= QMessageBox::information(this, "Title", "YOU WIN! \n wanna try again?",QMessageBox::Reset|QMessageBox::No);
            switch (result)
            {
            case QMessageBox::Reset:
                ready1 = 1;
                //std::this_thread::sleep_for(std::chrono::milliseconds(75));
                /*if (me->paixu == 1 && ready2 == 1 && ready3 == 1) {
                    st = 1;
                    sendMessage(1,20);
                    sendMessage(2,20);
                    reset();
                    return;
                }*/
                sendMessage(1,50);
                sendMessage(2,50);
                if (me->paixu != 1) reset();
                break;
            case QMessageBox::No:
                close();
                break;
            default:
                break;
            }
        }
    }
    else if (int(info[1]) == 30){
        //发牌
        addCard(1,readCard(int(info[2]), int(info[3]), info));
    }
    else if (int(info[1]) == 31){
        //发牌
        addCard(3,readCard(int(info[2]), int(info[3]), info));
    }
    else if (int(info[1]) == 40){
        addCard(1, card(int(info[2]),int(info[3])));
        //repaint();
        nextC++;
        //repaint();
        formC++;
        /*if(int(handC.size()) == 17){
            std::this_thread::sleep_for(std::chrono::milliseconds(75));
            sendMessage(1,15);
            sendMessage(2,15);
        }*/
    }
    else if (int(info[1]) == 41){
        //发牌
        addCard(3,card(int(info[2]),int(info[3])));
    }

    else {
        //qDebug() << int(info[1]) <<"can't explain";
    }
    //readWriteSocket1->waitForReadyRead(0);
};

void MainWindow::recvMessage2(){
    QByteArray info;
    //readWriteSocket1->readAll();
    //info = readWriteSocket1->readAll();
    info = readWriteSocket2->readAll();
    //info = readWriteSocket2->readData(20);
    //qDebug() << char('A' + int(info[0])-1) << "to" << char('A'+me->paixu-1);

    if (int(info[1]) == 100) {
        //qDebug() << "start!";
        st = 1;
        setButton();
        if (me->paixu == 1) {
            //qDebug() << char(me->paixu-1+'A') << "starts the game";
            startGame();
        }
    }
    else if(int(info[1]) == 15){
        if(int(info[0]) == nextPaixu()){
            nextC = int(info[2])-5;
        }
        else formC = int(info[2])-5;
    }
    else if(int(info[1]) == 20){
        reset();
    }
    else if (int(info[1]) == 50){
        ready3 = 1;
        qDebug() << char('A'+me->paixu - 1)<<"find 3 ready";
    }
    else if (int(info[1]) == 10){
        dizhu = int(info[2]);
        if(dizhu == me->paixu){
            //qDebug() << "i am dizhu!";
            st = 4;
            //domp3(2);
            setButton();
            if(handC.size() == 17) addCard(1,dizhuC);
            //repaint()
            std::this_thread::sleep_for(std::chrono::milliseconds(75));
            sendMessage(1,15);
            sendMessage(2,15);
        }
        else{
            st = 3;
            setButton();
        }
        //qDebug() << "dizhu is" << char(dizhu-1+'A');
    }
    else if (int(info[1]) == 11){
        //qDebug() << "receive 11";
        if(int(info[0]) != nextPaixu()){
            dizhu = int(info[3]);
            qiangdizhu(int(info[2])-5 + 1);
        }
    }
    else if (int(info[1]) == 12){
        dizhu = int(info[3]);
        qiangdizhu(int(info[2])-5 + 1);
    }
    else if (int(info[1]) == 69){
        for(auto i : tempC){
            throwC.push_back(i);
        }
    }
    else if (int(info[1]) == 70){
        tempC.clear();
        if(chupaizhe == int(info[2])) qDebug() << "kan wo biao yan !";
        chupaizhe = int(info[2]);
    }
    else if (int(info[1]) == 71){
        addCard(4, card(int(info[2]),int(info[3])));
    }
    else if (int(info[1]) == 72){
        if(throwC.empty()) {
            for(auto i : tempC) throwC.push_back(i);
        }
        if(me->paixu == int(info[2])){
            st = 4;
            setButton();
        }
    }
    else if(int(info[1]) == 80){
        if(int(info[2]) == dizhu || (int(info[2]) != dizhu && me->paixu == dizhu)){
            QMessageBox:: StandardButton result= QMessageBox::information(this, "Title", "YOU LOSE! \n wanna try again?",QMessageBox::Reset|QMessageBox::No);
            switch (result)
            {
            case QMessageBox::Reset:
                ready1 = 1;
                //std::this_thread::sleep_for(std::chrono::milliseconds(75));
                if (me->paixu != 1) reset();
                /*if (me->paixu == 1 && ready2 == 1 && ready3 == 1) {
                    st = 1;
                    sendMessage(1,20);
                    sendMessage(2,20);
                    reset();
                    return;
                }*/
                sendMessage(1,50);
                sendMessage(2,50);
                break;
            case QMessageBox::No:
                close();
                break;
            default:
                break;
            }
        }
        else{
            QMessageBox:: StandardButton result= QMessageBox::information(this, "Title", "YOU WIN! \n wanna try again?",QMessageBox::Reset|QMessageBox::No);
            switch (result)
            {
            case QMessageBox::Reset:
                ready1 = 1;
                //std::this_thread::sleep_for(std::chrono::milliseconds(75));
                if (me->paixu != 1) reset();
                /*if (me->paixu == 1 && ready2 == 1 && ready3 == 1) {
                    st = 1;
                    sendMessage(1,20);
                    sendMessage(2,20);
                    reset();
                    return;
                }*/
                sendMessage(1,50);
                sendMessage(2,50);
                break;
            case QMessageBox::No:
                close();
                break;
            default:
                break;
            }
        }
    }
    else if (int(info[1]) == 30){
        //发牌
        addCard(1,readCard(int(info[2]), int(info[3]), info));
    }
    else if (int(info[1]) == 31){
        //发牌
        addCard(3,readCard(int(info[2]), int(info[3]), info));
    }
    else if (int(info[1]) == 40){
        addCard(1, card(int(info[2]),int(info[3])));
        //repaint();
        nextC++;
        //repaint();
        formC++;
        /*if(int(handC.size()) == 17){
            std::this_thread::sleep_for(std::chrono::milliseconds(75));
            sendMessage(1,15);
            sendMessage(2,15);
        }*/
    }
    else if (int(info[1]) == 41){
        //发牌
        addCard(3,card(int(info[2]),int(info[3])));
    }
    else {
        //qDebug() << int(info[1]) <<"can't explain";
    }

    //readWriteSocket2->waitForReadyRead(0);

};


bool compc(card a, card b){
    if(a.num < b.num) return 1;
    if(a.num > b.num) return 0;
    if(a.huase > b.huase) return 1;
    return 0;
}
void MainWindow::con(){
    std::sort(handC.begin(),handC.end(),compc);
    std::sort(dizhuC.begin(),dizhuC.end(),compc);
    std::sort(throwC.begin(),throwC.end(),compc);
    std::sort(tempC.begin(),tempC.end(),compc);


    if(ready1 == 1 && ready2 == 1 && ready3 == 1 && me->paixu == 1){
        st = 1;
        setButton();
        std::this_thread::sleep_for(std::chrono::milliseconds(75));
        sendMessage(1,20);
        sendMessage(2,20);
        reset();
        qDebug() << char('A'+me->paixu-1)<<"starts the game";
        /*st = 1;
        setButton();
        std::this_thread::sleep_for(std::chrono::milliseconds(75));
        sendMessage(1,100);
        sendMessage(2,100);
        reset();*/
    }

    /*if (readWriteSocket1 != nullptr && readWriteSocket2 != nullptr && ready1 != 1) {
        ready1 = 1;
        sendMessage(1,50);
        sendMessage(2,50);
    }*/

    //2
    //setButton();
    repaint();
};



//***************************游戏逻辑
int MainWindow::zhadan(std::vector<card> my){
    if(my.size() != 4) return -1;
    int c = my[0].num;
    if (my[1].num != c || my[2].num != c || my[3].num != c){
        return -1;
    }
    return c;
}

int MainWindow::danzhang(std::vector<card> my){
    if(my.size() != 1) return -1;
    return my[0].num;
}

int MainWindow::wangzha(std::vector<card> my){
    if (my.size() != 2) return -1;
    if (my[0].num >= 16 && my[1].num >= 16) return 1;
    return -1;
}


int MainWindow::duizi(std::vector<card> my){
    if (my.size() != 2) return -1;
    if (my[0].num == my[1].num) return my[0].num;
    return -1;
}

int MainWindow::sanbudai(std::vector<card> my){
    if (my.size() != 3) return -1;
    if(my[0].num == my[1].num && my[0].num == my[2].num) return my[0].num;
    return -1;
}

int MainWindow::sandaiyi(std::vector<card> my){
    if (my.size() != 4) return -1;
    if(my[0].num == my[1].num && my[0].num == my[2].num) return my[0].num;
    else if (my[1].num == my[2].num && my[3].num == my[1].num) return my[1].num;
    return -1;
}

int MainWindow::sandaier(std::vector<card> my){
    if (my.size() != 5) return -1;
    if(my[0].num == my[1].num && my[0].num == my[2].num && my[3].num == my[4].num) return my[0].num;
    else if (my[0].num == my[1].num && my[3].num == my[2].num && my[3].num == my[4].num) return my[3].num;
    return -1;
}

int MainWindow::shunzi(std::vector<card> my){
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

int MainWindow::liandui(std::vector<card> my){
    if(int(my.size()) % 2 != 0 || int(my.size()) < 6) return -1;
    int count = 0;
    while (count < int(my.size())){
        if(my[count].num == 15) return -1;
        if(my[count].num != my[count+1].num) return -1;
        count += 2;
    }
    return my[0].num;
}


int MainWindow::sidaier(std::vector<card> my){
    if(int(my.size()) == 6){
        if(my[0].num == my[1].num && my[0].num == my[2].num && my[0].num == my[3].num){
            return my[0].num;
        }
        else if(my[1].num == my[2].num && my[1].num == my[3].num && my[1].num == my[4].num){
            return my[1].num;
        }
        else if (my[2].num == my[3].num && my[2].num == my[4].num && my[2].num == my[5].num){
            return my[4].num;
        }
    }
    else if(int(my.size()) == 8){
        if(my[0].num == my[1].num && my[0].num == my[2].num && my[0].num == my[3].num){
            if(my[4].num == my[5].num && my[6].num == my[7].num)
            return my[0].num;
        }
        if(my[2].num == my[3].num && my[2].num == my[4].num && my[2].num == my[5].num){
            if(my[0].num == my[1].num && my[6].num == my[7].num)
            return my[2].num;
        }
        if(my[4].num == my[5].num && my[4].num == my[6].num && my[4].num == my[7].num){
            if(my[0].num == my[1].num && my[2].num == my[3 ].num)
            return my[4].num;
        }
    }
    return -1;

}

int MainWindow::feiji(std::vector<card> my){
    if(int(my.size()) == 6){
        if(my[0].num == my[1].num && my[1].num == my[2].num && my[3].num == my[4].num && my[4].num == my[5].num){
            if(my[0].num != 15 && my[3].num != 15){
                return my[0].num;
            }
            else return -1;
        }
    }
    if(int(my.size()) == 8){
        if(my[0].num == my[1].num && my[1].num == my[2].num && my[3].num == my[4].num && my[4].num == my[5].num){
            if(my[0].num != 15 && my[3].num != 15){
                return my[0].num;
            }
            else return -1;
        }
        if(my[1].num == my[2].num && my[2].num == my[3].num && my[4].num == my[5].num && my[5].num == my[6].num){
            if(my[1].num != 15 && my[4].num != 15){
                return my[1].num;
            }
            else return -1;
         }
        if(my[2].num == my[3].num && my[3].num == my[4].num && my[5].num == my[6].num && my[6].num == my[7].num){
            if(my[2].num != 15 && my[5].num != 15){
                return my[2].num;
            }
            else return  -1;
         }
    }
    if(int(my.size()) == 10){
        if(my[0].num == my[1].num && my[1].num == my[2].num && my[3].num == my[4].num && my[4].num == my[5].num){
            if(my[0].num != 15 && my[3].num != 15 && my[6].num == my[7].num && my[8].num == my[9].num){
                return my[0].num;
            }
            else return -1;
        }
        if(my[2].num == my[3].num && my[3].num == my[4].num && my[5].num == my[6].num && my[6].num == my[7].num){
            if(my[2].num != 15 && my[5].num != 15 && my[0].num == my[1].num && my[8].num == my[9].num){
                return my[2].num;
            }
            else return -1;
        }
        if(my[4].num == my[5].num && my[5].num == my[6].num && my[7].num == my[8].num && my[8].num == my[9].num){
            if(my[4].num != 15 && my[7].num != 15 && my[0].num == my[1].num && my[2].num == my[3].num){
                return my[4].num;
            }
            else return -1;
        }
    }
    return -1;
}


int MainWindow::sanlian(std::vector<card> my){
    if (my.size() != 3) return -1;
    if (my[0].num != my[1].num || my[0].num != my[2].num) return -1;
    return my[0].num;
}

bool MainWindow::comp(card a, card b){
    return a.num < b.num;
}

/*int MainWindow::ICan(std::vector<card> his, std::vector<card> my){
    int hz = int(his.size());
    int mz = int(my.size());
    //std::sort(his.begin(),his.end(),MainWindow::comp());
    //std::sort(my.begin(),my.end(),MainWindow::comp());
    if(hz == 0) return 1;
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
};*/

int MainWindow::ICan(std::vector<card> his, std::vector<card> my){
    int hz = int(his.size());
    int mz = int(my.size());
    //std::sort(his.begin(),his.end(),MainWindow::comp());
    //std::sort(my.begin(),my.end(),MainWindow::comp());

    //return 1;


    if(wangzha(my) != -1){
        return 9;
    }

    if(wangzha(his) != -1){
        if(chupaizhe == me->paixu) return 8;
        return false;
    }

    if (zhadan(my) != -1){
        if(chupaizhe == me->paixu) return 8;
        if(wangzha(his) != -1) return false;
        else if (zhadan(my) > zhadan(his)) return 8;
        return false;
    }

    if(danzhang(my) != -1) {
        if(chupaizhe == me->paixu) return 1;
        if(danzhang(his) != -1 && danzhang(my) > danzhang(his)) return 1;
        else return false;
    }

    if(duizi(my) != -1){
        if(chupaizhe == me->paixu) return 2;
        if(duizi(his) != -1 && duizi(my) > duizi(his)) return 2;
        else return false;
    }

    if(sanbudai(my) != -1){
        if(chupaizhe == me->paixu) return 3;
        if(sanbudai(his) != -1 && sanbudai(my) > sanbudai(his)) return 3;
        else return false;
    }

    if(sandaiyi(my) != -1){
        if(chupaizhe == me->paixu) return 3;
        if(sandaiyi(his) != -1 && sandaiyi(my) > sandaiyi(his)) return 3;
        else return false;
    }

    if(sandaier(my) != -1){
        if(chupaizhe == me->paixu) return 3;
        if(sandaier(his) != -1 && sandaier(my) > sandaier(his)) return 3;
        else return false;
    }

    if(shunzi(my) != -1){
        if(chupaizhe == me->paixu) return 4;
        if(mz != hz) return false;
        if(shunzi(his) != -1 && shunzi(my) > shunzi(his)) return 4;
        else return false;
    }

    if(liandui(my) != -1){
        if(chupaizhe == me->paixu) return 5;
         if(mz != hz) return false;
         if(liandui(his) != -1 && liandui(my) > liandui(his)) return 5;
         else return false;
    }

    if(sidaier(my) != -1){
        if(chupaizhe == me->paixu) return 6;
        if(mz != hz) return false;
        if(sidaier(his) != -1 && sidaier(my) > sidaier(his)) return 6;
        else return false;
    }

    if(feiji(my) != -1){
        if(chupaizhe == me->paixu) return 7;
        if(mz != hz) return false;
        if(feiji(his) != -1 && feiji(my) > feiji(his)) return 7;
        else return false;
    }

    return false;

    /*if(hz == 0) return 1;
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
    }*/
};



void MainWindow::on_reset_clicked()
{
    sendMessage(1,20);
    sendMessage(2,20);
    reset();
}

void MainWindow::on_jiaodizhu_clicked()
{

    //qDebug() << char(me->paixu-1+'A') <<"accepted" << dizhuC;
    if(dizhuCC == 3){
        //me->bianchengdizhu();
        //card a = dizhuC[0];
        //me->handC.push_back(a);
        addCard(1,dizhuC);
        std::this_thread::sleep_for(std::chrono::milliseconds(75));
        sendMessage(1,15);
        sendMessage(2,15);
        std::this_thread::sleep_for(std::chrono::milliseconds(75));
        //assert(me != nullptr);
        //std::vector<card> cc = handC;
        //handC.clear();
        /*for(auto i: cc) {
            int nn = i.num;
            int hh = i.huase;
            handC.push_back(card(nn,hh));
        }*/
        /*handC.push_back(card(11,2));
        handC.push_back(card(11,2));
        handC.push_back(card(11,2));
        handC.push_back(card(11,2));
        handC.push_back(card(11,2));
        handC.push_back(card(11,2));
        handC.push_back(card(11,2));
        handC.push_back(card(11,2));
        handC.push_back(card(11,2));
        handC.push_back(card(11,2));
        handC.push_back(card(11,2));
        handC.push_back(card(11,2));
        handC.push_back(card(11,2));
        handC.push_back(card(11,2));
        handC.push_back(card(11,2));
        handC.push_back(card(11,2));
        handC.push_back(card(11,2));
        handC.push_back(card(11,2));*/
        //me->handC.
        //std::this_thread::sleep_for(std::chrono::milliseconds(50));

        st = 4;
        setButton();
        dizhu = me->paixu;
        sendMessage(1,10);
        sendMessage(2,10);
        std::this_thread::sleep_for(std::chrono::milliseconds(75));
        domp3(3);
        //repaint();
    }
    else{
        dizhu = 10 + me->paixu;
        std::this_thread::sleep_for(std::chrono::milliseconds(75));
        sendMessage(1,11);
        sendMessage(2,11);
        st = 1;
        setButton();
        std::this_thread::sleep_for(std::chrono::milliseconds(75));
        domp3(6);
        //std::thread t1(domp3,3);
        //t1.detach();
    }

    //domp3(2);
}

void MainWindow::on_bujiao_clicked()
{
    //qDebug() << char(me->paixu-1+'A') <<"refused" << dizhuC;
    if(dizhuCC == 3){
        dizhu = dizhu - 10;
        std::this_thread::sleep_for(std::chrono::milliseconds(75));
        sendMessage(1,10);
        sendMessage(2,10);
        st = 3;
        setButton();
        std::this_thread::sleep_for(std::chrono::milliseconds(75));
    }
    else{
        std::this_thread::sleep_for(std::chrono::milliseconds(75));
        sendMessage(1,11);
        sendMessage(2,11);
        st = 1;
        setButton();
        std::this_thread::sleep_for(std::chrono::milliseconds(75));
    }
    domp3(4);
    //std::this_thread::sleep_for(std::chrono::milliseconds(75));
    //sendMessage(1,15);
    //sendMessage(2,15);
}

void MainWindow::on_buyao_clicked()
{

    std::this_thread::sleep_for(std::chrono::milliseconds(75));
    sendMessage(1,70);
    sendMessage(2,70);

    for(auto i : tempC){
        std::this_thread::sleep_for(std::chrono::milliseconds(75));
        sendMessage(1,71,i);
        sendMessage(2,71,i);
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(75));
    sendMessage(1,72);
    sendMessage(2,72);
    st = 3;
    setButton();
    domp3(22);
}

void MainWindow::on_jueding_clicked()
{
    tempC.clear();
    bool pan = 1;
    while(pan){
        pan = 0;
        for(auto i = handC.begin(); i != handC.end(); i++){
            if((*i).ifChose){
                pan = 1;
                tempC.push_back(*i);
                throwC.push_back(*i);
                handC.erase(i);
                repaint();
                break;
            }
        }
    }
    std::sort(throwC.begin(),throwC.end(),compc);
    repaint();

    std::this_thread::sleep_for(std::chrono::milliseconds(75));
    chupaizhe = me->paixu;
    sendMessage(1,70);
    sendMessage(2,70);
    for(auto i : tempC){
        std::this_thread::sleep_for(std::chrono::milliseconds(75));
        sendMessage(1,71,i);
        sendMessage(2,71,i);
    }    
    std::this_thread::sleep_for(std::chrono::milliseconds(75));
    sendMessage(1,69);
    sendMessage(2,69);
    std::this_thread::sleep_for(std::chrono::milliseconds(75));
    sendMessage(1,72);
    sendMessage(2,72);
    st = 3;
    setButton();
    if(handC.empty()){
        std::this_thread::sleep_for(std::chrono::milliseconds(75));
        sendMessage(1,80);
        sendMessage(2,80);
        QMessageBox:: StandardButton result= QMessageBox::information(this, "Title", "YOU WIN! \n wanna try again?",QMessageBox::Reset|QMessageBox::No);
        switch (result)
        {
        case QMessageBox::Reset:            
            std::this_thread::sleep_for(std::chrono::milliseconds(75));
            sendMessage(1,50);
            sendMessage(2,50);
            ready1 = 1;
            if (me->paixu != 1) reset();
            //if (me->paixu == 1 && ready2 == 1 && ready3 == 1) {
                //st = 1;
                //std::this_thread::sleep_for(std::chrono::milliseconds(75));
                //sendMessage(1,20);
                //sendMessage(2,20);
                //qDebug() << char('A'+me->paixu-1)<<"starts the game";
                //reset();
                //return;
            //}
            //return;
            break;
        case QMessageBox::No:
            close();
            break;
        default:
            break;
        }

    }

    std::this_thread::sleep_for(std::chrono::milliseconds(75));
    sendMessage(1,15);
    sendMessage(2,15);

    //if(chupaizhe == me->paixu) domp3(14);

    if(wangzha(tempC) != -1) domp3(15);
    else if(danzhang(tempC) != -1 && tempC[0].num >= 16) domp3(9);
    else if (zhadan(tempC) != -1) domp3(10);
    else if (sandaiyi(tempC) != -1) domp3(12);
    else if (feiji(tempC) != -1) domp3(13);
    else if (sandaier(tempC) != -1) domp3(17);
    else if (sidaier(tempC) != -1) domp3(18);
    else if (danzhang(tempC) != -1) domp3(20);
    else if (liandui(tempC) != -1) domp3(23);
    else if (shunzi(tempC) != -1) domp3(21);
    else if (duizi(tempC) != -1) domp3(24);

    if(int(handC.size()) == 6) domp3(7);
    else if(int(handC.size()) == 1) domp3(11);
    else if(int(handC.size()) == 3) domp3(16);
    else if(int(handC.size()) == 9) domp3(19);



    //if(int(handC.size() == 1) domp3(11);
}


