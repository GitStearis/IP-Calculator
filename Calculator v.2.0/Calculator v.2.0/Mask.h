#pragma once

#include "Adress.h"
#include <string>
#include <iostream>

using namespace std;

class Mask : public Adress
{
public:
	Mask(string adress);

	void adressToInt();
	void adressCheck();
	void toConsole();
};

