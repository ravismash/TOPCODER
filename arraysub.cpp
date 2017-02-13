#include<iostream>
#include <algorithm>
using namespace std;

int main()
{
	unsigned int x=1000000;
	unsigned int y=100000;
	int indx2=-1;
	cin>>x;
	int a[x];
	for(int i=0;i<x;i++)
		cin>>a[i];
	cin>>y;
	for(int i=0;i<=x-y;i++)
	{
		if(i>0)
			cout<<" ";
		if(indx2>=i)
		{
			if(a[i+y-1]>a[indx2])
			{
				indx2=i+y-1;
			}
		}
		else
		{
			indx2=max_element(a+i,a+i+y)-a;
		}
		cout<<a[indx2];

	}
	return 0;
}
