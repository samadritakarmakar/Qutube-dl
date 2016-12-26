#include "qutubedl.h"
#include "ui_qutubedl.h"
#include <QString>
#include <QDebug>
#include <QProcess>
#include <QDir>
#include <QFileDialog>
Qutubedl::Qutubedl(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Qutubedl)
{
    ui->setupUi(this);
}

Qutubedl::~Qutubedl()
{
    delete ui;
    delete youtube;
}


void Qutubedl::on_Go_pb_clicked()
{
    get_texts();
    QStringList argument;

    if (proxy!="")
        argument<<"--proxy"<<proxy;
    if (fmt!="")
        argument<<"-tf"<<fmt;
    argument<<Url;
    qDebug()<<argument;

    button_handle();

    QDir open;
    youtube_d_handle();

    QFileDialog *d_path = new QFileDialog(this);
    QString d_path_string=d_path->getExistingDirectory(this,"Save Directory", QDir::homePath());
    qDebug()<<d_path_string;
    open.setCurrent(d_path_string);
    qDebug()<<argument;
    if(d_path_string !="")
        click_handle(argument);
}

//Fetches Available formats
void Qutubedl::on_get_fmt_pb_clicked()
{
    f_cb.clear();
    get_texts();
    youtube_d_handle();
    button_handle();
    QStringList argument;
    argument<<"-F"<<Url;
    click_handle(argument);
}

//update youtube-dl
void Qutubedl::on_updt_bcknd_pb_clicked()
{
    youtube_d_handle();
    button_handle();
    QStringList argument;
    argument<<"-U";
    click_handle(argument);
}

//on clicking stop push button.
void Qutubedl::on_stop_pb_clicked()
{
    button_handle();
    youtube->terminate();

}

//fetches texts entered
void Qutubedl::get_texts()
{
    //Url=ui->url->text();
    Url=ui->url->toPlainText();
    proxy=ui->prxy->text();
    fmt=ui->frmt->text();
}

//calls youtube-dl with given arguments
void Qutubedl::click_handle(QStringList argument)
{
#ifdef Q_OS_LINUX
    youtube->start(youtube_path+"./youtube-dl", argument);
#else
    youtube->start(youtube_path+"youtube-dl.exe", argument);
#endif

}

//Sets youtube-dl directory path in variable youtube_path
void Qutubedl::youtube_d_handle()
{
    QDir open;
    if(!open.cd("youtube-dl"))
    qWarning("Cannot Find Directory \"youtube-dl\"");
    if(i==0)
    {
        youtube_path=open.currentPath()+open.fromNativeSeparators("//youtube-dl")+open.fromNativeSeparators("/");
        i++;
    }
    qDebug()<<youtube_path+"./youtube-dl";
}

//connections to QProcess instance youtube
void Qutubedl::button_handle()
{
    connect(youtube,SIGNAL(started()),this, SLOT(disable_go()));
    connect(youtube,SIGNAL(finished(int)),this, SLOT(enable_go()));
    connect(youtube,SIGNAL(readyReadStandardOutput()),this, SLOT(readoutput()));
    connect(youtube,SIGNAL(readyReadStandardError()),this, SLOT(readoutput()));
}

//Originally disabled Go Push Button, now disables all Push Buttons other than Stop PB
void Qutubedl::disable_go()
{
    ui->Go_pb->setEnabled(false);
    ui->get_fmt_pb->setEnabled(false);
    ui->updt_bcknd_pb->setEnabled(false);
    //ui->stop_pb->setEnabled(false);
}

//Originally enabled Go Push Button, now Enables all Push Buttons other than Stop PB
void Qutubedl::enable_go()
{
    ui->Go_pb->setEnabled(true);
    ui->get_fmt_pb->setEnabled(true);
    ui->updt_bcknd_pb->setEnabled(true);
    //ui->stop_pb->setEnabled(true);
    f_output.clear();
}

 //Output of youtube-dl is printed in QTextBrowser output_tb
void Qutubedl::readoutput()
{
    QByteArray output=youtube->readAllStandardOutput();
    QByteArray output2=youtube->readAllStandardError();
    if (QString(output).contains("[download]", Qt::CaseSensitive))
        f_output=QString(output);
    else
        f_output=f_output+QString(output);
    f_output=f_output+QString(output2);
    qDebug()<<f_output;
    ui->output_tb->setText(f_output);
}

