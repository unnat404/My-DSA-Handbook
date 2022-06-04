// Template =======================================================================================
// #include <iostream>
// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long 

// int main()
// {
//     // brute force ?? pie(x^2)
//     // r,r*a,(r*a/b),(r*a/b)*a,((r*a/b)*a)/b

//     // #ifndef ONLINE_JUDGE
//     // freopen("input.txt", "r", stdin);
//     // freopen("output.txt", "w", stdout);
// 	// #endif

//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

    
//     ll t,n,i,j,sum,cas,x,count,ans;
//     string s,res="",tem;

//     cas=0;
// 	cin>>t;
// 	while(t>0){
// 	    t--;cas++;
	    
	   
// 	    res+="Case #"+to_string(cas)+": "+to_string(ans)+"\n";
// 	}
// // 	ans.erase(ans.length()-1);//removing new line charector from end
// 	cout<<res;
//     return 0;
// }
// =======================================================================================================
// 1) New Password : https://codingcompetitions.withgoogle.com/kickstart/round/00000000008cb4d1/0000000000b20f15
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

    
    ll t,n,i,j,sum,cas,x,count,ans;
    string s,res="",tem,p;
    bool digit,upper,lower,len,special;

    cas=0;
	cin>>t;
	while(t>0){
	    t--;cas++;
	    cin>>n>>p;
	    digit=upper=lower=len=special=false;
	    for(char ch:p){
	        if(ch-'A'>=0 && ch-'A'<26) upper=true;
	        if(ch-'a'>=0 && ch-'a'<26) lower=true;
	        if(ch-'0'>=0 && ch-'0'<10) digit=true;
	        if(ch=='#' || ch=='@' || ch=='*' || ch=='&') special=true;
	    }
	    
	    if(!upper) p+='A';
	    if(!lower) p+='a';
	    if(!special) p+='#';
	    if(!digit) p+='3';
	    x = 7-p.length();
	    if(x>0){
	        while(x--) p+='a';
	    }
	    
	   
	    res+="Case #"+to_string(cas)+": "+p+"\n";
	}
// 	ans.erase(ans.length()-1);//removing new line charector from end
	cout<<res;
    return 0;
}
//===========================================================================================
// 2) Range Partition
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long 
bool solve(int target,vector<int>& v,int n){
    if(target<=n){
        v.push_back(target);
        return true;
    }
    for(int i=1;i<=n/2 + 1;i++){
        if(target-i < n && target-i != i){
            v.push_back(i);
            v.push_back(target-i);
            return true;
        }
    }
    
    return false;
}
int main()
{
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
	// #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    
    ll t,n,i,j,sum,cas,x,y,count,len,target;
    bool found;
    string s,res="",tem,ans;

    cas=0;
	cin>>t;
	while(t>0){
	    t--;cas++;
	    cin>>n>>x>>y;
	    sum=n*(n+1)/2;
	    
	    if((sum*x)%(x+y)==0){
	        len=0;
	        ans="POSSIBLE\n",tem="";
	       // vector<int> v;
	       target=(x*sum)/(x+y);
	        for(int i=n;i>0;i--){
	            if(i<=target) len++,tem+=to_string(i)+" ",target-=i;//v.push_back(i);
	            
	        }
	        ans+=to_string(len)+"\n"+tem;
	    }
	    else ans="IMPOSSIBLE";
	    
	   // if(sum%(x+y)==0){ 
	   //     vector<int> v;
	   //     found=false;
	   //     ans="POSSIBLE";
	   //     x = x*(sum/(x+y));
	   //     y = sum-x;
	   //     //do for x
	   //     found = solve(x,v,n);
	   //     if(!found){
	   //         //do for y
	   //         found=solve(y,v,n);
	   //     }
	        
	   //     if(!found) ans="IMPOSSIBLE";
	   //     else{
	   //         ans+="\n"+to_string(v.size())+"\n";
	   //         for(auto x:v) ans+=to_string(x)+" ";
	   //        // ans+="\n";
	   //     }
	        
	   // }
	   // else ans="IMPOSSIBLE";
	   
	    res+="Case #"+to_string(cas)+": "+ans+"\n";
	}
// 	ans.erase(ans.length()-1);//removing new line charector from end
	cout<<res;
    return 0;
}
//=====================================================================================