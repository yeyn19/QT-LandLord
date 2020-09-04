#ifndef MYCONNECT_H
#define MYCONNECT_H

#include <QDialog>
#include <QtNetwork>
#include <QLabel>
#include <QMovie>

namespace Ui {
class myConnect;
}

class myConnect : public QDialog
{
    Q_OBJECT

public:
    explicit myConnect(QWidget *parent = nullptr);
    ~myConnect();

    QHostAddress getAddress1();
    QHostAddress getAddress2();
    quint16 getPort1();
    quint16 getPort2();
    QTcpSocket * getReadWriteSocket1();
    QTcpSocket * getReadWriteSocket2();

    QTcpServer * listenSocket1 = nullptr;
    QTcpServer * listenSocket2 = nullptr;
    QTcpSocket * readWriteSocket1 = nullptr;
    QTcpSocket * readWriteSocket2 = nullptr;

    int xu;

public slots:
    void acceptConnection1();
    void acceptConnection2();


signals:
    void leile();

private slots:
    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_3_clicked();

private:
    Ui::myConnect *ui;
    void accept();
    void ignore();
};

#endif // MYCONNECT_H
