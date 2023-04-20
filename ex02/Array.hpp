# ifndef	ARRAY_HPP
 # define	ARRAY_HPP

# include <iostream>
# include <exception>
# include <string>
# include <ctime>
# include "Colors.hpp"

template <typename	T> 
class Array
{
	public:
		Array();
		Array(size_t);
		Array(const	Array&);
		~Array();
		Array&			operator=(const Array&);
		T&				operator[](const size_t);
		const T&		operator[](const size_t) const;
		size_t			size() const;

	private:
		size_t	_size;
		T*		_container;
		
		class	InvalidIndexException : public std::exception
		{
			public:
				const char *what() const throw();
		};
};

# include "Array_impl.hpp"


# endif//	ARRAY_HPP