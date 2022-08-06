/***************************************************************************************************
Graphs Problem List(found during problem solving/contests):

- Leetcode 2360. Longest Cycle in a Graph :: https://leetcode.com/problems/longest-cycle-in-a-graph/


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


// =======================================================================================================================================


// =======================================================================================================================================


// =======================================================================================================================================
