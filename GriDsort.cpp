#include<iostream>
#include<algorithm>
#include<string>
#include<unordered_set>
#include<vector>
using namespace std;
class GridSort
{
   public :
string sort(int n, int m, vector<int> grid) {
    for (int i = 0; i < n; i++) {
      unordered_set<int> hs;
      for (int j = 0; j < m; j++) {
        hs.insert((grid[i*m+j]-1) / m);
      }
      if (hs.size() != 1) return "Impossible";
    }
    for (int j = 0; j < m; j++) {
      unordered_set<int> hs ;
      for (int i = 0; i < n; i++) {
        hs.insert((grid[i*m+j]-1) % m);
      }
      if (hs.size() != 1) return "Impossible";
    }
    return "Possible";
  }
};
int main()
{
	return 0;
}
