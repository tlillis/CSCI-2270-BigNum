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
	
	BigNum test3 = test2;
	cout << "testing copy constructor on BigNum test2" << endl;
	test3.printDigits();
	
	BigNum test4 = -99599;
	cout << "testing big num -99599 " 
		 << "with the int constructor" << endl;
	test4.printDigits();
	
	test2 = test2;
	cout << "testing = operator on test2 = test 2 (prints test2)" << endl;
	test3.printDigits();
	
	test2 = test4;
	cout << "testing = operator on test2 = test 4 (prints test2)" << endl;
	test4.printDigits();
	
	BigNum test5 = 10;
	test5 + test4;
	test5.printDigits();
	
	BigNum test6;
	cin >> test6;
	test6.printDigits();
	
	return 0;
}
