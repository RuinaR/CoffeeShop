#include "Vector.h"
template<typename T>
void Vector<T>::clear(void)
{
	this->_size = 0;
}
template<typename T>
void Vector<T>::erase(iterator itr)
{
	int i;
	for (i = 0; i < this->_size; i++)
	{
		if (itr == &(arr[i]))
		{
			for (; i < this->_size - 1; i++)
			{
				arr[i] = arr[i + 1];
			}
			this->_size--;
			break;
		}
	}
}
template<typename T>
T* Vector<T>::end(void)
{
	return &(this->arr[_size]);
}
template<typename T>
T* Vector<T>::begin(void)
{
	return &(this->arr[0]);
}
template<typename T>
void  Vector<T>::pop_back(void)
{
	//buffer underflow
	if (this->_size <= 0)
		return;

	this->_size--;
}
template<typename T>
void  Vector<T>::push_back(T data)
{
	//buffer overflow
	if (this->_size >= this->_capacity)
		return;

	this->arr[this->_size++] = data;
}
template<typename T>
T& Vector<T>::operator[](int index)
{
	return this->arr[index];
}
template<typename T>
T  Vector<T>::operator[](int index)const
{
	return this->arr[index];
}
template<typename T>
Vector<T>& Vector<T>::operator= (const Vector<T>& ref)
{
	this->_size = ref._size;
	this->_capacity = ref._capacity;
	delete[] this->arr;
	this->arr = new T[this->_capacity];
	for (int i = 0; i < this->_size; i++)
	{
		this->arr[i] = ref.arr[i];
	}
	return *this;
}
template<typename T>
Vector<T>::Vector() :_size(0), _capacity(100), arr(nullptr)
{
	this->arr = new T[this->_capacity];
}
template<typename T>
Vector<T>::Vector(const Vector<T>& ref) : _size(ref._size), _capacity(ref._capacity), arr(nullptr)
{
	this->arr = new T[this->_capacity];
	for (int i = 0; i < this->_size; i++)
	{
		this->arr[i] = ref.arr[i];
	}
}
template<typename T>
Vector<T>::Vector(int capT) :_size(0), _capacity(capT), arr(nullptr)
{
	this->arr = new T[this->_capacity];
}
template<typename T>
Vector<T>::~Vector()
{
	delete[] this->arr;
}