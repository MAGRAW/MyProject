#include "contact.h"

Contact::Contact(QString name, QString surname, QString phoneNumber)
    : m_name {std::move(name)},
      m_surname {std::move(surname)},
      m_phoneNumber {std::move(phoneNumber)}
{
}

QString Contact::name() const
{
    return m_name;
}

QString Contact::surname() const
{
    return m_surname;
}

QString Contact::phoneNumber() const
{
    return m_phoneNumber;
}
