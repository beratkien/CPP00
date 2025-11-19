#include "main.hpp"

int main()
{
    PhoneBook phoneBook;
    std::string command;
    std::cout << "---------------WELCOME TO THE AWESOME PHONE BOOK!---------------" << std::endl;
    while (true)
    {
        std::cout << "> Enter a command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, command);
        if(command == "ADD")
        {
            phoneBook.addContact();
        }
        else if(command == "SEARCH")
        {
            phoneBook.showContacts();
        }
        else if(command == "EXIT")
        {
            std::cout << "> Exiting the Phone Book. Goodbye!" << std::endl;
            break;
        }
        else
        {
            std::cout << "> Unknown command. Please try again." << std::endl;
        }
        
    }
}