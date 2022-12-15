#include "Coffee.h"

Coffee& Coffee::operator=(const Coffee& ref)
{
	this->name = ref.name;
	this->price = ref.price;
	this->bean = ref.bean;
	return *this;
}

Coffee::Coffee()
	:name("Coffee"), price(0), bean(0)
{
}

Coffee::Coffee(const Coffee& ref)
	:name(ref.name), price(ref.price), bean(ref.bean)
{
}

Coffee::Coffee(string name, int price, int bean)
	:name(name), price(price), bean(bean)
{
}

Coffee::~Coffee()
{
}


