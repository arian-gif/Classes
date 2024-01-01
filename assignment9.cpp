/*
Name: Arian & Jacob
Version 1.0
Assumptions: numerator and denominator are not doubles.
Description: Creates fraction class and test the fractions
*/
#include <cstdlib>
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
using namespace std;

class Fraction
{
	private:
		int numerator, denominator;
	
	public:
		void valid()
		{
			if(numerator<0&&denominator<0)
			{	
				cout<<"Error, new values given"<<endl;
				numerator = abs(numerator);
				denominator = abs(denominator);
			}
		}
		void numerator_denominator()
		{
			if(abs(numerator)>abs(denominator))
			{
				cout<<"Error, new values given"<<endl;
				numerator=0;
				denominator=1;//since you can't divide by 0
			}
		}
		Fraction()	
		{
			numerator=0;
			denominator=1;//since you can't divide by 0
		}
		Fraction(int num,int den)
		{	
			numerator =num;
			denominator= den;
			valid();
			numerator_denominator();
			
		}
		
		int get_numerator() const
		{
			return numerator;
		}
		int get_denominator() const
		{
			return denominator;
		}
		void set_numerator(int num)
		{
			numerator = num;
			valid();
			numerator_denominator();
		}
		void set_denominator(int den)
		{
			denominator = den;
			valid();
			numerator_denominator();
		}
		double decimal(int decimal_place)
		{	
			double decimal = double(numerator)/double(denominator);
    		double val = pow(10,decimal_place);
			decimal= round(val*decimal)/val;
			return decimal;
		}
		bool isExactlySame(Fraction const & other) const 
		{
			return (numerator == other.get_numerator())
			&&(denominator ==other.get_denominator());
		}
		void printFraction() const
		{
			cout<<numerator<<" / "<<denominator<<endl;		
		}
		
	
};

int main()
{	
	Fraction num1 = Fraction(-1,2);
	cout<<num1.decimal(2)<<endl;
	Fraction num2 = Fraction(-1,2);
	cout<<"True(1),False(0):"<<num2.isExactlySame(num1)<<endl;
	num1.printFraction();
	num2.printFraction();
	return EXIT_SUCCESS;
}

/*for fraction 1 = 4/3 and franction 2 = 1/3
Error, new values given
0
True(1),False(0):0
0 / 1
1 / 3

for fraction 1 = 5/6 and fraction 2 = 1/10
0.83
True(1),False(0):0
5 / 6
1 / 10

for fraction 1 = -1/2 and fraction2 = -1/2
-0.5
True(1),False(0):1
-1 / 2
-1 / 2
*/
