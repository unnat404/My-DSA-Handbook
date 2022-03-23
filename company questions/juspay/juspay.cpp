// 
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

// ==============================================================================================
// Find vertexes that need to be removed so that B cannot reach A in directed graph
// min-cut
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


// ==============================================================================================
/*
Juspay Round 3 Questions and Answers
4
Anonymous User
July 4, 2021 9:35 AM

3.5K VIEWS

Problem Statement
React Developer Community is a community of React developers. It allows developers to reach out to others and discuss various topics around JS programming. This community has been modelled as a directed social network graph.

Find Reachability

JS newbie A wants to check if he can reach out to a React expert B using his network.

Input Format
total members in React Developer Community

memberId1

MemberId2 ……………. MemberIdN

Total possible edges

………………

Follower

Following

Output Format
“0” OR “1”

*The problem has been curated and verified by Team Juspay.

Sample Testcase #0
Testcase Input
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
Testcase Output
1

#include
#include
#include
#include
#include
#include
#include<bits/stdc++.h>
using namespace std;

vectoradj[5001];
bool visited[5001];
bool dfs(int start, int end)
{
if(start==end)
return true;
visited[start]=1;
for(auto x: adj[start])
{
if(!visited[x])
if(dfs(x,end))
return true;
}
return false;

}
int main(){


int n; 
cin>>n; 
vector<int>members; 
for(int i=0;i<n;i++) 
{ 
    int x; 
    cin>>x; 
    members.push_back(x); 
} 
int end; 
cin>>end; 
for(int i=0;i<end;i++) 
{ 
 
    int x,y; cin>>x>>y; 
    adj[x].push_back(y); 
} 
int n1,n2; 
cin>>n1>>n2; 
if(dfs(n1,n2)) 
{ 
    cout<<"1"; 
} 
else
{
    cout<<"0"; 
}
return 0;
}

Problem Statement
React Developer Community is a community of React developers. It allows developers to reach out to others and discuss various topics around JS programming. This community has been modeled as a directed social network graph.

Learn JS

JS newbie A wants to learn React from B and wants to know in his network who can introduce him to B in the shortest time period.

Input Format
total members in UIFriendNetwork

memberId1

MemberId2 ……………. MemberIdN

Total possible edges


………………


Follower(Ninja A)

Following(JS expert B)

Output Format
Shortest Time A takes to reach B

*The problem has been curated and verified by Team Juspay.

Sample Testcase #0
Testcase Input
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
Testcase Output
5

#include
#include
#include
#include
#include
#include
#include<bits/stdc++.h>
using namespace std;

vector<pair<long long int,long long int>> a[100000];
vector visited(100000,0);
long long int mn=999999999999999,res=0,k=mn;
void dfs(long long int u,long long int v)
{
if(u==v)
{
if(mn>res)
{
mn=res;
}
}
visited[u]=1;
for(auto j: a[u])
{
if(visited[j.first]==0)
{
res+=j.second;
visited[j.first]==1;
dfs(j.first,v);
visited[j.first]==0;
res-=j.second;
}
}
visited[u]=0;
}
int main()
{

long long int n,e,x,y,i,w;
cin>>n;
for(i=0;i<n;i++)
{
cin>>x;
}
cin>>e;
for(i=0;i<e;i++)
{
cin>>x>>y>>w;
a[x].push_back({y,w});
}
cin>>x>>y;
dfs(x,y);
if(mn==k)
cout<<"-1";
else
cout<<mn;
return 0;
}

Problem Statement
React Developer Community is a community of React developers. It allows developers to reach out to others and discuss various topics around JS programming. This community has been modeled as a directed social network graph.

The Nagging React newbie

A Nagging React newbieB is constantly troubling React expert A. React Expert A needs to know the minimum set of people following him he needs to remove from his network to stop B from reaching out to him.

Input Format
total members in UIFriendNetwork

memberId1

MemberId2 ……………. MemberIdN

Total possible edges

………………

Follower

Following

Output Format
Set of memberId “A” needs to block

*The problem has been curated and verified by Team Juspay.

Sample Testcase #0
Testcase Input
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
Testcase Output
2 7

#include

#include

#include

#include

#include

#include

#include<bits/stdc++.h>

using namespace std;

int main() {

  unordered_map < int, vector > map;
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
  vectorres;
  queueq;
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
  for (int i: res)
    cout << i << " ";
  return 0;
}


*/
// ===========================================================================================================
/*

Largest sum cycle
8
avinash0786's avatar
avinash0786
12
May 2, 2021 1:17 AM

3.1K VIEWS

HERE IS THE QUESTION, WHAT IS THE LOGIC AND CODE TO SOLVE THIS QUESTION ??
You are given a maze with N cells. Each cell may have multiple entry points but not more than one exit (ie. entry/exit points are unidirectional doors like valves).

The cells are named with an integer value from 0 to N-1.

You need to find the the length of the largest cycle in the maze. Return -1 if there are no cycles.

INPUT FORMAT

First line has the number of cells N
Second line has list of N values of the edge[] array. edge[i] contains the cell number that can be reached from of cell ‘i’ in one step. edge[i] is -1 if the ‘i’th cell doesn’t have an exit.
OUTPUT FORMAT

length of the largest cycle.
Sample input:

23

4 4 1 4 13 8 8 8 0 8 14 9 15 11 -1 10 15 22 22 22 22 22 21

Sample output

6
=======================================================================
JUSPAY | INDIA | OA
0
Anonymous User
Anonymous User
Last Edit: June 8, 2021 7:55 AM

1.1K VIEWS

please help me to find solution
https://www.codingninjas.com/codestudio/problems/largest-cycle_1381333?leftPanelTab=0
=======================================================================
*/