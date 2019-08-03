/*input
1
6
5 4 1 1 1 1
 
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
int bit[100001];
int n;
#define LSB(i) ((i) & -(i))
int  sum(int i)
{
	int j=0; while(i>0) {j+=bit[i];i-=LSB(i);} return j;
}
void add(int i, int k)
{
	while (i <= n) 
        bit[i] += k, i += LSB(i);
}
void solve()
{
cin>>n;
int a[n];
memset(bit,0,sizeof(bit));
for(int i=0;i<n;i++){
	cin>>a[i];
}
int ans =0 ;
for(int i=n-1;i>=0;i--)
{
	ans+=sum(a[i]-1);
	add(a[i],1);
}
cout<<ans<<endl;

}
signed main() {
IOS;
int t ;
cin>>t;
while(t--)
{
	solve();
}
return 0;
}