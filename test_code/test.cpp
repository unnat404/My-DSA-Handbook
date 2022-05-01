#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long 
vector<vector<int>> pe = {{1,2,3},{1,3,2},{2,1,3},{2,3,1},{3,1,2},{3,2,1}};
vector<vector<int>> po = {{1,2},{2,1}};
void f(int i,vector<vector<int>>& v,int last,int p,int n,int sum,int ans){
	if(i>=n){
		ans=min(ans,sum);
	}
	if(p==2){
		for(auto x:po){
			sum+=abs(v[i][x[0]-1]-last);
			last = v[i][x[0]-1];
			sum+=abs(v[i][x[1]-1]-last);
			last = v[i][x[1]-1];
			f(i+1,v,last,p,n,sum,ans);			
		}
		
	}
	else if(p==3){
		for(auto x:pe){
			sum+=abs(v[i][x[0]-1]-last);
			last = v[i][x[0]-1];
			sum+=abs(v[i][x[1]-1]-last);
			last = v[i][x[1]-1];
			sum+=abs(v[i][x[2]-1]-last);
			last = v[i][x[2]-1];
			f(i+1,v,last,p,n,sum,ans);
		}
		
	}
	else{
		return;
	}
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
    // vector<vector<int>> pe = {{1,2,3},{1,3,2},{2,1,3},{2,3,1},{3,1,2},{3,2,1}};
	// vector<vector<int>> po = {{1,2},{2,1}};
    
    int t,n,p,i,j,sum,cas,x,count,ans,last,ai;
	int asize;
    string s,anss="",tem;

    cas=0;
	cin>>t;
	while(t>0){
	    t--;cas++;
	    cin>>n>>p;
		ai=0;
		if(p==2) asize=(int)(pow(2,n));
		else if(p==3) asize=(int)(pow(6,n));
		vector<int> sol((int)asize);
		vector<vector<int>> v(n,vector<int>(p));
	    for(i=0;i<n;i++){			
			j=0;
			while(j<p){
				cin>>x;
				v[i][j++]=x;
			}			
	    } 
		ans=INT_MAX;
		f(0,v,0,p,n,0,ans);
// void f(int i,vector<vector<int>>& v,int last,int p,int n,int sum,int& ans){

	    
	    anss+="Case #"+to_string(cas)+": "+to_string(ans)+"\n";
	}
// 	ans.erase(ans.length()-1);//removing new line charector from end
	cout<<anss;
    return 0;
}
