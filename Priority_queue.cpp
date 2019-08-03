/*input
 
*/
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define pb push_back
#define f first
#define s second
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pii pair<int,int>
class ComparisonClass{
public:
bool operator() (pair<int,int> a, pair<int,int> b) {
        return a.s<b.s;
    }
};
signed main() {
  IOS;
  priority_queue<pii,vector<pii>,ComparisonClass> q;
  q.push({10,1});
  q.push({20,5});
  q.push({30,3});
  cout << q.top().s;
return 0;
}
