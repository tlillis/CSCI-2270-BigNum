//Taylor's Personal Test File for the BigNum Assignment
//taylorjandrews@github.com

#include <iostream>
#include <cstdlib>
#include "BigNum.h"
#include <cstdio>
#include <cstdlib>
#include <signal.h>
#include <fstream>
#include <cstring>

using namespace std;
using namespace HW3;

int main()
{
	BigNum test = 99999;
	cout << "testing big num 99999 " 
		 << "with the int constructor" << endl;
	cout << test << endl << endl;
	
	BigNum test2 = (string) "0000894893458";
	cout << "testing big num 00008 with the string constructor" << endl;
	cout << test2 << endl << endl;
	
	BigNum test3 = test2;
	cout << "testing copy constructor on BigNum test2" << endl;
	cout << test3 << endl << endl;
	
	BigNum test4 = 99999;
	cout << "testing big num -99599 " 
		 << "with the int constructor" << endl;
	cout << test4 << endl << endl;
	
	BigNum test7 = 0
	BigNum test8 = 5;
	cout << test7 + test8 << endl;
	
	return 0;
}
