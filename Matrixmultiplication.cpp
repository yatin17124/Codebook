/*input
10 2 1
*/
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define pb push_back
#define f first
#define s second
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int const SZ = 2;
int MOD = 1e6; 
int add(int a, int b)
{
	int res = a + b;
	if(res >= MOD)
		return res - MOD;
	return res;
}

int mult(int a, int b)
{
	long long res = a;
	res *= b;
	if(res >= MOD)
		return res % MOD;
	return res;
}

struct matrix
{
	int arr[SZ][SZ];

	void reset()
	{
		memset(arr, 0, sizeof(arr));
	}

	void makeiden()
	{
		reset();
		for(int i=0;i<SZ;i++)
		{
			arr[i][i] = 1;
		}
	}

	matrix operator + (const matrix &o) const 
	{
		matrix res;
		for(int i=0;i<SZ;i++)
		{
			for(int j=0;j<SZ;j++)
			{
				res.arr[i][j] = add(arr[i][j], o.arr[i][j]);
			}
		}
		return res;
	}

	matrix operator * (const matrix &o) const 
	{
		matrix res;
		for(int i=0;i<SZ;i++)
		{
			for(int j=0;j<SZ;j++)
			{
				res.arr[i][j] = 0;
				for(int k=0;k<SZ;k++)
				{
					res.arr[i][j] = add(res.arr[i][j] , mult(arr[i][k] , o.arr[k][j]));
				}
			}
		}
		return res;
	}
};

matrix power(matrix a, int b)
{
	matrix res;
	res.makeiden();
	while(b)
	{
		if(b & 1)
		{
			res = res * a;
		}
		a = a * a;
		b >>= 1;
	}
	return res;
}
signed main() {
	IOS;
	int n,l,k;
	cin>>n>>k>>l;
	matrix mat;
	n/=5;
	mat.reset();
	k%=MOD;
	l%=MOD;
	mat.arr[0][0]=k;
	mat.arr[0][1]=l;
	
	mat.arr[1][0]=1;
	matrix mat2;
	mat2.reset();
	mat2.arr[0][0]=k;
	mat2.arr[1][0]=1;
	matrix res;
	res = power(mat,n-1);
	res = res * mat2;
	int ans = res.arr[0][0] + res.arr[0][1];
	ans%=MOD;
	string s = to_string(ans);
	string t = s;
	reverse(t.begin(), t.end());
	while(t.size()  < 6 ){
		t.pb('0');
	}
	reverse(t.begin(), t.end());
	cout << t << endl;
	return 0;
}
