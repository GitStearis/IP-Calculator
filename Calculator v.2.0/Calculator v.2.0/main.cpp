#include <iostream>
#include "Adress.h"
#include "IP.h"
#include "Mask.h"
#include "ID.h"

using namespace std;

void main()
{


	try
	{
		string input = {};

		cout << "ENTER IP ADRESS: ";
		cin >> input;
		Adress *ip = new IP(input);

		cout << "ENTER SUBNET MASK: ";
		cin >> input;
		Adress *mask = new Mask(input);

		cout << "\n\n";
		ip->toConsole();
		mask->toConsole();

		ID id(ip, mask);
		id.printSubnet();
		id.printHost();
	}
	catch (int error)
	{
		switch (error)
		{
		case 0: 
		{
			cout << "Wrong value of an oktet." << endl;
			cout << "Code - " << error << endl;  break;
		}
		case 1:
		{
			cout << "Programm tried to return an oktet that doesn't exist." << endl;
			cout << "Code - " << error << endl;  break;
		}
		case 20:
		{
			cout << "Wrong amount of oktets in IP." << endl;
			cout << "Code - " << error << endl;  break;
		}
		case 21:
		{
			cout << "Wrong amount of oktets in Mask." << endl;
			cout << "Code - " << error << endl;  break;
		}
		case 3: 
		{
			cout << "Wrong mask - one oktet is bigger than previous one." << endl;
			cout << "Code - " << error << endl;  break;
		}
		case 4:
		{
			cout << "Wrong mask - incorrect value of an oktet." << endl;
			cout << "Code - " << error << endl;  break;
		}
		case 50:
		{
			cout << "Wrong IP - there is an empty oktet." << endl;
			cout << "Code - " << error << endl;  break;
		}
		case 51:
		{
			cout << "Wrong mask - there is an empty oktet." << endl;
			cout << "Code - " << error << endl;  break;
		}
		}
	}
}