#pragma once
#include "CafeLate.h"
class Moca : public CafeLate
{
public:
	void GetInfor(void) const override;

	Moca& operator=(const Moca& ref);
	Moca();
	Moca(const Moca& ref);
	Moca(string name, int price, int bean, int milk, int choco);
	virtual ~Moca();

	inline int GetChoco(void) const { return this->choco; }
	inline void SetChoco(int choco) { this->choco = choco; }
protected:
	int choco;
};

