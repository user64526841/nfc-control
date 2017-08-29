#pragma once

#include <QObject>
#include <QNearFieldManager>
#include <QNdefMessage>
#include <QString>

class NFCManager : public QObject
{
    Q_OBJECT

public:
    explicit NFCManager(QObject* parent = 0);

private:
    QNearFieldManager* m_nfcManager;
    QNearFieldTarget::RequestId m_request;
    QString m_nfcMessage;

public slots:
    void startNfcDetection();
    void stopNfcDetection();

private slots:
    void targetDetected(QNearFieldTarget* target);
    void targetLost(QNearFieldTarget* target);
    void targetError(QNearFieldTarget::Error error, QNearFieldTarget::RequestId request);
    void ndefMessageRead(QNdefMessage message);
    void ndefMessageWritten();
};
