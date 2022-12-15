#pragma once
template <typename T>
class Iterator
{
public:
	T operator*(void);
	T* operator->(void);
	bool operator<=(const Iterator<T>& ref);
	bool operator<=(const T* ref);
	bool operator>=(const Iterator<T>& ref);
	bool operator>=(const T* ref);
	bool operator<(const Iterator<T>& ref);
	bool operator<(const T* ref);
	bool operator>(const Iterator<T>& ref);
	bool operator>(const T* ref);
	bool operator==(const Iterator<T>& ref);
	bool operator==(const T* ref);
	bool operator!=(const Iterator<T>& ref);
	bool operator!=(const T* ref);
	T* operator--(void);
	T* operator--(int a);
	T* operator++(void);
	T* operator++(int a);
	Iterator<T>& operator=(const Iterator<T>& ref);

	Iterator();
	Iterator(const Iterator<T>& ref);
	Iterator(T* m);
	~Iterator();
private:
	T* data;
};

