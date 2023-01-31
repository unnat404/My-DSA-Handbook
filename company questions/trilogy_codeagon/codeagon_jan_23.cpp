/*

8 Jan, 2023
Qns: 
- https://leetcode.com/discuss/interview-question/3018724/codeagon-2023-trilogy-innovations-hiring-contest
- https://docs.google.com/document/d/1ojXmh6o7l81REn7YWA2MeX5rtCchFiODoDVtIiwHt0k/edit?usp=sharing
*/

// ================================================================
#include <bits/stdc++.h>
using namespace std;
// ================================================================
/*
1. Two operations
Sol:

my observations:
- if n<=3 : ans = 0 (since any 2 can be substituted to a third element)
- there will be 3 candidates for sol (keep in mind we have atleast 4 elements in the vector now)
    - candidate 1 : substitute 1st two elements with the third element
    - candidate 2 : substitute last two elements with the third last element
    - candidate 3 : substitute first element with second element AND last eelement with the second last element 

*/ 
// int Solution::solve(vector<int> &v){
int twoOperations(vector<int>& v){
    sort(v.begin(),v.end());
    int ans,n=v.size();
    if(n<=3) return 0;
    ans = v[n-1]-v[0];//no change
    // 3 candidates for soln
    ans = min(ans,v[n-1]-v[2]);// candidate 1 
    ans = min(ans,v[n-3]-v[0]);// candidate 2 
    ans = min(ans,v[n-2]-v[1]);// candidate 3
    return ans;
}

// ================================================================
/*
5. Intersection Segments
Qn similar to : https://leetcode.com/problems/count-integers-in-intervals/description/

Soln: 
use this framwork to solve it:
https://github.com/kanisht09/Data-Structures-and-Algorithms/blob/main/C%2B%2B/Data%20Structures/Interval_structure.cpp

*/

#include <bits/stdc++.h>
#define ll long long
#define ff first
#define ss second
using namespace std;
struct range_maintainance {

    set<pair<int, int>>s;
    int get_size(){
        return s.size();
    }
    void fill_range(int x, int y) {
        auto it = s.upper_bound({x, 1e9});
        if (it != s.begin()) {
            it--;
            if (it->ss >= x) {
                // merge with [x,y]
                x = it->ff;
                y = max(y, it->ss);
                s.erase(it);

            }
        }
        it = s.upper_bound({y, 1e9});
        if (it != s.begin()) {
            it--;
            if (it->ss >= y) {
                // merge with [x,y]
                y = it->ss;
                x = min(x, it->ff);
                s.erase(it);

            }
        }
        while (1) {
            it = s.lower_bound({x, -1e9});
            if (it == s.end() || (it->ff >= y))
                break;
            s.erase(it);
        }
        s.insert({x,y});

    }
    void clear_range(int x, int y)
    {
        auto it = s.upper_bound({x, 1e9});
        if (it != s.begin()) {
            it--;
            if (it->ss >= y) {
                ll lo1 = it->ff;
                ll hi1 = x;


                ll lo2 = y;
                ll hi2 = it->ss;

                s.erase(it);
                s.insert({lo1, hi1});
                s.insert({lo2, hi2});
                return;
            }
            if (it->ss >= x) {

                ll lo = it->ff;
                ll hi = x;
                s.erase(it);
                s.insert({lo, hi});

            }
        }
        it = s.upper_bound({y, 1e9});
        if (it != s.begin()) {
            it--;
            if (it->ss >= y) {
                // merge with [x,y]

                ll lo = y;
                ll hi = it->ss;
                s.erase(it);
                s.insert({lo, hi});
            }
        }
        while (1) {
            it = s.lower_bound({x, -1e9});
            if (it == s.end() || (it->ff >= y))
                break;
            s.erase(it);
        }
    }
    bool check_point(int x) {
        auto it = s.upper_bound({x, 1e9});
        if (it == s.begin()) {
            return 0;
        }
        it--;
        return it->ss >= x;
    }
    bool check_range_any(int x, int y) {
        auto it = s.upper_bound({x, 1e9});
        if (it != s.end()) {
            if (it->first <= y) {
                return 1;
            }
        }
        return check_point(x);

    }
    bool check_range_all(int x, int y) {
        auto it = s.upper_bound({x, 1e9});
        if (it == s.begin()) {
            return 0;
        }
        it--;
        return it->ss >= y;
    }
    void print_status()
    {
        for (auto i : s) {
            cout << i.ff << " " << i.ss << ',';
        }
        cout<<'\n';

    }
};

int main(){
    range_maintainance ob;
    ob.fill_range(2,6);
    cout<<(ob.get_size());
    ob.fill_range(4,9);
    cout<<(ob.get_size());
    ob.fill_range(12,66);
    cout<<(ob.get_size());
    ob.fill_range(0,60);
    cout<<(ob.get_size());
    
}
// =====================================================================