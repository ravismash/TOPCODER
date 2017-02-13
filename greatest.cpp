#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s;
	unsigned long long x=0,y=1;
	cin>>s;
	for(int i=0;i<=1000-13;i++)
	{
		y=1;
		for(int j=0;j<13;j++)
		{
			y=y*(s[j+i]-'0');
		}
		if(y>x)
			x=y;
	}
	cout<<x;

	return 0;
}
