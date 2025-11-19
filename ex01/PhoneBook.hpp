#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include "main.hpp"

class PhoneBook 
{
    private:
    static const int maxContacts = 8;
        Contact contacts[maxContacts];
        int contactCount;
        int currIndex;
        void printHeader() const;
        void printRow(int index) const;
        

    public:
        PhoneBook();
        ~PhoneBook();

        void addContact();
        void showContacts() const;
        void showContactDetails(int index) const;
        std::string setFormat(const std::string& str) const;
};

#endif
