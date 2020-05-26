#include "contactsreader.h"

namespace
{
const std::vector<Contact> mockData {
    {"Script1", "aaaaaaa", "0101010400100101101001001"},
    {"Script2", "bbbbbbb", "0101010400100101101001001"},
    {"Script3", "ccccccc", "0101010400100101101001001"},
    {"Script4", "ddddddd", "0101010400100101101001001"},
    {"Script5", "eeeeeee", "0101010400100101101001001"},
    {"Script6", "fffffff", "0101010400100101101001001"},
    {"Script7", "ggggggg", "0101010400100101101001001"},
    {"Script8", "hhhhhhh", "0101010400100101101001001"},
    {"Script9", "iiiiiii", "0101010400100101101001001"},
    {"Script10", "jjjjjjj", "0101010400100101101001001"},
    {"Script11", "kkkkkkk", "0101010400100101101001001"},
    {"Script12", "lllllll", "0101010400100101101001001"},
    {"Script13", "mmmmmmm", "0101010400100101101001001"},
    {"Script14", "nnnnnnn", "0101010400100101101001001"},
    {"Script15", "ooooooo", "0101010400100101101001001"},
    {"Script16", "ppppppp", "0101010400100101101001001"}
};
}

std::pair<bool, std::vector<Contact> > ContactsReader::requestContactsBrowse()
{
    return std::make_pair(true, mockData);
}
