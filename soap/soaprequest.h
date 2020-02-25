#ifndef SOAPREQUEST_H
#define SOAPREQUEST_H

#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QObject>
#include <QUuid>

class SoapRequest : QObject
{
    Q_OBJECT
public:
    SoapRequest();
    ~SoapRequest();

    bool sendRequest(QString &result);
public:
    QString username, password, xAddress;
    QString body, action;
    QList<QString> XMLNs;
    QNetworkAccessManager *networkManager;
private:
    QString createRequest();
    QString createUserToken();
};

#endif // SOAPREQUEST_H
