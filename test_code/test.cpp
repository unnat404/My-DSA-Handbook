#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define nil -1
#define MAX 100
#define ll long long 

void dfs(int color,int node,vector<vector<int>> &g,vector<int> &vis, vector<int> &cur){
	vis[node]=color+1;
	// cout<<node<<" ";
	cur.push_back(node);
	for(auto nbr:g[node]){
		if(vis[nbr]==0) dfs(color,nbr,g,vis,cur);
	}
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int i,n,t,ans,a,b,u,v,m,count,cur_indeg;
	cin>>t;

	while(t--){
		cin>>n>>m;
		ans=count=0;
		vector<int> indeg(n,0),vis(n,0),cur;
		vector<vector<int>> g(n);

		for(i=0;i<m;i++){
			cin>>u>>v;
			u--,v--;
			indeg[v]++;
			g[u].push_back(v);
			g[v].push_back(u);
		}

		for(i=0;i<n;i++){
			cur.clear();
			cur_indeg=0;
			if(vis[i]==0){
				dfs(i,i,g,vis,cur),count++;
				for(auto x:cur){
					if(indeg[x]==0) cur_indeg++;
				}
				ans+=cur_indeg+1;
				// if(cur_indeg>0) ans--;
				
			} 
		}

		cout<<ans<<"\n";
		// cout<<"\n------------\n";
	}   

	
    return 0;
}
// ListNode* intersection(ListNode* head1, ListNode* head2){
// 	int len1,len2,i,diff;
// 	len1=len2=0;
// 	ListNode* intersection;
// 	len1=findLengthofList(head1);
// 	len2=findLengthofList(head2);
	
// 	diff = len1-len2;

// 	if(diff>0){
// 		// list1 is bigger
// 		diff = abs(diff);
// 		while(diff--){
// 			head1=head1->next;
// 		}
// 	}
// 	else{
// 		// list2 is bigger
// 		diff = abs(diff);
// 		while(diff--){
// 			head1=head1->next;
// 		}
// 	}

// 	// now start iterating
// 	while(head1!=head2){
// 		head1=head1->next;
// 		head2=head2->next;
// 	}


// }
/*

1 2 3 4 5 6 7 

11 7 13 

4
*/
