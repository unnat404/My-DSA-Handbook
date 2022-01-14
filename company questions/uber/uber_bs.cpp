//=================================================================================================
/*
Question List:
1- Justify text
2- longest palindromic subsequence
3- https://leetcode.com/problems/minimum-number-of-operations-to-make-array-continuous/
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
// Uber OA || SDE Intern 2 month  => 14/01/2022 
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
// Uber OA || SDE Intern 2 month => 14/01/2022 
// given a matrix[m][n], go from (0,0) to (m-1,n-1)
// matrix[i][j] stores numbers +ve(means adds power) and -ve(means drains power) and 0 mens empty(you can go in this cel though)
// whats the minimum power need to reach the required distination
bool isSafe(int i,int j,int m,int n){
    if(i<0 || j<0 || i>=m || j>=n) return false;
    return true;
}
int mario(vector<vector<int>> room){
    int i,j,m=room.size(),n=room[0].size(),cur;
    vector<vector<int>> dp(m,vector<int> (n,0));
    // vector<vector<int>> posDp(m,vector<int> (n,0));//take min of 
    // vector<vector<int>> negdp(m,vector<int> (n,0));

    dp[m-1][n-1]=room[m-1][n-1];
    for(i=m-1;i>=0;i--){
        for(j=n-1;j>=0;j--){
            if(isSafe(i+1,j,m,n)){
                dp[i][j]=room[i][j]+ dp[i+1][j];
            }
            if(isSafe(i,j+1,m,n)){
                dp[i][j]=max(dp[i][j], room[i][j]+dp[i][j+1]);
                // dp[i][j]=min(dp[i][j], room[i][j]+dp[i][j+1]);
            }
        }
    }
    if(dp[0][0]>=0) return 0;
    return dp[0][0];
}

//=================================================================================================
// Uber OA || SDE Intern 2 month => 14/01/2022 
// longest bitonic subsequence

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
//=================================================================================================
//=================================================================================================
//=================================================================================================
