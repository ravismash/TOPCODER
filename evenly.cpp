#include<iostream>

using namespace std;
bool EvenlyDivisible(int num)
{
	for(int i=1;i<=20;i++)
	{
		if(num%i!=0)
		{
			return false;
		}
	}
	return true;
}


int main(void)
{	
	int o=20;
	while(!EvenlyDivisible(o))
	{
		o+=20;	
	}
	cout<<"Your number is :"<<o<<EvenlyDivisible(18044195)<<endl;
	
}
