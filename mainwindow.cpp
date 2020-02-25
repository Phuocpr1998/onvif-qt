#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <ptzonvif/onvifptzservice.h>
#include <QThread>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    OnvifPTZService a;
    a.ContinuousMove("http://192.168.0.11/onvif/PTZ", "admin", "Admin123", "Profile_1", -0.2, 0, 0);
    QThread::sleep(4);
    a.Stop("http://192.168.0.11/onvif/PTZ", "admin", "Admin123", "Profile_1");
}

MainWindow::~MainWindow()
{
    delete ui;
}
