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

-> to do:
    - https://leetcode.com/problems/count-substrings-that-differ-by-one-character/

    
-> https://www.geeksforgeeks.org/top-20-dynamic-programming-interview-questions/?ref=lbp
-> https://www.geeksforgeeks.org/dynamic-programming-trees-set-1/
-> https://www.geeksforgeeks.org/dynamic-programming-trees-set-2/
*****************************************************************************************************/
// climbing stairs :: https://leetcode.com/problems/climbing-stairs/
//top down approach
class Solution {
public:
    //top down approach
    int climbHelper(int i,vector<int> &dp){
        if(i<=1){ dp[i]=1; return 1;}
        
        if(dp[i]!=-1) return dp[i];
        
        return dp[i]=climbHelper(i-1,dp)+climbHelper(i-2,dp);
        
    }
    int climbStairs(int n) {
        //dp[i] <- no of ways to reach i th step
        vector<int> dp(n+1,-1);
        return climbHelper(n,dp);
        
        
    }
};

//bottom up approach
class Solution {
public:
    int climbStairs(int n) {
        //dp[i] <- no of ways to reach i th step
        vector<int> dp(n+1,0);
        dp[1]=dp[0]=1;
        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];        
    }
};
//===================================================================================================
// hosue robber ::  https://leetcode.com/problems/house-robber/
class Solution {
public:
    int rob(vector<int>& nums) {
        //decision: which is the first home to rob : {0...n-1}
        //dp[i] <- max amt that can be stolen till house i if s[i] is robbed
        int i,n=nums.size();
        vector<int> dp(n+1,0);
        dp[n]=0,dp[n-1]=nums[n-1];
        for(i=n-2;i>=0;i--){
            dp[i]=max(dp[i+1],nums[i]+dp[i+2]);
        }
        return dp[0];
    }
};
//===================================================================================================
// decode ways 1:: https://leetcode.com/problems/decode-ways/
class Solution {
public:
    int numDecodings(string s) {
        int i,n=s.size();
        //dp[i] <- no of ways to decode s[i...n-1]
        //recurrence:
        //dp[i] = dp[i+1] + { dp[i+2] :: if s.substr(i,2) <= 26 }
        vector<int> dp(n+1,0);
        // dp[n]=dp[n-1]=1;
        dp[n]=1;
        dp[n-1]= s[n-1]=='0' ? 0:1;//important (edge case)
        for(i=n-2;i>=0;i--){
            if(s[i]=='0') continue; //important (edge case)
            dp[i] = dp[i+1];
            if(s.substr(i,2)<="26") dp[i]+=dp[i+2];
        }
        return dp[0];
    }
};
//===================================================================================================
//decode ways 2:: 

//===================================================================================================
// Leetcode 53. Maximum subarray :: https://leetcode.com/problems/maximum-subarray/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //recurrence:: 
        // s(i)=max(a[i]+s(i-1),a[i])
        int i,n=nums.size(),ans;
        if(n==0) return 0;
        vector<int> dp(n+1,0);
        dp[0]=ans=nums[0];
        for(i=1;i<n;i++){
            dp[i]=max(nums[i],nums[i]+dp[i-1]);
            ans=max(ans,dp[i]); //keep running maximum of all dp[i] 's
        }
        return ans;
    }
};
//input :: [-2,1,-3,4,-1,2,1,-5,4]
//dp[i] :: -2 1 -2 4 3 5 6 1 5
//ans = max(dp[i]) = 6
//above code can be space optimized -> kandane's algo
class Solution { //kadanee's algo
public:
    int maxSubArray(vector<int>& nums) {
        int ans=nums[0],tem,i,n=nums.size();
        tem=nums[0];
        for(i=1;i<n;i++){            
            if(tem+nums[i]<nums[i]){
                tem=nums[i];
            }
            else tem+=nums[i];
            ans=max(tem,ans);            
        }
        return ans;        
    }
};
//===================================================================================================
// Leetcode 152. Maximum Product Subarray :: https://leetcode.com/problems/maximum-product-subarray/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans,i,n=nums.size();
        if(n==0) return 0;
        //2 dp arrays:: maxPdt till i, minPdt till i (including i)
        // s(i) <- max product ending at indx i (including i, as subaaray) + , - 
        // s(i) = max(maxPdt[i-1]*nums[i],minPdt[i-1]*nums[i])
        vector<int> maxPdt(n),minPdt(n);
        maxPdt[0]=minPdt[0]=ans=nums[0];
        for(i=1;i<n;i++){
            maxPdt[i]=max(nums[i],max(maxPdt[i-1]*nums[i],minPdt[i-1]*nums[i]));
            minPdt[i]=min(nums[i],min(minPdt[i-1]*nums[i],maxPdt[i-1]*nums[i]));
            ans=max(ans,maxPdt[i]);
        }
        return ans;
    }
};

