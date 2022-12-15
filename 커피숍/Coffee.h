#pragma once
#include <iostream>
#include <string>
using namespace std;

class Coffee abstract
{
public:
	virtual void GetInfor(void) const = 0;
	virtual void MakeCoffee() = 0;

	Coffee& operator=(const Coffee& ref);
	Coffee();
	Coffee(const Coffee& ref);
	Coffee(string name, int price, int bean);
	virtual ~Coffee();

	inline string GetName(void)const { return this->name; }
	inline void SetName(string name) { this->name = name; }
	inline int GetPrice(void)const { return this->price; }
	inline void SetPrice(int price) { this->price = price; }
	inline int GetBean(void)const { return this->bean; }
	inline void SetBean(int bean) { this->bean = bean; }
protected:
	string name;
	int price;
	int bean;
};

