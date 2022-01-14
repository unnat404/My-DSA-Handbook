
/* 
Uber Questions Lists:
1- find all subsets that sum up to k ::  https://www.codingninjas.com/codestudio/problems/return-subsets-sum-to-k_759331
2- rotten oranges :: 
3- meeting :: https://www.codingninjas.com/codestudio/problems/meeting_1376415
4- house robbers
5- running median :: https://www.geeksforgeeks.org/median-of-stream-of-integers-running-integers/
6- Dictionary Nomad :: https://binarysearch.com/problems/Dictionary-Nomad/
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

//===================================================================================================

// meeting :: https://www.codingninjas.com/codestudio/problems/meeting_1376415

/*
Problem Statement
Ninja is organizing a meeting in an office that starts at a time ‘0’ and will end at a time ‘LAST’.
There are ‘N’ presentations that are going to take place in that meeting whose start and end times are given, i.e., ‘ith’ presentation starts at ‘START[i]’ and ends at ‘END[i]’. The presentations don’t overlap with each other. Ninja wants to reschedule at most ‘K’ presentations keeping the original order intact so that the longest period in which there is no presentation scheduled during the meeting is maximized.
Since Ninja is busy with other office work, your task is to help Ninja to reschedule at most ‘K’ presentations.

Constraints:
1 <= T <= 10
1 <= N <= 5000
0 <= K <= N
0 <= LAST <= 10^9
START[i] < END[i], for 1 <= i <= N.
END[i] <= START[i+1], for 1 <= i < N.
Time Limit: 1 second
----------------------
Sample Input 1:
1
2 1 4
0 1
2 3
Sample Output 1:
2
Explanation For Sample Output 1:
If we reschedule the second meeting from 2 to 1, then the duration from 2 to 4 will be free, and it is the longest among all possible answers.
----------------------
Sample Input 2:
1
3 0 11
2 4
4 5
8 10          
Sample Output 2:
3
*/
//approach 1: Brute Force Approach    : O(n*n)
//approach 2: sliding window approach : O(n)
/*
    Time Complexity     :   O(N)
    Space Complexity    :   O(N)
    Where 'N' is the number of the presentations.
*/

int maxInterval(int t, vector<int> &start, vector<int> &end, int k) {
	// Create a vector to store the time duration in which there is no presentation.
	vector<int> emptySlots;
	// Fill the vector 'emptySlots'.
	int prevEnd = 0;
	for (int i = 0; i < start.size(); i++) {
		emptySlots.push_back(start[i] - prevEnd);
		prevEnd = end[i];
	}
	emptySlots.push_back(t - prevEnd);
	int len = emptySlots.size();
	// Declare a variable to store the final answer.
	int ans = 0;
	// Declare a variable to store the sum of current window.
	int sum = 0;
	// Find the sum of 1st K + 1 window.
	for (int i = 0; i < k + 1 && i < len; i++) {
		sum = sum + emptySlots[i];
	}
	// Update 'ans'.
	ans = sum;
	// Find the sum of all K + 1 window and update 'ans' with the maximum.
	for (int i = k + 1; i < len; i++) {
		sum = sum - emptySlots[i - (k + 1)] + emptySlots[i];
		ans = max(sum, ans);
	}
	return ans;
}

//===================================================================================================
// no of unique paths :: https://www.codingninjas.com/codestudio/problems/total-unique-paths_1081470

// total unique paths: from (0,0)->(m-1,n-1)
// Returns count of possible paths to reach cell at
// row number m and column  number n from the topmost
// leftmost cell (cell at 1, 1)
int numberOfPaths(int m, int n)
{
    // Create a 2D table to store results of subproblems
    int count[m][n];

    // Count of paths to reach any cell in first column is 1
    for (int i = 0; i < m; i++)
        count[i][0] = 1;

    // Count of paths to reach any cell in first row is 1
    for (int j = 0; j < n; j++)
        count[0][j] = 1;

    // Calculate count of paths for other cells in
    // bottom-up manner using the recursive solution
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++)

            // By uncommenting the last part the code calculates the total
            // possible paths if the diagonal Movements are allowed
            count[i][j] = count[i - 1][j] + count[i][j - 1]; //+ count[i-1][j-1];
    }
    return count[m - 1][n - 1];
}

// same pblm with obstacles:: https://www.geeksforgeeks.org/unique-paths-in-a-grid-with-obstacles/ 

//===================================================================================================
// Dictionary Nomad :: https://binarysearch.com/problems/Dictionary-Nomad/

/*
Dictionary Nomad (Hard)
You are given a list of strings dictionary and two strings start and end.
You want to reach from start to end by modifying one character at a time and making sure each resulting word is also in the dictionary.
Words are case-sensitive.
Return the minimum number of steps it would take to reach end. Return -1 if it's not possible.

Constraints
0 ≤ n * m ≤ 300,000 ;where n is the length of dictionary and m is the length of the longest string

Example 1
Input
dictionary = ["day", "say", "soy"]
start = "soy"
end = "day"
Output
3
Explanation
We can take this path: ["soy", "say", "day"].

Example 2
Input
dictionary = ["day", "soy"]
start = "soy"
end = "day"
Output
-1
Explanation
There's no way to change 1 character to reach "day".
*/
int solve(vector<string>& dictionary, string start, string end) {
    unordered_set<string> seen{start}, dict(dictionary.begin(), dictionary.end());
    queue<string> q{{start}};
    int steps = 0;
    while (!q.empty()) {
        int sz = q.size();
        steps++;
        while (sz-- > 0) {
            auto& p = q.front();
            if (p == end) return steps;
            q.pop();
            for (int i = 0; i < p.size(); i++) {
                char old = p[i];
                for (char c = 'a'; c <= 'z'; c++) {
                    p[i] = c;
                    if (dict.count(p) && !seen.count(p)) {
                        seen.insert(p);
                        q.push(p);
                    }
                }
                p[i] = old;
            }
        }
    }
    return -1;
}

