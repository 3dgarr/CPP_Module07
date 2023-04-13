#include "./iter.hpp"

template<typename T>
void foo(T& elem)
{
	elem += 5;
}

int main()
{
	const size_t	SIZE = 10;
	int *arr = new int[SIZE];
	for (size_t i = 0; i < SIZE; i++)
	{
		arr[i] = i * 10;
	}
	for (size_t i = 0; i < SIZE; i++)
	{
		std::cout << arr[i] << " " << std::flush;
	}
	std::cout << std::endl;

	::iter(arr, SIZE, foo);

	for (size_t i = 0; i < SIZE; i++)
	{
		std::cout << arr[i] << " " << std::flush;
	}
	std::cout << std::endl;
	delete[] arr;

}