#pragma once
#include <utility>
#include <vector>
#include "contact.h"


class ContactsReader
{
public:
    std::pair<bool,
              std::vector<Contact>> requestContactsBrowse();

};