//===================================================================================================
//===================================================================================================
/*
Uber OA - codesignal 2021 :: https://leetcode.com/discuss/interview-question/1272223/uber-oa-questions-codesignal-test-2021
Ques 1 : given 2 string s , t we have to find kth character from the string formed by following process lets say x = ""
i = 1 append s to x 1 time
i = 2 append t to x 2 times
i = 3 append s to x 3 times
i = 4 append t to x 4 times
i = 5 append s to x 5 times ...and so on
you are given k <= 10^16, you have to find kth character from x formed using above process.
eg: s = "a", t = "bc", k = 4 ---> given input
Output: b
(since string x = "abcbcaaabcbcbcbc..... 4th char is b)

*/
char kthCharacter(string s,string t,int k)
{
    k = k-1;
    for(int index=1;k>=0;index++)
    {
        if(index%2==1)
        {
            if(s.size()*index > k)
            {
                return s[k%s.size()];//
            }
            else
            {
                k = k-(s.size()*index);
            }
        }
        else
        {
            if(t.size()*index > k)
            {
                return t[k%t.size()];//
            }
            else
            {
                k = k-(t.size()*index);
            }
        }
    }
}
//================================

/*
Uber OA - codesignal 2021 :: https://leetcode.com/discuss/interview-question/1272223/uber-oa-questions-codesignal-test-2021
Ques 2 : given a, b, c, d we have to find

	sum = 0;
	for(int i=a; i<=b; ++i) {
		for(int j=c; j<=d; ++j) {
			sum += (i^j);
		}
	}
	return sum
we have to optimize this, This code was given in question itself.
eg: a = 2, b = 3, c = 7, d = 8 --> given input
output : 30
final ans is --> (2^7) + (2^8) + (3^7) + (3^8) = 5 + 10 + 4 + 11 = 30

*/
// for q2- we can do it O(31(max( abs(a-b) , abs(c-d) ) ) time complexity
// https://codeforces.com/blog/entry/81136
int sumXor( int a , int b , int c , int d ) 
{
      int mod = 1e9+7 ; 
      int res = 0 ; 
      for( int i = 0 ; i < 31 ; i++ )
      {
             int f0 = 0 , f1 = 0 ;
             int s0 = 0 , s1 = 0 ; 
            for( int j = a ; j <= b ; j++ )
            {
                   if((j&(1<<i)))f1++;
                   else f0++;
            }
            for( int j = c ; j <= d ; j++ )
            {
                   if((j&(1<<i)))s1++;
                   else s0++;
            }
            res += (f0*s1 + f1*s0)*(1<<i) ; 
           res %= mod ;
      }
      return res%mod ; 
}
//===================================================================================================

// codesignal:divisor strings :: https://leetcode.com/discuss/interview-question/891658/postmates-oa-divisor-strings
/*
You are given two integers, n and k. Consider the string representation of n, and find the number of distinct
substrings of length k, such that n is divisible by the number formed by that substring. In other words, how many
different numbers formed by k consecutive digits of n are factors of n?

Note: The k-digit substrings may have leading zeros.
Example

For n = 120 and k = 2, the output should be divisorSubstrings(n, k) = 2.

The divisor substrings are 12 and 20 (120 is divisible by both of these).

For n = 555 and k = 1, the output should be divisorSubstrings(n, k) = 1.

All the substrings of length 1 are equal to 5 which is a divisor of 555. The answer is not 3 since we're only counting
distinct numbers.

For n = 5341 and k = 2, the output should be divisorSubstrings(n, k) = 0.

5341 is not divisible by 53, 34 nor 41, so the answer is 0.

Input/Output

[execution time limit] 4 seconds (php)

[input] integer n

An integer representing the number we're trying to find the substring factors of.

Guaranteed constraints:
1 ≤ n ≤ 109.

[input] integer k

An integer representing how many digits long the substrings should be.

Guaranteed constraints:
1 ≤ k ≤ 10,
10k - 1 ≤ n.

[output] integer

The number of distinct substrings of length k which are factors of n.
*/
import java.util.HashSet;
import java.util.Set;

class SubStringDivisible {

    static int countSubStr(int n, int k) {
        String str = String.valueOf(n);
        int count = 0;
        long strNum = Long.parseLong(str);
        Set<String> set = new HashSet<>();
        for (int i = 0; i < str.length(); i++) {
            for (int j = i + 1; j <= str.length(); j++) {
                String sub = str.substring(i, j);
                if(sub.length() == k) {
                    long num = Long.parseLong(sub);
                    if (num != 0 && strNum % num == 0 && !set.contains(sub)) {
                        count++;
                        set.add(sub);
                    }
                }
            }
        }
        return count;
    }


    // Driver code
    public static void main(String[] args) {
        int str = 120;
        int k = 2;
        System.out.println(countSubStr(str, k));

        str = 555;
        k = 1;
        System.out.println(countSubStr(str, k));

        str= 5341;
        k = 2;
        System.out.println(countSubStr(str, k));
    }
}

//===================================================================================================

//===================================================================================================

//===================================================================================================
//===================================================================================================
//===================================================================================================
//===================================================================================================
//===================================================================================================
//===================================================================================================
//===================================================================================================
//===================================================================================================
//===================================================================================================

//===================================================================================================
//===================================================================================================
//===================================================================================================
//===================================================================================================
//===================================================================================================
//===================================================================================================
//===================================================================================================
//===================================================================================================
