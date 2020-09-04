#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "myconnect.h"
#include "people.h"
#include <QtWidgets>
#include <QTimer>
#include <QTcpServer>
#include <QTcpSocket>
#include <QString>
#include <QLabel>
#include <QMediaPlaylist>
#include "domp3.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    people* me;
    void setButton();
    int st;
    //st -1连接 1准备 2该你抢地主 3打牌 4该你出牌
    int ready1;
    int ready2;
    int ready3;
    int dizhu;
    int dizhuCC;
    int startX = 100;
    int startY = 500;
    int chupaizhe;

    int formC;
    int nextC;

    std::vector<card> handC;
    std::vector<card> throwC;
    std::vector<card> dizhuC;
    std::vector<card> tempC;

public slots:
    void con();
    void concon();
    int nextPaixu();
    int nextRead();
    void reset();
    void sendMessage(int j, int i);
    void sendMessage(int j, int i, std::vector<card> cards);
    void sendMessage(int j, int i, card cd);
    void recvMessage1();
    void recvMessage2();
    void fapai();
    void startGame();
    void paintEvent(QPaintEvent *ev)  override;
    void mousePressEvent(QMouseEvent *ev)  override;
    void keyPressEvent(QKeyEvent *ev)  override;
    void qiangdizhu(int i);
    void addCard(int j, card c);
    void bianchengdizhu();
    void addCard(int j, std::vector<card> cards);
    void domp3(int i);
    int ICan(std::vector<card> his, std::vector<card> my);
    int danzhang(std::vector<card> my);
    int zhadan(std::vector<card> my);
    int wangzha(std::vector<card> my);
    int duizi(std::vector<card> my);
    int sanbudai(std::vector<card> my);
    int sandaiyi(std::vector<card> my);
    int sandaier(std::vector<card> my);
    int shunzi(std::vector<card> my);
    int sanlian(std::vector<card> my);
    int liandui(std::vector<card> my);
    int sidaier(std::vector<card> my);
    int feiji(std::vector<card> my);
    bool comp(card a, card b);

private slots:
    void on_reset_clicked();

    void on_jiaodizhu_clicked();

    void on_bujiao_clicked();

    void on_buyao_clicked();

    void on_jueding_clicked();

private:
    Ui::MainWindow *ui;

    QTimer* ti;
    QTimer* bgm;

    QMediaPlaylist *playlist;

    QMediaPlayer* player1;
    QMediaPlayer* player2;
    QMediaPlayer* player3;
    QMediaPlayer* player4;
    QMediaPlayer* player5;
    QMediaPlayer* player6;
    QMediaPlayer* player7;
    QMediaPlayer* player8;
    QMediaPlayer* player9;
    QMediaPlayer* player10;
    QMediaPlayer* player11;
    QMediaPlayer* player12;
    QMediaPlayer* player13;
    QMediaPlayer* player14;
    QMediaPlayer* player15;
    QMediaPlayer* player16;
    QMediaPlayer* player17;
    QMediaPlayer* player18;
    QMediaPlayer* player19;
    QMediaPlayer* player20;
    QMediaPlayer* player21;
    QMediaPlayer* player22;
    QMediaPlayer* player23;
    QMediaPlayer* player24;
    QMediaPlayer* player25;
    QMediaPlayer* player26;
    QMediaPlayer* player27;
    QMediaPlayer* player28;
    QMediaPlayer* player29;
    QMediaPlayer* player30;


    QTcpSocket* readWriteSocket1 = nullptr;
    QTcpSocket* readWriteSocket2 = nullptr;
};
#endif // MAINWINDOW_H
