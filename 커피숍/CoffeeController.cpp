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
	//�Ҹ��ڿ��� �Ҵ�����
	for (map<MENU, Command*>::iterator iter = menuMap.begin(); iter != menuMap.end(); iter++)
	{
		delete((*iter).second);
	}
	delete controller;	
}

void CoffeeController::ShowMenu(void) const
{
	cout << "-----Ŀ�Ǽ�-----" << endl;
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
		cout << "�߸��� ��ȣ�� �Է��ؼ� �޴��� ���ư��ϴ�." << endl;
		return;
	}
	this->menuMap[(MENU)number]->Execute();
}
