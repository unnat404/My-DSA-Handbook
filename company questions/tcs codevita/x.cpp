
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;



int reactivity(string s,unordered_map<char,pair<int,int>>& m){ 
  
    int x=0,y=0;
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
    // base = y+1;
    // x = s[1] + s[0]*base;
    x = y + (base * x);
  
    return x;
}

int main()
{
    //#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
	//#endif
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);



    string s="",a,e="";
    vector<string> v;
    vector<int> r;
    // cin>>s;
    getline(cin,s);

    for(auto c:s){

        if(c==' '){
            if(e!='') v.push_back(e);
            e="";
        }
        else e+=c;
    }
    if(e!="") v.push_back(e);
    
    for(int i=0;i<(int)s.length(),i++){
        char c = s[i];
        if(c==' '){
            if(e!='') v.push_back(e);
            e="";
        }
        else if(i+1)
    }
    

    unordered_map<char,pair<int,int>> m;
    int a=10;
    for(char c='A',c<='Z';c++){
        m[c]={a,++a};
    }
    a=36;
    for(char c='a',c<='z';c++){
        m[c]={a,++a};
    }

    for(auto x:v){
        int ss= reactivity(x);
        r.push_back(ss);
    }
    int n = (int)(v.size());
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


// #include <iostream>
// #include <algorithm>
// #include <bits/stdc++.h>
// using namespace std;
// int reactivity(string s){    
//     int x=0,y=0;
//     if(s[0]>='A' && s[0]<='Z'){
//         x = 10 + (s[0]-'A');
//     }
//     else{
//         x = 36 + (s[0]-'a');
//     }

//     if((int)s.length()==1) return x;

//     if(s[1]>='a' && s[1]<='z'){
//         y = 36 + (s[1]-'a');
//     }else y = 10+ (s[1]-'A');

//     int base = max(x+1,y+1);
//     // x = s[1] + s[0]*base;
//     x = y + (base * x);
//     return x;
// }

// int main()
// {
//     #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// 	#endif
//     // ios_base::sync_with_stdio(false);
//     // cin.tie(NULL);


//     string s,a,e;
//     vector<string> v;
//     vector<int> r;
//     // cin>>s;
//     getline(cin,s);

//     for(auto& c:s){
//         if(c==' '){
//             v.push_back(e);
//             e="";
//         }
//         else e+=c;
//     }
//     if(e!="") v.push_back(e);

//     for(auto& x:v){
//         int ss= reactivity(x);
//         r.push_back(ss);
//     }
//     int n = (int)v.size();
//     int ans=0;

//     // for(auto& i: v){
//     //     cout<<i<<" ";
//     // }cout<<"\n";

//     // for(auto& i: r){
//     //     cout<<i<<" ";
//     // }cout<<"\n";

//     for(int i=0;i<n;i++){
//         for(int j=i+1;j<n;j++){
//             ans = max(ans,__gcd(r[i],r[j]));
//         }
//     }
//     cout<<ans;

//     return 0;
// }

// //H O C N Au Ag Cl : 12
// //  Tc S Be Li Er In Dy As I Ac : 7


// // int main()
// // {
// //     int u,v,a,b,n,m,i,j,ans=0;
// //     cin>>n>>m;    
// //     vector<int> count(n,0);
// //     // vector<vector<int>> adj(n+1);
// //     for(i=0;i<m;i++){
// //         cin>>a>>b;
// //         count[a-1]++;
// //         count[b-1]++;  
// //     }
// //     vector<int> ind(n),cap(n);
// //     for(i=0;i<n;i++){
// //         cin>>cap[i];
// //     } 
// //     sort(cap.begin(),cap.end());
// //     for(i=0;i<n;i++){
// //         ind[i]=count[i];
// //     }
// //     sort(ind.begin(),ind.end());
   
// //     for(i=n-1;i>=0;i--){
// //         if(ind[i]>=0){
// //             ans= ans + ind[i] * cap[i];
// //         }
// //     }
// //     cout<<ans;
// //     return 0;
// // }