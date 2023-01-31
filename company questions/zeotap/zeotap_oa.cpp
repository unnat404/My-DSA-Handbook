/*
Kanisht : 22/11/22
Nandini : 24/11/22 
Akshat  : 24/11/22
Shadab  : not given
Shivam  :
Unnat   :  


--------
Notes
--------
Platform : Hackerrank (qn bank)
Few Qns were common/repeat

Format:
- 4 coding
- 3 sql
- 12 mcqs
*/
// ==============================================================
/*
Qn) Secondary cities
Given a tree, numbered {0,1,2,...,n} (edges given) 
Find the sum of all nodes which are not end nodes of diameter(end nodes of largest paths)
*/
// Kanisht's solution(partial) : https://p.ip.fi/f51b
#include<bits.h/stdc++.h>
using namespace std;

ll tsum=0;
int n;
map<int,set<int>>adj;
vector<int>dis(100001);
vector<int>parent(100001);
 
void dfs1(int src,int par){
    
    for(auto i:adj[src]){
        if(i!=par){
            parent[i]=src;
            dis[i]=dis[src]+1;
            dfs1(i,src);
        }
    }
}
vector<int>lf;
void dfs2(int src,int par,int mx){
    
    for(auto i:adj[src]){
        if(i!=par){
            parent[i]=src;
            dfs2(i,src,mx);
        }
    } 
    if(adj[src].size()==1 && par!=0 && dis[src]==mx){
        lf.push_back(src);
    }
}
 
long getSecondaryCitySum(int g_nodes,vector<int>g_from ,vector<int>g_to){
    
    tsum=(g_nodes*(g_nodes+1))/2;
    // cout<<tsum<<'\n';
    n=g_nodes;
    for(int i=1;i<=g_nodes;i++){
        adj[i].clear();
        dis[i]=0;
    }
    int g_edges=g_nodes-1;
    for(int i=0;i<g_edges;i++){
        adj[g_to[i]].insert(g_from[i]);
        adj[g_from[i]].insert(g_to[i]);
    }
    dfs1(1,0);
    int mx=0;
    int ds=1;
    for(int i=1;i<=g_nodes;i++){
        if(mx<dis[i]){
            mx=dis[i];
            ds=i;
        }
        dis[i]=0;
    }
    dfs1(ds,0);
    mx=0;
    
    int de=ds;
     for(int i=1;i<=g_nodes;i++){
        if(mx<dis[i]){
            mx=dis[i];
            de=i;
        }
        dis[i]=0;
    }
    int ct=mx/2;
        int tmp=de;
        while(ct--){
            tmp=parent[tmp];
    }
    
    if(mx&1){
        
        // two centers
        
        int fct=tmp;
        int sct=parent[tmp];
        adj[fct].erase(sct);
        adj[sct].erase(fct);
        
        dfs1(fct,0);
        mx=0;
        for(int i=1;i<=g_nodes;i++){
            if(mx<dis[i]){
                mx=dis[i];
            }
        }   
        dfs2(fct,0,mx);
        for(int i=1;i<=g_nodes;i++){
            dis[i]=0;
        }
        tsum-=fct;
        for(auto i:lf){
            
            int j=i;
            while(j!=fct){
                tsum-=j;
                j=parent[j];
            }
            
        }
        tsum-=sct;
        lf.clear();
        dfs1(sct,0);
        mx=0;
        for(int i=1;i<=g_nodes;i++){
            if(mx<dis[i]){
                mx=dis[i];
            }
        }   
        dfs2(sct,0,mx);
        for(int i=1;i<=g_nodes;i++){
            dis[i]=0;
        }
        for(auto i:lf){
            int j=i;
            while(j!=sct){
                tsum-=j;
                j=parent[j];
            }
        }
        lf.clear();
    }
    else{
        int fct=tmp;
        tsum-=fct;
        dfs1(fct,0);
        mx=0;
        for(int i=1;i<=g_nodes;i++){
            if(mx<dis[i]){
                mx=dis[i];
            }
        }   
        dfs2(fct,0,mx);
        for(int i=1;i<=g_nodes;i++){
            dis[i]=0;
        }
        for(auto i:lf)
        {
            int j=i;
            while(j!=fct){
                tsum-=j;
                j=parent[j];
            }
        }
        lf.clear();
    }
   
    return tsum;
}
 
 
// =============================================================
/*
SQL
-----

1) Maximum Average Departmental salary
- https://stackoverflow.com/questions/50996372/maximum-average-departmental-salary

Solution:

SELECT t1.name, t1.avgSal
FROM (SELECT d.name, avg(e.sal) AS avgSal
      FROM employee AS e
      JOIN dept AS d ON d.id = e.dept_id
      GROUP BY d.name) AS t1
JOIN (SELECT d.name, avg(e.sal) AS avgSal
      FROM employee AS e
      JOIN dept AS d ON d.id = e.dept_id
      GROUP BY d.name
      ORDER BY avgSal DESC
      LIMIT 1) AS t2
ON t1.avgSal = t2.avgSal

----------------------------------------------------------------
2) Maximum Cumulitive HAckos

- https://stackoverflow.com/questions/61169045/sql-query-maximum-cummulative
- https://medium.com/@ritinema23/atlassian-interview-experience-bee07be0bddf

*/