#pragma once
#include "Espresso.h"
class CafeLate :public Espresso
{
public:
	void GetInfor(void) const override;

	CafeLate& operator=(const CafeLate& ref);
	CafeLate();
	CafeLate(const CafeLate& ref);
	CafeLate(string name, int price, int bean, int milk);
	virtual ~CafeLate();

	inline int GetMilk(void) const { return this->milk; }
	inline void SetMilk(int milk) { this->milk = milk; }
protected:
	int milk;
};

