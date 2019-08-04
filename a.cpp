/*input

*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds; 
#define int long long 
#define pii pair<int,int>
#define pb push_back
#define f first
#define s second
#define FOR(i,n) for(int i=0;i<n;i++)
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int power(int x, int y, int mod = 2e18)
{int ans = 1;x%=mod;while(y){if(y&1)ans = (x * ans) % mod;x = (x * x) % mod;y >>= 1;}return ans;}

#ifndef ONLINE_JUDGE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
    template <typename Arg1>
    void __f(const char* name, Arg1&& arg1) { cerr << name << " : " << arg1 << endl; }
    template <typename Arg1, typename... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args) {
        const char* comma = strchr(names + 1, ',');
        cerr.write(names, comma - names) << " : " << arg1 << "  ";
        __f(comma + 1, args...);
    }
#else
#define trace(...)
#endif // ifndef ONLINE_JUDGE

template <typename T> ostream& operator << (ostream& os, const vector<T>& v) { for (int i = 0; i < v.size(); ++i) os << v[i] << " "; return os; } 
template <typename T> ostream& operator << (ostream& os, const set<T>& v) { for (auto it : v) os << it << " "; return os; } 
template <typename T, typename S> ostream& operator << (ostream& os, const pair<T, S>& v) { os << v.first << " " << v.second; return os; } 
template <typename T, typename S> ostream& operator << (ostream& os, const map<T, S>& v) { for (auto it : v) os << it.first << "=>" << it.second << "\n"; return os; } 

typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set; 
int const MOD = 1e9+7;
int const inf = 2e18;
int const N = 2e5+10;

signed main() {
    IOS;
    
    






return 0;
}