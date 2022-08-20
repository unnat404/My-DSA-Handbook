/*

1) https://leetcode.com/problems/koko-eating-bananas/
2) Leetcode 33. Search in Rotated Sorted Array :: https://leetcode.com/problems/search-in-rotated-sorted-array/
*/

// ===============================================================================================
#include<bits/stdc++.h>
using namespace std;
// ===============================================================================================
// 2) Leetcode 33. Search in Rotated Sorted Array :: https://leetcode.com/problems/search-in-rotated-sorted-array/
class Solution {
public:
    int findPivot(vector<int>& v){
        // finds pivot index(index of greatest array element) : returns -1 if no pivot exists
        int i,lo=0,hi=v.size()-1,mid;
        int n=v.size();
        while(lo<hi){
            mid = lo + (hi-lo)/2;
            // compare v[lo] and v[hi]
            if(mid+1<n && v[mid]>v[mid+1]) return mid;// prevent out of bounds
            if(v[mid]>v[hi]) lo=mid+1;
            else hi=mid;
        }
        return -1;// what to return ?? : -1, mid, lo, hi
    }
    int binSearch(vector<int>& v,int lo, int hi, int target){
        int mid,i,j;
        
        while(lo<=hi){
            mid=lo+(hi-lo)/2;
            if(v[mid]==target) return mid;
            else if(v[mid]>target) hi = mid-1;
            else lo = mid+1;
        }
        // if(v[lo]==target) return mid;
        return -1;        
    }
    
    int search(vector<int>& nums, int target) {
        int pivotIdx,i,j,n=nums.size(),idx,lo,hi;
        pivotIdx = findPivot(nums);
        // cout<<pivotIdx<<" :: \n";
        if(pivotIdx==-1 || pivotIdx==n-1) lo=0,hi=n-1;
        else if(nums[0]>target) lo = pivotIdx+1, hi =n-1;
        else lo=0,hi=pivotIdx;
        // cout<<lo<<" "<<hi<<"\n";
        return binSearch(nums,lo,hi,target);
    }
};
/*
:: find pivot :: 
- modified binary-search
- condition : v[i]>v[i+1]
  pattern   : T*F*
  find last T

:: apply binary search ::
- on appropriate half apply binary-search to find target

-------------------------
Input
[5,1,3]
5
Output
-1
Expected
0

--------------------------
Your input
[5,1,3]
5
[4,5,6,7,0,1,2]
0
[4,5,6,7,0,1,2]
3
[1]
0

Output
0
4
-1
-1

Expected
0
4
-1
-1

*/