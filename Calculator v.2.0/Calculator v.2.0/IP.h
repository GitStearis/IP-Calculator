#pragma once
#include "Adress.h"
#include <string>
#include <iostream>

using namespace std;

class IP : public Adress
{
public:
	IP(string adress);

	void adressToInt();
	void adressCheck();
	void toConsole();

};

