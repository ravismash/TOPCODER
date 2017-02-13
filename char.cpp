#include<iostream>
#include<string>
using namespace std;
int main()
{
	char c;
	string s;
	int k,n=0;
	cin>>s>>c>>k;
	int t_f;
	int m_f=0;
	int indx_t=0;
	int indx_g=0;
	int end=0;	
	n=s.length();
	for(int i=0;i<=n-k;i++)
	{
		t_f=0;
		for(int j=i;j<=i+k-1;j++)
		{
			if(s[j]==c)
			{
				t_f++;
				indx_t=j;
			}
		}
		if(t_f>=m_f&&indx_t!=i+k-1)
		{
			m_f=t_f;
			indx_g=indx_t;
			end=i+k-1;
		}
	}
	while(indx_g<end)
		indx_g++;
	if(indx_g==n-1)
		indx_g++;
	cout<<indx_g;
	return 0;
}

