/***************************************************************************************************
Graphs Problem List:

 -> matrices as graphs: 
    - Leetcode 200. Number of Islands :: https://leetcode.com/problems/number-of-islands/
    - Leetcode 53. Maximum subarray :: https://leetcode.com/problems/maximum-subarray/
    - **Leetcode 133. Clone Graph :: https://leetcode.com/problems/clone-graph/
    - (to do)(facebook) Leetcode 990. Satisfiability of Equality Equations :: https://leetcode.com/problems/satisfiability-of-equality-equations/
    - Leetcode 130. Surrounded Regions :: https://leetcode.com/problems/surrounded-regions/
    - **Leetcode 1254. Number of Closed Islands :: (same as 130 but you have to think here)(flood fill type) https://leetcode.com/problems/number-of-closed-islands/
    - Leetcode 694. Number of Distinct Islands (premium):: https://binarysearch.com/problems/Distinct-Islands
    - 
    - to do :: Leetcode 
    - to do :: Leetcode 

-> graphs topic based 
    - Leetcode 207. Course Schedule :: https://leetcode.com/problems/course-schedule/ (cyclicity for directed)(uber)
    - cyclicity for undirected graphs 
    - Leetcode 210. Course Schedule II :: https://leetcode.com/problems/course-schedule-ii/ (topo sort)(uber)
    - Leetcode 127. Word Ladder :: https://leetcode.com/problems/word-ladder/ (shaortest path)
    - Leetcode 542. 01 Matrix :: https://leetcode.com/problems/01-matrix/
    - Leetcode  1162. As Far from Land as Possible :: https://leetcode.com/problems/as-far-from-land-as-possible/
    - (to do)Leetcode premium 269:: Alien Dictionary :: https://leetcode.com/problems/alien-dictionary/
        - (to do)Lintcode :: Alien Dictionary :: https://www.lintcode.com/problem/892/
        - https://practice.geeksforgeeks.org/problems/alien-dictionary/1/
        - https://www.codingninjas.com/codestudio/problem-details/alien-dictionary_630423 || 
        - topo sort qn
    - Leetcode 743. Network Delay Time :: https://leetcode.com/problems/network-delay-time/ (shortest path- wieghted)
    - (to do)Leetcode 1102. Path with Maximum Minimum value :: https://leetcode.ca/all/1102.html
        - codestudio link:: https://www.codingninjas.com/codestudio/problems/path-with-maximum-and-minimum-value_1281861
    - (to do)Leetcode:: 1334. Find the City With the Smallest Number of Neighbors at a Threshold Distance :: https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/
        - https://cp-algorithms.com/graph/all-pair-shortest-path-floyd-warshall.html
    - (to do)Leetcode 1192. Critical Connections in a Network :: https://leetcode.com/problems/critical-connections-in-a-network/
        - question on bridges 
    - 


 -> To Do:
    - https://leetcode.com/problems/groups-of-strings/
    -* https://leetcode.com/problems/k-highest-ranked-items-within-a-price-range/ 
    - https://www.hackerrank.com/challenges/lilys-homework/problem 
    - * https://www.geeksforgeeks.org/minimum-number-swaps-required-sort-array/
    - * Leetcode premium 269:: Alien Dictionary :: https://leetcode.com/problems/alien-dictionary/ || https://www.lintcode.com/problem/892/

 -> Must Do:
    ○ Leetcode 133. Clone Graph :: https://leetcode.com/problems/clone-graph/
    ○ Leetcode 1254. Number of Closed Islands

--------------------
Leetcode Premium Problem resources:
    - For exact leetcode questions + company tags :: https://leetcode.ca/all/problems.html
    - 
    - codestudio search pblm
    - binarysearch 
    - lintcode
    
--------------------

*****************************************************************************************************/

// =======================================================================================================================================
#include <bits/stdc++.h>
using namespace std;
// =======================================================================================================================================
// Leetcode 200. Number of Islands :: https://leetcode.com/problems/number-of-islands/
class Solution {
public:
    bool inside(int x,int y,int n,int m){
        if(x<0 || x>=n || y<0 || y>=m) return false;
        return true;
    }
    void dfs(vector<vector<char>> &grid,int x,int y){
        int n=grid.size(),m=grid[0].size(),a,b;
        grid[x][y]='2';
        int dx[4]={-1,1,0,0};//left,right,down,up
        int dy[4]={0,0,-1,1};
        for(int i=0;i<4;i++){
            a=x+dx[i],b=y+dy[i];
            if(inside(a,b,n,m) && grid[a][b]=='1'){
                dfs(grid,a,b);
            } 
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size(),m=grid[0].size(),i,j,count=0;
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    dfs(grid,i,j);count++;
                }
            }
        }
        return count;
    }
};
//can be done using bfs also - qn essentially boils down to finding no of connected components

