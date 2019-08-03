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
int const N = 1e5 + 10 ; 
int par[N];
int sz[N];
void init(){
	for(int i=1;i<N;i++){
		par[i] = i ; 
		sz[i] = 1 ; 
	}
}
int fp(int i){
	if(par[i]==i){
		return i ; 
	}
	return fp(par[i]);
}
void merge(int x,int y){
	int X = fp(x);
	int Y = fp(y);
	if(X == Y )return ; 
	if(sz[X] > sz[Y]){
		swap(X,Y);
	}
	par[X] = par[Y];
	sz[Y] += sz[X];
	sz[X] = 0 ; 
}	
signed main() {
	IOS;
	init();
	merge(1,6);
	merge(2,5);
	cout << fp(2) << endl ;
	merge(3,5);
	merge(4,5);
	cout << fp(6) << endl ;
	merge(2,6);
	cout << fp(6) << endl ;
return 0;
}
