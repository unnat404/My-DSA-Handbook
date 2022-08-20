/*
Standard Graph Algorithms

- Topological Sort
    - dfs
    - bfs (kahn's algo)
- 

Reference:
- tuf graphs playlist :: https://www.youtube.com/playlist?list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw
- cp algorithms :: https://cp-algorithms.com/#graphs

*/
// ==============================================================================================================
#include <bits/stdc++.h>
#include <vector>
using namespace std; 
// ==============================================================================================================
// Topological Sort : dfs
// input : ensure that the graph input is DAG  (/if you are constructing graph yourself ensure its a DAG)
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
    // edges : a->b iff a is a pre-requisite of b (THIS DIRN OF EDGE IS IMP)

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

NOTE: 
- multiple toposorts are possible
- toposort is only possible for DAGs (directed acyclic graphs)

Observation (keep in mind for pblms) :
For a Topological ordering nodes are arranged in a line such that, all edges go from left to right :
- DFS Toposort : finds the rightmost vertex first (since we store the reverse order in a stack and reverse it at the end to get ordering)
- BFS Toposort : finds the leftmost vertex first (since we first find the node with indegree = 0 and keep on going level by level)

(kyu hila ala na bidu.....)
(Kahn chacha be like: " pushpa - pushpa raaj, mai jhukega ni saaala!! ")
*/

//===============================================================================================================

//Djikstra :
const int INF = 1000000000;
vector<vector<pair<int, int>>> adj;

void dijkstra(int s, vector<int> & d, vector<int> & p) {
    int n = adj.size();
    d.assign(n, INF);
    p.assign(n, -1);
    vector<bool> u(n, false);

    d[s] = 0;
    for (int i = 0; i < n; i++) {
        int v = -1;
        for (int j = 0; j < n; j++) {
            if (!u[j] && (v == -1 || d[j] < d[v]))
                v = j;
        }

        if (d[v] == INF)
            break;

        u[v] = true;
        for (auto edge : adj[v]) {
            int to = edge.first;
            int len = edge.second;

            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                p[to] = v;
            }
        }
    }
}

//path-restore::
vector<int> restore_path(int s, int t, vector<int> const& p) {
    vector<int> path;

    for (int v = t; v != s; v = p[v])
        path.push_back(v);
    path.push_back(s);

    reverse(path.begin(), path.end());
    return path;
}
//===============================================================================================================
/*
Minimum Spanning Tree :
- https://cp-algorithms.com/graph/mst_prim.html#trivial-implementations-on-m-and-on2-m-log-n
- https://cp-algorithms.com/graph/mst_kruskal.html
- https://cp-algorithms.com/graph/mst_kruskal_with_dsu.html

*/
// ==============================================================================================================
/* 
1)  Cycle Detection in Undirected Graph using BFS
2)  Cycle Detection in Undirected Graph using DFS
3)  Bipartite Graph (BFS)
4)  Bipartite Graph (DFS)
5)  Cycle Detection in Directed Graph using DFS
6)  TopoSort DFS (above)
7)  TopoSort BFS / Kahn's Algo (above)
8)  Cycle Detection in Directed Graph using BFS (using Kahn's Algo)
9)  Shortest Path in Undirected Graph with Unit Weights (from source to all other nodes)
10) 
11)
12)
13)
14)

TUF : NOTES : Graphs Playlist

- Cycle Detection in Undirected Graph using BFS
- Cycle Detection in Undirected Graph using DFS
- Bipartite Graph (BFS)
- Bipartite Graph (DFS)
- Cycle Detection in Directed Graph using DFS
- TopoSort DFS (above)
- TopoSort BFS / Kahn's Algo (above)
- Cycle Detection in Directed Graph using BFS (using Kahn's Algo)
- Shortest Path in Undirected Graph with Unit Weights (from source to all other nodes)
- 
- 
- 
- 


*/

// ==============================================================================================================
// 1) Cycle Detection in Undirected Graph using BFS
bool checkForCycle(int s,int V,vector<int> adj[],vector<int>& visited){
    // Creat Queue for BFS
    queue<pair<int,int>> q;//{node,parent} :: need for parent why?(think)
    visited[s]=1;
    q.push({s,-1});

    while(!q.empty()){
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for(auto& x:adj[node]){
            if(visited[x]==0){
                q.push({x,node});
                visited[x]=1;//imp to mark the node visited
            }
            else if(x!=parent) return true;
            // if the visited node(x) is not the parent of current node(node) => there's a cycle
        }
    }
    return false;//if no cycle after traversing whole component => return false 
}

