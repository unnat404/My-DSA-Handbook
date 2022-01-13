
/* 
Uber Questions Lists:
- find all subsets that sum up to k ::  https://www.codingninjas.com/codestudio/problems/return-subsets-sum-to-k_759331
- rotten oranges :: 
*/
//===================================================================================================
//find all subsets that sum up to k ::  https://www.codingninjas.com/codestudio/problems/return-subsets-sum-to-k_759331

//approach 1: recursion:: include/exclude
void f(int i,vector<int> arr, int k,vector<int> tem,int sum,vector<vector<int>> &ans){
    int n=arr.size();
    if(i==n){
        if(sum==k) ans.push_back(tem);
        return;
    }
    //exclude
    f(i+1,arr,k,tem,sum,ans);
    //include
    tem.push_back(arr[i]);
    f(i+1,arr,k,tem,sum+arr[i],ans);
}
vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    // Write your code here.
    vector<vector<int>> ans;
    vector<int> tem;
    f(0,arr,k,tem,0,ans);
    return ans;
}
//---------------------------------------------------------------------

//approach 2: bitmasking
vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
   vector<vector<int>>ans;
   for(int i=0;i<(1<<n);i++)
   {
       vector<int>temp;
       long long int sum=0;
       for(int j=0;j<n;j++)
       {
           if(i&(1<<j))
           {
               temp.push_back(arr[j]);
               sum+=arr[j];
           }
       }
       if(sum==k)
       {
           ans.push_back(temp);
       }

   }
   return ans;

}

//===================================================================================================
// rotten oranges: https://leetcode.com/problems/rotting-oranges/
//  https://www.codingninjas.com/codestudio/problems/rotting-oranges_701655?leftPanelTab=0

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;
        int m = grid.size(), n = grid[0].size(), days = 0, tot = 0, cnt = 0;
        queue<pair<int, int>> rotten;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] != 0) tot++;
                if(grid[i][j] == 2) rotten.push({i, j});
            }
        }
        
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        
        while(!rotten.empty()){
            int k = rotten.size();
            cnt += k; 
            while(k--){
                int x = rotten.front().first, y = rotten.front().second;
                rotten.pop();
                for(int i = 0; i < 4; ++i){
                    int nx = x + dx[i], ny = y + dy[i];
                    if(nx < 0 || ny < 0 || nx >= m || ny >= n || grid[nx][ny] != 1) continue;
                    grid[nx][ny] = 2;
                    rotten.push({nx, ny});
                }
            }
            if(!rotten.empty()) days++;
        }
        
        return tot == cnt ? days : -1;
    }
};
//above code is bfs solution
//===================================================================================================

//  https://www.codingninjas.com/codestudio/problems/indices-of-all-local-minima-and-local-maxima_873365 
// v.easy implementation based
 
//===================================================================================================

// https://leetcode.com/discuss/interview-question/1272223/uber-oa-questions-codesignal-test-2021