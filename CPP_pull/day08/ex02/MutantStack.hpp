#ifndef		MUTANTSTACK_HPP
# define	MUTANTSTACK_HPP

# include <iostream>
# include <stack>
# include <vector>

template<typename T>
class MutantStack : public std::stack<T> {
	public :
		MutantStack(void) : std::stack<T>() {}
		MutantStack(const MutantStack& copy) : std::stack<T>(copy) {}
		virtual ~MutantStack(void) {}
		MutantStack& operator = (const MutantStack& rhs) { std::stack<T>::operator = (rhs); }
		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		iterator 			begin(void) { return std::stack<T>::c.begin(); }
		iterator 			end(void) { return std::stack<T>::c.end(); }
		reverse_iterator 	rbegin(void) { return std::stack<T>::c.rbegin(); }
		reverse_iterator 	rend(void) { return std::stack<T>::c.rend(); }
		const_iterator 		cbegin(void) const { return std::stack<T>::c.cbegin(); }
		const_iterator 		cend(void) const { return std::stack<T>::c.cend(); }
} ;

/* old version 

template<typename T>
class MutantStack : public std::stack<T> {
	public :
		class iterator : public std::iterator<std::output_iterator_tag, T>
		{
			private:
				MutantStack<T>& _target;
				int 			_index;
			public:
				iterator(MutantStack<T> &target, int index);
				iterator& operator ++ (void);
				iterator& operator -- (void);
				iterator& operator ++ (int);
				iterator& operator -- (int);
				T operator * ();
				bool operator != (MutantStack::iterator &target);
		};
		MutantStack(void) : std::stack<T>() {}
		MutantStack(const MutantStack& copy) : std::stack<T>(copy) {}
		virtual ~MutantStack(void) {}
		MutantStack& operator = (const MutantStack& rhs) { std::stack<T>::operator = (rhs); }
		iterator begin(void) { return MutantStack<T>::iterator(*this, 0);}
		iterator end(void) { return MutantStack<T>::iterator(*this, this->size()); }
} ;


template<typename T>
MutantStack<T>::iterator::iterator(MutantStack<T>& target, int index) : _target(target) {
     _index = index;
}

template<typename T>
typename MutantStack<T>::iterator& MutantStack<T>::iterator::operator ++ () {
     _index += 1;
    return *this;
}

template<typename T>
typename MutantStack<T>::iterator& MutantStack<T>::iterator::operator -- () {
     _index -= 1;
    return *this;
}

template <typename T>
typename MutantStack<T>::iterator& MutantStack<T>::iterator::operator ++ (int) {
	iterator    tmp(*this);
    operator++();
    return tmp;
}

template <typename T>
typename MutantStack<T>::iterator &MutantStack<T>::iterator::operator -- (int) {
	iterator    tmp(*this);
    operator--();
    return tmp;
}

template<typename T>
T MutantStack<T>::iterator::operator * () {
    T ret;
    std::vector<T> tab;
    	int size =  _target.size();
    if (_index < 0 || _index >= size)
        throw std::range_error("Index out of bound");
    for (int i =  _index; i < (int)size - 1; ++i) {
        tab.push_back( _target.top());
         _target.pop();
    }
    ret =  _target.top();
    for (int i = 0; i < (int)tab.size(); ++i) {
         _target.push(tab.at(tab.size() - 1 - i));
    }
    return ret;
}

template<typename T>
bool MutantStack<T>::iterator::operator != (MutantStack::iterator& target) {
    return _index != target._index;
}

*/

#endif