bool isCycle(int V,vector<int> adj[]){ // main function 
    vector<int> vis(V+1,0);
    for(int i=0 ; i<V ; i++){
        if(!vis[i]){
            if(checkForCycle(i,V,adj,vis)) return true;
        }
    }
    return false;
}

/* Note: here we need to store parent of current node because:
- when traversing nbrs of node it will also visit its parent which is already visited so it will give a false positive for cycle 
- to avoid it we need to know the current node's parent
- to store parent here we can use
    - queue of pair (like done in above code), or ,
    - use visited array itself to store parent 
*/
// ==============================================================================================================
// 2) Cycle Detection in Undirected Graph using DFS
bool checkForCycle(int node,int parent,vector<int>& visited,vector<int> adj[]){
    visited[node] = 1;

    for(auto& nbr: adj[node]){
        if(visited[nbr]==0){
            if(checkForCycle(nbr,node,vis,adj)) return true;
        }  
        else if(nbr!=parent) return true;        
    }
    return false;

}

bool isCycle(int V,vector<int>& adj[]){ // main function 
    vector<int> vis(V+1,0);
    for(int i=0 ; i<V ; i++){
        if(!vis[i]){
            if(checkForCycle(i,-1,vis,adj)) return true;
        }
    }
    return false;
}
// ==============================================================================================================
// 3) Bipartite Graph (BFS) | Graph Coloring
// bipartite => can we color the graph using just 2 colors such that no 2 adjacent vertices have the same color
bool colorBipartiteBFS(int node, vector<int> &visited,vector<int> adj[]){
    queue<int> q;
    visited[node]=1;//coloring vertices
    q.push(node);
    while(!q.empty()){
        int curr = q.front();
        for(auto& nbr:adj[node]){
            if(visited[nbr]==-1){
                visited[nbr]= 1^visited[node];//opposite color to adjacent node
                q.push(nbr);
            }
            else if(visited[nbr]==visited[node]) return false;
            // if nbr has same color as parent(/adjacent) node => not bipartite
        }
    }
    return true;
}
bool checkBipartite(vector<int>& adj[], int n){
    vector<int> visited(n+1,-1); // visited itself used to mark color also
    // -1: no color , 1 : red , 2 : blue
    for(i=0; i<n; i++){
        if(visited[i]==-1){
            if(colorBipartiteBFS(i,visited,adj)==false) return false;
        }
    }
    // visited: stores one possible coloring 
    return true;

}
// ==============================================================================================================
// 4) Bipartite Graph (DFS) | Graph Coloring

bool colorBipartiteDFS(int node,int parent_color, vector<int>& visited,vector<int> adj[]){
    int color = visited[node];//
    for(auto& nbr:adj[node]){
        if(visited[nbr]==-1){
            //unvisited
            visited[nbr]= 1^parent_color;
            if(!colorBipartiteDFS(nbr,1^parent_color,visited,adj)) return false;
        }
        else if(visited[nbr]==parent_color){
            return false;
        }
    }
    return true;
}
bool checkBipartite(vector<int>& adj[], int n){
    vector<int> visited(n+1,-1); // visited itself used to mark color also
    // -1: no color , 1 : red , 2 : blue
    bool ans;
    for(i=0; i<n; i++){
        if(visited[i]==-1){
            visited[i]=1;//color of first node = 1 
            int parent_color = 1; 
            if(colorBipartiteDFS(i,1,visited,adj)==false) return false;
        }
    }
    // visited: stores one possible coloring 
    return true;

}
// ==============================================================================================================
// 5) Cycle Detection in Directed Graph using DFS
//----------------------------
// implementation #1:(more general)
//----------------------------
bool checkCycleDFS(int node,int vis[],int curr_path[],vector<int> adj[]){
    vis[node]=1;
    curr_path[node]=1;
    for(auto& nbr: adj[node]){
        if(vis[nbr]==-1){
            if(checkCycleDFS(nbr,vis,curr_path,adj)) return true; 
        }
        else if(curr_path[nbr]==1 && vis[nbr]==1){
            return true;
        }
    }
    curr_path[node]=0;//unmark current path node while while backtracking
    return false;
}
bool isCyclic(int N,vector<int> adj[]){
    int vis[N], curr_path[N];
    memset(vis,0,sizeof(vis));
    memset(curr_path,0,sizeof(curr_path));

    for(int i=0;i<n;i++){
        if(!vis[i]){
            if(checkCycleDFS(i,vis,curr_path,adj))
                return true;
        }
    }
    return false;
}
//----------------------------
// implementation #2
//----------------------------
class Solution {
public:    
    bool checkCycle(int node,vector<int> &vis,vector<vector<int>> &adj){
        if(vis[node]==2) return true;// visiting "node" again in its processing mode  => cycle present      
        vis[node]=2;// processing "node" 
        bool cycle=false;
        for(auto x:adj[node]){
            if(vis[x]!=1){
                if(checkCycle(x,vis,adj)) return true;
            }            
        }
        vis[node]=1;// processed already
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses,i,j;
        vector<vector<int>> adj(n);
        vector<int> vis(n,0);//unvis
        bool cycle = false;
        
        //build graph
        for(auto pre:prerequisites){
            adj[pre[0]].push_back(pre[1]);
        }
        
        for(i=0;i<n;i++){
            if(vis[i]==0){
                //unvisited
                cycle = checkCycle(i,vis,adj);
                if(cycle) return false;
            }
        }
        return true;
    }
};
/*
---------------------------------
vis[i] : {0,1,2} : 3 states of each node
0-> unvisited
1-> visited & processing done
2-> processing (/in current_path)

if you visit a node again if its in processing state(/in current path) => cycle exists
---------------------------------
*/
// ==============================================================================================================
// 6) Topological Sort (DFS)
// Check code above at top of page
// ==============================================================================================================
// 7) Topological Sort (BFS) / Kahn's Algo
// Check code above at top of page
// ==============================================================================================================
// 8) Cycle Detection in Directed Graph using BFS (using Kahn's Algo)