//===================================================================================================
// Leetcode 695. Max Area of Island :: https://leetcode.com/problems/max-area-of-island/
class Solution {
public:
    bool inside(int x,int y,int n,int m){
        if(x<0 || x>=n || y<0 || y>=m) return false;
        return true;
    }
    void dfs(vector<vector<int>> &grid,int x,int y,int &size){
        grid[x][y]=2;//marking visited
        ++size; // finding size of current connected component
        int n=grid.size(),m=grid[0].size(),i,j,a,b;
        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,-1,1};
        
        for(i=0;i<4;i++){
            a=x+dx[i],b=y+dy[i];
            if(inside(a,b,n,m) && grid[a][b]==1){//not visited and inside boundary
                dfs(grid,a,b,size);
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size(),i,j,area=0,cur=0;
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if(grid[i][j]==1){
                    //not visited
                    dfs(grid,i,j,cur=0);
                    area=max(area,cur);//updating max area 
                }
            }
        }
        return area;
    }
};
//can be done using bfs also - qn essentially boils down to finding size of largest connected components

// Q) another variation of above qn: finding size of largest perimeter of connected components
// Sol) same as above , we only increase the "size" of a component if current element lies on the perimeter of a component
// component perimeter check: 
// - if (i,j) node has one adjacent 0 to it,or,
// - if (i,j) lies on the border of the matrix  

//===================================================================================================
// -------------IMP Question-------------
// Leetcode 133. Clone Graph :: https://leetcode.com/problems/clone-graph/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public: 
    void dfs(Node* cur,unordered_map<Node*,Node*>& m){
        Node* newNode=new Node(cur->val);
        m[cur]=newNode;//map old node ka address to newNode address
        
        for(auto& nbr:cur->neighbors){
            if(m.find(nbr)!=m.end()){
                //neighbour has been visited before & space has been allocated to its clone node
                newNode->neighbors.push_back(m[nbr]);                
            }
            else{
                dfs(nbr,m);// explore that neighbour if its not visited
                //(as only after vsisiting it once is the clone of that node is formed)
                newNode->neighbors.push_back(m[nbr]);//then push that cloned node to newNode's neighbour vector
            }
        }       
        
    }
    Node* cloneGraph(Node* node) {
        if(node==nullptr) return nullptr;
        unordered_map<Node*,Node*> m;//<oldNode_address, newNode_address>  
        // this map also tells us if a node is visted or not 
        dfs(node,m);
        return m[node];//return the clone node for the given node
        
    }
};

