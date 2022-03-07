// NOTE: Advantage round of infytq = hackwithify ka 1st round
// --------------------------------------------------------
//shadab : advantage round if infytq

/*
Sample i/o:

3
95831
100120013
252525252525
ans: 252625367369


3
149
32
633
ans: 772

4
1
11
111
1111
ans: 1234
*/

// =============================================================================
// Kanisht : adv round:: 
// https://www.geeksforgeeks.org/multiset-erase-in-c-stl/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long i,n,x=0,t,j;
    cin>>n;
    vector<long long> num1(n),ans(n);
    multiset<long long> s;
    
    for(i=0;i<n;i++){
        cin>>num1[i];
        x^=num1[i];
        
    }
    for(i=0;i<n;i++){
        cin>>j;
        x^=j;
        s.insert(j);
    }
    
    bool pos=true;
    for(i=0;i<n;i++){
        t=x^num1[i];
        if(s.find(t)==s.end()){
            // return vector<int> (n,-1);
            pos=false;break;
        }
        ans[i]=t;
        s.erase(t);
    }
    if(pos==false){
        for(i=0;i<n;i++) cout<<"-1\n";
    }
    else{
        for(i=0;i<n;i++) cout<<ans[i]<<"\n";
    }
    // cout<<"Hello World";

    return 0;
}

// ====================================================
//Kanisht : advantage round qn 2
// You are given a array arr of size N. Find the size of largest good subsequence of arr.
// Note: A subsequence of size k is said to be good if for all (0<=i<=k) , B[0]+B[1]+...B[i] >= 0
void solve()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    priority_queue<int, vector<int>, greater<int>> pq;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        pq.push(a[i]);
        if (sum < 0)
        {
            int a = pq.top();
            sum -= a;
            pq.pop();
        }
    }
    cout << pq.size();
}
//======================================
//nanini: https://codeforces.com/problemset/problem/660/A (similar not exatly same)
// gcd wala - Unnat's Code- 100% tc passed
 
// ll gcd(ll a, ll b) {return (b == 0) ? a : gcd(b, a % b);} 

#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n,i,j,count=0;
    cin>>n;
    vector<int> v(n);
    for(i=0;i<n;i++){
        cin>>v[i];
        
    }
    for(i=1;i<n;i++){
        
        if(__gcd(v[i],v[i-1])==1){
            count++;
            i++;
        }
    }
    cout<<count;

    return 0;
}


// =================================================
// advantage round : Hrishabh 6/3/22 (50% passed by kanisht)

int n,m,K;
ll dp[1001][1001];
 
int ans(int i,int j)
{
    if(i==n && j==m)
        return 1;
 
    if(i>n || j>m)
    {
        return 0;
    }
    if(dp[i][j]!=-1)
        return dp[i][j];
    
    ll sum=0;
    for(int w=1;w<=K;w++)
    {
        sum=((sum%mod)+(ans(i+w,j)%mod))%mod;
        sum%=mod;        
        sum=((sum%mod)+(ans(i,j+w)%mod))%mod;
        sum%=mod;
        sum=((sum%mod)+(ans(i+w,j+w))%mod)%mod;
        sum%=mod;
    }
    return dp[i][j]=sum;
}
 
vector<int>solve(int T,vector<vector<int>>a){
    vector<int>b;
  
    for(int i=0;i<T;i++)
    {
        memset(dp,-1,sizeof(dp));
        n=a[i][0];
        m=a[i][1];
        K=a[i][2];
        int p=ans(1,1);
        b.push_back(p);
    }
    return b;
}
//-------------
// unnat's code(not correct)

// #include <iostream>
// #include <algorithm>
// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     long long n,i,j,count=0,t,mod=1e9+7,m,k,tx,ty;
//     vector<long long> ans;
//     cin>>t;
//     vector<vector<int>> dp(1000,vector<int>(1000,0));
//     dp[0][0]=1;
    

//     while(t--){
//         cin>>n>>m>>k;// later-optimize: by taking max of x,y dp matrix
//         for(i=0;i<n;i++){
//             for(j=0;j<m;j++){
//                 if(i==0 && j==0) continue;
//                 tx= min(i,k),ty=min(j,k);
//                 for(int x=i-tx;x<i;x++){
//                     for(int y=j-ty;y<j;y++){
//                         dp[i][j]=(dp[i][j]+dp[x][y])%mod;
//                     }
//                 }
//             }
//         }  
//         ans.push_back(dp[n-1][m-1]);
//     }
//     vector<int> v(n);
//     for(const auto& i:ans) cout<<i<<"\n";

//     return 0;
// }

//=========================
// find number of different arrays such that product of any two consecutive elements of array is <= k