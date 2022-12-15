#include "Espresso.h"

void Espresso::GetInfor(void) const
{
	cout << "Ŀ���̸�: " << this->name << endl;
	cout << "����(��): " << this->price << endl;
	cout << "���η�: " << this->bean << endl;
}

void Espresso::MakeCoffee()
{
	cout << this->name << "(��)�� ����� �ֽ��ϴ�. " << endl;
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
