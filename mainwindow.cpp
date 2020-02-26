#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QThread>
#include <QTimer>
#include <deviceonvif/onvifdeviceservice.h>
#include <mediaonvif/onvifmediaservice.h>
#include <ptzonvif/onvifptzservice.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    OnvifDeviceService a;
    DeviceCapabilities deviceCapabilities = a.GetCapabilities("http://192.168.0.11/onvif/device_service", "admin", "Admin123");

    OnvifMediaService b;
    QList<MediaProfile> listProfile = b.GetProfiles(deviceCapabilities.mediaXAddr, "admin", "Admin123");

    OnvifPTZService c;
    c.ContinuousMove(deviceCapabilities.ptzXAddr, "admin", "Admin123", listProfile[0].token, 0.2, 0, 0);
    QThread::msleep(2000);
    c.Stop(deviceCapabilities.ptzXAddr, "admin", "Admin123", listProfile[0].token);
    QThread::msleep(500);
    c.GoToHomePosition(deviceCapabilities.ptzXAddr, "admin", "Admin123", listProfile[0].token);
}

MainWindow::~MainWindow()
{
    delete ui;
}
