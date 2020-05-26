#pragma once
#include <QString>
#include <QVariant>

class Contact
{
public:
    Contact() = default;
    Contact(QString name, QString surname, QString phoneNumber);

    QString name() const;
    QString surname() const;
    QString phoneNumber() const;

private:
    QString m_name;
    QString m_surname;
    QString m_phoneNumber;
};
