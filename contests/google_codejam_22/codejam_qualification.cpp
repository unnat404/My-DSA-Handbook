// ===================================================================================
// Punched Cards (11 Pts)
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long 

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t,n,i,j,r,c,cas;
    string bound="",ans="",dot,tem,fdot,fbound;
    cas=0;
	cin>>t;
	while(t>0)
	{
	    t--;cas++;
	    bound=dot=tem="";
	    cin>>r>>c;
	    for(j=0;j<c;j++){
            if(j==0){
                bound+="..";
                dot+="..";
            }
            else{
                bound+="+-",dot+="|.";
            }
        }
        //boundary and dot container strings for first row of matrix
        bound+="+",dot+="|";
        tem+=bound+"\n"+dot+"\n";
        //modify boundary and dot container strings for rest of matrix
        bound[0]='+',bound[1]='-';
        dot[0]='|',dot[1]='.';
	    for(i=0;i<r-1;i++){
	        tem+=bound+"\n"+dot+"\n";
	    }
	    tem+=bound;
	    // add +-+- boundary for last row
	    
	    ans+="Case #"+to_string(cas)+":\n"+tem+"\n";
	}
	ans.erase(ans.length()-1);//removing new line charector
	cout<<ans;
    return 0;
}
// ===================================================================================
// 3D Printing (13 Pts)
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long 

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t,n,i,j,sum,cas;
    string ans="",tem;
    int v[3][4];
    cas=0;
	cin>>t;
	while(t>0)
	{
	    t--;cas++;
	    sum=1e6;
	    tem="";
	    for(i=0;i<3;i++){
	        for(j=0;j<4;j++){
	            cin>>v[i][j];
	        }
	    }
	    vector<int> ink(4,1e7);
	    for(j=0;j<4;j++){
            for(i=0;i<3;i++){
                ink[j]=min(ink[j],v[i][j]);
            }
            if(sum<ink[j]) ink[j]=sum,sum=0;
            else sum-=ink[j];
        }
        
        if(sum!=0){
            tem="IMPOSSIBLE";
        }
        else{
            for(i=0;i<4;i++){
    	        tem+=to_string(ink[i])+" ";
    	    }
        }
	    
	    ans+="Case #"+to_string(cas)+": "+tem+"\n";
	}
	ans.erase(ans.length()-1);//removing new line charector
	cout<<ans;
    return 0;
}
// ===================================================================================
//d100000

// approach 1: brute : by sorting
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long 

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t,n,i,j,sum,cas;
    string ans="",tem;

    cas=0;
	cin>>t;
	while(t>0)
	{
	    t--;cas++;
	    cin>>n;
	    sum=0;
	    vector<int> v(n);
	    for(i=0;i<n;i++) cin>>v[i];
	    sort(v.begin(),v.end());
	    for(const auto& x:v){
	        if(x>=(sum+1)) sum++;
	    }
	    
	    ans+="Case #"+to_string(cas)+": "+to_string(sum)+"\n";
	}
	ans.erase(ans.length()-1);//removing new line charector from end
	cout<<ans;
    return 0;
}

// approach 2: using indexing/frequency
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
	    maxi=-1;
	    vector<int> f(1e6+10,0));
	    for(i=0;i<n;i++){
            cin>>x;
            maxi=max(maxi,x);
            f[x]++;

        } 
        int curr=0;
	    // sort(v.begin(),v.end());
	    for(i=1;i<=maxi;i++){
            curr=max(i,curr+f[i]);
        }
	    
	    ans+="Case #"+to_string(cas)+": "+to_string(curr)+"\n";
	}
	ans.erase(ans.length()-1);//removing new line charector from end
	cout<<ans;
    return 0;
}
// ===================================================================================

// ===================================================================================

// ===================================================================================

