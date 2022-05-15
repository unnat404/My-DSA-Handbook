// HAckerEarth SDe Hiring challenge
/*
- https://leetcode.com/discuss/interview-question/1991844/AMAZON-or-OA-or-SDE1-or-2022


Minimize Difference

You are given a tree with N vertices numbered from 1 to N. The ith edge connects Vertex xi and Vertex yi bidirectionally. You have to divide this tree into three connected components by cutting any two edges of the tree. Let the three components be C1, C2, and C3. Let X1, X2, and X3 be the XOR of all the vertices of the components C1, C2, and C3 respectively.

Task
Minimize the difference between the maximum and minimum xor values of the components. In short, you have to minimize the value of max(X1, X2, X3) - min(X1, X2, X3).

Notes:
- A tree is an undirected, connected and acyclic graph.
- A set of nodes forms a connected component in a tree if any node from the set of nodes can reach any other node by traversing edges.
- The bitwise XOR of integers A and B, A XOR B, is when A XOR B is written in base two, the digit in the 2k's place (k ≥ 0) is 1 if exactly one of A and B is 1, and 0 otherwise. For example, XOR of (101)2 and (110)2 is (011)2
Cutting an edge means partitioning the vertices of the tree into two disjoint subsets. In other words, cutting an edge results in an increase in the number of connected components.

Example

Assumptions

N = 4
edges = [[1, 2], [2, 3], [4, 1]]
Approach

You can cut the edge between 2 and 3 and the edge between 1 and 4.
The components are now C1 = {1, 2}, C2 = {3} and C3 = {4}. So the XOR values are X1 = 3(1⊕2), X2 = 3 and X3 = 4.
Thus, the answer is 4 - 3 = 1.
Function description

Complete the function solve provided in the editor. This function takes the following 2 parameters and returns the minimum difference between the maximum and minimum XOR values of the components:

N: Represents the number of vertices
edges: Represents the array containing edges of the tree​​
Input format

Note: This is the input format that you must use to provide custom input (available above the Compile and Test button).

The first line contains T denoting the number of test cases. T also specifies the number of times you have to run the solve function on a different set of inputs.
For each test case:
The first line contains integer N denoting the number of vertices.
Each of the following N − 1 line contains two integers x and y which indicates that there is an edge between x and y.
Output format

For each test case in a new line, print the minimum possible difference between the maximum and minimum XOR values of the components.

Sample input

2
5
1 4
5 1
3 4
1 2
4
4 1
3 2
2 1
Sample output

3

1

Explanation

The first line contains the number of test cases, T = 2.

For the first test case

Given

N = 5
edges = [[1, 2], [1, 4], [1, 5], [3, 4]]
Approach

You can cut the edge between 3 and 4 and the edge between 1 and 4.
The components are now C1 = {1, 2, 5}, C2 = {3} and C3 = {4}. So the XOR values are X1 = 6(1⊕2⊕5), X2 = 3 and X3 = 4.
Thus, the answer is 6 - 3 = 3.
Sample Input 1

3
5
4 5
3 1
3 2
1 5
5
5 4
1 3
5 3
3 2
5
2 5
3 4
4 2
4 1
-----------------
Sample Output
-----------------
0
0
2
-------------------------------------
Sample Input 2
-----------------
4
3 4
1 3
4 2
4
3 2
4 1
3 1
9
9 8
5 6
3 9
1 4
3 6
2 8
4 5
5 7
-----------------
Sample Output
-----------------
2
2
1

*/

#include<bits/stdc++.h>
using namespace std;

int solve (int N, vector<vector<int> > edges) {
   // Write your code here
   
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for(int t_i = 0; t_i < T; t_i++)
    {
        int N;
        cin >> N;
        vector<vector<int> > edges(N-1, vector<int>(2));
        for (int i_edges = 0; i_edges < N-1; i_edges++)
        {
        	for(int j_edges = 0; j_edges < 2; j_edges++)
        	{
        		cin >> edges[i_edges][j_edges];
        	}
        }

        int out_;
        out_ = solve(N, edges);
        cout << out_;
        cout << "\n";
    }
}


/*
-----
i/p
-----
3
5
4 5
3 1
3 2
1 5
5
5 4
1 3
5 3
3 2
5
2 5
3 4
4 2
4 1

---
o/p
---
0
0
2

*/