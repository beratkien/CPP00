#include "main.hpp"

PhoneBook::PhoneBook() : contactCount(0), currIndex(0) {}
PhoneBook::~PhoneBook() {}

std::string PhoneBook::setFormat(const std::string& str) const
{
    if(str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}

void PhoneBook::printHeader() const
{
    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << std::endl;
}

void PhoneBook::printRow(int index) const
{
    std::cout << std::setw(10) << index << "|"
              << std::setw(10) << setFormat(contacts[index].getFirstName()) << "|"
              << std::setw(10) << setFormat(contacts[index].getLastName()) << "|"
              << std::setw(10) << setFormat(contacts[index].getNickname()) << std::endl;
}

void PhoneBook::addContact()
{
    std::string name;
    std::string lname;
    std::string nname;
    std::string pnumber;
    std::string secret;
    system("clear");
    std::cout << "----- Add New Contact -----" << std::endl;
    std::cout << "> Enter First Name: ";
    std::getline(std::cin, name);
    std::cout << "> Enter Last Name: ";
    std::getline(std::cin, lname);
    std::cout << "> Enter Nickname: ";
    std::getline(std::cin, nname);
    std::cout << "> Enter Phone Number: ";
    std::getline(std::cin, pnumber);
    std::cout << "> Enter Darkest Secret: ";
    std::getline(std::cin, secret);
    system("clear");
    if(contactCount < maxContacts)
        contactCount++;
    if(currIndex == maxContacts)
        currIndex = 0;

    contacts[currIndex].setFirstName(name);
    contacts[currIndex].setLastName(lname);
    contacts[currIndex].setNickname(nname);
    contacts[currIndex].setPhoneNumber(pnumber);
    contacts[currIndex].setDarkestSecret(secret);
    currIndex++;
    std::cout << "> Contact added successfully!" << std::endl;

}

void PhoneBook::showContactDetails(int index) const
{
    const Contact& contact = contacts[index];
    std::cout << "----- Contact Details -----" << std::endl;
    std::cout << "First Name: " << contact.getFirstName() << std::endl;
    std::cout << "Last Name: " << contact.getLastName() << std::endl;
    std::cout << "Nickname: " << contact.getNickname() << std::endl;
    std::cout << "Phone Number: " << contact.getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << contact.getDarkestSecret() << std::endl;
}

void PhoneBook::showContacts() const
{
    if(contactCount == 0)
    {
        std::cout << "> No contacts available." << std::endl;
        return;
    }
    printHeader();
    for(int i = 0; i < contactCount; i++)
        printRow(i);
    std::cout << "-----------------------------" << std::endl;
    std::string input;
    int index;
    if(contactCount == 1)
        std::cout << "> Enter index to view details : ";
    else
        std::cout << "> Enter index to view details (0 to " << contactCount - 1 << "): ";
    if(!std::getline(std::cin, input) || input.empty())
    {
        std::cout << "> Invalid input." << std::endl;
        return;
    }
    if(input.find_first_not_of("0123456789") != std::string::npos || input.length() > 1)
    {
        std::cout << "> Invalid input. Please enter a numeric number." << std::endl;
        return ;
    }
    else
    {
        index = std::atoi(input.c_str());
    }
        
    if(index < 0 || index >= contactCount)
    {
        std::cout << "> Invalid index. Please enter a number between 0 and " << contactCount - 1 << "." << std::endl;
        return;
    }
    showContactDetails(index);

}