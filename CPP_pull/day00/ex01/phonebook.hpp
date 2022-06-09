#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include <string>
# include <iostream>
# include <iomanip>
# include "contact.hpp"

# define C_SIZE	8

class phoneBook {
	private :
		Contact		contacts[8];
		int			counter;
		void 		headerInfoPrinter(std::string output_data);
		void		contactList();

	public :
		phoneBook();
		~phoneBook();
		void	addContact();
		void	addContactInfo();
		void	searchContact();
} ;

#endif