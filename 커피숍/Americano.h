#pragma once
#include "Espresso.h"
class Americano : public Espresso
{
public:
	Americano& operator=(const Americano& ref);
	Americano();
	Americano(const Americano& ref);
	Americano(string name, int price, int bean);
	virtual ~Americano();
};

