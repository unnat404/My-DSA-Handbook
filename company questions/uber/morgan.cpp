

=======================================
// Nandini Morgan Stanley OA || 23-02-2022
#include <iostream>
#include <bits/stdc++.h>
// #include <iostream>


int solve(vector<vector<int>>& cost){
    int n=cost.size(),m=cost[0].size(),i,j,ans;
    vector<vector<int>> dp(n,vector<int>(m,0));
    dp[0]=cost[0];    

    for(i=1;i<n;i++){
        for(j=0;j<m;j++){
            int cur=INT_MAX,tem=INT_MAX;
            //prev row min excluding  j
            for(int k=0;k<m;k++){
                if(k!=j){
                    cur=min(cur,dp[i-1][k]);
                    tem=min(tem,cost[i-1][k]);
                }
            }
            // cur+=cost[i][j]; // i-1 th row se min + current cost

            if(i>=2){
                dp[i][j]=min(cur+cost[i][j], tem+cost[i][j]+dp[i-2][j]);
            }
            else dp[i][j]=cur + cost[i][j];//i=1 k liye
        }
    }

    ans=dp[n-1][0];
    for(int k=0;k<m;k++){
        ans=min(ans,dp[i-1][k]);
    }
    
    // for(i=0;i<n;i++){
    //     for(j=0;j<m;j++){
    //         cout<<dp[i][j]<<" ";
    //     }cout<<"\n";
    // }
    return ans;
}


int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n,m,i,j;
    // cin>>n>>m;
    vector<vector<int>> cost= {{2,40,50,60},{3,40,50,60},{2,40,50,60}};
    int ans= solve(cost);
    cout<<ans;
    return 0;
}
// ans = 44
==============================================