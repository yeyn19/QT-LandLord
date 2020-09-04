#include "myconnect.h"
#include "ui_myconnect.h"

myConnect::myConnect(QWidget *parent) :
    QDialog(parent),
    xu(5),
    ui(new Ui::myConnect)
{
    ui->setupUi(this);
    connect(ui->yess, SIGNAL(clicked()), this, SLOT(accept()));
    connect(ui->cancell, SIGNAL(clicked()), this, SLOT(close));
}

myConnect::~myConnect()
{
    delete ui;
}

QHostAddress myConnect::getAddress1(){
    return QHostAddress(ui->add1->text());
}

QHostAddress myConnect::getAddress2(){
    return QHostAddress(ui->add2->text());
}

quint16 myConnect::getPort1(){
    return ui->pp1->text().toUShort();
}

quint16 myConnect::getPort2(){
    return ui->pp2->text().toUShort();
}

QTcpSocket *myConnect::getReadWriteSocket1()
{
    return readWriteSocket1;
}

QTcpSocket *myConnect::getReadWriteSocket2()
{
    return readWriteSocket2;
}

void myConnect::acceptConnection1()
{
    qDebug() << "socket1 ok";
    if(xu == 1){
        readWriteSocket1 = listenSocket1->nextPendingConnection();
        emit leile();
    }

    if(readWriteSocket1 != nullptr && readWriteSocket2 != nullptr){
        return QDialog::accept();
    }
}

void myConnect::acceptConnection2()
{
    qDebug() << "socket2 ok";
    if(xu == 1 || xu == 2) {
        readWriteSocket2 = listenSocket2->nextPendingConnection();
        emit leile();
    }

    if(readWriteSocket1 != nullptr && readWriteSocket2 != nullptr){
        return QDialog::accept();
    }
}


void myConnect::accept()
{
    qDebug() << "accept";
    if(xu == 1){
        if(listenSocket1 == nullptr){
            listenSocket1 =new QTcpServer;
        listenSocket1->listen(QHostAddress::Any,getPort1());
        //ui->loading->show();
        //ui->loading->movie()->start();
        QObject::connect(listenSocket1,SIGNAL(newConnection()),this,SLOT(acceptConnection1()));
        }

        if(listenSocket2 == nullptr){
            listenSocket2 =new QTcpServer;
        listenSocket2->listen(QHostAddress::Any,getPort2());
        //ui->loading->show();
        //ui->loading->movie()->start();
        QObject::connect(listenSocket2,SIGNAL(newConnection()),this,SLOT(acceptConnection2()));
        }
    }

    if(xu == 2){
        if(readWriteSocket1 == nullptr){

            this->readWriteSocket1 = new QTcpSocket;
            QObject::connect(readWriteSocket1,SIGNAL(connected()),this,SLOT(acceptConnection1()));
            this->readWriteSocket1->connectToHost(getAddress1(),getPort1());
        }

        if(listenSocket2 == nullptr){
            listenSocket2 =new QTcpServer;
        listenSocket2->listen(QHostAddress::Any,getPort2());
        //ui->loading->show();
        //ui->loading->movie()->start();
        QObject::connect(listenSocket2,SIGNAL(newConnection()),this,SLOT(acceptConnection2()));
        }

    }

    if(xu == 3){
        if(readWriteSocket1 == nullptr){

            this->readWriteSocket1 = new QTcpSocket;
            QObject::connect(readWriteSocket1,SIGNAL(connected()),this,SLOT(acceptConnection1()));
            this->readWriteSocket1->connectToHost(getAddress1(),getPort1());
        }
        if(readWriteSocket2 == nullptr){

            this->readWriteSocket2 = new QTcpSocket;
            QObject::connect(readWriteSocket2,SIGNAL(connected()),this,SLOT(acceptConnection2()));
            this->readWriteSocket2->connectToHost(getAddress2(),getPort2());
        }
    }
}

void myConnect::on_radioButton_clicked()
{
    xu = 1;
    ui->label_2->setText("server 1");
    ui->label_4->setText("server 2");
    ui->add1->setText("127.0.0.1");
    ui->add2->setText("127.0.0.1");
    ui->pp1->setText("1111");
    ui->pp2->setText("1115");

}

void myConnect::on_radioButton_2_clicked()
{
    xu = 2;
    ui->label_2->setText("connect 1");
    ui->label_4->setText("server 3");
    ui->add1->setText("127.0.0.1");
    ui->add2->setText("127.0.0.1");
    ui->pp1->setText("1111");
    ui->pp2->setText("2222");
}

void myConnect::on_radioButton_3_clicked()
{
    xu = 3;
    ui->label_2->setText("connect 2");
    ui->label_4->setText("connect 3");
    ui->add1->setText("127.0.0.1");
    ui->add2->setText("127.0.0.1");
    ui->pp1->setText("1115");
    ui->pp2->setText("2222");
}
