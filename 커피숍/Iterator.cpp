#include "Iterator.h"

template <typename T>
T Iterator<T>::operator*(void)
{
	return *(this->data);
}
template <typename T>
T* Iterator<T>::operator->(void)
{
	return this->data;
}
template <typename T>
bool Iterator<T>::operator<=(const Iterator<T>& ref)
{
	return (this->data <= ref.data);
}
template <typename T>
bool Iterator<T>::operator<=(const T* ref)
{
	return (this->data <= ref);
}
template <typename T>
bool Iterator<T>::operator>=(const Iterator<T>& ref)
{
	return (this->data >= ref.data);
}
template <typename T>
bool Iterator<T>::operator>=(const T* ref)
{
	return (this->data >= ref);
}
template <typename T>
bool Iterator<T>::operator<(const Iterator<T>& ref)
{
	return (this->data < ref.data);
}
template <typename T>
bool Iterator<T>::operator<(const T* ref)
{
	return (this->data < ref);
}
template <typename T>
bool Iterator<T>::operator>(const Iterator<T>& ref)
{
	return (this->data > ref.data);
}
template <typename T>
bool Iterator<T>::operator>(const T* ref)
{
	return (this->data > ref);
}
template <typename T>
bool Iterator<T>::operator==(const Iterator<T>& ref)
{
	return (this->data == ref.data);
}
template <typename T>
bool Iterator<T>::operator==(const T* ref)
{
	return (this->data == ref);
}
template <typename T>
bool Iterator<T>::operator!=(const Iterator<T>& ref)
{
	return (this->data != ref.data);
}
template <typename T>
bool Iterator<T>::operator!=(const T* ref)
{
	return (this->data != ref);
}
template <typename T>
T* Iterator<T>::operator--(void)
{
	this->data--;
	return this->data;
}
template <typename T>
T* Iterator<T>::operator--(int a)
{
	T* d = this->data;
	this->data--;
	return d;
}
template <typename T>
T* Iterator<T>::operator++(void)
{
	this->data++;
	return this->data;
}
template <typename T>
T* Iterator<T>::operator++(int a)
{
	T* d = this->data;
	this->data++;
	return d;
}
template <typename T>
Iterator<T>& Iterator<T>::operator=(const Iterator<T>& ref)
{
	this->data = ref.data;
	return *this;
}
template <typename T>
Iterator<T>::Iterator() :data(nullptr) {}
template <typename T>
Iterator<T>::Iterator(const Iterator<T>& ref) : data(ref.data) {}
template <typename T>
Iterator<T>::Iterator(T* m) : data(m) {}
template <typename T>
Iterator<T>::~Iterator() {}