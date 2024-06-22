#include <iostream>
#include <string>
#include <iomanip>
#include <stdlib.h>
#include <cctype> 

#include "Phonebook.hpp"

Phonebook::Phonebook() : nextContact(0), numberContacts(0) {}

std::string Phonebook::truncate(std::string str) const {
    if (str.length() >= 10)
        return str.substr(0, 9) + '.';
    else
        return str;
}

void	Phonebook::displayAll(void) const {
    std::cout << std::endl;
    for (int i = 0; i < numberContacts; i++)
    {
        Contact	contact = contacts[i];
        std::cout << std::setw(10) << std::string(1, '0' + i) << "|" \
        << std::setw(10) << truncate(contact.getFirstName()) << "|" \
        << std::setw(10) << truncate(contact.getLastName()) << "|" \
        << std::setw(10) << truncate(contact.getNickName()) << "|" \
        << std::endl;
    }
}

void	Phonebook::displayOne(int index) const {
    Contact	contact = contacts[index];
    std::cout \
        << std::endl \
        << "First name: " << contact.getFirstName() << std::endl \
        << "last name: " << contact.getLastName() << std::endl \
        << "Nick name: " << contact.getNickName() << std::endl \
        << "Phone number: " << contact.getPhoneNumber() << std::endl \
        << "Darkest secret: " << contact.getSecret() << std::endl;
}

void    Phonebook::readData(const std::string& prompt, std::string& var) {
    std::cout << prompt << std::endl;
    std::getline(std::cin, var);
    if (std::cin.eof())
        exit(1);
}

bool    checkIfDigits(const std::string& number) {
    for (size_t i = 0; i < number.length(); i++) {
        if (std::isdigit(number[i]) == false)
            return false;
    }
    return true;
}

void	Phonebook::add(void) {
    std::string firstName;
    std::string lastName;
    std::string nickName;
    std::string phoneNumber;
    std::string secret;

    readData("First name: ", firstName);
    readData("last name: ", lastName);
    readData("Nick name: ", nickName);
    readData("Phone number: ", phoneNumber);
    if (checkIfDigits(phoneNumber) == false) {
        std::cout << "Not a number, abort ADD command" << std::endl;
        return;
    }
    readData("Darkest secret: ", secret);

    contacts[nextContact % 8] = Contact(firstName, lastName, nickName, \
        phoneNumber, secret);
    nextContact = (nextContact + 1) % 8;
    numberContacts = numberContacts + 1 > 8 ? 8 : numberContacts + 1;
}

void	Phonebook::search(void) {
    std::string	str;
    long int	index;

    if (numberContacts == 0) {
        std::cout << "No contacts." << std::endl;
        return;
    }
    displayAll();
    while (true) {
        readData("\nChoose an index: ", str);
        if (str.length() != 1 || std::isdigit(str[0]) == false) {
            std::cout << "\nNot a valid index" << std::endl;
            continue;
        }
        index = str[0] - '0';
        if (index >= numberContacts) {
            std::cout << "\nNot a valid index" << std::endl;
            continue;
        }
        displayOne((int) index);
        break;
    }
}

void	Phonebook::use() {
	std::string	input;
	Phonebook	phonebook;

	while (true)
	{
   		std::cout << "\nChoose a command (ADD, SEARCH, EXIT)> ";
        std::getline(std::cin, input);
        if (std::cin.eof()) {
            break;
        }
		if (input.compare("ADD") == 0)
			phonebook.add();
		else if (input.compare("SEARCH") == 0)
			phonebook.search();
		else if (input.compare("EXIT") == 0)
			break;
	}
}
