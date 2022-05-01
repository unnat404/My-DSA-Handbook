
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long 
bool isPalindrome(string S)
{
    for (int i = 0; i < S.length() / 2; i++) {
        if (S[i] != S[S.length() - i - 1]) {
            return false;
        }
    }
    return true;
}
int main()
{
    // brute force ?? pie(x^2)
    // r,r*a,(r*a/b),(r*a/b)*a,((r*a/b)*a)/b
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    
    ll t,n,i,j,sum,cas,x,count,ans;
    string s,anss="",tem;

    cas=0;
	cin>>t;
	while(t>0){
	    t--;cas++;
	    cin>>n;
	    tem="";
	    ans=count=0;
	    while(n%2==0){
	        n/=2;
	        count++;
	    }
	    if(count>0) ans++;
	    for(int i=3;i<=sqrt(n);i+=2){
	        count=0;
	        while(n%i==0){
	            n/=i;
	            count++;
	        }
	        if(count>0 && isPalindrome(to_string(i))){
	            ans++;
	        }
	    }
	    if(isPalindrome(to_string(n))) ans++;
	   
	    anss+="Case #"+to_string(cas)+": "+to_string(ans)+"\n";
	}
// 	ans.erase(ans.length()-1);//removing new line charector from end
	cout<<ans;
    return 0;
}