//===================================================================================================
//Leetcode 547. Number of Provinces ::  https://leetcode.com/problems/number-of-provinces/
class Solution {
public:
    void dfs(int node,vector<int>& visited,vector<vector<int>> &isConnected){
        visited[node]=1;//mark visited
        int n=visited.size();
        for(int i=0;i<n;i++){
            if(isConnected[node][i]==1 && i!=node && !visited[i]){
                // connected node & i!=node & not visited[i] then perform dfs on it 
                dfs(i,visited,isConnected);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size(),i,provinceCount=0;
        //visited k liye array
        vector<int> visited(n,0);
        
        for(i=0;i<n;i++){
            if(!visited[i]){
                dfs(i,visited,isConnected);
                provinceCount++;
            }
        }
        return provinceCount;
    }
};
// Question boils down to finding no of connected components (easy peasy)
//===================================================================================================

// Leetcode 990. Satisfiability of Equality Equations :: https://leetcode.com/problems/satisfiability-of-equality-equations/
// company :: facebook

// sir ka code


// -------------TO DO--------

// my code :: incorrect hai niche wla  (error aa rha hai check it why)
class Solution {
public:
    //question came in facebook
    void dfs(char node,int component_idx,unordered_map<char,int>& m,vector<vector<int>>& relation ){
        m[node]=component_idx;
        
        for(int i=0;i<26;i++){
            if(m.find((char)((int)'a'+i))==m.end() && relation[(int)(node-'a')][i]==1 ){
                // unvisited & has equality relation
                dfs((char)((int)'a'+i),component_idx,m,relation);
            }
        }        
    }
    bool equationsPossible(vector<string>& equations) {
        // 1. make connected graph for equals and assign(/map) all nodes in same component same value (label components)
        // 2. now traverse for not equals elements , these 2 nodes should have different component values for qun to exist
        
        //think about self loops in both equality(a==a) & unequality(a!=a) 
        int i,j,n=equations.size(),component_index=0;
        unordered_map<char,int> m;//node -> component_index
        vector<vector<int>> relation(26,vector<int> (26,0));
        unordered_set<char> s;
        // vector<vector<char>> eq(26),uneq(26);
        for(i=0;i<n;i++){
            char a,b,sign;
            s.insert(a),s.insert(b);
            a=equations[i][0],sign=equations[i][1],b=equations[i][3];
            if(sign=='!'){
                relation[(int)(a-'a')][(int) (b-'a')]=-1;//unequal
                // relation[(int)(b-'a')][(int)(a-'a')]=-1;
                // uneq[a-'a'].push_back(b);
            }
            else{
                relation[(int)(a-'a')][(int)(b-'a')]=1;//equal
                // relation[(int)(b-'a')][(int)(a-'a')]=1;
                // eq[a-'a'].push_back(b);
            }
        }
        
        for(auto& ch:s){//forming & labelling components
            if(m.find(ch)==m.end()){
                //not visited
                dfs(ch,component_index,m,relation);
                component_index++;
            }
        }
        
        for(i=0;i<26;i++){
            for(j=0;j<26;j++){
                if(relation[i][j]==-1 && m[(char)((int)'a'+i)]==m[(char)((int)'a'+j)]) return false;
            }
        }
        return true;
        
    }
};

//===================================================================================================
// Leetcode 130. Surrounded Regions :: https://leetcode.com/problems/surrounded-regions/

class Solution {
public:
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};
    bool inRange(int x,int y, int m,int n){
        if(x<0 || x>=m || y<0 || y>=n) return false;
        return true;
    }
    void dfs(int x,int y,vector<vector<int>> &vis){
        int i,j,m=vis.size(),n=vis[0].size();
        vis[x][y]=-1;
        
        for(i=0;i<4;i++){
            int a=x+dx[i],b=y+dy[i];
            if(inRange(a,b,m,n) && vis[a][b]==1) dfs(a,b,vis);
        }
    }
    
    void solve(vector<vector<char>>& board) {
        // 0. visited matrix => 0 if X, 1 if 'O' 
        // 1. visit all O's that are connected to boundary and mark them -1 in visited matrix
        // 2. visit remaining O's (which are marked 1 in visited matrix) and convert them to X
        
        int i,j,m=board.size(),n=board[0].size();
        vector<vector<int>> visited(m,vector<int> (n,0));
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                if(board[i][j]=='O') visited[i][j]=1;//mark O as 1
            }                
        }
        
        for(i=0;i<m;i++){
            if(visited[i][0]==1) dfs(i,0,visited);// visit left border
            if(visited[i][n-1]==1) dfs(i,n-1,visited);//visit right border
        }
        for(i=0;i<n;i++){
            if(visited[0][i]==1) dfs(0,i,visited);// visit left border
            if(visited[m-1][i]==1) dfs(m-1,i,visited);//visit right border
        }
        
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                if(visited[i][j]==1) board[i][j]='X';
            }
        }
    }
};

//===================================================================================================
// Leetcode :: 1254. Number of Closed Islands :: https://leetcode.com/problems/number-of-closed-islands/

class Solution {
public:
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};
    bool inRange(int x,int y,int m,int n){
        if(x<0 || y<0 || x>=m || y>=n) return false;
        return true;
    }
    void dfs(int x,int y,vector<vector<int>> &grid){
        int i,j,m=grid.size(),n=grid[0].size();
        grid[x][y]=-1;//mark visited
        
        for(i=0;i<4;i++){
            int a=x+dx[i],b=y+dy[i];
            if(inRange(a,b,m,n) && grid[a][b]==0) dfs(a,b,grid);
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        // 1. visit all lands that are connected to any of the borders & mark them as -1
        // 2. now count no of connected components  (of label 1)
        
        int i,j,m=grid.size(),n=grid[0].size(),count_islands=0;
        //visit and mark all lands that ar connected to any border as -1 
        ///(thus disqualifing those lands to be closed islands)
        for(i=0;i<m;i++){
            if(grid[i][0]==0) dfs(i,0,grid);//visit lands components connected to left boundary
            if(grid[i][n-1]==0) dfs(i,n-1,grid);//rioght boundary
        }
        for(i=0;i<n;i++){
            if(grid[0][i]==0) dfs(0,i,grid);//top boundary
            if(grid[m-1][i]==0) dfs(m-1,i,grid);//bottom boundary
        }
        
        for(i=1;i<m-1;i++){
            for(j=1;j<n-1;j++){
                if(grid[i][j]==0){
                    dfs(i,j,grid);
                    count_islands++;//count no of islands(/connected components with label=0) now 
                }
            }
        }
        return count_islands;
    }
};
//===================================================================================================
// Leetcode 694. Number of Distinct Islands (premium):: https://binarysearch.com/problems/Distinct-Islands

