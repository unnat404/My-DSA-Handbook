/*
Round 2 : OA
- https://www.geeksforgeeks.org/minimum-circles-needed-to-be-removed-so-that-all-remaining-circles-are-non-intersecting/
- 
*/
// ===============================================================================
/*
Qn) Find minimum no of circles to be removed so that no 2 circles overlap/touch 
- https://codeforces.com/blog/entry/106177?f0a28=1
- https://leetcode.com/discuss/interview-question/2416447/intuit


sample i/p:
3
0 0 3
2 0 3
4 0 3

sample o/p:
2

---------------------------------------
Sol)
Approach/Inspiration:
Given the constraints, I think an O(N^2) solution will be acceptable.

You can create a graph data structure where the nodes represent the circles and edges between two nodes denote the corresponding circles overlapping. Creating this graph will have O(N^2) time complexity.

Now the question can be re-interpreted as deleting the minimum number of nodes from the graph such that none of the remaining nodes are connected to each other (i.e. the remaining graph only has nodes and no edges). You can do this by selecting an edge (in any order) and getting rid of it by deleting one of its nodes (select the node with the maximum number of edges) also, don't forget to remove the other edges of this node from the graph as well! Repeat this step until all the edges are removed from the graph.
This operation will take O(E) where E = number of edges ( 0 <= E <= N^2 )
*/

#include <bits/stdc++.h>
using namespace std;
#include <stdio.h>


bool isIntersecting(vector<int> &a,vector<int> &b){
    double d = sqrt((a[2]-b[2])*(a[2]-b[2]) + (a[1]-b[1])*(a[1]-b[1]));
    
    if(d<= a[0]+b[0]) return true;
    return false;
}
int main()
{
    int i,j,n,x,y,r,cur,ans=0;
    cin>>n;
    vector<vector<int>> p(n,vector<int>(3,0));
    vector<set<int>> adj(n);
    for(i=0;i<n;i++){
        cin>>x>>y>>r;
        p[i][0]=r,p[i][1]=x,p[i][2]=y;
    }
    
    vector<int> indeg(n,0);
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            if(isIntersecting(p[i],p[j])){
                adj[i].insert(j);
                adj[j].insert(i);
                indeg[i]++,indeg[j]++;
            }
        }
    }
    
    /* 
    note: 
    key importance is to be given to data structures used 
    since it helps in creating/implementing dynamic priority_queue like feature
    */
    set<pair<int,int>> pq;
    for(i=0;i<n;i++){
        if(indeg[i]>0) pq.insert({indeg[i],i});
    }
    pair<int,int> c;
    while(!pq.empty()){
        ans++;
        auto it =  pq.rbegin();
        c = *it;
        cur = c.second;
        pq.erase(c);
        for(auto nbr:adj[cur]){
            if(indeg[nbr]>0){
                pq.erase({adj[nbr].size(),nbr});
                adj[nbr].erase(cur);
                indeg[nbr]--;
                if(indeg[nbr]>0) pq.insert({adj[nbr].size(),nbr});
            }
        }
        adj[cur].clear();
    }
    cout<<ans;
    return 0;
}
// ===========================================================================

#include <bits/stdc++.h>
#define ll long long
using namespace std; 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    ll n,m;
    cin>>n>>m;
    if(m>=n){
        
        for(int i=1;i<=n;i++){
            cout<<i<<' ';
        }
        cout<<'\n';
    }
    else{
        int val=1;
        while(n--){
            
            cout<<val<<' ';
            val++;
            if(val==m+1){
                val=1;
            }            
        }
        cout<<'\n';
    } 
    return 0;
}