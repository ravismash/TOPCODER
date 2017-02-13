#include <iostream>
#include <cmath>
#include<string>
using namespace std;
int binary_decimal(int n);
int decimal_binary(int n);
int main()
{
   int n;
   char c;
   string s("helloe");	
  cout << "Instructions: " << endl;
   cout << "1. Enter alphabet 'd' to convert binary to decimal." << endl;
   cout << "2. Enter alphabet 'b' to convert decimal to binary." << endl;
   int x=-5;
   int i=0;	
   while(x)
   {
	int temp=x%2;
	cout<<temp<<endl;
	s[i]=s[i]+(temp);
	i++;
	x=x/2;
    }		
   cout<<s<<endl;	
   if (c =='d' || c == 'D')
   {
       cout << "Enter a binary number: ";
       cin >> n;
       cout << n << " in binary = " << binary_decimal(n) << " in decimal";
   }
   if (c =='b' || c == 'B')
   {
       cout << "Enter a binary number: ";
       cin >> n;
       cout << n << " in decimal = " << decimal_binary(n) << " in binary";
   }
   return 0;
}

int decimal_binary(int n)  /* Function to convert decimal to binary.*/
{
    int rem, i=1, binary=0;
    while (n!=0)
    {
        rem=n%2;
        n/=2;
        binary+=rem*i;
        i*=10;
    }
    return binary;
}

int binary_decimal(int n) /* Function to convert binary to decimal.*/
{
    int decimal=0, i=0, rem;
    while (n!=0)
    {
        rem = n%10;
        n/=10;
        decimal += rem*pow(2,i);
        ++i;
    }
    return decimal;
}
