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


signed main() {
	IOS;
	SegTree seg;
	seg.init(10);
	seg.update(1,5,100);
	cout << seg.query(2,3) << endl;
	seg.update(2,2,100);
	cout << seg.query(2,3) << endl;
return 0;
}
