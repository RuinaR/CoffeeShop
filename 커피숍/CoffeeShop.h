#pragma once
#include "Coffee.h"
#include "Espresso.h"
#include "Americano.h"
#include "CafeLate.h"
#include "Moca.h"
#include "Vector.h"
#include "Vector.cpp"
#include <map>

class CoffeeShop
{
public:
	enum
	{
		E_NULL = 0,
		E_Espresso,
		E_Americano,
		E_CafeLate,
		E_Moca,
		E_MAX
	};

	void Open(void);
	void Order(void);
	void View(void);
	void Close(void);
	void Exit(void);

	CoffeeShop& operator=(const CoffeeShop& ref);
	CoffeeShop();
	CoffeeShop(const CoffeeShop& ref);
	~CoffeeShop();
private:
	void GetCurrentDateTime(string& strNow);
	bool SelectSaveFileName(char* strFileName);

	Espresso defEspresso;
	Americano defAmericano;
	CafeLate defCafeLate;
	Moca defMoca;

	int totalPrice;
	int totalBean;
	int totalMilk;
	int totalChoco;

	Vector<Coffee*> many;
	map<string, map<int, Coffee*>> coffees;
};

