/*input
4
1 1
1 2
0
1 1
*/
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define f first
#define s second
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
int const mod = 1e9+7;
int power(int x, int y, int mod = 2e18){ int ans = 1;x %= mod;while(y){if(y&1)ans = (x * ans) % mod;x = (x * x) % mod;y >>= 1;}return ans;}
int gcd(int a , int b){if(a==0)return b;return gcd(b%a,a);}
vector<int> v[1001];
bool vis[1001];
int previous[1001];
bool match(int i){
	if(i == -1) return 1;
	if(vis[i]) return 0;
	vis[i]=1;
	for(auto x : v[i]){
		if(match(previous[x]))
		{
			previous[x]=i;
			return 1;
		}
	}
	return 0;
}
signed main() {
	IOS;
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		previous[i]=-1;
		int k;
		cin>>k;
		for(int j=0;j<k;j++){
			int y;
			cin>>y;
			v[i].pb(y);
		}
	}
	int matchings = 0 ;
	for(int i=0;i<n;i++){
		memset(vis,0,sizeof(vis));
		if(match(i)) matchings++;
	}
	cout<<n-matchings;
return 0;
}