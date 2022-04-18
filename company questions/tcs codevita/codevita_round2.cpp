#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

void  tokenize(string s, string del, vector<string>& v)
{
    int start = 0;
    int end = s.find(del);
    while (end != -1) {
        // cout << s.substr(start, end - start) << endl;
        v.push_back(s.substr(start, end - start));
        start = end + del.size();
        end = s.find(del, start);
    }
    v.push_back(s.substr(start, end - start));
    // cout << s.substr(start, end - start);
}
int findOrder(int N, vector<vector<int>> graph){
    // note: here the nodes are in between [0...N-1] ,
    // otherwise for char/any general nodes we will have to usee different data structures 
    // like: graph :: unordered_map<char,unordered_set<char>> graph;
    // indegree :: inordred_map<char,int> indegree;
    int level=0;
    vector<int> indegree(N,0);
    vector<int> order;// store the topo ordering of nodes
    queue<int> q;// to store nodes who have reached indegree=0 in fifo manner

    for(int i=0;i<N;i++){
        for(const auto& nbr:graph[i]){
            indegree[nbr]++;// initial value of indegree for all nodes is assigned as  0
        }
    }

    //push all nodes with initial indegree = 0, in the queue 
    for(int i=0;i<N;i++){
        if(indegree[i]==0)
            q.push(i);
    }

    //bfs traversal + topo sort logic
    while(!q.empty()){
        int x = q.size();
        while(x--){
            int node = q.front();
            order.push_back(node);
            q.pop();

            for(auto& nbr:graph[node]){
                indegree[nbr]--;
                if(indegree[nbr]==0) q.push(nbr);
            }
        }level++;        
    }
    return order.size()==N ? level:-1;
}
int findOrder(int N, map<string,vector<string>> graph){
    // note: here the nodes are in between [0...N-1] ,
    // otherwise for char/any general nodes we will have to usee different data structures 
    // like: graph :: unordered_map<char,unordered_set<char>> graph;
    // indegree :: inordred_map<char,int> indegree;
    int level=0;
    map<string,int> indegree;
    for(auto x:graph) indegree[x.first]=x.second.size();
    // vector<int> indegree(N,0);
    vector<string> order;// store the topo ordering of nodes
    queue<string> q;// to store nodes who have reached indegree=0 in fifo manner

    for(auto& j:graph){
        for(const auto& nbr:graph[i]){
            indegree[nbr]++;// initial value of indegree for all nodes is assigned as  0
        }
    }

    //push all nodes with initial indegree = 0, in the queue 
    for(int i=0;i<N;i++){
        if(indegree[i]==0)
            q.push(i);
    }

    //bfs traversal + topo sort logic
    while(!q.empty()){
        int x = q.size();
        while(x--){
            int node = q.front();
            order.push_back(node);
            q.pop();

            for(auto& nbr:graph[node]){
                indegree[nbr]--;
                if(indegree[nbr]==0) q.push(nbr);
            }
        }level++;        
    }
    return order.size()==N ? level:-1;
}


int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s,a,b;
    int i,j,n;
    // cin>>s;
    getline(cin,s);
    // s="1.{},2.{1,4},3.{2},4.{3}";
    //remove spaces and resize
    remove(s.begin(),s.end(),' ');
    int l = s.length(); // storing the length of the string
    int c = count(s.begin(), s.end(),' '); // counting the number of whitespaces
    remove(s.begin(), s.end(), ' ');
    s.resize(l-c);
    // 1.{},2.{1,4},3.{2},4.{3}    
    vector<string> v;
    tokenize(s,",",v);
    for(auto& x:v) cout<<x<<" ";
    //v contains "," sepearted strings
    // n=v.size();//node count

    // vector<vector<int>> pre(n,vector<int>());// 0 based 
    // int x,nbr;//full the graph
    

    // pre[0]={};
    // pre[1]={0,3};
    // pre[2]={1};
    // pre[3]={2};

    // int ans = findOrder(n,pre);
    // if(ans==-1) cout<<"error";
    // else cout<<ans;
    // return 0;

    // getline(cin,s);
    return 0;
}
// ==================================================================================================
// pblm g:
// #include <iostream>
// #include <algorithm>
// #include <bits/stdc++.h>
// using namespace std;
// int knapsack( vector<int> wt, vector<int> val, int n,int capacity)
// {
//     int i, w;
//     vector<vector<int>> dp(n + 1, vector<int>(capacity + 1,0));
    
//     for(i = 1; i <= n; i++){
//         for(w = 1; w <= capacity; w++){
//             if (wt[i - 1] <= w)
//                 dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
//             else
//                 dp[i][w] = dp[i - 1][w];
//         }
//     }
//     return dp[n][capacity];
// }
// int main(){
// //     #ifndef ONLINE_JUDGE
// //     freopen("input.txt", "r", stdin);
// //     freopen("output.txt", "w", stdout);
// // 	#endif
// //     ios_base::sync_with_stdio(false);
// //     cin.tie(NULL);
//     int n,m,i,j,x,y,t,k,z,pos=0;

//     cin>>n>>m>>x>>y>>t;
//     vector<int> w(n*m),val(m*n);
//     for(i=0;i<n;i++){
//         for(j=0;j<m;j++){
//             cin>>k;
//             z=abs(x-i)+abs(y-j);
//             w[pos]=2*z+1;
//             val[pos]=k;
//             pos++;
//         }
//     }
//     cout<<knapsack(w,val,n*m,t);
// }

/*
i/p:
3 4
1 3 
10
1 1 9 1
1 5 1 0 
1 1 1 1

o/p:
14

*/
// ==================================================================================================