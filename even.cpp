#include<iostream>
using namespace std;
int main()
{
	int x=13;	
       while(x>0)
	{	
		x=(x&-x);
		cout<<x<<endl;
	}
	return 0;
}
