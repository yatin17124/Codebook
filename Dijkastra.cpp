/*input
3 3 3
1 2 3
1 2 1
2 3 2
1 3 3
*/
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define f first
#define s second
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define  mp make_pair
long long  const inf = 1e12;
int n,m,k;
int numberofpaths[100010];
int junc[100010];
vector<pair<int,int> > v[100010];
long long dis[100010];
bool vis[100010];
void dijkastra(){
	priority_queue<pair<int,int> > pq;
	pq.push(mp(0,1));
	while(pq.size()!=0){
		int i = pq.top().s;
		int curdis = -pq.top().f;
		pq.pop();
		if(vis[i])continue;
		vis[i]=1;
		for(auto to : v[i]){
			if(!vis[to.f]){
				if(dis[to.f]==to.s+curdis){
					numberofpaths[to.f]++;
				}
				if(dis[to.f]>to.s+curdis){
					dis[to.f]=to.s+curdis;
					numberofpaths[to.f]=numberofpaths[i];
					pq.push(mp(-dis[to.f],to.f));
				}
			}
		}
		
	}
}
signed main() {
	IOS;
	cin>>n>>m>>k;
	for(int i=0;i<k;i++)cin>>junc[i];
	int x,y,z;
	for(int i=0;i<m;i++){
		cin>>x>>y>>z;
		v[x].pb(make_pair(y,z));
		v[y].pb(make_pair(x,z));
	}
	for(int i=1;i<=n;i++)dis[i]=inf;
	dis[1]=0;
	dijkastra();
	if(numberofpaths[n]>0)cout<<"yes";
	else cout<<"no";
return 0;
}