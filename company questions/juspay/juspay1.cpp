// ================================================================================================================
// minimum cut:: (qn :: 2)
#include<bits/stdc++.h>

using namespace std;

int main() {

  unordered_map < int, vector<int> > map;
  unordered_map < int, int > visited;
  int N, M, x, y;
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> x;
    map[x] = {};
  }
  cin >> M;
  for (int i = 0; i < M; i++) {
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
// ================================================================================================================
// djikstra (minimum distance) (qn 2)
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#define ll long long int
#define pll pair<ll,ll>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
using namespace std;
vector<pair<ll, ll>>adj[100005];
vector<ll>vis(100005, 0);
vector<ll>dis(100005, 0); 
int main()
{ 
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
    ll n;
    cin >> n;
    map<ll, ll>m;
    ll id;
    for (ll i = 1; i <= n; i++)
    {
        cin >> id;
        m[id] = i;
        dis[i] = 1e18;
    }
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>>q;
    ll mx;
    cin >> mx;
    ll id1, id2, time;
    for (ll i = 0; i < mx; i++)
    {
        cin >> id1 >> id2 >> time;
        adj[m[id1]].pb({m[id2], time});
        // adj[m[id2]].pb({m[id1],time});  // for undirected graph comment this line
 
    }
    ll src, end;
    cin >> src >> end;
    src = m[src];
    end = m[end];
 
    dis[src] = 0;
    q.push({dis[src], src});
    while (!q.empty())
    {
        ll curdis = q.top().ff;
        ll curnode = q.top().ss;
        q.pop();
        if (curdis != dis[curnode])continue;
        for (auto i : adj[curnode])
        {
            if (dis[i.ff] > curdis + i.ss)
            {
                dis[i.ff] = curdis + i.ss;
                q.push({dis[i.ff], i.ff});
            }
        }
    }
    if (dis[end] == 1e18)
    {
        cout << -1 << '\n';
    }
    else
    {
        cout << dis[end] << '\n';
    } 
    return 0; 
}
// =================================================================================
//connected component reachability 
#include<bits/stdc++.h>

using namespace std;

vectoradj[5001];
bool visited[5001];
bool dfs(int start, int end) {
  if (start == end)
    return true;
  visited[start] = 1;
  for (auto x: adj[start]) {
    if (!visited[x])
      if (dfs(x, end))
        return true;
  }
  return false;

}
int main() {

  int n;
  cin >> n;
  vector < int > members;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    members.push_back(x);
  }
  int end;
  cin >> end;
  for (int i = 0; i < end; i++) {

    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
  }
  int n1, n2;
  cin >> n1 >> n2;
  if (dfs(n1, n2)) {
    cout << "1";
  } else {
    cout << "0";
  }
  return 0;
}
// ================================================