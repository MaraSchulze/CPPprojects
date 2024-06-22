#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class  Phonebook {
	private:
		Contact	contacts[8];
		int		nextContact;
		int		numberContacts;

        void	search(void);
        void	add(void);
        void	displayOne(int index) const;
        void	displayAll(void) const;
        std::string truncate(std::string str) const;
        void    readData(const std::string& prompt, std::string& var);

    public:
        Phonebook();
        void    use();
};

#endif
