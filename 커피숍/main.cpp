#include "CoffeeController.h"

int main(void)
{
	CoffeeController coffController;
	int num = 0;
	while (true)
	{
		coffController.ShowMenu();
		cin >> num;
		coffController.SelectMenu(num);
	}
	return 0;
}