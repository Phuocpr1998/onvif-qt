#include "onvifptzservice.h"

#include <soap/soaprequest.h>

OnvifPTZService::OnvifPTZService()
{
    this->ptzNameSpace.push_back("xmlns:i=\"http://www.w3.org/2001/XMLSchema-instance\"");
    this->ptzNameSpace.push_back("xmlns:d=\"http://www.w3.org/2001/XMLSchema\"");
    this->ptzNameSpace.push_back("xmlns:c=\"http://www.w3.org/2003/05/soap-encoding\"");
}

bool OnvifPTZService::ContinuousMove(QString ptzXAddress, QString username, QString password, QString profile, double x, double y, double z)
{
    SoapRequest *soapRequest = new SoapRequest();
    soapRequest->xAddress = ptzXAddress;
    soapRequest->username = username;
    soapRequest->password = password;
    soapRequest->action = "http://www.onvif.org/ver20/ptz/wsdl/ContinuousMove";
    soapRequest->XMLNs = this->ptzNameSpace;
    QString body("<ContinuousMove xmlns=\"http://www.onvif.org/ver20/ptz/wsdl\">");
    body.push_back("<ProfileToken>");
    body.push_back(profile);
    body.push_back("</ProfileToken>");
    body.push_back("<Velocity>");
    body.push_back("<PanTilt xmlns=\"http://www.onvif.org/ver10/schema\" x=\"" + QString::number(x) + "\" y=\""+ QString::number(y) +"\"/>");
    body.push_back("<Zoom xmlns=\"http://www.onvif.org/ver10/schema\" x=\"" + QString::number(z) + "\"/>");
    body.push_back("</Velocity></ContinuousMove>");
    soapRequest->body = body;
    bool result = soapRequest->sendRequest();
    delete soapRequest;
    return result;
}

bool OnvifPTZService::Stop(QString ptzXAddress, QString username, QString password, QString profile)
{
    SoapRequest *soapRequest = new SoapRequest();
    soapRequest->xAddress = ptzXAddress;
    soapRequest->username = username;
    soapRequest->password = password;
    soapRequest->action = "http://www.onvif.org/ver20/ptz/wsdl/Stop";
    soapRequest->XMLNs = this->ptzNameSpace;
    QString body("<Stop xmlns=\"http://www.onvif.org/ver20/ptz/wsdl\">");
    body.push_back("<ProfileToken>");
    body.push_back(profile);
    body.push_back("</ProfileToken>");
    body.push_back("<PanTilt>true</PanTilt><Zoom>true</Zoom>");
    body.push_back("</Stop>");
    soapRequest->body = body;
    bool result = soapRequest->sendRequest();
    delete soapRequest;
    return result;
}
