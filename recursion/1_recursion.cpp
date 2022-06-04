/***************************************************************************************************
 Recursion Problem List:

 -> 1d dp: 
    - Leetcode 51. N-Queens :: https://leetcode.com/problems/n-queens/
    - to do :: Leetcode 
    - to do :: Leetcode  
    - to do :: Leetcode  

 -> To Do	
    ○ 
    ○ 
    ○ 

*****************************************************************************************************/
// =====================================================================================================================================
#include <bits/stdc++.h>
using namespace std;
// =====================================================================================================================================
// Leetcode 51. N-Queens :: https://leetcode.com/problems/n-queens/
class Solution {
public:
    // function to check if (row,col) is a safe position according to current placement of queen 
    bool is_safe(int n,int row,int col,vector<vector<int>>& state){
        // check all 4 attacking conditions 
        // (same row,same col, same diagonal with slope -1, same diagonal with slope +1 )
        for(int i=0;i<state.size();i++){
            if(row==state[i][0] || col==state[i][1]) return false;
            if(col-row==state[i][2] || col+row==state[i][3]) return false;
        }
        return true;
    }
    
    // fuction to permute over all queen's positions and backtrack
    void solve(int row,int n,vector<string>& curr,vector<vector<string>>& ans,vector<vector<int>>& state){
        // base case
        if(row>=n){
            ans.push_back(curr);return;
        }        
        
        int i,j,k;
        for(j=0;j<n;j++){
            if(is_safe(n,row,j,state)){
                curr[row][j]='Q';
                state.push_back({row,j,j-row,j+row});
                solve(row+1,n,curr,ans,state); // recursive call               
                curr[row][j]='.';// backtracking step
                state.pop_back();// backtracking step
            }            
        }        
    } 
    
    // actual function in question
    vector<vector<string>> solveNQueens(int n) {
        string s;
        int i;
        for(i=0;i<n;i++) s+=".";
        vector<vector<int>> state;// used for safety check
        /* state[i] stores:: {row,col,row-col,row+col} :: each state defines a queen's attacking positions
            -> same row & col are ovioius 
            -> row-col : denotes positions diagonal with slope -1 & passing through {row,col}
            -> row+col : denotes diagonal with slope +1 & passing through {row,col}
        */
        vector<vector<string>> ans;
        vector<string> curr(n,s);// initially stores all "."s in n*n matrix kinda         
        solve(0,n,curr,ans,state);
        return ans;
    }
};

// =====================================================================================================================================
// =====================================================================================================================================
// =====================================================================================================================================
// =====================================================================================================================================
// =====================================================================================================================================
// =====================================================================================================================================
