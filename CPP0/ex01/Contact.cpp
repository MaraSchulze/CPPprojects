#include "Contact.hpp"

Contact::Contact() {}

Contact::Contact(const std::string& first, const std::string& last, const std::string& nick,
                 const std::string& phone, const std::string& _secret_)
    : firstName(first), lastName(last), nickName(nick), phoneNumber(phone), secret(_secret_) {}
	
std::string Contact::getFirstName() const {
    return firstName;
}

std::string Contact::getLastName() const {
    return lastName;
}

std::string Contact::getNickName() const {
    return nickName;
}

std::string Contact::getPhoneNumber() const {
    return phoneNumber;
}

std::string Contact::getSecret() const {
    return secret;
}