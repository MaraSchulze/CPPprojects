/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 09:40:00 by marschul          #+#    #+#             */
/*   Updated: 2024/03/07 15:56:07 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery Creation", false, 145, 137, "") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("Shrubbery Creation", false, 145, 137, target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    if (this != &other) {
        AForm::operator=(other);
    }
    return *this;
}

void ShrubberyCreationForm::execute_action() const {
    std::ofstream	outFile(getTarget().c_str());
    if (!outFile.is_open())
        return;
    outFile << "     *" << std::endl;
    outFile << "    ***" << std::endl;
    outFile << "   *****" << std::endl;
    outFile << "  *******" << std::endl;
    outFile << " *********" << std::endl;
    outFile << "***********" << std::endl;
    outFile << "    ***" << std::endl;
    outFile << "    ***" << std::endl;
    outFile.close();
}
