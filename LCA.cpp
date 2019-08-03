/*input
1
7
3 2 3 4
0
3 5 6 7
0
0
0
0
2
5 7
2 7
*/
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define pb push_back
#define f first
#define s second
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int n,q;
struct LCA {
    vector<int> height, euler, first, segtree;
    vector<bool> visited;
    int n;

    LCA(vector<vector<int>> &adj, int root = 0) {
        n = adj.size();
        height.resize(n);
        first.resize(n);
        euler.reserve(n * 2);
        visited.assign(n, false);
        dfs(adj, root);
        int m = euler.size();
        segtree.resize(m * 4);
        build(1, 0, m - 1);
    }

    void dfs(vector<vector<int>> &adj, int node, int h = 0) {
        visited[node] = true;
        height[node] = h;
        first[node] = euler.size();
        euler.push_back(node);
        for (auto to : adj[node]) {
            if (!visited[to]) {
                dfs(adj, to, h + 1);
                euler.push_back(node);
            }
        }
    }

    void build(int node, int b, int e) {
        if (b == e) {
            segtree[node] = euler[b];
        } else {
            int mid = (b + e) / 2;
            build(node << 1, b, mid);
            build(node << 1 | 1, mid + 1, e);
            int l = segtree[node << 1], r = segtree[node << 1 | 1];
            segtree[node] = (height[l] < height[r]) ? l : r;
        }
    }

    int query(int node, int b, int e, int L, int R) {
        if (b > R || e < L)
            return -1;
        if (b >= L && e <= R)
            return segtree[node];
        int mid = (b + e) >> 1;

        int left = query(node << 1, b, mid, L, R);
        int right = query(node << 1 | 1, mid + 1, e, L, R);
        if (left == -1) return right;
        if (right == -1) return left;
        return height[left] < height[right] ? left : right;
    }

    int lca(int u, int v) {
        int left = first[u], right = first[v];
        if (left > right)
            swap(left, right);
        return query(1, 0, euler.size() - 1, left, right);
    }
};
void solve(){
	cin>>n;
	int root=-1;
	vector<vector<int>> v(n+1);
	bool vis[n+1];
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++){
		int m;
		cin>>m;
		while(m--){
			int y;
			cin>>y;
			v[i].pb(y);
			vis[y]=1;
		}
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]) root = i ;
	}
	LCA l(v,root);
	cin>>q;
	while(q--){
		int u,v;
		cin>>u>>v;
		cout << l.lca(u,v) << endl ;
	}
}

signed main() {
	IOS;
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		cout << "Case "<<i<<":\n";
		solve();
	}
return 0;
}
