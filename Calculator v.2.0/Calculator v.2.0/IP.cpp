#include "IP.h"


IP::IP(string adress)
{
	setInput(adress);
	adressToInt();
	adressCheck();
}

void IP::adressToInt()
{
	int dotCounter = 0;
	int dotPosition[3] = {};
	string adress = getInput();

	for (unsigned int i = 0; i < adress.size(); i++)
	{
		if (adress[i] == '.')
		{
			dotPosition[dotCounter] = i;
			dotCounter++;
		}
	}
	if (dotCounter != 3)
		throw 20; //Неверное кол-во октетов

	for (unsigned int i = 1; i < OK_AMOUNT; i++)
	{
		//Пустой октет
		if (dotPosition[i] - 1 == dotPosition[i - 1]) 
			throw 50;
	}

	string buf = {};
	int currentPos = 0;
	for (unsigned int i = 0; i < OK_AMOUNT; i++)
	{
		buf = adress.substr(currentPos, dotPosition[i]);
		setOktet(i, stoi(buf));
		currentPos = dotPosition[i] + 1;
	}
}

void IP::adressCheck()
{

}

void IP::toConsole()
{
	cout << "IP: " << getInput() << endl;
}
