
/* 
Uber Questions Lists:
1- find all subsets that sum up to k ::  https://www.codingninjas.com/codestudio/problems/return-subsets-sum-to-k_759331
2- rotten oranges :: 
3- meeting :: https://www.codingninjas.com/codestudio/problems/meeting_1376415
4- house robbers
5- running median :: https://www.geeksforgeeks.org/median-of-stream-of-integers-running-integers/
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
