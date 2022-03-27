//=================================================================================================
/*
Question List:
1- Justify text
2- longest palindromic subsequence
3- https://leetcode.com/problems/minimum-number-of-operations-to-make-array-continuous/
4- uber oa || 14/01/2022 || base2 to base6 || imp (repeat)(big integer/better approach)
5- uber oa || 14/01/2022 || longest bitonic subseq - leetcode/gfg 
6- uber oa || 14/01/2022 || dungeon games - leetcode 
7- lis - o(n*n) & o(n*log n) approaches
8- Get Longest Increasing Subsequence Path
9- sliding window max
10- uber oa || 14/01/2022 || question 4 (convert base2 to base6) : repeated
11- uber oa || 14/01/2022 || 
12- uber oa || 14/01/2022 || modification of burst balloons
13- uber hacktag 1.0 :: Office and Keys :: https://codeforces.com/problemset/problem/830/A
14- uber past qn :: Xor Pyramid :: https://codeforces.com/contest/983/problem/B
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

// https://www.hackerrank.com/contests/goc-cdc-series-10/challenges/itsybitsy/editorial
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define MOD 1000000007
#define mod 998244353
#define ar array
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

void test_case() {
    int n; cin >> n;
    vector<int> a(n);
    bool zero = true;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == 1) zero = false;
    }
    if (zero) {
        cout << 0 << "\n";
        return;
    }

    // a = 0010 --> 0100
    reverse(a.begin(), a.end());
    vector<int> res(105);
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            // convert number to 2*n
            int carry = 0;
            for (int j = 0; j < 104; j++) {
                int num_here = 2*res[j] + carry;
                carry = num_here/6;
                res[j] = num_here%6;
            }
            assert(carry == 0);
        }
        else {
            // convert number to 2*n + 1
            int carry = 0;
            for (int j = 0; j < 104; j++) {
                int num_here = 2*res[j] + carry;
                carry = num_here/6;
                res[j] = num_here%6;
            }
            carry = 1;
            for (int j = 0; j < 104; j++) {
                int num_here = res[j] + carry;
                carry = num_here/6;
                res[j] = num_here%6;
            }
            assert(carry == 0);
        }
    }
    assert(res.back() == 0);
    while (res.back() == 0) res.pop_back();
    for (int i = 0; i < (int) res.size(); i++) {
        if (i > 0) cout << " ";
        cout << res[i];
    }
    cout << endl;
}

int32_t main() {
    fast_io;

    int t; cin >> t;
    while (t--) {
        test_case();
    }

    return 0;
}

//not all test cases will pass th below code (since big integer problem) 
//(As max no. => 2^101-1)
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


//=================================================================================================
// 5. Uber OA || SDE Intern 2 month => 14/01/2022 
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
//approach 2
// 5. Uber OA || SDE Intern 2 month => 14/01/2022 
// longest bitonic subsequence :: (1st increase, then decrease)
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
// 6. Leetcode 1761. Minimum Degree of a Connected Trio in a Graph
// https://leetcode.com/problems/minimum-degree-of-a-connected-trio-in-a-graph/
// O(n*n*n)
/*
Input  1: n = 6, edges = [[1,2],[1,3],[3,2],[4,1],[5,2],[3,6]]
Output 1: 3
Explanation: There is exactly one trio, which is [1,2,3]. The edges that form its degree are bolded in the figure above.

Input  2: n = 7, edges = [[1,3],[4,1],[4,3],[2,5],[5,6],[6,7],[7,5],[2,6]]
Output 2: 0
Explanation: There are exactly three trios:
1) [1,4,3] with degree 0.
2) [2,5,6] with degree 2.
3) [5,6,7] with degree 2.
*/
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
//9. sliding window maximum ::
/*
Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
*/
//soln using deque:: The data structure used is know as Monotonic Queue

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;
        for (int i=0; i<nums.size(); i++) {
            if (!dq.empty() && dq.front() == i-k) dq.pop_front();
            while (!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();
            dq.push_back(i);
            if (i>=k-1) ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};
//=================================================================================================
// 10. Uber OA || SDE Intern 2 month => 14/01/2022 || unnat
// base2 to base6 :: (repeat)


//=================================================================================================
// 11. Uber OA || SDE Intern 2 month => 14/01/2022 || unnat
// kinda similar :: https://www.geeksforgeeks.org/split-array-into-k-subarrays-such-that-sum-of-maximum-of-all-subarrays-is-maximized/


//=================================================================================================
// 12. Uber OA || SDE Intern 2 month => 14/01/2022 || unnat
// leetcode :: brust balloons ka modification 

//=================================================================================================
// Uber hacktag :: https://codedaily.in/uber-hack-tag-questions/
// Ofiice and Keys(codeforces-1800) = Drivers and Batteries(uber hacktag) :: https://codeforces.com/problemset/problem/830/A
#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define V vector
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define endl "\n"
#define all(x) x.begin(), x.end()
#define forstl(i, s)  for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
// #pragma comment(linker, '/STACK:200000')        //prevent stack overflow ..STACK Limiter
// #pragma comment(linker, "/stack:200000000")
// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define time() cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" 
#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)
const int MOD=1e9+7;
const int MOD2=998244353;
ld PI=2*acos(0.0);
 
template <typename T> T gcd(T a, T b){return (b==0)?a:gcd(b,a%b);}
template <typename T> T lcm(T a, T b){return a*(b/gcd(a,b));}   
template <typename T> T mod_exp(T b, T p, T m){T x = 1;while(p){if(p&1)x=(x*b)%m;b=(b*b)%m;p=p>>1;}return x;}
template <typename T> T invFermat(T a, T p){return mod_exp(a, p-2, p);}
template <typename T> T exp(T b, T p){T x = 1;while(p){if(p&1)x=(x*b);b=(b*b);p=p>>1;}return x;}
string tostring(int number){stringstream ss; ss<<number; return ss.str();}
int toint(const string &s) {stringstream ss; ss << s; int x; ss >> x; return x;}
 
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}  
//main soln part starts here (upar tak template hai khali) 

