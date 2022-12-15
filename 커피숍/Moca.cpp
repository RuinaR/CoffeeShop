#include "Moca.h"

void Moca::GetInfor(void) const
{
	CafeLate::GetInfor();
	cout << "ÃÊÄÝ¸´¾ç: " << this->choco << endl;
}

Moca& Moca::operator=(const Moca& ref)
{
	CafeLate::operator=(ref);
	this->choco = ref.choco;
	return *this;
}

Moca::Moca()
	:CafeLate(), choco(0)
{
}

Moca::Moca(const Moca& ref)
	:CafeLate(ref), choco(ref.choco)
{
}

Moca::Moca(string name, int price, int bean, int milk, int choco)
	:CafeLate(name, price, bean, milk), choco(choco)
{
}

Moca::~Moca()
{
}
