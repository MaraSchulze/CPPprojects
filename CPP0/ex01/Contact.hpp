#ifndef CONTACT_H
#define CONTACT_H

#include <string>

class Contact {
private:
    std::string firstName;
    std::string lastName;
    std::string nickName;
    std::string phoneNumber;
    std::string secret;

public:
	Contact(void);
    Contact(const std::string& first, const std::string& last, const std::string& nick,
            const std::string& phone, const std::string& _secret_);
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getNickName() const;
    std::string getPhoneNumber() const;
    std::string getSecret() const;
};

#endif
