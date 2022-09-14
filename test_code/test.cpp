// most optimized : 
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define ull unsigned long long int

// build lps array
vector<int> kmpProcess(string needle) {
	int n = needle.size();
	vector<int> lps(n, 0);
	for (int i = 1, len = 0; i < n;) {
		if (needle[i] == needle[len]) {
			lps[i++] = ++len;
		} else if (len) {
			len = lps[len - 1];
		} else {
			lps[i++] = 0;
		}
	}
	return lps;
}

// fuction to find matching substring exists or not (using KMP algo)
int findNeedleInHaystack(string haystack, string needle) {
	int m = haystack.size(), n = needle.size();
	if (!n) {
		return 0;
	}
	vector<int> lps = kmpProcess(needle);
	for (int i = 0, j = 0; i < m;) {
		if (haystack[i] == needle[j]) { 
			i++, j++;
		}
		if (j == n) {
			return i - j;
		}
		if (i < m && haystack[i] != needle[j]) {
			j ? j = lps[j - 1] : i++;
		}
	}
	return -1;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("consecutive_cuts_chapter_1_validation_input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll i,t,n,k,x;
	
    int found,cas;
    string s,res="",ans,a,b,tem;
	bool possible;

    cas=0;
	cin>>t;
	while(t>0){
	    t--;cas++;
	    cin>>n>>k;
		a=b="";
		found=-1;
		for(i=0;i<n;i++){
			cin>>tem;
			if(a=="") a+= tem;
			else a+= " " +tem;			
		}	
		for(i=0;i<n;i++){
			cin>>tem;
			if(b=="") b=tem;
			else b+= " " +tem;			

		}

		b += " " +b;
		if(k>0) found = findNeedleInHaystack(b,a);

		if(found == -1) ans = "NO";
		else ans = "YES";
	    res+="Case #"+to_string(cas)+": "+ans+"\n";
	}
// 	ans.erase(ans.length()-1);//removing new line charector from end
	cout<<res;
    return 0;
}
