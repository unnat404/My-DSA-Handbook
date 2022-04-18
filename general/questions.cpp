/***************************************************************************************************
General Problem List:

 -> Contest Upsolving: 
    - Leetcode :: https://leetcode.com/contest/weekly-contest-277/problems/maximum-good-people-based-on-statements/
    - Leetcode 
    - Leetcode 
    - Leetcode 
    - 
    
-> greedy:
    - Leetcode 134. Gas Station :: https://leetcode.com/problems/gas-station 
    - Leetcode 678. Valid Parenthesis String
    - 
 
-> To Do:
    - Leetcode 92. Reverse Linked List II :: https://leetcode.com/problems/reverse-linked-list-ii/
    - shadab:: https://www.geeksforgeeks.org/median-of-two-sorted-arrays-of-different-sizes/
    - shadab:: https://leetcode.com/problems/maximum-employees-to-be-invited-to-a-meeting/
    - shadab:: https://leetcode.com/problems/burst-balloons/
    - shadab:: https://codeforces.com/contest/1625/problem/C
    - shadab:: https://leetcode.com/problems/maximum-employees-to-be-invited-to-a-meeting/
    - shadab:: https://leetcode.com/problems/solving-questions-with-brainpower/
    - shadab:: https://leetcode.com/problems/minimum-cost-to-hire-k-workers/
    - shadab:: https://leetcode.com/problems/maximum-profit-in-job-scheduling/
    
 -> Must Do:
    ○ ...
    ○ ...

*****************************************************************************************************/
//https://www.geeksforgeeks.org/median-of-two-sorted-arrays-of-different-sizes/


// =======================================================================================================================================
// Leetcode 134. Gas Station :: https://leetcode.com/problems/gas-station 
// Either you know or you dont kinda pblm
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int i,n=gas.size(),total=0,gas_left=0,start=0;
        //check if its possible to complete a trip
        for(i=0;i<n;i++){
            total+=(gas[i]-cost[i]);
        }
        if(total<0) return -1;//not possible 
        
        gas_left=0,start=0;
        for(i=0;i<n;i++){
            gas_left+=gas[i]-cost[i];
            if(gas_left<0){
                start=i+1;//if we can't make from point A to B, then our start can't be any point in between [A...B] 
                gas_left=0;
            }
        }
        return start;
    }
};
/*
Algo: 
step 1: 
- check sum(gas)>=sum(cost) => soln is possible 
- Otherwise return -1 => not possible

step 2: 
- move form left to right: 
- if we can't make from point A to B, then our start can't be any point in between [A...B] => increment start to B+1

Note(not sure though): above greedy approach works as its guranteed i the qns that : If there exists a solution, it is guaranteed to be unique

*/
// =======================================================================================================================================
// =======================================================================================================================================
// =======================================================================================================================================
// =======================================================================================================================================
// =======================================================================================================================================
// =======================================================================================================================================
// =======================================================================================================================================
// =======================================================================================================================================
// =======================================================================================================================================
// =======================================================================================================================================
// =======================================================================================================================================
// =======================================================================================================================================
// =======================================================================================================================================







