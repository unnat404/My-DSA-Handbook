#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
int reactivity(string s){
    int x,y;
    if(s[0]>='A' && s[0]<='Z'){
        x = 10 + (s[0]-'A');
    }
    else{
        x = 36 + (s[0]-'a');
    }

    if((int)s.length()==1) return x;

    if(s[1]>='a' && s[1]<='z'){
        y = 36 + (s[1]-'a');
    }else y = 10+ (s[1]-'A');

    int base = max(x+1,y+1);
    // x = s[1] + s[0]*base;
    x = y + base * (x);
    return x;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);


    string s,a,e;
    vector<string> v;
    vector<int> r;
    // cin>>s;
    getline(cin,s);

    for(auto& c:s){
        if(c==' '){
            v.push_back(e);
            e="";
        }
        else e+=c;
    }
    if(e!="") v.push_back(e);

    for(auto& x:v){
        r.push_back(reactivity(x));
    }
    int n = (int)v.size();
    int ans=0;

    // for(auto& i: v){
    //     cout<<i<<" ";
    // }cout<<"\n";

    // for(auto& i: r){
    //     cout<<i<<" ";
    // }cout<<"\n";

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            ans = max(ans,__gcd(r[i],r[j]));
        }
    }
    cout<<ans;

    return 0;
}
//H O C N Au Ag Cl : 12
//  Tc S Be Li Er In Dy As I Ac : 7

#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
int reactivity(string s){
    int x,y;
    if(s[0]>='A' && s[0]<='Z'){
        x = 10 + (s[0]-'A');
    }
    else{
        x = 36 + (s[0]-'a');
    }

    if((int)s.length()==1) return x;

    if(s[1]>='a' && s[1]<='z'){
        y = 36 + (s[1]-'a');
    }else y = 10+ (s[1]-'A');

    int base = max(x+1,y+1);
    // x = s[1] + s[0]*base;
    x = y + base * (x);
    return x;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);


    string s,a,e;
    vector<string> v;
    vector<int> r;
    // cin>>s;
    getline(cin,s);

    for(auto& c:s){
        if(c==' '){
            v.push_back(e);
            e="";
        }
        else e+=c;
    }
    if(e!="") v.push_back(e);

    for(auto& x:v){
        r.push_back(reactivity(x));
    }
    int n = (int)v.size();
    int ans=0;

    // for(auto& i: v){
    //     cout<<i<<" ";
    // }cout<<"\n";

    // for(auto& i: r){
    //     cout<<i<<" ";
    // }cout<<"\n";

    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            ans = max(ans,__gcd(r[i],r[j]));
        }
    }
    cout<<ans;

    // cout<<"\n=============\n";
    // cout<<reactivity("He")<<"\n";
    // cout<<reactivity("Be")<<"\n";
    // cout<<reactivity("Au")<<"\n";
    // cout<<reactivity("L")<<"\n";

    return 0;
}

//============================================================================================
// Class Arrangement - AC
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
	// #endif
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);


    string s,a,e;
    vector<string> v;
    vector<int> r;
    // cin>>s;
    getline(cin,s);
    int n = (int)s.length();

    int i,ge,bo,g;
    ge=g=bo=0;
    for(i=0;i<n;i++){
        if(s[i]=='G') g++;
        if(i%2 == 0 && s[i]=='G') ge++;//0 2 4 ...
      	if(i%2 == 1 && s[i]=='B') bo++;//1 3 5 ...
    }
    char ends;
    // cout<<"--"<<s<<"--\n";
    if(n%2==0){
        cout<<(int)min(ge,g-ge);
        return 0;
    }
    // cout<<g <<" "<<ge<<"\n";
    if(g == (n+1)/2){
        ends = 'G';
        cout<< (g-ge);// g at odd
    }
    else{
        cout<< bo;
    }
    return 0;
    
}
//GGGGBBBGBBGGB : 4
// GGBBG : 1
// class_arrange.cpp
//---------------------------------------
// akshat
int main()
{
    string x;
    getline(cin,x);
    int i,j,k,n = (int)s.length(),t=0,tc=0,bc=0,ans;

    for(i=0;i<n;i++){
        if(x[i]=='B' & i%2 == 1 ) bc++;
        if(x[i]=='G') t++;
        if(x[i]=='G' & i%2 == 0) tc++;
      	
    }
    
    if(n%2==0){
        ans = min(t-tc,t);        
    }
    else{
        if(t > n/2){
            ans = t-tc;
        }
        else ans = bc;
    }
    cout<<ans;
    return 0;
    
}
//-------------------------------------------
//======================================================================================
// Graphs : AC
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
	// #endif
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int n,m,i,j,ans=0,u,v;
    cin>>n>>m;
    // map<int,int> indegree;
    vector<int> indegree(n+1,0);
    // vector<vector<int>> adj(n+1);
    for(i=0;i<m;i++){
        cin>>u>>v;
        indegree[u]++;
        indegree[v]++;  
    }
    vector<int> ind(n),weight(n);
    for(i=0;i<n;i++){
        cin>>weight[i];// input
        ind[i]=indegree[i+1];
    }
    sort(ind.begin(),ind.end());
    sort(weight.begin(),weight.end());
    for(i=n-1;i>=0;i--){
        if(ind[i]>0){
            ans+=(ind[i] * weight[i]);
        }
    }
    cout<<ans;
    return 0;
}
/*
4
2
1 2
3 4
9 3 6 7 
ans : 25

5
4
2 1
2 3 
1 4
2 4 
1 2 3 4 5
ans:31

*/ 
// =============================================================================
int main() {

   unordered_map<char,pair<int,int>>mp;
   mp['A']={10,11};
   int a=11;
   for(char c='B';c<='Z';c++){
      mp[c]={a,a+1};
      a++;
   }
   mp['a']={36,37};
   a=37;
   for(char c='b';c<='z';c++){
      mp[c]={a,a+1};
      a++;
   }
   string str;
   getline(cin,str);
   //cout<<str<<endl;
   int i=0;
   int reactivity=0;
   unordered_map<string,int>react;
   while(i<(int)str.length()){
      if(str[i]==' '){
         i++;
      }
      else if(str[i]!=' ' && (i+1<(int)str.length() && str[i+1]!=' ')){
          reactivity=mp[str[i]].first*mp[str[i+1]].second+mp[str[i+1]].first;
          string s;
          s.push_back(str[i]);
          s.push_back(str[i+1]);
          react[s]=reactivity;
         i+=2;
      }
      else if(str[i]!=' ' && (i+1<(int)str.length() && str[i+1]==' ')){
          reactivity=mp[str[i]].first; 
          string s;
          s.push_back(str[i]);
          react[s]=reactivity;
          i+=2;
      }
   }
   int ans=1;
   for(auto it:react){
      for(auto it2:react){
         if(it.first!=it2.first){
            ans=max(ans,__gcd(it.second,it2.second));
         }
      }
   }
   cout<<ans<<endl;

}