const int maxm = 2*1e3+5;
int a[maxm],b[maxm];
int n,k,p;
int dp[maxm][maxm];
 
int checker(int pos,int key)
{
	if(pos >= n) return -1e12;
	if(key >= k) return 1e12;
	if(dp[pos][key]!=-1) return dp[pos][key];
	int ans = 0;
	int op1 = checker(pos,key+1);
	int time = abs(a[pos] - b[key]) + abs(b[key] - p);
	int op2 = max(time,checker(pos+1,key+1));
	ans = min(op1,op2);
	return dp[pos][key] = ans;
}
 
void solve()
{
	cin>>n>>k>>p;
	memset(dp,-1,sizeof dp);
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);// sort people positions
	for(int i=0;i<k;i++) cin>>b[i];
	sort(b,b+k);// sort keys(or battery) positions
	cout<<checker(0,0)<<endl;
}
 
int32_t main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE                    //file start
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);   
    #endif                                  //file end
    // int cases=1;
    // int t; cin>>t;
    // while(t--)
    solve();
    return 0;
} 
// 1LL check ?

//=================================================================================================
// Uber Past qn :  https://codeforces.com/contest/983/problem/B

#include <bits/stdc++.h>
 
using namespace std;
 
int run();
 
int main() {
#ifdef home
  freopen("i", "r", stdin);
  freopen("d", "w", stderr);
#endif
  cout.precision(15);
 
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
 
  run();
}
 
const int N = 5000;
 
int a[N];
 
int dp[N][N];
 
int run() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    dp[0][i] = a[i];
  }
  for (int i = 1; i < n; i++) {
    for (int j = 0; j <= n - i; j++) {
      dp[i][j] = dp[i - 1][j + 1] ^ dp[i - 1][j];
    }
  }
 
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < n - i; j++) {
      dp[i][j] = max({dp[i][j], dp[i - 1][j], dp[i - 1][j + 1]});
    }
  }
 
  int q;
  cin >> q;
 
  for (int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;
    --l;
    int len = r - l - 1;
    cout << dp[len][l] << '\n';
  }
}
//=================================================================================================
// uber hacktag 2.0
/*
 - nikki :: https://www.geeksforgeeks.org/a-program-to-check-if-strings-are-rotations-of-each-other/
 - nikki :: 
 - shadab ::
 - kanisht ::
 - unnat :: 


*/
//=================================================================================================
/* D2C question :
- nandini : codehers
- unnat : uber hacktag 2.0
*/
#include <bits/stdc++.h>
#define ll long long int
 
 
 
using namespace std;
 
 
 
int main()
{
 
 
 
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int t;
    t=1;
    // cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        map<ll,ll>m;
        vector<ll>a(n);
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            m[a[i]]++;
        }
        ll q,mt;
        cin>>q;
        ll ans=0;
        while(q--)
        {
            cin>>mt;
            ll ans=0;
            for(int i=1;i<=sqrt(mt);i++)
            {
                if(mt%i==0)
                {
                    if((mt/i)!=i)
                    {
                        ans+=m[mt/i];
                        ans+=m[i];
                    }
                    else
                    {
                        ans+=m[i];
                    }
                }
            }
            cout<<ans<<'\n';
        }
    }
    
    return 0;
 
}

//=================================================================================================

//=================================================================================================

//=================================================================================================

//=================================================================================================

//=================================================================================================

//=================================================================================================

//=================================================================================================
