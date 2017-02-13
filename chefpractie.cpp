#include<iostream>
#include<vector>
using namespace std;
 
const long long inf = 2e9 + 1000;
 
int sgn(long long n) {
	return (n > 0) - (n < 0);
}
 
bool zigzag(vector<long long> &a) {
	bool ok1 = true;
	bool ok2 = true;
	for (int i = 0; i < (int)a.size() - 1; i++) {
		if (i % 2 == 0) {
			if (!(a[i] < a[i + 1])) ok1 = false;
			if (!(a[i] > a[i + 1])) ok2 = false;
		} else {
			if (!(a[i] > a[i + 1])) ok1 = false;
			if (!(a[i] < a[i + 1])) ok2 = false;
		}
	}
	return ok1 || ok2;
}
 
void solve() {
	int n;
	scanf("%d", &n);
 
	vector<long long> a(n), b(n);
	for (int i = 0; i < n; i++) {
		scanf("%lld %lld", &a[i], &b[i]);
	}
 
	vector<long long> es;
	for (int i = 0; i < n - 1; i++) {
		int j = i + 1;
 
		long long pass = inf;
		long long fail = 0;
 
		while (pass - fail > 1) {
			long long mid = (pass + fail) / 2;
 
			if (sgn(a[i] - a[j]) != sgn(a[i] + mid * b[i] - a[j] - mid * b[j])) {
				pass = mid;
			} else {
				fail = mid;
			}
		}
 
		if (pass != inf) {
			for (int i = -1; i <= 1; i++) {
				if (pass + i >= 1) {
					es.push_back(pass + i);
				}
			}
		}
	}
 
	es.push_back(0);
	sort(es.begin(), es.end());
	es.erase(unique(es.begin(), es.end()), es.end());
 
	vector<pair<long long, long long>> ans;
 
	long long l = -1, r = -1;
	for (long long t : es) {
		vector<long long> c(n);
		for (int i = 0; i < n; i++) {
			c[i] = a[i] + t * b[i];
		}
		if (zigzag(c)) {
			if (l == -1) {
				l = t;
				r = t;
			} else {
				r = t;
			}
		} else {
			if (l != -1) {
				ans.emplace_back(l, r);
			}
			l = -1;
			r = -1;
		}
	}
 
	if (l != -1) ans.emplace_back(l, inf);
 
	cout << ans.size() << endl;
 
	for (auto p : ans) {
		if (p.second != inf) {
			printf("%lld %lld\n", p.first, p.second);
		} else {
			printf("%lld Inf\n", p.first);
		}
	}
}
 
int main() {
	int T;
	cin >> T;
	while (T--) solve();
} 
