#pragma once
#include <iostream>

template<typename T>
void iter(T* arr, size_t length, void(*f)(T& element))
{
	for (size_t i = 0; i < length; i++)
	{
		f(arr[i]);
	}	
}