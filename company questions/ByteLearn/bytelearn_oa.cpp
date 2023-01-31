/*

*/
// =============================================================================
/*
1. 
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int getWhiteLength(int n,int m,vector<vector<int>> &lights){
    int i,j,ans=0,mx=0,count;
    vector<vector<int>> dp(1e5+5,vector<int>(3,0));
    for(auto x:lights){
        x[0]--;
        dp[x[1]][x[0]]++,dp[x[2]+1][x[0]]--;
        mx=max(mx,x[2]+2);
    }
    
    for(i=1;i<mx;i++){
        count=0;
        for(j=0;j<3;j++){
            dp[i][j]+=dp[i-1][j];
            if(dp[i][j]>=1) count++;
        }
        if(count==3) ans++;
    }
    return ans;
}
int main()
{    
    vector<vector<int>> v={{1,1,5},{2,2,5},{3,3,5}};
    int ans=getWhiteLength(50,3,v);
    cout<<ans;
    return 0;
}