int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
char dir[4]={'R','D','L','U'};// is this direction of visiting imp?? maybe?? i dont think so
// char dir[4]={'L','D','R','U'};
void dfs(int x,int y,string &island,vector<vector<int>> &matrix){
    int n=matrix.size(),m=matrix[0].size();
    matrix[x][y]=2;

    for(int i=0;i<4;i++){
        int a=x+dx[i],b=y+dy[i];
        if(a<0 || b<0 || a>=n || b>=m || matrix[a][b]!=1) continue;
        island+=dir[i];
        dfs(a,b,island,matrix);
        island+='#';//backtracking step/divider to distinguish between islands
    }
}
int solve(vector<vector<int>>& matrix) {
    int n=matrix.size(),m=matrix[0].size(),i,j;
    unordered_set<string> s;//distinct islands storing 
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(matrix[i][j]==1){
                string island="";
                dfs(i,j,island,matrix);
                s.insert(island);
            }
        }
    }
    return (int)s.size();//return size of set => no of distinct islands
}
// in above approach its valid to think:: will the island string differ if we start fromma different node of the island
// Ans is YES it will be differnet BUT it WONT happen for same islands as we start traversing form the topmost & leftmost node in every island
// so we need not take care of that

/* 
-> crux of the problem is to store islands & differentiate between them (/know if 2 islands are equal)
    Some ways to acheive it is: 
    - keep set<vector<pair<int, int>>> s; where vector of pair stores the origin shifted coordinates of islands (https://binarysearch.com/problems/Distinct-Islands/solutions/4719189)(for reference & soln)
    - keep set<string> s; where string represdents the island by mapping the order in which we traverse the island 
*/

/*
d,r,u,l

d # r # 
1 1 
1    

d r # #
1
1 1
 
# represents the backtracking step (needed to distinguish between different islands)

*/
//===================================================================================================
// Leetcode 207. Course Schedule :: https://leetcode.com/problems/course-schedule/
// Company tags:: Uber 

//soln: you have to keep 2 arrays(for directed graphs mein cyclicity check krne k liye)
// -> one for current path ,&,
// -> one for visited (only visited is need in case of undirected graphs) 
class Solution {
public:
    bool checkCycle(int node,vector<int>& visited,vector<bool> &cur_path,vector<vector<int>> &adj){
        // visited[node]=1;
        bool cycle=false;
        for(auto& nbr:adj[node]){
            if(cur_path[nbr]==true) return cycle=true;//cycle present
            
            if(!visited[nbr]){//not visited
                cur_path[nbr]=true;
                visited[nbr]=1;
                cycle= cycle || checkCycle(nbr,visited,cur_path,adj);
                cur_path[nbr]=false;
            }            
        }return cycle;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int i,n=prerequisites.size();
        vector<int> visited(numCourses,0);
        vector<vector<int>> adj(numCourses);
        for(auto& x:prerequisites){
            adj[x[0]].push_back(x[1]);
        }
        
        for(i=0;i<numCourses;i++){
            if(!visited[i]){
                vector<bool> cur_path(numCourses,false);
                visited[i]=1;
                cur_path[i]=true;
                if(checkCycle(i,visited,cur_path,adj)){
                    return false;//if cycle present => course cant be finished as no starting point
                }
                cur_path[i] = false;
            }
        }
        return true;//no cycle => course can be finished
    }
};

