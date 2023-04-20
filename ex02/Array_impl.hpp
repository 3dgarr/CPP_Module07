# ifndef	ARRAY_IMPL_HPP
 # define	ARRAY_IMPL_HPP

template <typename T>
Array<T>::Array()
	:	_size(0), 
		_container(NULL)
{}

template <typename T>
Array<T>::Array(size_t	n)
	:	_size(n)
{
	_container = new T[n];
	for(size_t i = 0; i < _size; i++)
		_container[i] = T();
}

template <typename T>
Array<T>::Array(const Array& rhs)
{
	_size = rhs._size;
	_container = new T[_size];
	for (size_t i = 0; i < _size; i++)
	{
		_container[i] = rhs._container[i];
	}
}

template <typename T>
Array<T>::~Array()
{
	delete[] _container;
}

template <typename T>
Array<T>&	Array<T>::operator=(const Array& rhs)
{
	if (this != &rhs)
	{
		delete[] _container;
		_size = rhs._size;
		_container = new T[_size];
		for(size_t i = 0; i < _size; i++)
		{
			_container[i] = rhs._container[i];
		}
	}
	return (*this);
}

template <typename T>
T&	Array<T>::operator[](size_t	index)
{
	if (index >= _size)
		throw	InvalidIndexException();
	return (_container[index]);
}

template <typename T>
const T&	Array<T>::operator[](size_t	index) const
{
	if (index >= _size)
		throw	InvalidIndexException();
	return (_container[index]);
}

template <typename T>
size_t	Array<T>::size(void) const
{
	return (_size);
}

template <typename T>
const char*	Array<T>::InvalidIndexException::what() const throw()
{
	return ("Invalid index");
}

# endif//	ARRAY_IMPL_HPP