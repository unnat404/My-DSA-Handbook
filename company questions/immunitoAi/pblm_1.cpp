#include<bits/stdc++.h>
using namespace std;
 
 
int n;
string s;
int mx = 0;
string ans = "";
bool solve(int i, int sum, int ct, string rest) {
    if (i == n) {
        if (sum == 0) {
            if (mx < ct) {
                mx = ct;
                ans = rest;
            }
        }
        return (sum == 0);
    }
    bool res = false;
    res |= solve(i + 1, sum + (s[i] - '0'), ct, rest + '+');
    res |= solve(i + 1, sum - (s[i] - '0'), ct + 1, rest + '-');
    return res;
}
 
 
int main() {
 
 
    cin >> s;
    n = s.size();
    int cans = solve(0, 0, 0, "");
    if (cans) {
        if (ans[0] == '+') {
            cout << ans.substr(1) << '\n';
        }
        else
            cout << ans << '\n';
    }
    else {
        cout << "not possible\n";
    }
 
 
 
    return 0;
}
// ===================================
/*

1 rest api based simple hackerranbk question : partial was done : but should have complete full

Selection criteria: >60% in hackerank test

- 2 sql problems : v.v. easy (full done)
- 3 to 4 mcq's : general web based  
    - good uri design
    - accepted rest response types: json, xml, csv
- 
*/
//====================================