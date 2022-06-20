#ifndef		SPAN_HPP
# define	SPAN_HPP

# define	MAX_INT	2147483647

# include	<iostream>
# include	<algorithm>
# include	<iterator>
# include	<vector>

class Span {
	private :
		unsigned int 		_nSize;
		std::vector<int>	_objs;
	public :
		Span(void) {}
		~Span(void) {}
		Span(unsigned int size);
		Span (const Span& copy);
		Span& operator = (const Span& rhs);

		void	addNumber(int num);
		int		shortestSpan(void) const;
		int		longestSpan(void) const;
		
		class	VectorIsFull : public std::exception {
			public : virtual const char* what() const throw() {
				return "Error : vector is full !";
			}
		} ;

		class	VectorIsEmpty : public std::exception {
			public : virtual const char* what() const throw() {
				return "Error : vector must include more than 1 element !";
			}
		} ;


} ;

#endif