// i/p    : -2  3   -4
//Ans: 24 : Reason:: below
// maxPdt : -2  3   24
// minPdt : -2  -6   -12
//===================================================================================================

// Leetcode 978. Longest Turbulent Subarray :: https://leetcode.com/problems/longest-turbulent-subarray/
//my implementation: this is cleaner for me 
class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int i,n=arr.size(),ans=1;
        if(n==0) return 0;
        // if(n==1) return 1;//edge 
        // upDown :: 0,1,0,1,0,1... pattern
        // downUp :: 1,0,1,0,1,0... pattern
        vector<int> upDown(n,0),downUp(n,0);
        upDown[0]=downUp[0]=0;
        for(i=1;i<n;i++){
            //equality is an edge case
            if(arr[i]>arr[i-1]){
                upDown[i]=max(downUp[i-1]+1,2);
                //updown[i] will extend from downUp[i-1], if downUp[i-1] exists 
                //else, new pattern of upDown[i] with size 2 is formed 
            }
            else if(arr[i]<arr[i-1]){
                downUp[i]=max(upDown[i-1]+1,2);
            }
            ans=max(ans,max(upDown[i],downUp[i]));//keep running max
        }
        return ans;
    }
};

//---------------same approach slightly different implementation (sanket bhaiya)
class Solution {
public:
    int maxTurbulenceSize(vector<int>& nums) {
        int i,j,ans,n=nums.size();
        vector<int> upDown(n,0),downUp(n,0);
        //upDown: 0,1,0,1,... pattern
        //downUp: 1,0,1,0,... pattern
        upDown[0]=downUp[0]=ans=1;
        for(i=1;i<n;i++){
            //equality :: edge case
            if(i%2==1){//odd index
                upDown[i]= nums[i]>nums[i-1] ? upDown[i-1]+1 : 1;
                downUp[i]= nums[i]<nums[i-1] ? downUp[i-1]+1 : 1;                
            }
            else{//even index
                upDown[i]= nums[i]<nums[i-1] ? upDown[i-1]+1 : 1;
                downUp[i]= nums[i]>nums[i-1] ? downUp[i-1]+1 : 1;
            }
            ans=max(ans,max(upDown[i],downUp[i]));
        }
        return ans;
        
    }
};

//===================================================================================================

// Leetcode 32. Longest Valid Parentheses :: https://leetcode.com/problems/longest-valid-parentheses/
// 2 approaches :: ->stack approach  ->dp approach

//approach 2: using dp
class Solution {
public:
    //approach 1: using stack
    //approach 2: using dp(current)
   
    int longestValidParentheses(string s) {
        int i,n=s.length(),prev_end,cur_begin,ans=0;
        if(n==0) return 0;
        vector<int> dp(n,0);
        //dp[i] : max length of valid paren ending at index i
        dp[0]=0;//empty is valid paren
        for(i=1;i<n;i++){
            if(s[i]=='('){
                dp[i]=0;continue;
            }
            else{ // for -> s[i]=')'
                cur_begin = i-dp[i-1]-1;
                if(cur_begin>=0 && s[cur_begin]=='('){
                    dp[i]=dp[i-1]+2; //+2 for indexes : i , cur_begin
                    prev_end = cur_begin-1;
                    if(prev_end >= 0){
                        dp[i] += dp[prev_end]; // +dp[prev_end] for the pattern ending just b4 current pattern start
                    }
                }
            }
            ans=max(ans,dp[i]);           
        }
        return ans;
    }
};

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
//===================================================================================================
//===================================================================================================
//===================================================================================================
//===================================================================================================
//===================================================================================================
//===================================================================================================
//===================================================================================================
//===================================================================================================
