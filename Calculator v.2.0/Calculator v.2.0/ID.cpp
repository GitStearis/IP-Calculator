#include "ID.h"


ID::ID(Adress *ip, Adress *mask)
{
	for (unsigned int i = 0; i < OK_AMOUNT; i++)
	{
		oktetHost[i] = ip->getOktet(i) & ~mask->getOktet(i);
		oktetSubnet[i] = ip->getOktet(i) & mask->getOktet(i);
	}

}

void ID::printHost()
{
	cout << "HOST ID: ";
	for (unsigned int i = 0; i < OK_AMOUNT; i++)
	{
		if (i != 3) 
			cout << oktetHost[i] << ".";
		else 
			cout << oktetHost[i] << endl;
	}
}

void ID::printSubnet()
{
	cout << "SUBNET ID: ";
	for (unsigned int i = 0; i < OK_AMOUNT; i++)
	{
		if (i != 3)
			cout << oktetSubnet[i] << ".";
		else
			cout << oktetSubnet[i] << endl;
	}
}
