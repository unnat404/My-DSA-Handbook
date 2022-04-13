// ========================================================================================
// https://www.interviewbit.com/problems/stack-queue/
/*
Given an array of integers A. There is a sliding window of size B which is moving from the very left of the array to the very right.
 You can only see the B numbers in the window. Each time the sliding window moves rightwards by one position.
 You have to find the maximum for each window and print it in a new line.
Return an array C, where C[i] is the maximum value in the array from A[i] to A[i+B-1].
Refer to the given example for clarity.

Constraints

1 <= B <= |A|<= 106
Input Format

The first argument given is the integer array A.
The second argument given is the integer B.
Output Format

Return an array C, where C[i] is the maximum value of from A[i] to A[i+B-1].
Sample Input

A = [1, 3, -1, -3, 5, 3, 6, 7]
B = 3
Sample Output

[3, 3, 5, 5, 6, 7]
*/

// Complete the given function
vector<int> solve(vector<int> &A, int B){
    int n = A.size();
    assert(B <= n);
    vector<int> C;
    C.resize(n - B + 1);
    deque<int> Q;
    for (int i = 0; i < B; i++) {
        while (!Q.empty() && A[i] >= A[Q.back()])
            Q.pop_back();
        Q.push_back(i);
    }
    for (int i = B; i < n; i++) {
        C[i - B] = A[Q.front()];
        while (!Q.empty() && A[i] >= A[Q.back()])
            Q.pop_back();
        while (!Q.empty() && Q.front() <= i - B)
            Q.pop_front();
        Q.push_back(i);
    }
    C[n - B] = A[Q.front()];
    return C;
}
// deque question
// ========================================================================================
