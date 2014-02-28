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
	BigNum test = 90;
	test.printDigits();
	
	BigNum test2 = (string) "00008";
	test2.printDigits();
	
	return 0;
}
