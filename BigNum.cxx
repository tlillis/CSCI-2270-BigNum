// FILENAME: BigNum.cxx
// This is the implementation file of the BigNum class


#ifndef HW3_BIGNUM_CXX
#define HW3_BIGNUM_CXX
#include <algorithm>   // Provides copy function
#include <cstdlib>
#include <iostream>
#include <string>
#include <cstring>
#include <cassert>
#include "BigNum.h"

using namespace std;

namespace HW3
{
	BigNum::BigNum()
	{	
		capacity = DEFAULT_CAPACITY;
		digits = new unsigned int[capacity];
		positive = true;
		
		digits[0] = 0;
		used = 1;
	}    

	BigNum::BigNum(int num)
	{
		capacity = DEFAULT_CAPACITY;
		digits = new unsigned int[capacity];
		unsigned int i = 0, rem = 0;
		used = 0;
		
		if (num >= 0)
			positive = true;
		else
		{
			positive = false;
			num *= -1;
		}
		
		do 
		{	
			rem = num % 10;
			num /= 10;
			
			if(used == capacity)
			{
				resize(capacity * 2);
			}
			
			digits[i] = rem;
			
			i++;
			used++;
			
		} while (num != 0);
		
		trim();
	}

	// Constructor that receives a string; leading 0's will be ignored
	BigNum::BigNum(const string& str)
	{
		capacity = DEFAULT_CAPACITY;
		digits = new unsigned int[capacity];
		
		unsigned int i = 0, k = 0, val = 0;
		used = 0;
		
		if (str.substr(0,1).compare("-") == 0)
		{
			positive = false;
			i = 1;
		}
		else
		{
			positive = true;
		}
		
		while(i < str.size())
		{
			if(used == capacity)
			{
				resize(capacity * 2);
			}
			
			val = atoll((str.substr(str.size()- i - positive, 1)).c_str());
			digits[k] = val;
			
			k++;
			i++;
			used++;
		}
		
		trim();
	}
 
    BigNum::BigNum(const BigNum& anotherBigNum)
    {
		used = anotherBigNum.used;
		capacity = anotherBigNum.capacity;
		positive = anotherBigNum.positive;
		
		digits = new unsigned int[capacity];
		
		for (unsigned int i = 0; i < used; i++)
		{
			digits[i] = anotherBigNum.digits[i];
		}
		
		trim();
    }

    BigNum::~BigNum()
    {
		delete [] digits;
    }
    
    //helper method for Taylors Test
    //should probably be removed (don't forget the header file)
    void BigNum::printDigits()
    {
		if (!positive)
			cout << "-";
		for (unsigned int i = 0; i < used; i++)
		{			
			cout << digits[used - i - 1];
		}
		cout << endl << endl;
	}
    
    void BigNum::resize(unsigned int n)
	{
		unsigned int* newDigits = new unsigned int[n];
	
		copy(digits, digits + capacity, newDigits);
		
		delete[] digits;

		digits = newDigits;	
		capacity = n;
	}

	BigNum& BigNum::operator=(const BigNum& anotherBigNum)
	{
		if(&anotherBigNum == this)
		{
			return *this;
		}
		else
		{
			delete [] digits;
			capacity = anotherBigNum.capacity;
			used = anotherBigNum.used;
			positive = anotherBigNum.positive;
			
			digits = new unsigned int[capacity];
			
			for (unsigned int i = 0; i < used; i++)
			{
				digits[i] = anotherBigNum.digits[i];
			}
		}		
		
		return *this;
	}

  	BigNum& BigNum::operator+=(const BigNum& addend)  
	{
		*this = *this + addend;
		return *this;
	}

	BigNum& BigNum::operator-=(const BigNum& subtractand)
	{
		*this = *this - subtractand;
		return *this;
	}

	BigNum& BigNum::operator*=(const BigNum& multiplicand)
	{
		*this = *this * multiplicand;
		return *this;
	}
	
	/*
	BigNum& BigNum::operator/=(const BigNum& divisor)
	{
		return *this;
	}

	BigNum& BigNum::operator%=(const BigNum& divisor)
	{
		return *this;
	}
	*/

	BigNum& BigNum::operator++()
	{
		return (*this += 1);
	}

	BigNum& BigNum::operator--()
	{
		return (*this -= 1);
	}
	

	BigNum& BigNum::diff(const BigNum& a, const BigNum& b)
	{
		return *this;
	}

	BigNum& BigNum::mult(const BigNum& a, const BigNum& b)
	{
		return *this;
	}
	
	BigNum& BigNum::sum(const BigNum& a, const BigNum& b) 
	{
		return *this;
	}
	
	
	BigNum operator+(const BigNum& a, const BigNum& b)
	{
		BigNum result = 5;
		return result;
	}

	BigNum operator-(const BigNum& a, const BigNum& b)
	{
		BigNum result;
		return result;
	}
      
	BigNum operator*(const BigNum& a, const BigNum& b)
	{
		BigNum result;
		return result;
	}
	
	/*
	BigNum operator / (const BigNum& a, const BigNum& b)
	{
		BigNum result;
		return result;
	}


	BigNum operator%(const BigNum& a, const BigNum& b)
	{
		BigNum result;
		return result;
	}
	*/

	bool operator>(const BigNum& a, const BigNum& b)
	{
		return true;
	}


	bool operator>=(const BigNum& a, const BigNum& b)
	{
		return true;
	}


	bool operator<(const BigNum& a, const BigNum& b)
	{
		return true;
	}


	bool operator<=(const BigNum& a, const BigNum& b)
	{
		return true;
	}


	bool operator==(const BigNum& a, const BigNum& b)
	{
		return true;
	}


	bool operator!=(const BigNum& a, const BigNum& b)
	{
		return true;
	}

	// trim leading zeros
	void BigNum::trim()
	{
		bool zero = false;
		
		if (digits[used - 1] == 0)
			zero = true;
		
		while(zero)
		{
			used--;
			if(digits[used - 1] != 0)
				zero = false;
		}
	}
	
	
	std::ostream& operator<<(std::ostream &os, const BigNum& bignum)
	{
		return os;
	}	 

	std::istream& operator>>(std::istream &is, BigNum& bignum)
	{
		string in = "";
		is >> in;
		bignum = (string) in;
		
		return is;
	}
	
	/*
	BigNum factorial(const BigNum& a)
	{
		BigNum result;
		return result;
    }
    */
  }



#endif



