#include<bits/stdc++.h>

using namespace std;

int main() {

  unordered_map<int,vector<int>> map;
  unordered_map<int,int> visited;
  int n,m, x, y;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x;
    map[x] = {};
  }
  cin >> m;
  for (int i = 0; i < m; i++) {
    cin >> x >> y;
    map[x].push_back(y);
  }
  cin >> x >> y;
  vector<long long>res;
  queue<long long>q;
  visited[x] = 1;
  q.push(x);
  while (!q.empty()) {
    int z = q.front();
    q.pop();
    for (int i: map[z]) {
      if (visited[i] == 0) {
        if (i == y)
          res.push_back(z);
        else {
          visited[i] = 1;
          q.push(i);
        }
      }
    }
  }
  sort(res.begin(), res.end());
  if(res.size()==0){
      cout<<"-1";return 0;
  }
  for (int i: res)
    cout << i << " ";
    
  return 0;
}
/*
::i/p::
4
2
5
7
9
4
2 9
7 2
7 9
9 5
7
9

::o/p::
2 7
*/
// ========================================================================
//q2) 
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<pair<ll, ll>>adj[100005];
vector<ll>vis(100005, 0);
vector<ll>dis(100005, 0); 
int main()
{     
    ll n,maxi,id,u,v,time;
    cin >> n;
    map<ll, ll>m;
    for (ll i = 1; i <= n; i++){
        cin >> id;
        m[id] = i;
        dis[i] = 1e18;
    }
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>>q;//min pq
    
    cin >> maxi;
    for (ll i = 0; i < maxi; i++){
        cin >> u >> v >> time;
        adj[m[u]].push_back({m[v], time});        
    }
    ll src, dest;
    cin >> src >> dest;
    src = m[src];
    dest = m[dest];
 
    dis[src] = 0;
    q.push({dis[src], src});
    while (!q.empty()){
        ll curdis = q.top().first;
        ll curnode = q.top().second;
        q.pop();
        if (curdis != dis[curnode])continue;
        for (auto i : adj[curnode]){
            if (dis[i.first] > curdis + i.second){
                dis[i.first] = curdis + i.second;
                q.push({dis[i.first], i.first});
            }
        }
    }
    if (dis[dest] == 1e18) cout << -1 << '\n';    
    else cout << dis[dest] << '\n';
    return 0; 
}
/*
::i/p::
4
2
5
7
9
4
2 9 2
7 2 3
7 9 7
9 5 1
7
9

::o/p::
5
*/
// ===============================================================
// q3) 
#include<bits/stdc++.h>

using namespace std;

// vector adj[5001];
// bool visited[5001];
bool dfs(int src, int dest,vector<vector<int>>& adj,vector<int>& visited) {
  if (src == dest)
    return true;
  visited[src] = 1;
  // cout<<src<<" ";
  for (auto& x: adj[src]) {
    if (!visited[x])
      if (dfs(x, dest,adj,visited))
        return true;
  }
  return false;

}
int main() {
	// cout<<"0";
  int n,x,edges,y;
  cin >> n;
//   vector <int> v;
  map<int,int> m;
  for (int i = 0; i < n; i++) {    
    cin >> x;
    // v[i]=x;
  	m[x]=i;
  }  
  cin >> edges;
  vector<vector<int>> adj(n+10);
  vector<int> visited(n+10,0);

  for (int i = 0; i < edges; i++) {    
    cin>>x>>y;
    adj[m[x]].push_back(m[y]);//directed x->y
  }
  int src,dest;
  cin >> src >> dest;
  if (dfs(m[src], m[dest],adj,visited)){
    cout << "1";
  } 
  else {
    cout << "0";
  }
  return 0;
}
/*
::i/p::
4
2
5
7
9
4
2 9
7 2
7 9
9 5
7
9

::o/p::
1

*/
// ========================================================================