/***************************************************************************************************
Graphs Problem List:

 -> matrices as graphs: 
    - Leetcode 200. Number of Islands :: https://leetcode.com/problems/number-of-islands/
    - Leetcode 53. Maximum subarray :: https://leetcode.com/problems/maximum-subarray/
    - Leetcode 
    - Leetcode 
    - 
    - to do :: Leetcode 413. Arithmetic Series
    - to do :: Leetcode 343. Interger Break

 -> To Do:
    - https://leetcode.com/problems/groups-of-strings/
    -* https://leetcode.com/problems/k-highest-ranked-items-within-a-price-range/  
 -> Must Do:
    ○ ...
    ○ ...

*****************************************************************************************************/
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
//===================================================================================================
//===================================================================================================
//===================================================================================================
//===================================================================================================
//===================================================================================================
//===================================================================================================
//===================================================================================================
//===================================================================================================

