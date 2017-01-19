#include "Adress.h"


Adress::Adress()
{
	this->input = {" "};
	for (int i = 0; i < OK_AMOUNT; i++)
		oktet[i] = 0;
}

void Adress::setInput(string inp)
{
	this->input = inp;
}

void Adress::setOktet(int index, int value)
{
	if (value >= 0 && value < 256)
		this->oktet[index] = value;
	else
		throw 0;//Ќеверное значение одного из октетов
}

string Adress::getInput()
{
	return this->input;
}

int Adress::getOktet(int index)
{
	if (index >= 0 && index <= OK_AMOUNT)
		return oktet[index];
	else
	throw 1; //ѕопытка вернуть несуществующий октет
}
