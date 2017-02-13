#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>
 
using namespace std;
 string findPassword(vector<int> x)
  {
        int n = x.size();
        int f[100];
        for(int i = 1;i <= 100;i++) f[i] = x[i - 1];
        int num[100],tot = 0;
        for(int i = n;i >= 1;i--)
        {
            int cnt = 0;
            for(int j = i + 1;j <= n;j++)
            {
                cnt += num[j] * (j - i + 1);
            }
            num[i] = f[i] - cnt;
            if(num[i] < 0) return "";
            tot += i * num[i];
        	cout<<num[i]<<cnt<<f[i]<<endl;
	}
        if(tot != n) return "";
 
        string ans = "";
        for(int i = n;i >= 1;i--)
        {
            while(num[i] > 0)
            {
                num[i]--;
                for(int j = 1;j <= i;j++)
                ans = ans + "a";
                for(int k = 1;k <= n;k++)
                if(num[k] > 0)
                {
                    num[k]--;
                    for(int j = 1;j <= k;j++)
                      ans = ans + "b";
                    break;
                }
            }
        }
 
        return ans;
  }
int main()
{
	string ans;
	vector<int> y;
	y.push_back(5);
	y.push_back(0);
	y.push_back(0);
	y.push_back(0);
	y.push_back(0);

	ans=findPassword(y);
	cout<<ans<<endl;
	return 0;
}
