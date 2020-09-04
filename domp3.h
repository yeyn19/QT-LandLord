#ifndef DOMP3_H
#define DOMP3_H

#include <QObject>
#include <QThread>
#include <QMediaPlayer>
#include <QSound>

class domp3: public QThread
{
        Q_OBJECT
public:
    int i;
    domp3(int ii): i(ii){
    }

protected:
    void run(){
        //qDebug() << "mp3 !!";
        //QMediaPlayer* player = new QMediaPlayer;
        QSound a("/Users/yeyining/landlord/sanbing.mp3");
        //connect(player, SIGNAL(positionChanged(qint64)), this, SLOT(positionChanged(qint64)));
        if(i == 1){
            qDebug() << "mp3 !!";

            //player->setMedia(QMediaContent(QUrl::fromLocalFile("/Users/yeyining/landlord/sanbing.mp3")));
        }
        if(i == 2){
            //player->setMedia(QUrl::fromLocalFile("/Users/yeyining/landlord/quantiqili.mp3"));
        }
        //player->setVolume(100);
        //player->play();
        a.play();
    }// 新线程入口
};

#endif // DOMP3_H
