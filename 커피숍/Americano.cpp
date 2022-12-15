#include "Americano.h"

Americano& Americano::operator=(const Americano& ref)
{
	Espresso::operator=(ref);
	return *this;
}

Americano::Americano()
	:Espresso()
{
}

Americano::Americano(const Americano& ref)
	:Espresso(ref)
{
}

Americano::Americano(string name, int price, int bean)
	:Espresso(name, price, bean)
{
}

Americano::~Americano()
{
}
