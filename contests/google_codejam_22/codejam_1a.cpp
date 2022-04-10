// =============================================================================
// Template
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long 

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t,n,i,j,sum,cas,x,maxi;
    string ans="",tem;

    cas=0;
	cin>>t;
	while(t>0)
	{
	    t--;cas++;
	    cin>>n;
	    
        
	    
	    ans+="Case #"+to_string(cas)+": "+to_string(curr)+"\n";
	}
	ans.erase(ans.length()-1);//removing new line charector from end
	cout<<ans;
    return 0;
}

// =============================================================================
