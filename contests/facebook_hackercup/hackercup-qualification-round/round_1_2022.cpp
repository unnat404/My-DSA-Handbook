// ============================================================================================================================
// B1 & B2

// #include <iostream>
// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long 
// #define ull unsigned long long int

// int main()
// {
//     #ifndef ONLINE_JUDGE
//     freopen("watering_well_chapter_1_input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// 	#endif

//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
    
//     ll i,t,cas,j;
// 	ull x,y,a,b,sum,n,q,mod,tem;
// 	mod=1e9+7;
	
//     bool found;
//     string s,res="",ans,inp,all_trees;
// 	bool possible;

//     cas=0;
// 	cin>>t;
// 	while(t>0){
// 	    t--;cas++;
// 	    cin>>n;
// 		unordered_map<ull,ull> mx,my;
// 		vector<pair<ull,ull>> vn,vq; 
// 		// vector<ull> nx(2,0),ny(2,0),qx(2,0),qy(2,0);// x,x^2
// 		x=y=a=b=sum=0;
// 		for(i=0;i<n;i++){
// 			cin>>x>>y;
// 			vn.push_back({x,y});
// 		}	

// 		cin>>q;
// 		// if(cas==8) cout<<q<<" \n\n";
// 		for(i=0;i<q;i++){
// 			cin>>x>>y;
// 			vq.push_back({x,y});
// 		}

// 		sum=0;
// 		for(i=0;i<n;i++){
// 			if(mx.find(vn[i].first) == mx.end()){
// 				tem = vn[i].first ;
// 				for(j=0;j<q;j++) mx[tem] = (mx[tem] + ((tem-vq[j].first)*(tem-vq[j].first))%mod) % mod ;
// 			}
// 			if(my.find(vn[i].second) == my.end()){
// 				tem = vn[i].second ;
// 				for(j=0;j<q;j++) my[tem] = (my[tem] + ((tem-vq[j].second)*(tem-vq[j].second))%mod) % mod ;
// 			}
// 			sum = (sum + (mx[vn[i].first] + my[vn[i].second])%mod)%mod;
// 		}
	   
// 	    res+="Case #"+to_string(cas)+": "+to_string(sum)+"\n";
// 	}
// 	cout<<res;
//     return 0;
// }
/*
Case #1: 52
Case #2: 131
Case #3: 110090622
Case #4: 120
Case #5: 1712
Case #6: 198450
Case #7: 633155595
Case #8: 777092013
Case #9: 418307892
*/

//=======================================================================================================
// most optimized : 
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define ull unsigned long long int

int main()
{
    // #ifndef ONLINE_JUDGE
    // freopen("watering_well_chapter_1_input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
	// #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll i,t,cas;
	ull x,y,a,b,sum,n,q,mod;
	mod=1e9+7;
	
    bool found;
    string s,res="",tem,ans,inp,all_trees;
	bool possible;

    cas=0;
	cin>>t;
	while(t>0){
	    t--;cas++;
	    cin>>n;
		vector<ull> nx(2,0),ny(2,0),qx(2,0),qy(2,0);// x,x^2
		x=y=a=b=sum=0;
		for(i=0;i<n;i++){
			cin>>x>>y;
			nx[0] = (nx[0]+x)%mod;
			nx[1] = (nx[1] + (x*x)%mod) % mod;
			ny[0] = (ny[0]+y)%mod;
			ny[1] = (ny[1] + (y*y)%mod) % mod; 
		}	

		cin>>q;
		// if(cas==8) cout<<q<<" \n\n";
		for(i=0;i<q;i++){
			cin>>x>>y;
			qx[0] = (qx[0]+x)%mod;
			qx[1] = (qx[1] + (x*x)%mod) % mod;
			qy[0] = (qy[0]+y)%mod;
			qy[1] = (qy[1] + (y*y)%mod) % mod; 
		}

		sum = (((nx[1]*q)%mod) + ((ny[1]*q)%mod) + ((qx[1]*n)%mod) + ((qy[1]*n)%mod) - ((2*((nx[0]*qx[0])%mod))%mod) - ((2*((ny[0]*qy[0])%mod))%mod)) % mod; 	
	   
	    res+="Case #"+to_string(cas)+": "+to_string(sum)+"\n";
	}
// 	ans.erase(ans.length()-1);//removing new line charector from end
	cout<<res;
    return 0;
}


