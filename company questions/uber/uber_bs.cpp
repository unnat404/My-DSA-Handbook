//=================================================================================================
/*
Question List:
1- Justify text
2- longest palindromic subsequence
3- https://leetcode.com/problems/minimum-number-of-operations-to-make-array-continuous/
4- uber oa || base2 to base6
5- uber oa || longest bitonic subseq - leetcode/gfg 
6- uber oa || dungeon games - leetcode 
7- lis - o(n*n) & o(n*log n) approaches
8- Get Longest Increasing Subsequence Path
*/

//=================================================================================================

/*
1. Justify Text
Hard
Given a list of words and an integer line length k, return a list of strings which represents each line fully justified, with as many words as possible in each line.
There should be at least one space between each word, and pad extra spaces when necessary so that each line has exactly length k. Spaces should be distributed as equally as possible, with any extra spaces distributed starting from the left.
If you can only fit one word on a line, then pad the right-hand side with spaces.
Each word is guaranteed not to be longer than k.
Example 1
Input
words = ["the", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog"]
k = 16
Output
["the  quick brown", "fox  jumps  over", "the   lazy   dog"]
Explanation
First line: 1 extra space on the left (distributing from the left)
Second line: 2 extra spaces distributed evenly
Third line: 4 extra spaces distributed evenly
*/

/*
Implementation
....................................................................................................

Time Complexity
\mathcal{O}(n)O(n), we've pre-calculated the sum of elements, so it is O(n), if we need to consider the length of the strings, then it is O(n*k)

Space Complexity
\mathcal{O}(n)O(n), we need to prepare the answer array. To speed up calculation, we also preserve a sum array.
*/
void fit_in(vector<string>& words, vector<int>& sumsize, int i, int j, int k, vector<string>& ans) {
    string wip;
    int left_sp = k - sumsize[j + 1] + sumsize[i];
    for (int p = i; p < j; p++) {
        int sp = left_sp % (j - p) == 0 ? left_sp / (j - p) : 1 + left_sp / (j - p);
        left_sp -= sp;
        wip.append(words[p]);
        wip.append(sp, ' ');
    }
    wip.append(words[j]);
    if (wip.size() < k) wip.append(k - wip.size(), ' ');
    ans.push_back(wip);
}

vector<string> solve(vector<string>& words, int k) {
    vector<string> ans;
    vector<int> sumsize{0};
    for (int i = 0, s = 0; i < words.size(); i++) {
        s += words[i].size();
        sumsize.push_back(s);
    }

    for (int i = 0, j = 0; i < words.size();) {
        while (j < words.size() && sumsize[j + 1] - sumsize[i] + j - i <= k) j++;
        fit_in(words, sumsize, i, j - 1, k, ans);
        i = j;
    }
    return ans;
}
//=================================================================================================

// 2. longest palindromic subsequence
int solve(string s) {
    int n=s.length(),j;
    if(s.length()==0) return 0;
    // return longestPal(s,0,s.length()-1);
    int pal[n][n];
    for(int i=0;i<n;i++){
        pal[i][i]=1;
    }
    int a,i;
    for(a=2;a<=n;a++){
        for(i=0;i<n-a+1;i++){
            j=i+a-1;
            if(s[i]==s[j] && a==2) pal[i][j]=2;
            else if(s[i]==s[j]) pal[i][j]=pal[i+1][j-1]+2;
            else pal[i][j]=max(pal[i+1][j],pal[i][j-1]);
        }
    }
    return pal[0][n-1];
}
//=================================================================================================

// 3. OJ: https://leetcode.com/problems/minimum-number-of-operations-to-make-array-continuous/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(1)
// Check out "C++ Maximum Sliding Window Cheatsheet Template!" which can help you solve all sliding window problems.
class Solution {
public:
    int minOperations(vector<int>& A) {
        int N = A.size(), ans = N, j = 0;
        sort(begin(A), end(A));
        A.erase(unique(begin(A), end(A)), end(A)); // only keep unique elements
        int M = A.size();
        for (int i = 0; i < M; ++i) {
            while (j < M && A[j] < A[i] + N) ++j; // let `j` point to the first element that is out of range -- `>= A[i] + N`.
            ans = min(ans, N - j + i); // The length of this subarray is `j - i`. We need to replace `N - j + i` elements to make it continuous.
        }
        return ans;
    }
};
//=================================================================================================
// 4. Uber OA || SDE Intern 2 month  => 14/01/2022 
//covert base 2 number to base 6
// i/p : (1100) in base 2 => base2<bool> : [flase,false,true,true] ,
// o/p : (20) in base 6   => base6<int> : [0,2] 
//  Note : base6 is stored in reverse
vector<int> base2ToBase6(vector<bool> base2){
    int power=1,i,num=0;
    reverse(base2.begin(),base2.end());//doubt regarding this
    for(i=base2.size()-1;i>=0;i--){
        num+= base2[i]==true ? num+pow : num;
        power*=2;
    }
    vector<int> ans;
    int cur;
    while(num>0){
        cur=num%6;
        ans.push_back(cur);
        num/=6;
    }

    reverse(ans.begin(),ans.end());
    return ans;
}
while(n>5){
    ...
}
if(n>0) ans.push_back(n);

