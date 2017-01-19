#pragma once
#include "IP.h"
#include "Mask.h"
#include <iostream>
#include <string>

using namespace std;

class ID
{
private:
	unsigned int oktetHost[OK_AMOUNT];
	unsigned int oktetSubnet[OK_AMOUNT];

public:
	ID(Adress *ip, Adress *mask);
	void printHost();
	void printSubnet();
};

