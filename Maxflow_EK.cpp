/*input
3 2 5
20 10 10
25 30
1 1 3
2 1 1
2 2 4
3 1 2
3 2 5

*/
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define f first
#define s second
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long 
int capacities[503][503];
int flowPassed[503][503];
vector<int> graph[503];
int parentsList[503];       
int currentPathCapacity[503];  
 
int bfs(int startNode, int endNode)
{
    memset(parentsList, -1, sizeof(parentsList));
    memset(currentPathCapacity, 0, sizeof(currentPathCapacity));
 
    queue<int> q;
    q.push(startNode);
 
    parentsList[startNode] = -2;
    currentPathCapacity[startNode] = 999;
 
    while(!q.empty())
    {
        int currentNode = q.front();
        q.pop();
 
        for(int i=0; i<graph[currentNode].size(); i++)
        {
            int to = graph[currentNode][i];
            if(parentsList[to] == -1)
            {
                if(capacities[currentNode][to] - flowPassed[currentNode][to] > 0)
                {
                    parentsList[to] = currentNode;
                    currentPathCapacity[to] = min(currentPathCapacity[currentNode], 
                    capacities[currentNode][to] - flowPassed[currentNode][to]);
                    if(to == endNode)
                    {
                        return currentPathCapacity[endNode];
                    }
                    q.push(to);
                }
            }
        }
    }
    return 0;
}
 
int edmondsKarp(int startNode, int endNode)
{
    int maxFlow = 0;
      while(true)
    {
        int flow = bfs(startNode, endNode);
        if (flow == 0) 
        {
            break;
        }
        maxFlow += flow;
        int currentNode = endNode;
        while(currentNode != startNode)
        {
            int previousNode = parentsList[currentNode];
            flowPassed[previousNode][currentNode] += flow;
            flowPassed[currentNode][previousNode] -= flow;
            currentNode = previousNode;
        }
    }
    return maxFlow;
}
void solve(){


// int capacities[502][502];
// int flowPassed[502][502];
// vector<int> graph[502];
for(int i=0;i<502;i++){
  graph[i].clear();
}
// int parentsList[502];       
// int currentPathCapacity[502]; 
memset(capacities,0,sizeof(capacities));
memset(flowPassed,0,sizeof(flowPassed));
  int W,P;
  vector<pair<int,int> > edges ;
  cin>>W>>P;
  // PushRelabel g(P+W+2);
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
    graph[x.s].pb(P+x.f);
    graph[x.f+P].pb(x.s);
    capacities[x.s][P+x.f]=F[x.s];
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
    graph[0].pb(i);
    graph[i].pb(0);
    capacities[0][i]=F[i];
    // mat[0][i]=F[i];
    // g.addEdge(0,i,F[i]);
  }
  //Sink
  // named every WEAVER AS P+i


  for(int i=1;i<=W;i++){
    graph[i+P].pb(SINK);
    graph[SINK].pb(i+P);
    capacities[i+P][SINK]=(max_val-N[i]);
    // g.addEdge(i+P,SINK,);
  }
  int ans =edmondsKarp(SRC, SINK);
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