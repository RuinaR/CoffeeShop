#include "CoffeeController.h"
#include "SimpleCommand.h"
#include "SimpleCommand.cpp"
#include <iostream>
using namespace std;

CoffeeController::CoffeeController(CoffeeShop* m)
	:controller(m),menuMap()
{
	menuMap.insert(pair<MENU, Command*>(MENU::E_Open,
		new SimpleCommand<CoffeeShop>
		(controller, &CoffeeShop::Open)));
	menuMap.insert(pair<MENU, Command*>(MENU::E_Order,
		new SimpleCommand<CoffeeShop>
		(controller, &CoffeeShop::Order)));
	menuMap.insert(pair<MENU, Command*>(MENU::E_View,
		new SimpleCommand<CoffeeShop>
		(controller, &CoffeeShop::View)));
	menuMap.insert(pair<MENU, Command*>(MENU::E_Close,
		new SimpleCommand<CoffeeShop>
		(controller, &CoffeeShop::Close)));
	menuMap.insert(pair<MENU, Command*>(MENU::E_EXIT,
		new SimpleCommand<CoffeeShop>
		(controller, &CoffeeShop::Exit)));
}

CoffeeController::CoffeeController()
	:controller(nullptr), menuMap()
{
	controller = new CoffeeShop();
	menuMap.insert(pair<MENU, Command*>(MENU::E_Open,
		new SimpleCommand<CoffeeShop>
		(controller, &CoffeeShop::Open)));
	menuMap.insert(pair<MENU, Command*>(MENU::E_Order,
		new SimpleCommand<CoffeeShop>
		(controller, &CoffeeShop::Order)));
	menuMap.insert(pair<MENU, Command*>(MENU::E_View,
		new SimpleCommand<CoffeeShop>
		(controller, &CoffeeShop::View)));
	menuMap.insert(pair<MENU, Command*>(MENU::E_Close,
		new SimpleCommand<CoffeeShop>
		(controller, &CoffeeShop::Close)));
	menuMap.insert(pair<MENU, Command*>(MENU::E_EXIT,
		new SimpleCommand<CoffeeShop>
		(controller, &CoffeeShop::Exit)));
}

CoffeeController::~CoffeeController()
{
	//소멸자에서 할당해제
	for (map<MENU, Command*>::iterator iter = menuMap.begin(); iter != menuMap.end(); iter++)
	{
		delete((*iter).second);
	}
	delete controller;	
}

void CoffeeController::ShowMenu(void) const
{
	cout << "-----커피숍-----" << endl;
	cout << "1. OPEN" << endl;
	cout << "2. ORDER" << endl;
	cout << "3. VIEW" << endl;
	cout << "4. CLOSE" << endl;
	cout << "5. EXIT" << endl;
	cout << ">>";
}

void CoffeeController::SelectMenu(int number)
{
	system("cls");
	if (number <= (int)MENU::E_NULL || number >= (int)MENU::E_MAX)
	{
		cout << "잘못된 번호를 입력해서 메뉴로 돌아갑니다." << endl;
		return;
	}
	this->menuMap[(MENU)number]->Execute();
}
