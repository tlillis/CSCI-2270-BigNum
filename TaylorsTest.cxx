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
	test.printDigits();
	
	BigNum test2 = (string) "00008";
	cout << "testing big num 00008 with the string constructor" << endl;
	test2.printDigits();
	
	return 0;
}
