#include<iostream>
#include<list>
#include<string>
using namespace std;
   int gcd(long a, long b) {
    return b == 0 ? a : gcd(b, a % b);
	}
    string possible(long n,int k,int x,int y)
    {
        string s("Impossible");
        bool *visited =new bool[n];
        list<int>*adj= new list<int>[n+1];
	cout<<n<<endl;
        for(long i=0;i<=n;i++)
        {
	   for(long j=0;j<=n;j++)
            {
            	
		int z=0;	
		if(i==0||j==0)
			z=1;
                else if(i<j)
                {
                    z=gcd(j,i);
                }
                else
                    z=gcd(i,j);
	/*	int x1=adj>>(i*n+j);
		int y1=(x1>>1)<<1;
		int z1=x1^y1;*/
                if(z>k)
                {
			adj[i].push_back(j);
			adj[j].push_back(i);
	/*		adj[i][j]=1;
			adj[j][i]=1;*/
                   /* adj=(adj|1<<(i*n+j));
                    adj=(adj|1<<(j*n+i));
			*/
                }
	    }	
        }
	cout<<"hello2"<<endl;
        if(x==y)
            s="Posible";
 	list<int>q;
        visited[x]=true;
        q.push_back(x);
        int flag=0;
	cout<<"hello"<<endl;
	 list<int>::iterator i;
        while(!q.empty()&&flag==0)
        {
            int s1=q.front();
            q.pop_front();
            for( i=adj[s1].begin();i!=adj[s1].end()&&flag==0;++i)
             {
	/*	int x1=adj>>(s1*n+i);
		int y1=(x1>>1)<<1;
		int z1=x1^y1;*/
              //  if(adj[s1][i]==1)
               // {
                    if(*i==y)
                    {
                        flag=1;
                        s="Possible";
                    }
                    if(!visited[*i])
                    {
                        visited[*i]=true;
                        q.push_back(*i);
                    }
                        
            //    }
            }
        }
        return s;
    }
int main()
{
	
	cout<<"hello34"<<endl;
	string s=possible(1000000,2000,12345,54321);
	cout<<s<<endl;
	return 0;
}
