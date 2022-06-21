#ifndef CONTACT_H
# define CONTACT_H

# include <string>
# include <iostream>

class Contact {
	private :
		std::string	_first_name;
		std::string _last_name;
		std::string _nickname;
		std::string _phone_number;
		std::string _darkest_secret;

	public :
		Contact();
		~Contact();
		void		setFirstName(std::string first_name);
		void		setLastName(std::string last_name);
		void		setNickname(std::string nickname);
		void		setPhoneNumber(std::string phone_number);
		void		setDarkestSecret(std::string darkest_secret);

		/* getters create a copy, this is not a good realisation, but 
		at this stage we don't know about "&" */
		std::string	getFirstName() const;
		std::string	getLastName() const;
		std::string	getNickname() const;
		std::string	getPhoneNumber() const;
		std::string	getDarkestSecret() const;

} ;

#endif