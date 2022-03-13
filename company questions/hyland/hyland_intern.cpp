
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// Unnat,Hrishabh - q2
// Reducing Array (normal pq question)
int solve(vector<int> v){
    int i,j,n;
    priority_queue<int,vector<int>,greater<int>> q;
    for(auto x:v){
        q.push(x);
    }
    int c,count=0;
    while(q.size()>1){
        c = q.top();
        q.pop();
        c = c+q.top();
        q.pop();
        q.push(c);
        count+=c;
    }
    return count;
}

// Hrishabh - q3
// Swapping charectors :: minimum lexixographical string fing
// operation = swap any 2 charectors (any number of times ) 
string swap(string s){
    string a,b;
    int i,n=s.length();
    map<char,vector<int>> m;
    priority_queue<char,vector<char>,greater<char>> pq;
    set<char> ss;
    vector<int> v(30,0);
    for(i=0;i<n;i++){
        m[s[i]].push_back(i);
        ss.insert(s[i]);
    }
    for(auto& x:ss){
        pq.push(x);
    }
    for(i=0;i<n;i++){
        if(s[i] > pq.top()){
            vector<int> temp = m[pq.top()];
            m[pq.top()] = m[s[i]];
            m[s[i]]=temp;
            pq.pop();
            
        }
        if(s[i]==pq.top()){
            while(i<n && s[i]<=pq.top()) i++;
            pq.pop();
        }
    }
    
    for(auto& ch:m){
        for(auto& i:ch.second){
            s[i] = ch.first;
        }
    }
    return s;
    // input :: string q = "bbcacad"; 
    // output :: aabcbcd    
    
}

int main()
{
    vector<int> v = {10,30,20};
    // cout<<"Hello World";
    // cout<<solve(v);
    string q = "bbcacad"; //
    cout<<swap(q);

    return 0;
}
