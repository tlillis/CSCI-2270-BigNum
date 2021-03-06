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
	//Constructors
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
		
		if(num == 0)
		{
			digits[0] = 0;
			used = 1;
		}
		else 
		{
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
		else if (str.substr(0,1).compare("+") == 0)
		{
			positive = true;
			i = 1;
		}
		if (i == 1)
		{
			while(i < str.size())
			{
				if(used == capacity)
				{
					resize(capacity * 2);
				}
				
				val = atoll((str.substr((str.size()-i), 1)).c_str());
				digits[k] = val;
				
				k++;
				i++;
				used++;
			}
		}
		else
		{
			positive = true;
			while(i < str.size())
			{
				if(used == capacity)
				{
					resize(capacity * 2);
				}
				
				val = atoll((str.substr((str.size()-i-1), 1)).c_str());
				digits[k] = val;
				
				k++;
				i++;
				used++;
			}
		}
		
		if(str.compare("0") != 0)
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
    
    void BigNum::resize(unsigned int n)
	{
		if (n > capacity)
		{
			unsigned int* newDigits = new unsigned int[n];
		
			copy(digits, digits + capacity, newDigits);
			
			delete[] digits;

			digits = newDigits;	
			capacity = n;
		}
	}

	//Operators with =
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
	
	
	BigNum& BigNum::operator/=(const BigNum& divisor)
	{
		return *this;
	}

	BigNum& BigNum::operator%=(const BigNum& divisor)
	{
		return *this;
	}
	
	
	//Incrementers
	BigNum& BigNum::operator++()
	{
		return (*this += 1);
	}

	BigNum& BigNum::operator--()
	{
		return (*this -= 1);
	}
	
	//Helper methods
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
	
	//friend functions for +,-,*
	BigNum operator+(const BigNum& a, const BigNum& b)
	{	
		BigNum result = 0, zero = 0;
		int hold = 0;

		//checks if either BigNum is 0
		if((a == zero) && (b == zero))
			return result;

		else if (a == zero)
		{
			result = b;
			return result;
		}

		else if (b == zero)
		{
			result = a;
			return result;
		}

		//sets result's sign to be positive or negative based on which 
		//  BigNum is bigger, also sets results capacity to be large as possible
		if (a.positive && b.positive)
		{
			result.positive = true;

			if(a > b)
				result.resize(a.used + 1);
			else
				result.resize(b.used + 1);
		}

		else if (!a.positive && !b.positive)
		{
			result.positive = false;

			if(a > b)
				result.resize(b.used + 1);
			else
				result.resize(a.used + 1);
		}		
		else 
		{
			BigNum aPos = a, bPos = b;
			aPos.positive = true;
			bPos.positive = true;

			if (aPos > bPos) 
			{
				result.positive = a.positive;
				result.resize(a.used + 1);
			}
			else if (bPos > aPos)
			{
				result.positive = b.positive;
				result.resize(b.used + 1);
			}
			else
				return result;
		}
		
		if((a.positive == 1) && (b.positive == 1))
		{
			
			bool borrowedFrom = false;

			for(unsigned int i = 0; i < result.capacity; i++)
			{				
				//increased the count of digits stored
				if ((i < a.used) || (i < b.used) || (hold != 0))
					result.used++;

				//if there are still digits in a or b to add, add them
				if(i < a.used)
					hold += a.digits[i] * (a.positive * 2 - 1);
				if(i < b.used)
					hold += b.digits[i] * (b.positive * 2 - 1);

				if (hold < 0)
				{
					borrowedFrom = true;
					hold += 10;
				}

				result.digits[i] = hold % 10;
				hold /= 10;

				if(borrowedFrom)
				{
					borrowedFrom = false;
					hold -= 1;
				}
			}
		}
		else if (a.positive != b.positive)
		{
			bool borrowedFrom = false;

			BigNum aPos = a, bPos = b;
			aPos.positive = true;
			bPos.positive = true;

			if((aPos > bPos) && !a.positive)
			{
				bPos.positive = a.positive;
				aPos.positive = b.positive;
			}
			else if ((bPos > aPos) && !b.positive)
			{
				bPos.positive = a.positive;
				aPos.positive = b.positive;
			}
			else
			{
				aPos.positive = a.positive;
				bPos.positive = b.positive;
			}

			for(unsigned int i = 0; i < result.capacity; i++)
			{				
				//increased the count of digits stored
				if ((i < aPos.used) || (i < bPos.used) || (hold != 0))
					result.used++;

				//if there are still digits in a or b to add, add them
				if(i < aPos.used)
					hold += aPos.digits[i] * (aPos.positive * 2 - 1);
				if(i < bPos.used)
					hold += bPos.digits[i] * (bPos.positive * 2 - 1);

				if (hold < 0)
				{
					borrowedFrom = true;
					hold += 10;
				}

				result.digits[i] = hold % 10;
				hold /= 10;

				if(borrowedFrom)
				{
					borrowedFrom = false;
					hold -= 1;
				}
			}
		}
		else
		{
			bool borrowedFrom = false;

			for(unsigned int i = 0; i < result.capacity; i++)
			{				
				//increased the count of digits stored
				if ((i < a.used) || (i < b.used) || (hold != 0))
					result.used++;

				//if there are still digits in a or b to add, add them
				if(i < a.used)
					hold -= a.digits[i] * (a.positive * 2 - 1);
				if(i < b.used)
					hold -= b.digits[i] * (b.positive * 2 - 1);

				if (hold < 0)
				{
					borrowedFrom = true;
					hold += 10;
				}

				result.digits[i] = hold % 10;
				hold /= 10;

				if(borrowedFrom)
				{
					borrowedFrom = false;
					hold -= 1;
				}
			}
		}
		result.trim();
		return result;
	}
	
	BigNum operator-(const BigNum& a, const BigNum& b)
	{
		BigNum result, negative = -1;
		if((a == 0) && (b == 0))
			return result;
		if(a == 0)
		{
			result = b;
			result.positive = !result.positive;
			return result;
		}
		if(b == 0)
		{
			result = a;
			return result;
		}
		result = a + (b * negative);
		return result;
	}
      
	BigNum operator*(const BigNum& a, const BigNum& b)
	{
		BigNum negative = -1, zero = 0, ten = 10, one = 1;
		BigNum result;
		BigNum hold;
					
		//checks if either one is zero, in which case the answer will be 0
		if ((a == zero) || (b == zero))
			result = 0;
		//check for multiplication by -1
		else if (a == negative)
		{
			result = b;
			result.resize(result.capacity * 2);
			result.positive = (b.positive == a.positive);
		}
		else if (b == negative)
		{
			result = a;
			result.resize(result.capacity * 2);
			result.positive = (b.positive == a.positive);
		}
		//check for multiplication by 10
		else if(a == ten)
		{
			result = b;
			result.resize(a.used + b.used);
			for(unsigned int i = 0; i < result.used; i++)
			{
				result.digits[result.used - i] = result.digits[result.used - i - 1];
			}
			result.digits[0] = 0;
			result.used++;
		}			
		else if(b == ten)
		{
			result = a;
			result.resize(a.used + b.used);
			for(unsigned int i = 0; i < result.used; i++)
			{
				result.digits[result.used - i] = result.digits[result.used - i - 1];
			}
			result.digits[0] = 0;
			result.used++;
		}	
		//check if the bignums are just one digit long
		else if(a.used == 1 && b.used == 1)
		{
			result.resize(result.capacity * 2);
			result = a.digits[0] * b.digits[0];
		}	
		else
		{
			for (unsigned int k = 0; k < a.used; k++)
			{
				result *= ten;
				hold = a.digits[a.used - k - 1];
				result += (b * hold);
			}
			
		}
		
		//sets the sign based on the signs of the two multiplicands
		result.positive = true;
		
		if (a.positive != b.positive)
			result.positive = false;
			
		if (result != zero)
			result.trim();
		
		return result;
	}
	
	
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
	

	//friend comparators
	bool operator>(const BigNum& a, const BigNum& b)
	{
		if((a == b) || (b.positive > a.positive))
			return false;
			
		if(a.positive > b.positive)
			return true;
			
		if(a.positive && b.positive) 
		{
			if(a.used > b.used)
				return true;
			if(b.used > a.used)
				return false;
		
			for (unsigned int i = 0; i < a.used; i++)
			{
				if(a.digits[a.used - i - 1] > b.digits[a.used - i - 1])
					return true;
				else if (a.digits[a.used - i - 1] < b.digits[a.used - i - 1])
					return false;
			}
		}
		
		else if(!a.positive && !b.positive) 
		{
			if(b.used > a.used)
				return true;
			if(a.used > b.used)
				return false;
		
			for (unsigned int i = 0; i < a.used; i++)
			{
				if(b.digits[a.used - i - 1] > a.digits[a.used - i - 1])
					return true;
				else if (b.digits[a.used - i - 1] < a.digits[a.used - i - 1])
					return false;
			}
		}
		
		return false;
	}


	bool operator>=(const BigNum& a, const BigNum& b)
	{
		return ((a > b) || (a == b));
	}


	bool operator<(const BigNum& a, const BigNum& b)
	{
		return (b > a);
	}


	bool operator<=(const BigNum& a, const BigNum& b)
	{
		return ((b > a) || (a == b));
	}


	bool operator==(const BigNum& a, const BigNum& b)
	{
		if(a.used != b.used)
			return false;
			
		if(a.positive != b.positive)
			return false;
			
		for (unsigned int i = 0; i < a.used; i++)
		{
			if(a.digits[i] != b.digits[i])
				return false;
		}
		
		return true;
	}


	bool operator!=(const BigNum& a, const BigNum& b)
	{
		return (!(a == b));
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
			if (used == 1)
				zero = false;
		}
	}
	
	//input and output
	std::ostream& operator<<(std::ostream &os, const BigNum& bignum)
	{
		if(!bignum.positive)
			os << "-";
		
		for (unsigned int i = 0; i < bignum.used; i++)
		{
			os << bignum.digits[bignum.used - i -1];
		}
		
		return os;
	}	 

	std::istream& operator>>(std::istream &is, BigNum& bignum)
	{
		string in = "";
		is >> in;
		bignum = (string) in;
		
		return is;
	}
	
	BigNum factorial(const BigNum& a)
	{
		BigNum result, fact = 1;
		for (BigNum i = 1; i <= a; ++i)
		{
			fact *= i;
		}
		result = fact;
		return result;
    }
  }



#endif
