/*

code chef (nandini - 18/11/2022)
1) simple vrute force 
2) modulo : solved using maps 
3) dp (2states)
4) graph : (by condensing dtrongly connected component)
*/
// ===============================================================================
/*
3) longest equal subarray (dp)
(passed)
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define nil -1
#define MAX 100
#define ll long long 


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int i,n,t,ans,a,b;
	cin>>t;

	while(t--){
		cin>>n;
		ans=0;
		vector<int> v(n);
		for(i=0;i<n;i++) cin>>v[i];
		vector<vector<int>> dp(n,vector<int>(2,1));

		for(i=1;i<n;i++){
			a=v[i],b=v[i-1];
			if(a-b==1){// 4 3
				dp[i][0]=max(dp[i][0],dp[i-1][1]+1);
			}
			else if(a==b){
				dp[i][0]=max(dp[i][0],dp[i-1][0]+1);
				dp[i][1]=max(dp[i][1],dp[i-1][1]+1);
			} 
			else if(b-a==1) dp[i][1]=max(dp[i][1],dp[i-1][0]+1);//4 3
		}

		// for(i=0;i<n;i++) { cout<<dp[i][0]<<" "<<dp[i][1]<<"\n"; ans=max({ans,dp[i][0],dp[i][1]});}
		for(i=0;i<n;i++) ans=max({ans,dp[i][0],dp[i][1]});
		
		cout<<ans<<"\n";
		// cout<<"\n------------\n";
	}   

	
    return 0;
}
/*
------
i/p
------
3
5
5 6 6 6 7
6
3 4 4 3 3 4
4 
1 2 3 4

------
o/p
------
4
6
2
*/
// ==========================================================================
/*
4) 

*/
// kanisht approach - passed (https://p.ip.fi/xjF0) 
#include <bits/stdc++.h>
#define ll long long 
#define pb push_back
#define ff first
#define ss second
 
using namespace std;
 
vector<ll>adj[100005];
vector<ll>tr[100005];
vector<ll>ind(100005);
vector<ll>vis(100005);
vector<ll>color(100005);
 
void dfs(int node, stack<int> &st) {
    vis[node] = 1; 
    for(auto it: adj[node]) {
        if(!vis[it]) {
            dfs(it, st); 
        }
    }
    
    st.push(node); 
}
void rev(int node,int temp) {
   
    vis[node] = 1;
    color[node]=temp;
 
    for(auto it: tr[node]) {
        if(!vis[it]) {
            rev(it,temp); 
        }
    }
}
 
void dfs2(int node){
    
    vis[node]=1;
    for(auto i:adj[node]){
        
        if(!vis[color[i]]){
            dfs2(color[i]);
        }
    }
    
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<pair<int,int>>edg;
        for(int i=1;i<=n;i++){
            adj[i].clear();
            tr[i].clear();
            vis[i]=0;
            ind[i]=0;
            color[i]=0;
        }
        int x,y;
        vector<pair<int,int>>v;
        for(int i=0;i<m;i++){
            cin>>x>>y;
            adj[x].push_back(y);
            edg.push_back({x,y});
        
        }
        stack<int> st;
        for(int i = 1;i<=n;i++) 
        {
     	    if(!vis[i]) {
	           dfs(i, st); 
	         }
	    }
	    
	 for(int i = 1;i<=n;i++) {
	    vis[i] = 0; 
	    for(auto it: adj[i]) {
	        tr[it].push_back(i); 
	    }
	}
	
	
	
	while(!st.empty()) {
	    int node = st.top();
	    st.pop(); 
	    if(!vis[node]) {
	        rev(node,node); 
	    }
	}
	int ans=0;
    for(int i=1;i<=n;i++){
        vis[i]=0;
    }
    for(int i=1;i<=n;i++){
        
        if(!vis[color[i]]){
            dfs2(color[i]);
        }
        
    }
    for(auto u:edg){
        
        int x=u.ff;
        int y=u.ss;
        if(color[x]!=color[y]){
            ind[color[y]]++;
        }
    }
    for(int i=1;i<=n;i++){
        vis[i]=0;
    }
    for(int i=1;i<=n;i++){
        if(ind[color[i]]==0 && !vis[color[i]]){
            ans++;
            vis[color[i]]=1;
        }
    }
    cout<<ans<<'\n';
    }
    
    
    return 0;
}
 
 //-------- below is my approach did not work (below approach not passed - but sample were passing)
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
				if(cur_indeg>0) ans--;
				
			} 
		}
 
		cout<<ans<<"\n";
		// cout<<"\n------------\n";
	}   
 
	
    return 0;
}