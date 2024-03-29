/*input
3 1
1 2 3
*/
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define pii pair<int,int>
#define pb push_back
#define f first
#define s second
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int  curxor = 0 ;
struct Trienode{
	struct Trienode* bits[2];
	int sum; 
};
struct Trienode* newnode(int val){
	struct Trienode* temp = new Trienode;
	temp->bits[0] = NULL;
	temp->bits[1] = NULL;
	temp->sum = val;
	return temp;
}
void insert(struct Trienode* root,int num){
	struct Trienode* pCrawl = root;
	for(int i = 33 ; i >=0 ;i--){
		if((1LL<<i) & num){
			if(pCrawl->bits[1]==NULL){
				pCrawl->bits[1] = newnode(0);
			}
			pCrawl = pCrawl->bits[1];
		}
		else{
			if(pCrawl->bits[0]==NULL){
				pCrawl->bits[0] = newnode(0);
			}
			pCrawl = pCrawl->bits[0];	
		}
		pCrawl->sum++;
	}
 
}
int lol(struct Trienode* root){
	if(root){
		return root->sum;
	}
	return 0;
}
int get(struct Trienode* root,int prefix,int k){
	struct Trienode* pCrawl = root;
	int ans = 0;
	for(int i = 33 ; i>=0 ; i--){
		if(!pCrawl)break;

		int PB = (prefix >> i) & 1LL;
        int bit = (k >> i) & 1LL;
        if (PB == bit) {
            if (PB == 1) {
                ans += lol(pCrawl->bits[1]);
            }
            pCrawl = pCrawl->bits[0];
        }
        else {
            if (PB == 0) {
                ans += lol(pCrawl->bits[0]);
            }
            pCrawl = pCrawl->bits[1];
        }
	}
	return ans;
}
signed main() {
	IOS;
	int n,k;
	cin>>n>>k;
	struct Trienode* root = newnode(0);
	insert(root,0);
	int ans = 0 ;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		curxor^=x;
		ans += get(root,curxor,k);
		insert(root,curxor);
	}
	cout << n*(n+1)/2 - ans << endl;
return 0;
}