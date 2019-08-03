/*input
5 5
1 5 2 4 3
q 1 5
q 1 3
q 3 5
u 3 6
q 1 5
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
#define pb push_back 
void buildtree(ll *tree,int a[],int treenode,int start,int end)
{
	if(start==end)
		{tree[treenode]=a[start];return ;}
	int mid=(start+end)/2;
	buildtree(tree,a,2*treenode,start,mid);
	buildtree(tree,a,2*treenode+1,mid+1,end);
	tree[treenode]=tree[2*treenode]+tree[2*treenode+1];
}

void update(ll *tree,int start,int end,int treenode,int idx,int value)
{

	if(start==end)
	{
		tree[treenode]=value; return;
	}
	int mid=(start+end)/2;
	if(idx>mid)
		update(tree,mid+1,end,2*treenode+1,idx,value);
	else
		update(tree,start,mid,2*treenode,idx,value);
	tree[treenode]=tree[2*treenode]+tree[2*treenode+1];
}
ll query(ll *tree,int start,int end,int treenode,int left,int right)
{
	//completley outside
	if(start>right||end<left)
		return 0;
	if(start>=left&&end<=right)
		return tree[treenode];
	int mid=(start+end)/2;
	return query(tree,start,mid,2*treenode,left,right)+query(tree,mid+1,end,2*treenode+1,left,right);
}	

int main() {
  
  int n,q;
  cin>>n>>q;
  int a[n+1];
  for(int i=1;i<=n;i++)
  	cin>>a[i];

  ll *tree = new ll[4*n];
  buildtree(tree,a,1,1,n);
  // update(tree,1,n,1,1,5);


  // for(int i=1;i<=2*n;i++)
  // 	cout<<tree[i]<<endl;

  for(int i=0;i<q;i++)
  {
  	char c;
  	int x,y;
  	cin>>c>>x>>y;
  	if(c=='q')
  		cout<<query(tree,1,n,1,x,y)<<endl;
  	else
  		update(tree,1,n,1,x,y);
  }

delete [] tree;
return 0;
} 