// /*
// -----------------------------
// soln/approach: #1 : works only for 0<= Ai,Bi,Xi,Yi <=3000 
// -----------------------------
// map<ll,ll> mx,my;
// :: for mx ::
// for xi -> find sum of squares for all q_xj's
// 	=> sum (xi - q_xj)^2 :: j -> [0,Q-1]
// :: for my ::
// do simliar as mx but for y-coordinates

// -> map works here since there will be overlaps hence preventing calculation for Q queries for every x/y i

// -----------------------------
// soln/approach: #2 : works for 0<= Ai,Bi,Xi,Yi <=1e9 , as well,  
// -----------------------------
// Observations: 
// - x independent of y
// - math magic combo: (a-b)^2 = a^2 + b^2 - 2ab


// ------------------------------
// meta hackercup - round 1 - unnat agarwal - hire me @meta
// ------------------------------
// */

/*
=================================================================================

// #include <iostream>
// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long 
// #define ull unsigned long long int

// int main()
// {
//     #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// 	#endif

//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
    
//     ll i,t,cas;
// 	ull x,y,a,b,sum,n,q,mod=1e9+7;
// 	ll anss;
// 	mod=1e9+7;
	
//     bool found;
//     string s,res="",tem,ans,inp,all_trees;
// 	bool possible;

//     cas=0;
// 	cin>>t;
// 	while(t>0){
// 	    t--;cas++;
// 	    cin>>n;
// 		vector<ull> nx(2,0),ny(2,0),qx(2,0),qy(2,0);// x,x^2
// 		vector<vector<ull>> vn(n); 
// 		x=y=a=b=sum=0;
// 		anss=0;
// 		for(i=0;i<n;i++){
// 			cin>>x>>y;
// 			vn[i]={x,y};
// // 			nx[0] = (nx[0]+x)%mod;
// // 			nx[1] = (nx[1] + (x*x)%mod) % mod;
// // 			ny[0] = (ny[0]+y)%mod;
// // 			ny[1] = (ny[1] + (y*y)%mod) % mod; 
// 		}	

// 		cin>>q;
// 		vector<vector<ull>> qn(q);
// 		for(i=0;i<q;i++){
// 			cin>>x>>y;
// 			qn[i]={x,y};
// // 			qx[0] = (qx[0]+x)%mod;
// // 			qx[1] = (qx[1] + (x*x)%mod) % mod;
// // 			qy[0] = (qy[0]+y)%mod;
// // 			qy[1] = (qy[1] + (y*y)%mod) % mod; 
// 		}
		
// 		for(i=0;i<n;i++){
// 		    for(ll j=0;j<q;j++) {
// 		        anss = (anss + ((vn[i][0]-qn[j][0])*(vn[i][0]-qn[j][0]))%mod + ((vn[i][1]-qn[j][1])*(vn[i][1]-qn[j][1]))% mod)%mod ;
// 		    }
// 		}

// // 		sum = (((nx[1]*q)%mod) + ((ny[1]*q)%mod) + ((qx[1]*n)%mod) + ((qy[1]*n)%mod) - ((2*((nx[0]*qx[0])%mod))%mod) - ((2*((ny[0]*qy[0])%mod))%mod)) % mod; 	
	   
// 	    res+="Case #"+to_string(cas)+": "+to_string(anss)+"\n";
// 	}
// // 	ans.erase(ans.length()-1);//removing new line charector from end
// 	cout<<res;
//     return 0;
// }
// ====================================================================================================
*/
// ======================================================================================================================================