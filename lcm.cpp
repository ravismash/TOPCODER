#include<iostream>
using namespace std;
long gcd(long a, long b) {
  if (b == 0) return a;
  return gcd(b, a%b);
}
long lcm(long n) {
  long res = 1, i;
  for (i = 2; i <=n; i++) {
    res = res*i/gcd(res, i);
  }
  return res;
}
int main()
{
	long sm=lcm(20);
	cout<<sm<<endl;
	return 0;
}
