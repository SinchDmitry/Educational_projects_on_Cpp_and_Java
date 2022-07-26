#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain {
	protected :
		std::string	_ideas[100];
	public :
		Brain(void);
		~Brain(void);
		Brain(const std::string &idea);
		Brain(const Brain &copy);
		Brain &operator = (const Brain &op);
		std::string	getIdea(int num) const;
		void	setIdea(int num, std::string idea);
} ;

#endif