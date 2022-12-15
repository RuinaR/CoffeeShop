#include "CafeLate.h"

void CafeLate::GetInfor(void) const
{
	Espresso::GetInfor();
	cout << "¿ìÀ¯·®: " << this->milk << endl;
}

CafeLate& CafeLate::operator=(const CafeLate& ref)
{
	Espresso::operator=(ref);
	this->milk = ref.milk;
	return *this;
}

CafeLate::CafeLate()
	:Espresso(), milk(0)
{
}

CafeLate::CafeLate(const CafeLate& ref)
	:Espresso(ref), milk(ref.milk)
{
}

CafeLate::CafeLate(string name, int price, int bean, int milk)
	:Espresso(name, price, bean), milk(milk)
{
}

CafeLate::~CafeLate()
{
}
