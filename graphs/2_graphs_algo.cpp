/*
Standard Graph Algorithms

- Topological Sort
    - dfs
    - bfs (kahn's algo)
- 

Reference:
- tuf graphs playlist :: https://www.youtube.com/playlist?list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw
- cp algorithms

*/
// ==============================================================================================================
#include <bits/stdc++.h>
using namespace std; 
// ==============================================================================================================
// Topological Sort : dfs
// input : ensure that the graph input is DAG  (/if you are constructing grah yourself ensure its a DAG)
// output: one of the possible topological order
void findTopoSortDFS(int node,vector<int>& visited, stack<int>& rev_order, vector<int> graph[]){
    visited[node] = 1;

    for(const auto& nbr:graph[node]){
        if(!visited[nbr]){
            findTopoSortDFS(nbr,visited,rev_order,graph);
        }
    }
    rev_order.push(node);    
}
vector<int> topoSortDFS(int N, vector<int> graph[]){
    // assuming nodes are in range [0...N-1]
    // edges : a->b iff a is a pre-requisite of b
    int i,j;
    vector<int> visited(N,0);
    stack<int> rev_order;
    vector<int> topo_order;//ans
    for(i=0;i<N;i++){
        if(!visited[i]){
            findTopoSortDFS(i,visited,rev_order,graph);
        }
    }
    while(!rev_order.empty()){
        topo_order.push_back(rev_order.top());
        rev_order.pop();
    }
    return topo_order;

}

// int main(){
//     vector<int> graph[5];
//     graph[0] = {1};
//     graph[1] = {2};//,{3},{4},{}];
//     vector<int> ans = topoSortDFS(5,graph); 
//     for(const auto& i: ans) cout<<i<<" ";
//     cout<<"\n";
//     return 0;
// }

// ---------------------------------------------------------------
// Topological Sort : bfs (kahn's algo)
// input : ensure that the graph input is DAG  (/if you are constructing grah yourself ensure its a DAG)
// output: one of the possible topological order
vector<int> topoSortBFS(int N, vector<int> graph[]){
    // note: here the nodes are in between [0...N-1] ,
    // otherwise for char/any general nodes we will have to usee different data structures 
    // like: graph :: unordered_map<char,unordered_set<char>> graph;
    // indegree :: inordred_map<char,int> indegree;

    vector<int> indegree(N,0);
    vector<int> order;// store the topo ordering of nodes
    queue<int> q;// to store nodes who have reached indegree=0 in fifo manner

    for(int i=0;i<N;i++){
        for(const auto& nbr:graph[i]){
            indegree[nbr]++;// initial value of indegree for all nodes is assigned as  0
        }
    }

    //push all nodes with initial indegree = 0, in the queue 
    for(int i=0;i<N;i++){
        if(indegree[i]==0)
            q.push(i);
    }

    //bfs traversal + topo sort logic
    while(!q.empty()){
        int node = q.front();
        order.push_back(node);
        q.pop();

        for(auto& nbr:graph[node]){
            indegree[nbr]--;
            if(indegree[nbr]==0) q.push(nbr);
        }
    }
    return order;
}

int main(){
    vector<int> graph[7];
    graph[0] = {1};
    graph[1] = {2,3};
    graph[2] = {5,4};
    graph[3] = {4};
    graph[4] = {};
    graph[5] = {6};
    graph[6] = {};

    //---------------------------------------------
    cout<<"\n\nTopoSort order for DFS:: ";
    vector<int> ansDFS = topoSortDFS(7,graph); 
    for(const auto& i: ansDFS) cout<<i<<" ";
    //---------------------------------------------
    cout<<"\n\nTopoSort order for BFS:: ";
    vector<int> ansBFS = topoSortBFS(7,graph); 
    for(const auto& i: ansBFS) cout<<i<<" ";
    cout<<"\n";
    //---------------------------------------------    
    return 0;
}

/*
Sample Output for above graph : 
TopoSort order for DFS:: 0 1 3 2 4 5 6

TopoSort order for BFS:: 0 1 2 3 5 4 6
*/

// ==============================================================================================================

// ==============================================================================================================

// ==============================================================================================================

// ==============================================================================================================

// ==============================================================================================================

// ==============================================================================================================

// ==============================================================================================================

// ==============================================================================================================

// ==============================================================================================================

// ==============================================================================================================

// ==============================================================================================================

// ==============================================================================================================

// ==============================================================================================================

// ==============================================================================================================

// ==============================================================================================================
