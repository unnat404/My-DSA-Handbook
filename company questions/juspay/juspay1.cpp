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
// min-cut :: soln c:: https://usaco.guide/problems/cses-1695-police-chase/solution
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
#define f first
#define s second
#define pb push_back
#define all(x) begin(x), end(x)

#define F0R(i,a) for(int i=0; i<(a); i++)
#define FOR(i,a,b) for(int i=(a); i<=(b); i++)
#define R0F(i,a) for(int i=(a)-1; i>=0; i--)
#define ROF(i,a,b) for(int i=(b); i>=a; i--)
#define trav(a,x) for (auto& a: x)

int n, m;
ll adj[501][501], oadj[501][501];

ll flow[501];
bool V[501];
int pa[501];
using pii = pair<int, int>;
vector<pii> ans;

bool reachable() {
	memset(V, false, sizeof(V));
	queue<int> Q; Q.push(1); V[1]=1;
	while(!Q.empty()) {
		int i=Q.front(); Q.pop();
		FOR(j,1,n) if (adj[i][j] && !V[j])
			V[j]=1, pa[j]=i, Q.push(j);
	}
	return V[n];
}

int main() {
	cin >> n >> m;
	FOR(i,1,n) FOR(j,1,n) adj[i][j]=oadj[i][j]=0;
	F0R(i,m) {
		ll a,b; cin >> a >> b;
		adj[a][b]++, adj[b][a]++;
		oadj[a][b]++, oadj[b][a]++;
	}
	int v, u;
	while(reachable()) {
		ll flow = 1e18;
		for (v=n; v!=1; v=pa[v]) {
			u = pa[v];
			flow = min(flow, adj[u][v]);
		}
		for (v=n; v!=1; v=pa[v]) {
			u = pa[v];
			adj[u][v] -= flow;
			adj[v][u] += flow;
		}
	}
	reachable();
	FOR(i,1,n) FOR(j,1,n)
	if (V[i] && !V[j] && oadj[i][j]) ans.pb({i,j});
	cout << ans.size() << '\n';
	trav(a, ans) cout << a.f << " " << a.s << '\n';
}

// =======================================================