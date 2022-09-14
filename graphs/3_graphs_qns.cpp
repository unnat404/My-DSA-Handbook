/***************************************************************************************************
Graphs Problem List(found during problem solving/contests):

- Leetcode 2360. Longest Cycle in a Graph :: https://leetcode.com/problems/longest-cycle-in-a-graph/
- Minm vertices to be removed(/deleted) so that all nodes become disconnected

*****************************************************************************************************/

// =======================================================================================================================================
#include <bits/stdc++.h>
using namespace std;
// =======================================================================================================================================
// Leetcode 2360. Longest Cycle in a Graph :: https://leetcode.com/problems/longest-cycle-in-a-graph/
class Solution {
public:
    int mark_dist(vector<int>& edges,vector<pair<int,int>>& dist, int node){
        int i,j,n=edges.size(),cur=node,far=0;
        
        while(true){
            if(edges[cur]==-1) return -1;// no further node to go
            cur = edges[cur];
            if(dist[cur].first!=INT_MAX){
                // Note: its a cycle only if the node is visited twice during the same dfs call
                // to check same dfs visit we use the dist[cur].second : to keep track of diff dfs calls
                
                // check if this node is being visited again for the same dfs call
                // -> if yes => cycle exists  
                // -> otherwise => for current path its not a cycle, its simply a path merge
                if(node != dist[cur].second) return -1;
                
                return far+1-dist[cur].first;// returning length of cycle
                // length of cycle = distance during (second visit - first visit)
            }
            far++;
            dist[cur]={far,node};
        }
    }
    
    
    int longestCycle(vector<int>& edges) {
        int i,j,n=edges.size(),k,cur_size, ans_dist = -1;
        vector<pair<int,int>> dist(n,{INT_MAX,-1});
        // dist[i].first  -> stores distance of i'th node from root dfs node
        // dist[i].second -> stores root node for which dfs is being called 
        
        for(i=0;i<n;i++){
            if(dist[i].first==INT_MAX){
                //unvisited
                cur_size = mark_dist(edges,dist,i);
                ans_dist  = max(ans_dist,cur_size);// -1 => no cycle
            }
        }
         
        return ans_dist;
    }
};

/*
-------------------
edge case(sort of)
-------------------
i/p:
[-1,4,-1,2,0,4]

o/p: -1
*/
// =======================================================================================================================================
/* 
Q) Minimum vertices to be removed(/deleted) so that all nodes become disconnected
Given : N vertices in graph ;  M edges given in M lines by Ai and Bi (1-based indexing of nodes)
------------------- 
sample i/p format:
------------------- 
n m 
Ai Bi 
.
.
Am Bm

------------------- 
sample o/p format
------------------- 
x : its the minm no of nodes that need to be deleted


------------------- 
sample i/p #1
------------------- 
5 4
1 2
1 3
3 5
5 4

------------------- 
sample o/p #1
------------------- 
2


------------------- 
sample i/p #2
------------------- 
4 4
1 2
1 3
2 3
3 4

------------------- 
sample o/p #2
------------------- 
2

------------------- 
sample i/p #3
------------------- 
6 9
1 2
1 3
2 3
3 4
2 6
3 6
3 5
1 5
5 6

------------------- 
sample o/p #3
------------------- 
3



*/
#include <bits/stdc++.h>
#define ll long long
#define vll vector<ll>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define all(x) x.begin(),x.end()
using namespace std;
 
const ll mod =1e9+7;
 
int main() {
	
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	ll t;
	t=1;
// 	cin>>t;
	while(t--)
	{
	    int n,m;
	    cin>>n>>m;
	    vector<int>deg(n+1);// keep track of degree of node given by index as node (helps to find pair {degree_of_node,node} )
	    vector<set<int>>v(n+1);// optimized adjancency list
        // (since after each neighbour is visited it can be deleted easily using set)
	    int x,y;
        for(int i=0;i<m;i++){
            cin>>x>>y;
            v[x].insert(y);
            v[y].insert(x);
            deg[x]++;
            deg[y]++;
        }
        // set's end will store the biggest degree node
        set<pair<int,int>>s;// {degree_of_node,node}
        for(int i=1;i<=n;i++)
        {
            s.insert({deg[i],i});
        }
        int ct=0;
        while(s.size()>0){
            
            auto lst=s.rbegin();// set's end will store the biggest degree node
            int src=lst->ss;
            // cout<<src<<'\n';
            int src_deg=lst->ff;
            for(auto it:v[src]){
                int child_deg=deg[it];
                int child=it;
                v[it].erase(src);
                s.erase({child_deg,child});
                deg[it]--;
                if(deg[it]>0){
                    s.insert({deg[it],it});
                }
            }
            s.erase({src_deg,src});
            ct++;
        }
	    cout<<ct<<'\n';
	}
	
	return 0;
}
/*
-------------
approach :
-------------

totalDegree = sum of degree of all nodes.
while(totalDegree > 0) {
    - Remove the node with highest degree and it's edges.
    - Update degree count of each node.
    - totalDegree = sum of degree of all remaining nodes.
}
remaining nodes are all disconnected

----------------
implementation :
----------------
- totalDegree taken care by size of set<pair<int,int>>s;

*/

// =======================================================================================================================================


// =======================================================================================================================================


// =======================================================================================================================================