/*
//not my  approach : see this later (from leetcode discuss)

//Just a simple topological sort, which can be finished in 15 lines. Beats 99%.

bool canFinish(int n, vector<pair<int, int>>& pre) {
    vector<vector<int>> adj(n, vector<int>());
    vector<int> degree(n, 0);
    for (auto &p: pre) {
        adj[p.second].push_back(p.first);
        degree[p.first]++;
    }
    queue<int> q;
    for (int i = 0; i < n; i++)
        if (degree[i] == 0) q.push(i);
    while (!q.empty()) {
        int curr = q.front(); q.pop(); n--;
        for (auto next: adj[curr])
            if (--degree[next] == 0) q.push(next);
    }
    return n == 0;
}

*/
/*
------------
input:
------------
20
[[0,10],[3,18],[5,2],[6,11],[11,14],[13,1],[15,1],[17,4],[2,7],[7,19],[7,8],[8,9],[9,12],[12,16]]
3
[[0,1],[0,2],[1,2]]
2
[[1,0]]
2
[[1,0],[0,1]]
100
[[1,0],[2,0],[2,1],[3,1],[3,2],[4,2],[4,3],[5,3],[5,4],[6,4],[6,5],[7,5],[7,6],[8,6],[8,7],[9,7],[9,8],[10,8],[10,9],[11,9],[11,10],[12,10],[12,11],[13,11],[13,12],[14,12],[14,13],[15,13],[15,14],[16,14],[16,15],[17,15],[17,16],[18,16],[18,17],[19,17],[19,18],[20,18],[20,19],[21,19],[21,20],[22,20],[22,21],[23,21],[23,22],[24,22],[24,23],[25,23],[25,24],[26,24],[26,25],[27,25],[27,26],[28,26],[28,27],[29,27],[29,28],[30,28],[30,29],[31,29],[31,30],[32,30],[32,31],[33,31],[33,32],[34,32],[34,33],[35,33],[35,34],[36,34],[36,35],[37,35],[37,36],[38,36],[38,37],[39,37],[39,38],[40,38],[40,39],[41,39],[41,40],[42,40],[42,41],[43,41],[43,42],[44,42],[44,43],[45,43],[45,44],[46,44],[46,45],[47,45],[47,46],[48,46],[48,47],[49,47],[49,48],[50,48],[50,49],[51,49],[51,50],[52,50],[52,51],[53,51],[53,52],[54,52],[54,53],[55,53],[55,54],[56,54],[56,55],[57,55],[57,56],[58,56],[58,57],[59,57],[59,58],[60,58],[60,59],[61,59],[61,60],[62,60],[62,61],[63,61],[63,62],[64,62],[64,63],[65,63],[65,64],[66,64],[66,65],[67,65],[67,66],[68,66],[68,67],[69,67],[69,68],[70,68],[70,69],[71,69],[71,70],[72,70],[72,71],[73,71],[73,72],[74,72],[74,73],[75,73],[75,74],[76,74],[76,75],[77,75],[77,76],[78,76],[78,77],[79,77],[79,78],[80,78],[80,79],[81,79],[81,80],[82,80],[82,81],[83,81],[83,82],[84,82],[84,83],[85,83],[85,84],[86,84],[86,85],[87,85],[87,86],[88,86],[88,87],[89,87],[89,88],[90,88],[90,89],[91,89],[91,90],[92,90],[92,91],[93,91],[93,92],[94,92],[94,93],[95,93],[95,94],[96,94],[96,95],[97,95],[97,96],[98,96],[98,97],[99,97]]
------------
output:
------------
true
true
true
false
true
*/
// Qn boils down to findig cyclicity in a directed graph
//===================================================================================================
// Leetcode 210. Course Schedule II :: https://leetcode.com/problems/course-schedule-ii/
// tags : uber, topo sort
#import <bits/stdc++.h>
class Solution {
public:
   
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        //1. start traversing elements with inDegree=0 and make their neighbours ka inDegree-1
        //2. if after traversing all elemnts the course_order ka size != numCourses => cycle present
        vector<int> in(numCourses,0);//inDegree for each node
        vector<int> cur_set,course_order;//stores the set we are traversing now
        int i,idx=0;
        vector<vector<int>> adj(numCourses);
        
        //Populate graph and indegree vector
        for(i=0;i<prerequisites.size();i++){
            // our mapping: Edge from prerequisites[1] -> prerequisites[0]
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);// 0 pe indegree hoga 
            in[prerequisites[i][0]]++;
        }
        //Initialize the first set of elements to visit with indgree = 0
        for(i=0;i<numCourses;i++){
            if(in[i]==0){
                cur_set.push_back(i);
                course_order.push_back(i);
            }             
        }
        
        while(idx < cur_set.size()){
            for(auto& nbr:adj[cur_set[idx]]){
                in[nbr]--;//Decrease indegree of all neighbours of idx by 1
                if(in[nbr]==0){
                    cur_set.push_back(nbr);
                    course_order.push_back(nbr);
                }
            }idx++;
        }
        // return cur_set.size()!=numCourses ? vector<int>():cur_set;
        return course_order.size()!=numCourses ? vector<int>():course_order;
    }
};
// Topological sort based question
//===================================================================================================
//  Leetcode 127. Word Ladder :: https://leetcode.com/problems/word-ladder/
// tags :  google(v.old) , shortest path
class Solution {
public:
    //1. model of graph : nodes as wordlist elements & beginWord  (undirected edges bw elements at distance 1)
    //2. find shortest distance between beginWord & endWord nodes : use level order traversal for it(bfs)
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int ans=0,i,j,level=0;
        unordered_set<string> visited,dict;
        queue<string> curLevel;
        
        for(auto& word:wordList){
            dict.insert(word);
        }
        curLevel.push(beginWord); //start with the beginWord
        visited.insert(beginWord);//mark it as visited
        
