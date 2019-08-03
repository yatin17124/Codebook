/*input
2
3 2
0 0 1 10
10 0 1 10
20 0 1 10
5 0 2
15 0 4
3 2
0 0 1 10
10 0 1 10
20 0 1 10
5 0 2
15 0 5
*/
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define f first
#define s second
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long 
int const mod = 1e9+7;
struct edge
{
  int from, to, cap, flow, index;
  edge(int from, int to, int cap, int flow, int index):
    from(from), to(to), cap(cap), flow(flow), index(index) {}
};

struct PushRelabel
{
  static const long long INF=1e18;

  int n;
  vector<vector<edge> > g;
  vector<long long> excess;
  vector<int> height;

  PushRelabel(int n):
    n(n), g(n), excess(n), height(n) {}

  void addEdge(int from, int to, int cap)
  {
    g[from].push_back(edge(from, to, cap, 0, g[to].size()));
    if(from==to)
      g[from].back().index++;
    g[to].push_back(edge(to, from, 0, 0, g[from].size()-1));
  }

  void push(edge &e)
  {
      int amt=(int)min(excess[e.from], (long long)e.cap - e.flow);
    if(height[e.from]<=height[e.to] || amt==0)
      return;
    e.flow += amt;
    g[e.to][e.index].flow -= amt;
    excess[e.to] += amt;
    excess[e.from] -= amt;
  }

  void relabel(int u)
  {
    int d=2e5;
    for(auto &it:g[u])
    {
      if(it.cap-it.flow>0)
        d=min(d, height[it.to]);
    }
    if(d<INF)
      height[u]=d+1;
  }

  vector<int> find_max_height_vertices(int source, int dest)
  {
    vector<int> max_height;
    for(int i=0;i<n;i++)
    {
      if(i!=source && i!=dest && excess[i]>0)
      {
        if(!max_height.empty() && height[i] > height[max_height[0]])
          max_height.clear();
        if(max_height.empty() || height[i] == height[max_height[0]])
          max_height.push_back(i);
      }
    }
    return max_height;
  }

  long long max_flow(int source, int dest)
  {
    excess.assign(n, 0);
    height.assign(n, 0);
    height[source]=n;
    excess[source]=INF;
    for(auto &it:g[source])
      push(it);

    vector<int> current;
    while(!(current = find_max_height_vertices(source, dest)).empty())
    {
      for(auto i:current)
      {
        bool pushed=false;
        for(auto &e:g[i])
        {
          if(excess[i]==0)
            break;
          if(e.cap - e.flow>0 && height[e.from] == height[e.to] + 1)
          {
            push(e);
            pushed=true;
          }
        }
        if(!pushed)
        {
          relabel(i);
          break;
        }
      }
    }

    long long max_flow=0;
    for(auto &e:g[source])
      max_flow+=e.flow;

    return max_flow;
  }
};
void solve(){
  int W,P;
  vector<pair<int,int> > edges ;
  cin>>W>>P;
  PushRelabel g(P+W+2);
  // Graph g(P+W+2);
  int X[W+1],Y[W+1],N[W+1],R[W+1],F[P+1];
  for(int i=1;i<=W;++i){
    cin>>X[i]>>Y[i]>>N[i]>>R[i];
  }
  for(int i=1;i<=P;i++){
    int x,y;
    cin>>x>>y>>F[i];
    for(int j=1;j<=W;j++){
      if(R[j]*R[j]>=(X[j]-x)*(X[j]-x)+(Y[j]-y)*(Y[j]-y)){
        // cout<<"connect : "<<j<<" "<<i<<endl;
        edges.pb({j,i});
      }
    }
  }
  int  max_val = N[1];
  int sum_of_F = 0 ; 
  set<int> s;
  for(auto x : edges){
    if(x.f == 1){
      max_val+= F[x.s];
      F[x.s]=0;
    }
    else
    {
      // adj[x.f].pb(x.s);
      s.insert(x.s);
      g.addEdge(x.s,x.f+P,F[x.s]);
      // sum_of_F+=F[x.s];
    }
  }
  for(auto x : s){
    sum_of_F+=F[x];
  }
  for(int i=2; i<=W;i++){
    if(N[i]>max_val){
      cout <<"Lonesome Willy\n";
      return ; 
    }
  }

  // Create a source and a sink 
  // source = 0  ; sink = max 
  int SINK = P+W+1;
  int SRC = 0 ; 
  
  for(int i=1;i<=P;i++){
    // mat[0][i]=F[i];
    g.addEdge(0,i,F[i]);
  }
  //Sink
  // named every WEAVER AS P+i


  for(int i=1;i<=W;i++){
    g.addEdge(i+P,SINK,max_val-N[i]);
  }
  int ans = g.max_flow(SRC, SINK);
  // int ans ; 
  // cout << sum_of_F <<" ";
  // cout << ans << endl ; 
  if(ans == sum_of_F){
    cout <<"Suiting Success\n";
  }
  else
    cout <<"Lonesome Willy\n";
  return;
}
signed main() {
  IOS;
  int t;
  cin>>t;
  while(t--){
    solve();
  }
  return 0 ; 
}