/*

-----------------Resources/Links-----------------
OA Qns
- https://github.com/KushalVijay/CrackMicrosoftResource/blob/main/CrackMicrosoftResource.md
- https://www.geeksforgeeks.org/maximum-difference-first-last-indexes-element-array/
-


Interview Qns
- * https://leetcode.com/discuss/interview-question/398023/Microsoft-Online-Assessment-Questions
    - view comments also for more qns 
    - https://leetcode.com/discuss/interview-question/398023/Microsoft-Online-Assessment-Questions/1255511
    - https://leetcode.com/discuss/interview-question/398023/Microsoft-Online-Assessment-Questions/1046220  
-



*/
//=============================================================================================================

/*
tejasri-nallabothula
58
February 7, 2022 2:49 AM

Read More
Just gave my assessment few minutes ago. I got the following questions

Given an array of integers(+ve,-ve and 0) find the sign of the product of all the given values.
The following code runs fine for smaller inputs but not for the larger inputs. Optimize the code without changing the functionality
public int sol(int[] A){
int N = A.length(), result = 0;
for(int i=0;i<N;i++){
	for(int j=0;j<N;j++){
		if(A[i] == A[j]) result = Math.max(result,Math.abs(i-j));
		}
	}
	return result;
}
Given an integer(+ve or -ve) consisting of at least one 5 in its digits(can have more than one 5). Return the maximum value by deleting exactly one 5 from its digit.
Ex: N = 1598 => result = 198(remove the only 5 from the sequence)
N = 150,958 => result = 15,098(we wanna return the maximum value 15,098 > 10,958)
N = -5859 => result = -589 ( -589>- 859)
I couldn't write the optimized solution for the second problem as I ran out of time. Hope this helps.


*/
// ==========================================================================================
// 1. https://www.geeksforgeeks.org/maximum-difference-first-last-indexes-element-array/

// C++ implementation to find the maximum difference
// of first and last index of array elements
#include <bits/stdc++.h>

using namespace std;

// function to find the
// maximum difference
int maxDifference(int arr[], int n)
{
	// structure to store first and last
	// index of each distinct element
	struct index
	{
		int f, l;
	};
	
	// maps each element to its
	// 'index' structure
	unordered_map<int, index> um;
	
	for (int i=0; i<n; i++)
	{
		// storing first index
		if (um.find(arr[i]) == um.end())
			um[arr[i]].f = i;
		
		// storing last index
		um[arr[i]].l = i;
	}
	
	int diff, max_diff = INT_MIN;
	
	unordered_map<int, index>::iterator itr;

	// traversing 'um'
	for (itr=um.begin(); itr != um.end(); itr++)
	{
		// difference of last and first index
		// of each element
		diff = (itr->second).l - (itr->second).f;
		
		// update 'max_dff'
		if (max_diff < diff)
			max_diff = diff;
	}
	
	// required maximum difference
	return max_diff;
}


// Driver program to test above
int main()
{
	int arr[] = {2, 1, 3, 4, 2, 1, 5, 1, 7};
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "Maximum Difference = "
		<<maxDifference(arr, n);
	return 0;	
}
// ==========================================================================================
