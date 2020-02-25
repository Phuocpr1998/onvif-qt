#ifndef OnvifPTZService_H
#define OnvifPTZService_H

#include <QString>
#include <QList>

class OnvifPTZService
{
private:
    QList<QString> ptzNameSpace;
public:
    OnvifPTZService();
    bool ContinuousMove(QString ptzXAddress, QString username, QString password, QString profile, double x, double y, double z);
    bool Stop(QString ptzXAddress, QString username, QString password, QString profile);
};

#endif // OnvifPTZService_H