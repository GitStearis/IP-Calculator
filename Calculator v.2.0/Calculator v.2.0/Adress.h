#pragma once

#include <string>

using namespace std;

#define OK_AMOUNT 4

class Adress
{
private:
	string input;
	unsigned int oktet[OK_AMOUNT];

protected:
	void setInput(string inp);
	void setOktet(int index, int value);

public:
	Adress();

	string getInput();
	int getOktet(int index);
	
	virtual void toConsole() = 0;
};