        while(!curLevel.empty()){
            int len=curLevel.size();
            level++;// increment level
            while(len>0){
                len--;
                string cur,temp;
                cur=temp=curLevel.front();
                curLevel.pop();

                for(i=0;i<cur.size();i++){
                    for(j=0;j<26;j++){
                        cur[i] = 'a'+j;// change the i'th charecter in current word to all possible letters 'a' to 'z'
                        // if(cur==endWord) return level+1;
                        if(dict.find(cur)!=dict.end() && visited.find(cur)==visited.end()){
                            curLevel.push(cur);  
                            visited.insert(cur);//mark visited
                            if(cur==endWord) return level+1;
                        }
                    }cur=temp;// change cur to same initial word in the queue 
                }
            }
        }
        return 0;
        
    }
};
//===================================================================================================

// Leetcode 542. 01 Matrix :: https://leetcode.com/problems/01-matrix/
class Solution {
public:
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};
    bool inRange(int i,int j,int n,int m){// kina like a inRange() function with modified aim to find distance
        // int r=dist.size(),c=dist[0].size(),x=1e5;
        if(i<0 || j<0 || i>=n || j>=m) return false;
        return true;        
    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size(),i,j,distance=0;
        queue<pair<int,int>> curset;// current set to be iterated upon
        vector<vector<int>> visited(n,vector<int>(m,-1));
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if(mat[i][j]==0){
                    visited[i][j]=distance;//initial distance =0 for all 0's in th matrix
                    curset.push({i,j});
                } 
            }
        }
        
        while(!curset.empty()){
            int len=curset.size();
            distance++;//increment the level for level order traversal 
            while(len>0){
                len--;
                i=curset.front().first,j=curset.front().second;
                curset.pop();
                for(int x=0;x<4;x++){
                    int a=i+dx[x],b=j+dy[x];
                    if(inRange(a,b,n,m) && visited[a][b]==-1){
                        //inrange and unvisited
                        visited[a][b]=distance;
                        curset.push({a,b});
                    }
                }                
            }
        }
        return visited;
        
    }
};

// pblm boils down to finding shortest path
// but we do parallel bfs for multiple nodes at same time (following level order traversal)

//===================================================================================================
// Leetcode  1162. As Far from Land as Possible :: https://leetcode.com/problems/as-far-from-land-as-possible/
class Solution {
public:
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};
    
    int maxDistance(vector<vector<int>>& grid) {
        int i,j,n=grid.size(),m=grid[0].size(),distance=-1;
        vector<vector<int>> vis(n,vector<int> (m,-1));
        queue<pair<int,int>> q;
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if(grid[i][j]==1){
                    distance=0;
                    vis[i][j]=distance;
                    q.push({i,j});
                }
            }
        }
        // Level-order traversal (multi-source bfs)
        while(!q.empty()){
            int len = q.size();
            distance++;
            while(len>0){
                len--;
                int x=q.front().first,y=q.front().second;
                q.pop();
                for(i=0;i<4;i++){
                    int a = x+dx[i], b = y+dy[i];
                    if(a<0 || a>=n || b<0 || b>=m) continue;
                    
                    if(vis[a][b]==-1){
                        q.push({a,b});
                        vis[a][b]=distance;
                    }
                }
            }
        }
        return distance<=1 ? -1 : distance-1 ;
        
    }
};
//  qn boils down to : simultaneos bfs for shortest path
// pblm is simlar to prev one

//===================================================================================================
// Leetcode premium 269:: https://leetcode.com/problems/alien-dictionary/
// Lintcode :: https://www.lintcode.com/problem/892/

// Practice Link : https://practice.geeksforgeeks.org/problems/alien-dictionary/1/#
#include <bits/stdc++.h>
using namespace std; 

