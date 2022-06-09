#include "phonebook.hpp"
#include "contact.hpp"

/* constructor */
phoneBook::phoneBook() {
	this->counter = 0;
}

/* destructor */
phoneBook::~phoneBook() {}

/* methods */
void	phoneBook::addContactInfo() {
	std::string	tmp;
	std::cout << "Please, enter first name: ";
	std::getline (std::cin, tmp);
	this->contacts[this->counter % C_SIZE].setFirstName(tmp);
	std::cout << "Please, enter last name: ";
	std::getline (std::cin, tmp);
	this->contacts[this->counter % C_SIZE].setLastName(tmp);
	std::cout << "Please, enter nickname: ";
	std::getline (std::cin, tmp);
	this->contacts[this->counter % C_SIZE].setNickname(tmp);
	std::cout << "Please, enter phone number: ";
	std::getline (std::cin, tmp);
	this->contacts[this->counter % C_SIZE].setPhoneNumber(tmp);
	std::cout << "Please, enter darkest secret: ";
	std::getline (std::cin, tmp);
	this->contacts[this->counter % C_SIZE].setDarkestSecret(tmp);
	this->counter++;
}

void	phoneBook::addContact() {
	std::string	tmp;
	if (this->counter < 8) {	
		addContactInfo();
	} else {
		std::cout << "this operation will override last contact. Continue? [y/n]" << std::endl;
		std::getline(std::cin, tmp);
		if (tmp == "n") {
			return ;
		} else if (tmp == "y") {
			addContactInfo();
		}
	}
}

void	phoneBook::searchContact() {
	int			tmp = 0;
	contactList();
	while (tmp < C_SIZE) {
		std::cout << "Please, enter contact id: ";
		std::cin >> tmp;
		if (tmp >= C_SIZE) {
			std::cout << "Error: wrong contact id, try again" << std::endl;
		} else if (!this->counter) {
			std::cout << "Error: no contacts in phone book" << std::endl;
			break ;
		} else {
			std::cout << "First name : " << contacts[tmp].getFirstName() << std::endl;
			std::cout << "Last name : " << contacts[tmp].getLastName() << std::endl;
			std::cout << "Nickname : " << contacts[tmp].getNickname() << std::endl;
			std::cout << "Phone number : " << contacts[tmp].getPhoneNumber() << std::endl;
			std::cout << "Secret : " << contacts[tmp].getDarkestSecret() << std::endl;
			break ;
		}
	}
}

void	phoneBook::contactList() {
	std::string	output_data;
	std::cout << "[===========================================]" << std::endl;
	std::cout << "[     Index|First Name| Last Name|  Nickname]" << std::endl;
	std::cout << "[===========================================]" << std::endl;
	for(int i = 0; i < C_SIZE; i++) {
		std::cout << "|" << std::setw(10) << i;
		output_data = contacts[i].getFirstName();
		headerInfoPrinter(output_data);
		output_data = contacts[i].getLastName();
		headerInfoPrinter(output_data);
		output_data = contacts[i].getNickname();
		headerInfoPrinter(output_data);
		std::cout << "|" << std::endl;
		std::cout << "[-------------------------------------------]" << std::endl;
	}
}

void	phoneBook::headerInfoPrinter(std::string output_data) {
	if (output_data.length() >= 10) {
		std::cout << "|" << output_data.substr(0, 9) << ".";
	} else {
		std::cout << "|" << std::setw(10) << output_data;
	}
}
