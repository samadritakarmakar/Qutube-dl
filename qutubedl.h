#ifndef QUTUBEDL_H
#define QUTUBEDL_H

#include <QWidget>
#include <QProcess>
#include <QString>

namespace Ui {
class Qutubedl;
}

class Qutubedl : public QWidget
{
    Q_OBJECT

public:
    explicit Qutubedl(QWidget *parent = 0);
    ~Qutubedl();

private slots:
    void on_Go_pb_clicked();
    void disable_go();
    void enable_go();
    void readoutput();

    void on_get_fmt_pb_clicked();

    void on_updt_bcknd_pb_clicked();

    void on_stop_pb_clicked();

private:
    Ui::Qutubedl *ui;
    QProcess *youtube=new QProcess(this);
    QString f_output;
    QString f_cb;
    int i=0,z=0;
    QString youtube_path;
    QString Url;
    QString proxy;
    QString fmt;

    void get_texts();
    void click_handle(QStringList argument);
    void button_handle();
    void youtube_d_handle();
};

#endif // QUTUBEDL_H
