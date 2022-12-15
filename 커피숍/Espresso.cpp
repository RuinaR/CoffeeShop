#include "Espresso.h"

void Espresso::GetInfor(void) const
{
	cout << "커피이름: " << this->name << endl;
	cout << "가격(원): " << this->price << endl;
	cout << "원두량: " << this->bean << endl;
}

void Espresso::MakeCoffee()
{
	cout << this->name << "(을)를 만들고 있습니다. " << endl;
}

Espresso& Espresso::operator=(const Espresso& ref)
{
	Coffee::operator=(ref);
	return *this;
}

Espresso::Espresso()
	:Coffee()
{
}

Espresso::Espresso(const Espresso& ref)
	:Coffee(ref)
{
}

Espresso::Espresso(string name, int price, int bean)
	:Coffee(name, price, bean)
{
}

Espresso::~Espresso()
{
}
