#include "main.hpp"

Contact::Contact() {

}
Contact::~Contact() {

}

void Contact::setFirstName(const std::string& str) {
    firstName = str;
}
void Contact::setLastName(const std::string& str) {
    lastName = str;
}
void Contact::setNickname(const std::string& str) {
    nickname = str;
}
void Contact::setPhoneNumber(const std::string& str) {
    phoneNumber = str;
}
void Contact::setDarkestSecret(const std::string& str) {
    darkestSecret = str;
}

const std::string& Contact::getFirstName() const {
    return firstName;
}
const std::string& Contact::getLastName() const {
    return lastName;
}
const std::string& Contact::getNickname() const {
    return nickname;
}
const std::string& Contact::getPhoneNumber() const {
    return phoneNumber;
}
const std::string& Contact::getDarkestSecret() const {
    return darkestSecret;
}
