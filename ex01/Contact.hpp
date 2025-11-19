#ifndef CONTACT_HPP
#define CONTACT_HPP
#include "main.hpp"

class Contact {
    private:
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;  

    public:
      Contact();

      ~Contact();

        void setFirstName(const std::string& fname);
        void setLastName(const std::string& lname);
        void setNickname(const std::string& nname);
        void setPhoneNumber(const std::string& pnumber);
        void setDarkestSecret(const std::string& secret);

        const std::string& getFirstName() const;
        const std::string& getLastName() const;
        const std::string& getNickname() const;
        const std::string& getPhoneNumber() const;
        const std::string& getDarkestSecret() const;


};
#endif