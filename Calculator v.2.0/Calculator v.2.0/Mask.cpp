#include "Mask.h"

#define NUM_RIGHT 9

Mask::Mask(string adress)
{
	setInput(adress);
	adressToInt();
	adressCheck();
}

void Mask::adressToInt()
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
		throw 21; //Неверное кол-во октетов

	for (unsigned int i = 1; i < OK_AMOUNT; i++)
	{
		//Пустой октет
		if (dotPosition[i] - 1 == dotPosition[i - 1])
			throw 51;
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

void Mask::adressCheck()
{
	for (unsigned int i = 1; i < OK_AMOUNT; i++)
	{
		if (getOktet(i) > getOktet(i - 1)) throw 3;
	}

	int rightOktets[NUM_RIGHT] = { 128, 192, 224, 240, 248, 252, 254, 255, 0 };
	for (unsigned int i = 0; i < OK_AMOUNT; i++)
	{
		int counter = 0;
		for (int k = 0; k < NUM_RIGHT; k++)
		{
			if (getOktet(i) != rightOktets[k])
			{
				counter++;
			}
		}
		if (counter != NUM_RIGHT - 1) throw 4;
	}
}

void Mask::toConsole()
{
	cout << "Mask: " << getInput() << endl;
}
