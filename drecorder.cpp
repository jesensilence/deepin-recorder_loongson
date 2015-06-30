#include "drecorder.h"
#include "ui_drecorder.h"
#include <qmessagebox.h>
#include <unistd.h>

DRecorder::DRecorder(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DRecorder)
{
    ui->setupUi(this);

    connect(ui->pushButton_start,SIGNAL(clicked()),this,SLOT(bt_start()));
    connect(ui->pushButton_stop,SIGNAL(clicked()),this,SLOT(bt_stop()));

}

DRecorder::~DRecorder()
{
    delete ui;
}
void DRecorder::bt_start()
{

    QString s = ui->lineEdit_2->text();


    sprintf(name,"%s.wav",s.toUtf8().data());

    sprintf(cmd,"arecord -t wav -f cd -D hw:0 ~/%s.wav",s.toUtf8().data());
   // QMessageBox::about(NULL,"HAH ",name);
    ui->pushButton_start->setDisabled(true);
     th = new myThread(cmd);

   // system(cmd);
    //QThread::start();
    th->start();

 }
void DRecorder::run(){
    system(cmd);
}
void DRecorder::bt_stop(){


    system("pkill arecord");
    system("pkill arecord");
    system("pkill arecord");
    ui->pushButton_start->setDisabled(false);
}