bool isCyclic(int n,vector<int> adj[]){
    queue<int> q;
    vector<int> indegree(n+1,0);

    for(int i=0;i<n;i++){
        for(auto& nbr:adj[i]){
            indegree[nbr]++;
        }
    }

    for(int i=0;i<n;i++){
        if(indegree[i]==0) q.push(i);
    }

    int count=0;//count of ordered nodes(/equivalent to no of nodes not part of cycle) in graph
    while(!q.empty()){
        int node=q.front();
        q.pop();
        count++;
        for(auto& nbr:adj[node]){
            indegree[nbr]--;
            if(indegree[nbr]==0){
                q.push(nbr);
            }
        }
    }

    if(count==n){
        return false;//no cycle present => iff (no. of vertices in graph = no. of vertices visited by kahn's algo) 
    }
    return true;

}
// this simply reduces to applying kahn's algo & counting the no of nodes for which we can order the graph 
// using kahn's algo only the members not part of cycle can be part of ordering (since all nodes part of cycle will never acheive indegree=0)
// ==============================================================================================================
// 9) Shortest Path in Undirected Graph with *Unit* edge Weights (from given source to all other nodes)

vector<int> shortestPathInUndirected(int n,int src,vector<int>& adj){
    vector<int> distance(n,INT_MAX);//assign infinity cost to all nodes initially
    queue<int> q;
    q.push(src);
    distance[src]=0;

    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto& nbr:adj[node]){
            if(distance[node]+1 < distance[nbr]){
                distance[nbr]=distance[node]+1;
                q.push(nbr);
            }
        }
    }

    return distance;// distance vector from source node to all other nodes 
}
// ==============================================================================================================
// 10) Shortest Path in Directed Acyclic Graph (DAG)
/*
Approach:
- first find topo sort of DAG(this is imp)
- traverse(bfs) in topo order and keep updating distance of nodes from source 
*/
void findTopoSort(int node, stack<int> &rev_order, vector<int>& vis, vector<pair<int,int>>& adj[]){
    vis[node]=1;    
    for(auto& nbr:adj[node]){
        if(!vis[nbr]) findTopoSort(nbr,rev_order,vis,adj);
    }
    rev_order.push(node);//note : we push the node in stack at the last(after all its chilren nodes are visited)
}
vector<int> shortestPathInDAG(int src,int n,vector<pair<int,int>> adj[]){

    stack<int> rev_order;
    for(int i=0;i<n;i++){
        if(!vis[i]) findTopoSort(i,rev_order,vis,adj);
        // find toposort for all components: we simply add toposort of different connected components to the same stack
    }

    vector<int> distance(n);
    for(i=0;i<n;i++) distance[i]=INT_MAX;
    distance[src]=0;

    while(!st.empty()){
        int node= st.top();
        st.pop();

        if(distance[node]!=INT_MAX){
            // either src node ,OR, some of its descendents will satisfy above condition
            for(auto& nbr: adj[node]){
                if(distance[nbr.first] > distance[node]+nbr.second){
                    distance[nbr.first] = distance[node]+nbr.second;
                }
            }
        }
    }
    return distance;
}


// ==============================================================================================================

// ==============================================================================================================

// ==============================================================================================================

// ==============================================================================================================
