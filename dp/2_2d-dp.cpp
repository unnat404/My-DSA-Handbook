/***************************************************************************************************
 DP Problem List:

 -> 1d dp: 
    - climbing stairs :: https://leetcode.com/problems/climbing-stairs/
    - hosue robber    ::  https://leetcode.com/problems/house-robber/
    - house robber 2  ::
    - decode ways 1   :: https://leetcode.com/problems/decode-ways/
    - decode ways 2   :: 
    - Leetcode 53. Maximum subarray :: https://leetcode.com/problems/maximum-subarray/
    - Leetcode 152. Maximum   Subarray :: https://leetcode.com/problems/maximum-product-subarray/
    - Leetcode 978. Longest Turbulent Subarray :: https://leetcode.com/problems/longest-turbulent-subarray/
    - Leetcode 32. Longest Valid Parentheses :: https://leetcode.com/problems/longest-valid-parentheses/
    - 
    - to do :: Leetcode 413. Arithmetic Series
    - to do :: Leetcode 343. Interger Break
    - to do :: Leetcode 2147. Number of Ways to Divide a Long Corridor :: https://leetcode.com/problems/number-of-ways-to-divide-a-long-corridor/


 -> 2d dp:
	- 1 suffix array + 1 integer(of certain range) :: knapsack problems and its variants (lec -6 ka mid se, lec7,lec8)
	- 2 suffix(/prefix) arrays
		○ Longest common subsequence
		○ Longest palindromic substring
        ○ Longest palindromic subsequence

*****************************************************************************************************/
//===================================================================================================
// Longest palindromic subsequence :: https://leetcode.com/problems/longest-palindromic-subsequence/

class Solution {
public:
    /* Approach 1: s = original & s' = reverse of s, find the LCS(s,s') ; LCS=longest common subsequence 
       Approach 2: expand palindrome around the center */
    int longestPalindromeSubseq(string s) {
        // Solution for Approach 2
        // Optimization pblm (since longest) => can think of DnC (Divide and Conquer) approach 
        // Here our subproblem can be thought as this: for LPS(s[0 .... n-1]) 
        // if(s[0]==s[n-1]) then LPS(s[0 .... n-1]) = 2+LPS(s[1 ... n-2])
        // else LPS(s[0 ... n-1]) = max(LPS(s[1 ... n-1]), LPS(s[0 ... n-2]) )
        
        // form above its clear that our subproblem will be any general subarray of string s  => s[i ... j]
        // => we have 2 variables here i & j (start & end indexes of any subarray)        
        int i,j,n=s.length();
        vector<vector<int>> dp(n,vector<int>(n,0));
        
        //Recurrence Relation
        // dp(i,j) <- length of LPS in s[i ... j]
        // dp(i,j) = dp[i+1][j-1] : if(s[i]==s[j])
        //         = max(dp[i][j-1],dp[i+1,j]) : if(s[i]!=s[j])
        
        //Base Case
        for(i=0;i<n;i++) dp[i][i]=1;
        
        for(i=n-2;i>=0;i--){//bottom to up
            for(j=i+1;j<n;j++){//left to right
                if(s[i]==s[j]) dp[i][j]=2+dp[i+1][j-1];
                else{
                    dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
                }
            }
        }
        //dp[0][n-1] :: final ans
        return dp[0][n-1];
    }
};
/*
"aa"
1 2 _/        1 3 ~
0 1           0 1   


"aaa"
 i|j  0 1 2
 
 0:   1 2 3
 1:   0 1 2
 2:   0 0 1
*/
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
//===================================================================================================
//===================================================================================================
//===================================================================================================
//===================================================================================================
