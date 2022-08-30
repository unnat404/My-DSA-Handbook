#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long 

int main()
{
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
	// #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll t,n,i,j,sum,cas,x,y,m,k,trees;
    bool found;
    string s,res="",tem,ans,inp,all_trees;
	bool possible;

    cas=0;
	cin>>t;
	while(t>0){
	    t--;cas++;
	    cin>>n>>m;
		all_trees=inp="";
		trees=0;
		for(i=0;i<n;i++){
			cin>>s;
			inp+=s;
			if(i<n-1) inp+="\n";
			for(auto c:s) trees = (c=='^') ? trees+1 : trees;
		}
		ans = "";
		if(trees>0 && (n==1 || m==1)) ans = "Impossible";
		else{
			ans = "Possible\n";
			if(trees==0) ans+=inp;
			else{
				//all trees
				tem = "";
				for(j=0;j<m;j++) tem+="^";
				for(i=0;i<n;i++){
					all_trees+=tem;
					if(i<n-1) all_trees+="\n";
				}
				ans+=all_trees;
			}			 
		}		
	   
	    res+="Case #"+to_string(cas)+": "+ans+"\n";
	}
// 	ans.erase(ans.length()-1);//removing new line charector from end
	cout<<res;
    return 0;
}