//=================================================================================================
// 5. Uber OA || SDE Intern 2 month => 14/01/2022 
// same question :: https://leetcode.com/problems/dungeon-game/
// given a matrix[m][n], go from (0,0) to (m-1,n-1)
// matrix[i][j] stores numbers +ve(means adds power) and -ve(means drains power) and 0 mens empty(you can go in this cel though)
// whats the minimum power mario needs to reach the required distination ?
// matrix[i][j] in range: [-1000,1000] ; 1<= m,n <= 300
// at each/any point the health must be >0 ,other wise mario dies

int calculateMinimumHP(vector<vector<int>> &dungeon) {
    int n = dungeon.size();
    int m = dungeon[0].size();

    vector<vector<int> > dp(n + 1, vector<int>(m + 1, 1e9));
    dp[n][m - 1] = 1;
    dp[n - 1][m] = 1;
    
    for (int i = n - 1; i >= 0; i--) 
    {
        for (int j = m - 1; j >= 0; j--) 
        {
            // int down = dp[i+1] - dungeon[i][j];
            // int right = dp[i][j+1] - dungeon[i][j];
            // int need = mi(down,right);
            int need = min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j];                
            // store this value
            dp[i][j] = need <= 0 ? 1 : need;
        }
    }
    return dp[0][0];
}
//soln ref: https://www.youtube.com/watch?v=w5lB4ViKk6g
//-------------------------------------------------------
//my soln : totally wrong
// bool isSafe(int i,int j,int m,int n){
//     if(i<0 || j<0 || i>=m || j>=n) return false;
//     return true;
// }
// int mario(vector<vector<int>> room){
//     int i,j,m=room.size(),n=room[0].size(),cur;
//     vector<vector<int>> dp(m,vector<int> (n,0));
//     // vector<vector<int>> posDp(m,vector<int> (n,0));//take min of 
//     // vector<vector<int>> negdp(m,vector<int> (n,0));

//     dp[m-1][n-1]=room[m-1][n-1];
//     for(i=m-1;i>=0;i--){
//         for(j=n-1;j>=0;j--){
//             if(isSafe(i+1,j,m,n)){
//                 dp[i][j]=room[i][j]+ dp[i+1][j];
//             }
//             if(isSafe(i,j+1,m,n)){
//                 dp[i][j]=max(dp[i][j], room[i][j]+dp[i][j+1]);
//                 // dp[i][j]=min(dp[i][j], room[i][j]+dp[i][j+1]);
//             }
//         }
//     }
//     if(dp[0][0]>=0) return 0;
//     return dp[0][0];
// }

//=================================================================================================
// Uber OA || SDE Intern 2 month => 14/01/2022 
// longest bitonic subsequence :: (1st increase, then decrease)

//o(n*n) approach
int minimumMountainRemovals(vector<int>& nums) {
        int n=nums.size(),i,j,ans=1;
        vector<int> a=nums;
        vector<int> lis(n,1),lds(n,1);
        for(i=1;i<n;i++){
            lis[i]=1;
            for(j=0;j<i;j++){
                if(nums[i]>nums[j]) lis[i]=max(lis[i],lis[j]+1);
            }
        }
        
        for(i=n-2;i>=0;i--){
            for(j=n-1;j>i;j--){
                if(nums[j]<nums[i]) lds[i]=max(lds[i],lds[j]+1);
            }
        }
        // reverse(a.begin(),a.end());
        for(i=0;i<n;i++){
            if(lis[i]==1 || lds[i]==1) continue; //this is done if it has to have both increasing and decreasing patterns
            ans=max(ans,lis[i]+lds[i]-1);
        }
        // ans --> at this moment stores length of longest bitonic subsequence 
        // return ans; //ans --> at this moment stores length of longest bitonic subsequence 
        ans=n-ans; //ans after this stores the min elements to be deleted to make array longest bitonic 
        return ans;
        
    }

