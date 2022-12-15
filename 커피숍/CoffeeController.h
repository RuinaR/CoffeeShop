#pragma once
#include "Command.h"
#include <map>
#include "CoffeeShop.h"

class CoffeeController
{
public:
	enum class MENU
	{
		E_NULL,
		E_Open,
		E_Order,
		E_View,
		E_Close,
		E_EXIT,
		E_MAX
	};

	CoffeeController(CoffeeShop* m);
	CoffeeController();
	~CoffeeController();
	void ShowMenu(void) const;
	void SelectMenu(int number);

private:
	map<MENU, Command*> menuMap;
	CoffeeShop* controller;
};

