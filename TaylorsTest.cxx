

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
	
	BigNum test4 = -99599;
	cout << "testing big num -99599 " 
		 << "with the int constructor" << endl;
	cout << test4 << endl << endl;
	
	BigNum test2 = (string) "0000894893458";
	cout << "testing big num 00008 with the string constructor" << endl;
	cout << test2 << endl << endl;
	
	BigNum test3 = test2;
	cout << "testing copy constructor on BigNum test2" << endl;
	cout << test3 << endl << endl;
	
	BigNum test7 = (string) "-98765432135135135465461315313543546546545616516168464";
	BigNum test8 = (string) "-100000";
	BigNum test9 = test7 + test8;
	cout << "Testing addition"  << endl;
	cout << test7 << " + " << test8 << " = " << endl << test9 << endl << endl;
	
	BigNum test10 = (string) "98765432135135135465461315313543546546545616516168464";
	BigNum test11 = (string) "100000";
	BigNum test12 = test10 - test11;
	cout << "Testing subtraction"  << endl;
	cout << test10 << " - " << test11 << " = " << endl << test12 << endl << endl;

	BigNum test13 = (string) "1111111111111111111111111111111111111111111";
	BigNum test14 = (string) "1111111111111111111111111111111111111111111";
	BigNum test15 = test13 * test14;
	cout << "Testing multiplication"  << endl;
	cout << test13 << " * " << test14 << " = " << test15 << endl << endl;

	BigNum n = 123456;
	BigNum m = 987654;
	
	cout << n * m << endl;
	
	BigNum test16 = (string) "100";
	BigNum test17 = factorial(test16);
	cout << "Testing Factorial"  << endl;
	cout << test16 << "! = " << test17 << endl << endl;
	
	return 0;
}