class Solution{
    public:
    string findOrder(string dictionary[], int n, int K) {
        // Construct the graph
        // Node are letters
        // a->b iff a<b
        // Adjacency List
        unordered_map<char,unordered_set<char>> graph;// choice of this data structure is imp 
        // unordered_map<char,vector<char>> graph;
        int i,j,x,y;
        vector<char> ans;
        unordered_map<char,int> indegree;
        
        // initializing indegree and graph keys ----------------------------------------------------------------
        for(i=0;i<n;i++){
            for(j=0;j<dictionary[i].size();j++){
                if(graph.find(dictionary[i][j]) == graph.end()){
                    indegree[dictionary[i][j]] = 0;
                    graph[dictionary[i][j]] = {};//empty map value
                }
            }
        }
        // Constructing graph & indegree calculation -----------------------------------------------------------
        for(i=0;i<n-1;i++){
            j=i+1;
            // transitive depedencies are taken care of even if we just add relation betwen i and i+1 elements
            x=y=0;
            if(dictionary[i]==dictionary[j]) continue;
            while(x<dictionary[i].size()  && y<dictionary[j].size() && dictionary[i][x] == dictionary[j][y] ){
                x++,y++;
            }
            
            // if dictionary[j] is a prefix of dictionary[i]
            if(y == dictionary[j].size()) return "";        
            if(x == dictionary[i].size()) continue;
            // for 1st different positions in adjacent words we map the relationship
            if(graph[dictionary[i][x]].find(dictionary[j][y]) == graph[dictionary[i][x]].end()){
                // graph[dictionary[i][x]].push_back(dictionary[j][y]);
                graph[dictionary[i][x]].insert(dictionary[j][y]);
                indegree[dictionary[j][y]]++;//assuming default start value is 0   
            }          
        }

        // Topo Sort ---------------------------------------------------------------------------------------------
        // We take all nodes whose indegree = 0 => all of them can be the current smallest charector => push them in queue  
        queue<char> q;
        for(auto& node:indegree){
            if(node.second == 0) q.push(node.first);
        }
        
        while(!q.empty()){
            char ch=q.front();
            ans.push_back(ch);// current smallest element is pushed in ans & poped from queue
            q.pop();
            for(auto& nbr: graph[ch]){ // visit all neighbour's of ch (=> elements greater than ch)
                indegree[nbr]--;// since we remove ch => its indegree contribution to its nbr is accounted for so remove it 
                if(indegree[nbr]==0) q.push(nbr);
                // if after decreasing the indegree of the nbr == 0 => now its level has been reached & can be pushed on the queue
            }        
        }        
        string res="";
        // Note: K = graph.size()
        if(ans.size() == graph.size()){
            for(auto& x:ans) res+=x;
        }
        return res;
        
    }
};

// above question was on topo sort
/*
NOTE: for some problems its very hard to understand if its a graph problem, so reverse engineer it, meaning:
Since graphs have very few/limited algorithms (like connectivity, cyclicity, shortest path(weighted and unweighted), topological sort, union find),
so the best part about graphs is you can try applying each one of them and see if its a graph problem or not.

So for eg: for Q)Leetcode 269.Alien Dictionary :: we have to order something(=>its an ordering problem)
So one of the ways we can think of is: it may be Topological Sort(since ordering) if graph problem and try applying it
*/
//===================================================================================================
// Leetcode 743. Network Delay Time :: https://leetcode.com/problems/network-delay-time/ (shortest path- wieghted)

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Level order traversal : bfs -> but since its weighted we maintain a *priority queue*
        // maintain runninng max for time & visited set also
        // at last check if visited set size == n, if not then return -1 else return running max 
        unordered_set<int> visited;//we could use array of size n also for this question where nodes are in [0...N-1] (it would have ben more effective)
        // Weighted BFS(weighted level order traversal) => priority queue
        // Minimum priority queue (of pair) : syntax
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; // <time,node> :sort by time 
        int i,j,time=0,tmax=0;
        
        vector<vector<pair<int,int>>> adj(n);// ui :<vi,weight>
        for(const auto& x:times){
            adj[x[0]-1].push_back({x[1]-1,x[2]});//buidling graph (0 : n-1)
        }
        k=k-1;//making 0 based nodes
        pq.push({time,k});//pushing initial node k into the pq
        
        // Level order traversal
        while(!pq.empty()){
            int t_curr,node;
            t_curr = pq.top().first, node = pq.top().second; 
            pq.pop();
            visited.insert(node);
            tmax = max(tmax,t_curr);
            
            if(visited.size()==n) return tmax;//this has to be inside the loop
            // Push all neighbours
            for(const auto& nbr:adj[node]){
                if(visited.find(nbr.first)==visited.end()){//unvisited nbr
                    pq.push({ t_curr + nbr.second , nbr.first});//{t+wt,nxt_node}                    
                }
                // visited nodes must be ignored/not visited again so as to avoid any infinite loops in case of cycles
                // therefore visit each node at most once                    
            }
        }
        if(visited.size()==n) return tmax;
        return -1;
    }
};
// NOTE: think about cycles also : edge cases
/*
[[1,2,1],[2,1,3]]
2
2
ans= 1

[[1,2,1],[2,3,2],[1,3,4]]
3
1
ans=3
*/

//===================================================================================================
// (premium)Leetcode 1102. Path With Maximum Minimum Value 
// :: https://www.codingninjas.com/codestudio/problems/path-with-maximum-and-minimum-value_1281861
// https://leetcode.ca/all/1102.html

