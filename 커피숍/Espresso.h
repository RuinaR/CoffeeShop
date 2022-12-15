#pragma once
#include "Coffee.h"
class Espresso :public Coffee
{
public:
	void GetInfor(void) const override;
	void MakeCoffee() override;

	Espresso& operator=(const Espresso& ref);
	Espresso();
	Espresso(const Espresso& ref);
	Espresso(string name, int price, int bean);
	virtual ~Espresso();
};

