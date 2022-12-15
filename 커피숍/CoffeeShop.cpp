#include "CoffeeShop.h"
#include <Windows.h>	
#include <fstream>
#include <ctime>
#include <string>
#define MAX_FILE_SIZE 1024

void CoffeeShop::Open(void)
{
	system("cls");
	int price = 0;
	int bean = 0;
	int milk = 0;
	int choco = 0;
	cout << "[----OPEN----]" << endl;
	cout << "각 커피의 정보를 입력하세요." << endl;
	//Espresso
	cout << "[Espresso]" << endl;
	cout << "price:";
	cin >> price;
	cout << "bean:";
	cin >> bean;
	defEspresso.SetPrice(price);
	defEspresso.SetBean(bean);
	//Americano
	cout << "[Americano]" << endl;
	cout << "price:";
	cin >> price;
	cout << "bean:";
	cin >> bean;
	defAmericano.SetPrice(price);
	defAmericano.SetBean(bean);
	//CafeLate
	cout << "[CafeLate]" << endl;
	cout << "price:";
	cin >> price;
	cout << "bean:";
	cin >> bean;
	cout << "milk:";
	cin >> milk;
	defCafeLate.SetPrice(price);
	defCafeLate.SetBean(bean);
	defCafeLate.SetMilk(milk);
	//Moca
	cout << "[Moca]" << endl;
	cout << "price:";
	cin >> price;
	cout << "bean:";
	cin >> bean;
	cout << "milk:";
	cin >> milk;
	cout << "choco:";
	cin >> choco;
	defMoca.SetPrice(price);
	defMoca.SetBean(bean);
	defMoca.SetMilk(milk);
	defMoca.SetChoco(choco);

	system("cls");
	cout << "입력한 정보입니다." << endl;
	cout << "[Espresso]" << endl;
	defEspresso.GetInfor();
	cout << "[Americano]" << endl;
	defAmericano.GetInfor();
	cout << "[CafeLate]" << endl;
	defCafeLate.GetInfor();
	cout << "[Moca]" << endl;
	defMoca.GetInfor();
}

void CoffeeShop::Order(void)
{
	system("cls");
	string strNow = "";
	int select = 0;
	int num = 0;
	cout << "[----ORDER----]" << endl;
	cout << "주문할 커피를 선택하세요:" << endl;
	cout << E_Espresso << ". Espresso" << endl;
	cout << E_Americano << ". Americano" << endl;
	cout << E_CafeLate << ". CafeLate" << endl;
	cout << E_Moca << ". Moca" << endl;
	cin >> select;
	if (select <= E_NULL || select >= E_MAX)
	{
		cout << "잘못된 번호 입력" << endl;
		return;
	}
	cout << "주문할 갯수를 입력하세요:" << endl;
	cin >> num;
	if (num <= 0)
	{
		cout << "0개 이하로 주문 불가능" << endl;
		return;
	}
	GetCurrentDateTime(strNow);
	map<int, Coffee*> tmpMap;	//임시맵
	switch (select)
	{
	case E_Espresso:
		totalPrice += defEspresso.GetPrice() * num;
		totalBean += defEspresso.GetBean() * num;
		tmpMap[num] = new Espresso(defEspresso);
		break;
	case E_Americano:
		totalPrice += defAmericano.GetPrice() * num;
		totalBean += defAmericano.GetBean() * num;
		tmpMap[num] = new Americano(defAmericano);
		break;
	case E_CafeLate:
		totalPrice += defCafeLate.GetPrice() * num;
		totalBean += defCafeLate.GetBean() * num;
		totalMilk += defCafeLate.GetMilk() * num;
		tmpMap[num] = new CafeLate(defCafeLate);
		break;
	case E_Moca:
		totalPrice += defMoca.GetPrice() * num;
		totalBean += defMoca.GetBean() * num;
		totalMilk += defMoca.GetMilk() * num;
		totalChoco += defMoca.GetChoco() * num;
		tmpMap[num] = new Moca(defMoca);
		break;
	}
	this->coffees[strNow] = tmpMap;

	for (int i = 0; i < num; i++)
	{
		switch (select)
		{
		case E_Espresso:
			this->many.push_back(new Espresso(defEspresso));
			break;
		case E_Americano:
			this->many.push_back(new Americano(defAmericano));
			break;
		case E_CafeLate:
			this->many.push_back(new CafeLate(defCafeLate));
			break;
		case E_Moca:
			this->many.push_back(new Moca(defMoca));
			break;
		}
	}

	//커피를 만들고
	for (Vector<Coffee*>::iterator itr = this->many.begin(); itr != this->many.end(); itr++)
	{
		(*itr)->MakeCoffee();
	}

	//Vector의 데이터들 할당 해제, Vector clear
	for (Vector<Coffee*>::iterator itr = this->many.begin(); itr != this->many.end(); itr++)
	{
		delete (*itr);
	}
	many.clear();
}

void CoffeeShop::View(void)
{
	system("cls");
	cout << "[----VIEW----]" << endl;
	cout << "번호       이름       가격       개수       시간" << endl;
	int i = 1;
	for (map<string, map<int, Coffee*>>::iterator itr = coffees.begin(); itr != coffees.end(); itr++)
	{
		cout << i << "       " << itr->second.begin()->second->GetName() << "     " <<
			itr->second.begin()->second->GetPrice() << "원       " << itr->second.begin()->first << "       " << itr->first << endl;
		i++;
	}
}

