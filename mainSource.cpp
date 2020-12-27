# include <iostream>
# include "libHeader.h"
#include <cstring>
#include <fstream>
using namespace std;

void mMenu();
bool mine();

int main()
{
	bool init = mine();
	if (init == false)
	{
		mMenu();
	}
	return 0;
}

void mMenu()
{
	vecThreeD vec1;
	while (true)
	{
		char input1;
		cout << "[a] Display 3D vectors." << endl;
		cout << "[b] Enter 3D vectors." << endl;
		cout << "[c] Compare 3D vectors." << endl;
		cout << "[d] Calculate arctan." << endl;
		cout << "[e] To exit." << endl;
		cout << "Key in your choice(a, b, c, d or e): ";
		cin >> input1;
		if (input1 == 'a')
		{
			vec1.display();
		}
		else if (input1 == 'b')
		{
			float i, j, k;
			cout << "In ai + bj + ck" << endl;
			cout << "Enter a: ";
			cin >> i;
			cout << "Enter b: ";
			cin >> j;
			cout << "Enter c: ";
			cin >> k;
			vec1.enter(i, j, k);
			vec1.display();
		}
		else if (input1 == 'c')
		{
			float com1, com2, com3;
			int ret;
			cout << "For comparison, enter the vector in di + ej + fk" << endl;
			cout << "Enter d: ";
			cin >> com1;
			cout << "Enter e: ";
			cin >> com2;
			cout << "Enter f: ";
			cin >> com3;
			ret = vec1.compare(com1, com2, com3);
			cout << "The return value is " << ret << endl;

		}
		else if (input1 == 'd')
		{
			double azi;
			azi = vec1.azimuth();
			cout << "Azimuth is " << azi << endl;
		}
		else if (input1 == 'e')
		{
			cout << "Exiting the function." << endl;
			break;
		}
		else
		{
			cout << "Wrong input! Please give a valid response." << endl;
		}
	}
}
bool mine()
{
	char iname[50], ipass[50];	//arrays to hold username and password

	ifstream fi;
	fi.open("password.txt", ios::app);
	if (!fi)
	{
		cerr << "File opening error. Closing the program..." << endl;
		return true;
	};
	cout << "Enter UserName = ";
	cin.getline(iname, 50); char uname[50], upass[50];
	while (fi.good())
	{
		if (strcmp(iname, uname) == 0) //user name correct
		{
			cout << "You have three tries" << endl;
			int attempts = 0;
			while (attempts < 3) {
				cout << "\n" << endl;
				cout << "Enter Password = ";
				cin.getline(ipass, 50);
				cout << "\n";
				if (strcmp(ipass, upass) == 0) {
					cout << "Successful Login!\n";
					bool newuser = false;
					return newuser;
					break;
				}
				else {
					cout << "incorrect password. Try again." << endl;
					attempts++;
				}
			} if (attempts = 3) {
				fi.close();
				cout << "Three tries are over. Closing the program..." << endl;
				return true;
			}
		}
		else if (strcmp(iname, uname) != 0) {
			cout << "Please enter new password: " << endl;
			cin.getline(ipass, 50);
			ofstream fo;
			fo.open("password.txt", ios::app);	//use append mode to add two more lines
			fo << iname << endl << ipass << endl; //stores inside file
			fo.close();
			cout << "New account created.\n";
			bool newuser = false;
			return newuser;
		}

	}
}