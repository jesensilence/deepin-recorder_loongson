#ifndef DRECORDER_H
#define DRECORDER_H

#include <QWidget>
#include <stdlib.h>
#include <stdio.h>
#include <QThread>

namespace Ui {
class DRecorder;
}
class myThread : public QThread
{
public:
    char cmd1[250];
    myThread(char *cmd){
        memcpy(cmd1,cmd,250);
    }

    void run(){
        system(cmd1);
    }
};

class DRecorder : public QWidget
{
    Q_OBJECT

public:
    explicit DRecorder(QWidget *parent = 0);
    ~DRecorder();
    char name[200];
    char cmd[250];
    void run();
    myThread *th;
private slots:
    void bt_start();
    void bt_stop();
friend class myThread;
private:
    Ui::DRecorder *ui;
};

#endif // DRECORDER_H