void CoffeeShop::Close(void)
{
	system("cls");
	cout << "[----CLOSE----]" << endl;
	cout << "총 매출: " << totalPrice << "원" << endl;
	cout << "총 원두량: " << totalBean << "g" << endl;
	cout << "총 우유량: " << totalMilk << "g" << endl;
	cout << "총 초콜릿양: " << totalChoco << "g" << endl << endl;
	cout << "번호       이름       가격       개수       시간" << endl;
	int i = 1;
	for (map<string, map<int, Coffee*>>::iterator itr = coffees.begin(); itr != coffees.end(); itr++)
	{
		cout << i << "       " << itr->second.begin()->second->GetName() << "     " <<
			itr->second.begin()->second->GetPrice() << "원       " << itr->second.begin()->first << "       " << itr->first << endl;
		i++;
	}
	cout << "파일에 저장하시겠어요? y/n" << endl;
	char input = '\0';
	cin >> input;
	if (input != 'y' && input != 'Y')
	{
		cout << "메뉴로 돌아갑니다.." << endl;
		return;
	}
	char fileName[MAX_FILE_SIZE] = "";
	if (!SelectSaveFileName(fileName))
	{
		cout << "메뉴로 돌아갑니다.." << endl;
		return;
	}
	ofstream w;
	w.open(fileName);

	if (!w.is_open())
	{
		cout << "file write open error" << endl;
		return;
	}
	int j = 0;
	for (map<string, map<int, Coffee*>>::iterator itr = coffees.begin(); itr != coffees.end(); itr++)
	{
		string str = "";
		str.append(to_string(j));
		str.append("이름:");
		str.append(itr->second.begin()->second->GetName());
		str.append("  가격:");
		str.append(to_string(itr->second.begin()->second->GetPrice()));
		str.append("  개수:");
		str.append(to_string(itr->second.begin()->first));
		str.append("  시간:");
		str.append(itr->first);
		str.append("\n");
		w.write(str.c_str(), str.size());
		j++;
	}
	w.close();
}

void CoffeeShop::Exit(void)
{
	//Exit에서 할당 해제
	for (map<string, map<int, Coffee*>>::iterator itr = coffees.begin(); itr != coffees.end(); itr++)
	{
		delete (itr->second.begin()->second);
	}
	many.~Vector(); //소멸자 수동호출
	cout << "종료합니다..." << endl;
	exit(0);
}

CoffeeShop& CoffeeShop::operator=(const CoffeeShop& ref)
{
	this->many = ref.many;
	this->coffees = ref.coffees;
	this->defEspresso = ref.defEspresso;
	this->defAmericano = ref.defAmericano;
	this->defCafeLate = ref.defCafeLate;
	this->defMoca = ref.defMoca;
	return *this;
}

CoffeeShop::CoffeeShop()
	:many(), coffees(),
	defEspresso("Espresso", 1500, 11),
	defAmericano("Americano", 2500, 11),
	defCafeLate("CafeLate", 3500, 11, 20),
	defMoca("Moca", 4000, 11, 20, 5),
	totalBean(0), totalChoco(0), totalMilk(0), totalPrice(0)
{
	defEspresso.SetName("Espresso");
	defAmericano.SetName("Americano");
	defCafeLate.SetName("CafeLate");
	defMoca.SetName("Moca");
}

CoffeeShop::CoffeeShop(const CoffeeShop& ref)
	:many(ref.many), coffees(ref.coffees),
	defEspresso(ref.defEspresso), defAmericano(ref.defAmericano),
	defCafeLate(ref.defCafeLate), defMoca(ref.defMoca)
	, totalBean(ref.totalBean), totalChoco(ref.totalChoco), totalMilk(ref.totalMilk), totalPrice(ref.totalPrice)
{
	defEspresso.SetName("Espresso");
	defAmericano.SetName("Americano");
	defCafeLate.SetName("CafeLate");
	defMoca.SetName("Moca");
}

CoffeeShop::~CoffeeShop()
{
}

void CoffeeShop::GetCurrentDateTime(string& strNow)
{
	strNow.clear();
	time_t current = time(nullptr);
	tm now = { 0 };

	localtime_s(&now, &current);

	strNow.append(to_string(now.tm_year + 1900) + "-");
	strNow.append(to_string(now.tm_mon + 1) + "-");
	strNow.append(to_string(now.tm_mday) + " ");
	strNow.append(to_string(now.tm_hour) + ":");
	strNow.append(to_string(now.tm_min) + ":");
	strNow.append(to_string(now.tm_sec));
}

bool CoffeeShop::SelectSaveFileName(char* strFileName)
{
	bool result = false;

	OPENFILENAMEA of = { 0 };
	of.lStructSize = sizeof(of);
	of.nMaxFile = MAX_FILE_SIZE;
	of.lpstrInitialDir = ".";
	of.lpstrFilter = "all files(*.*)\0*.*\0*.txt\0*.txt\0";
	of.lpstrFile = strFileName;
	if (GetSaveFileNameA(&of))
		result = true;

	return result;
}