#include <iostream>
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
int pathWithMaxMinValue(vector<vector<int>> &arr)
{
    int m=arr.size(),n=arr[0].size() ,i,j,ans=-1;
    vector<vector<bool>> visited(m,vector<bool>(n,false));
    // Priority queue of vector :: less() is the inbuilt comparator for max-heap by 1st element of vector
    priority_queue<vector<int>, vector<vector<int>>, less<vector<int>> > pq;
    
    pq.push({arr[0][0],0,0});
    while(!pq.empty()){
        vector<int> t = pq.top();
        pq.pop();
        if(visited[t[1]][t[2]]) continue;
        visited[t[1]][t[2]] = true;
        
        if(t[1]==m-1 && t[2]==n-1) ans=max(ans,t[0]);
        for(auto& dir:dirs){
            int x = dir[0]+t[1], y = dir[1]+t[2];
            if(x<0 || y<0 || x>=m || y>=n || visited[x][y])
                continue;
            pq.push({min(arr[x][y],t[0]),x,y});
        }
    }
    return ans;
    
}
// Driver Code ::
int main()
{
    // vector<vector<int>> g ={{2,3,4},{1,2,3},{3,23,4}};
    vector<vector<int>> g ={{5,4,5},{1,2,6},{7,4,6}};
    cout<<pathWithMaxMinValue(g);//o/p :: 4 for above graph 

    return 0;
}
//===================================================================================================
// Leetcode 1334. Find the City With the Smallest Number of Neighbors at a Threshold Distance:: https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/
// https://cp-algorithms.com/graph/all-pair-shortest-path-floyd-warshall.html
/*
NOTE: APSP (all pair shortest path -> Floyd Warshall)
A(i)(j)(k) = minimum metric(eg: path sum) to reach form node I to node j ;  with intermediate nodes belonging to the set: {v0,v1,…,vk} 


Things we need to consider: 
	1. Order of iteration (/order of filling the table):
		a. Form the recursive relation its clear we need to fill the minimum k first ,i.e, since A(ijk) is dependent on A(ij(k-1)) therefore we fill the table for k=0 first then for k=1,…. & so on
	2. Base Case
		a. dp(ij) = -1 ; if no edge between nodes i & j
		b. dp(ij) = Wij ; if there is a edge between node i & j and weight of the edge is Wij
	3. Space Optimization: 
		a. Can it be done with 2 matrices ? 
			i. Yes, one for previous k, and one for current k
		b. **Can it be done with just 1 matrix ? 
			i. YES , we know the matrix will be updated and that we cannot avoid , now we see that the updated values and previous values are same/ not changed so it wont affect our ans, therefore using only 1 matrix will suffice.
               Another way to think about it is : the updated value id the same as the previous value so storing the previous value in another matrix is not needed.
			ii. Recursion: A(i)(j)(k) = min( A(i)(j)(k-1), A (i)(k)(k-1) + A(k)(j)(k-1)
			iii. We see that : A(i)(k)(k-1) = A(i)(k)(k) ; since going form I to k with intermediate nodes as v0,v1,..,vk-1 is same as   going form I to k with intermediate nodes as v0,v1,..,vk ; ( otherwise it would imply that there is a self loop/cycle in the  graph and making path sum infinite )
			iv. Similar case for : A(k)(j)(k-1) = A(k)(j)(k)	
*/

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // Floyd Warshall Algo ----------------------------------------------------
        vector<vector<pair<int,int>>> graph(n);
        vector<vector<int>> dp(n, vector<int>(n,INT_MAX));
        int i,j,k,count,res=INT_MAX,res_vertex;
        
        for(const auto& edge : edges){
            graph[edge[0]].push_back({edge[1],edge[2]});
            graph[edge[1]].push_back({edge[0],edge[2]});
            // Base Case.
            dp[edge[0]][edge[1]] = edge[2];// these value can be changed later on
            dp[edge[1]][edge[0]] = edge[2];
        }
        
        //Base Case.
        for(i=0;i<n;i++){
            dp[i][i]=0;
        }
        
        for(k=0; k<n ; k++){
            for(i=0;i<n;i++){
                for(j=0;j<n;j++){
                    if(dp[i][k]!=INT_MAX && dp[k][j]!=INT_MAX){
                        dp[i][j] = min(dp[i][j],dp[i][k]+dp[k][j]);
                    }
                }
            }
        }
        
        // Part specific for this question ----------------------------------------
        for(i=0;i<n;i++){
            int count=0;
            for(j=0;j<n;j++){
                if(dp[i][j]<=distanceThreshold){
                    count++;          
                }                
            }
            if(count<=res){
                res_vertex = i;
                res = count;
            }
        }
        return res_vertex;        
        
    }
};

//===================================================================================================
// Leetcode 1192. Critical Connections in a Network:: https://leetcode.com/problems/critical-connections-in-a-network/

//===================================================================================================
//===================================================================================================

