
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long 
int findParity(string s){
	int sum=0;
	for(auto c:s){
		sum += c-'a'+1;
	}
	return sum%2==0 ? 0:1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
    
    int t,n,q,i,j,sum,cur,cas,u,v,node,x,y,last;
    string s,ans="",word="",tem;

    cas=0;
	// cin>>t;
	t=1;
	while(t>0)
	{
	    t--;cas++;
	    cin>>s;
		s+="-";
		n=s.length();
		tem=ans=word="";
		vector<string> v;
		unordered_map<string,string> m;
		for(i=0;i<n;i++){
			if(s[i]!='-') word+=tolower(s[i]);//word+=s[i];
			else{
				v.push_back(word);
				tem=word;
				sort(tem.begin(),tem.end());
				if(findParity(tem)==1) reverse(tem.begin(),tem.end());
				m[word]=tem;
				// ans+=word+"-";
				tem = word = "";
			}
		}
		sort(v.begin(),v.end());
		
		// for(auto x:m) cout<<x.first<<" "<<x.second<<"\n";

		for(auto x:v){
			ans += m[x]+"-";
		}
		ans = ans.substr(0,ans.size()-1);
		
	}
	// ans.erase(ans.length()-1);//removing new line charector from end
	cout<<ans;
    return 0;
}
/*
i/p : oihA-uMakHig-jjfSxU-jDxUPHCgq-CZNNx
o/p : zxnnc-cdghjpqux-fjjsux-oiha-aghikmu
*/
// =================================================================================================

// qn : https://www.geeksforgeeks.org/multiply-large-numbers-represented-as-strings/