//---------------
// OJ: https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    int minimumMountainRemovals(vector<int>& A) {
        int N = A.size(), ans = N;
        vector<int> a(N), b(N), v;
        for (int i = 0 ; i < N; ++i) {
            int x = A[i];
            auto it = lower_bound(begin(v), end(v), x);
            a[i] = it - begin(v);
            if (it != end(v)) *it = x;
            else v.push_back(x);
        }
        v.clear();
        for (int i = N - 1; i >= 0; --i) {
            int x = A[i];
            auto it = lower_bound(begin(v), end(v), x) ;
            b[i] = it - begin(v); 
            if (it != end(v)) *it = x;
            else v.push_back(x);
        }
        for (int i = 1; i < N; ++i) {
            if (a[i] && b[i]) ans = min(ans, N - (a[i] + b[i] + 1));
        }
        return ans;
    }
};
//=================================================================================================
// Leetcode 1761. Minimum Degree of a Connected Trio in a Graph
// https://leetcode.com/problems/minimum-degree-of-a-connected-trio-in-a-graph/
// O(n*n*n)
class Solution {
public:
    int deg[403];
    int adj[403][403];
    
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        for (auto& vec : edges) {
            int u = vec[0], v = vec[1];
            deg[u]++; deg[v]++;
            adj[u][v] = adj[v][u] = 1;
        }
        int ans = 1e9;
        for (int i = 1; i <= n; i++) {
            for (int j = i+1; j <= n; j++) {
                if (!adj[i][j]) continue;
                for (int k = j+1; k <= n; k++) {
                    if (adj[i][k] && adj[j][k]) {
                        ans = min(ans, deg[i] + deg[j] + deg[k] - 6);
                    }
                }
            }
        }
        if (ans == 1e9) return -1;
        return ans;
    }
};

//--------
int minTrioDegree(int n, vector<vector<int>>& edges) {
    vector<vector<int>> am(n + 1, vector<int>(n + 1));
    vector<int> cnt(n + 1);
    int res = INT_MAX;
    for (auto &e: edges) {
        am[min(e[0], e[1])][max(e[0], e[1])] = 1;
        ++cnt[e[0]];
        ++cnt[e[1]];
    }
    for (auto t1 = 1; t1 <= n; ++t1)
        for (auto t2 = t1 + 1; t2 <= n; ++t2)
            if (am[t1][t2])
                for (auto t3 = t2 + 1; t3 <= n; ++t3)
                    if (am[t1][t3] && am[t2][t3])
                        res = min(res, cnt[t1] + cnt[t2] + cnt[t3] - 6);
    return res == INT_MAX ? -1 : res;
}
//=================================================================================================
// 7.lis : longes increasing subsequence

//o(n*n)
int lengthOfLIS(vector<int> &a){
    int n=a.size(),i,j,ans;
    if(n==0) return 0;
    vector<int> dp(n,1);
    dp[0]=ans=1;
    for(i=1;i<n;i++){
        dp[i]=1;
        for(j=0;j<i;j++){
            if(a[i]>a[j]){
                dp[i]=max(dp[i],dp[j]+1);
            }
            ans=max(ans,dp[i]);
        }
    }
    return ans;
}

//o(n*log n)
//length of longest non-decreasing subsequence
// int lnds(vector<int>& a){
int lis(vector<int> &a){ //length of longest increasing subsequence
    int n=a.size(),i,ans;
    vector<int> temp;
    for(i=0;i<n;i++){
        // if(temp.size()==0 || temp.back()<=a[i]){ //for lnds
        if(temp.size()==0 || temp.back() < a[i]){ //for lis
            temp.push_back(a[i]);
        }
        else{
            // int ind=upper_bound(temp.begin(),temp.end(),a[i])-temp.begin(); // for lnds
            int ind=lower_bound(temp.begin(),temp.end())-temp.begin(); //for lis
            temp[ind]=a[i];
        }
    }
    return temp.size();
}

//-------------
int lengthOfLIS(vector<int>& nums) {
        vector<int> sub;
        for (int x : nums) {
            if (sub.empty() || sub[sub.size() - 1] < x) {
                sub.push_back(x);
            } else {
                auto it = lower_bound(sub.begin(), sub.end(), x); // Find the index of the smallest number >= x
                *it = x; // Replace that number with x
            }
        }
        return sub.size();
    }
//=================================================================================================

// 8. Get Longest Increasing Subsequence Path
class Solution {
public:
    vector<int> pathOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> sub, subIndex; // Store index instead of value for tracing path purpose
        vector<int> path(n, -1); // path[i] point to the index of previous number in LIS
        for (int i = 0; i < n; ++i) {
            if (sub.empty() || sub[sub.size() - 1] < nums[i]) {
                path[i] = sub.empty() ? -1 : subIndex[sub.size() - 1];
                sub.push_back(nums[i]);
                subIndex.push_back(i);
            } else {
                int idx = lower_bound(sub.begin(), sub.end(), nums[i]) - sub.begin();
                path[i] = idx == 0 ? -1 : subIndex[idx - 1];
                sub[idx] = nums[i];
                subIndex[idx] = i;
            }
        }
        vector<int> ans;
        int t = subIndex[subIndex.size() - 1];
        while (t != -1) {
            ans.push_back(nums[t]);
            t = path[t];
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    vector<int> nums = {2, 6, 8, 3, 4, 5, 1};
    vector<int> res = Solution().pathOfLIS(nums); // [2, 3, 4, 5]
    for (int x : res) cout << x << " "; 
    return 0;
}
//=================================================================================================
//=================================================================================================
