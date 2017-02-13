#include<iostream>
#include<sstream>
#include<cmath>
using namespace std;
int str2int (const string &str) {
  stringstream ss(str);
  int num;
  ss >> num;
  return num;
}
int choose(string lyrics[])
{
	int res=1000,num=0;
	int size_lyrics=2;
	int * mask  = new int(size_lyrics);
	for(int i=0;i<size_lyrics;i++)
	{
		lyrics[i].replace(lyrics[i].find("Y"),1,"1");
		lyrics[i].replace(lyrics[i].find("N"),1,"0");
		mask[i]=(str2int(lyrics[i]));
	}
	cout<<"hello"<<endl;
	int carols=lyrics[0].length();
	for(int m=0;m<1<<carols;m++)
	{
		bool ok=true;
		for(int i=0;i<size_lyrics;i++)
		{
			cout<<mask[i]<<endl;
			if((mask[i]&m)==0)	
			{
				cout<<"hello"<<endl;
				ok=false;
			}
		}
		if(ok&(__builtin_popcount(m)<res))
		{
			cout<<ok;
			res=__builtin_popcount(m);
		}
		
	}
	return res;
}
int main()
{	string s1[30];
	for(int i=0;i<=1;i++)
	{
		string s;
		cin>>s;
		s1[i]=s;
	}
	int res=choose(s1);
	cout<<res<<endl;

	return 0;
}
