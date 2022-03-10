// ====================================================================
/*
Q) Mock 1.3
You are given an integer N. Find the number of the positive divisors of F(N),
where F(N) = N * (N-1) * (N-2) ……* 1, here “*” denotes multiplication.
You need to find the answer modulo 10^9 + 7.
*/
// ** Nice Question **
#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int pd[1100],num[1100];
int n;
const int mo=1e9+7;
int main(){
    scanf("%d",&n);
    for (int i=2;i<=n;i++)
   	 for (int j=i+i;j<=n;j+=i) pd[j]=1;
    int ans=1;
    for (int i=2;i<=n;i++)
   	 if (pd[i]==0){// i is prime
   		 int tot=0;
   		 for (int j=i;j<=n;j*=i) tot+=n/j;// finding total power of prime no. i for numbers in range [1...n]
   		 ans=1ll*ans*(tot+1)%mo;// multiplying (power + 1) of all primes to get total no of factors
        // eg : no of factors of :  2^x * 3^y * 5^z is (x+1)(y+1)(z+1)
   	 }
    cout<<ans<<endl;
}
// ====================================================================
/*
Q) Mock 2.1
You are given two integers N and K. 
Find the number of triples (a,b,c) of positive integers not greater than N such that a+b,b+c and c+a are all multiples of K.
 The order of a,b,c does matter, and some of them can be the same.
*/
// C++ program for the above approach

#include "bits/stdc++.h"
using namespace std;

// Function to count the number of
// triplets from the range [1, N - 1]
// having sum of all pairs divisible by K
int countTriplets(int N, int K)
{
	// If K is even
	if (K % 2 == 0) {
		long long int x = N / K;
		long long int y = (N + (K / 2)) / K;

		return x * x * x + y * y * y;
	}

	// Otherwise
	else {
		long long int x = N / K;
		return x * x * x;
	}
}

// Driver Code
int main()
{
	int N,K;
    cin>>N>>K;
	cout << countTriplets(N, K);

	return 0;
}

// ====================================================================
/*
Q) Mock 2.2
Polly likes to play with numbers.
She defines a number as cool if the sum of its digits divides n.
Find if the number is called cool.
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
unsigned long long getSumD ( unsigned long long x ) {
	return x == 0 ? 0 : x%10 + getSumD( x/10 );
}
int main () {

	long long n;
	cin >> n;
	if ( n%getSumD(n) ) {
    	cout << "No\n";
	}else {
    	cout << "Yes\n";
	}
}
// ====================================================================
/*
Q) Mock 2.3
There are N special Diyas in front of Ram house. The height of the i-th diya (1≤i≤N) is hi unit.
He decides to choose K diyas from these diyas and decorate them with electric lights. To make the scenery more beautiful, the heights of the decorated diyas should be as close to each other as possible.
More specifically, let the height of the tallest decorated diya be hmax units, and the height of the shortest decorated diya be hmin units.
Ram feels the smaller the value hmax−hmin is, the better. Find the minimum possible value of hmax−hmin.
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main() {
	int n, K;
	cin >> n >> K;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a.begin(), a.end());
	int ans = 2e9;
	for (int i = 0; i + K - 1 < n; i++) {
    	ans = min(ans, a[i + K - 1] - a[i]);
	}
	cout << ans << endl;
}
// ====================================================================
/*
Q) Mock 1.2
You are given a string S.
You have to find a string that starts with ‘a’ and ends with ‘z’, by taking out a substring of a string S.
Find the greatest length of the string you can construct.
If no substring exists output -1.
*/
#include<bits/stdc++.h>

using namespace std;
int main()
{
  int mini=1e9;
  int maxi=-1;
  string s;
  cin>>s;
  for(int i=0;i<s.length();i++)
  {
	if(s[i]=='a')
  	mini=min(mini,i);
	if(s[i]=='z')
  	maxi=max(maxi,i);
  }
 if(maxi == -1){
   cout << -1 << '\n';
   return 0;
 }
 cout<<maxi-mini+1<<endl;
}
// ====================================================================
/*
Q) Mock 1.1
There are a total of P persons standing in a zigzag line. 
You have an infinite supply of F food items. You can distribute food in any order.
The only condition here is any two adjacent persons must have different types of food out of the K items.
Find out the total number of ways to distribute the food among the people.
*/
#include <iostream>
#include<string>
#include<algorithm>
#include<queue>
#include<cmath>
#include<set>
#include<map>
typedef long long int ll;
using namespace std;

int main(){
  ll N, K;
  ll ans=1;
  cin >> N >> K;
  ans=K;
  for(int n=1;n<N;n++){
  	ans*=(K-1);
  }
  cout << ans << endl;
  return 0;
}
// ====================================================================
/*
Q) Mock 3.1
You are given an array A  which consists of N positive integers.Now you want to put all this elements in another container.So you start with first element of the array A i.e, at index 1  and move towards index N , and for each index  you perform the following operation:
Put the element at the top of the container.
rotate the container by 180 degrees.
After you put all the elements in the container,your task is to print the elements of this container from bottom to top.

Constraints:
1<=N<=2*1e5
0 <=x[i]<= 1e9
------------
i/p: 
3
1 2 3
o/p: 3 1 2
------------
i/p:
2
5 6
o/p: 6 5
------------
*/
#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	assert(n >= 1 && n <= 2e5);
	int a[n];
	for (int i = 0; i < n; i++)cin >> a[i], assert(a[i] >= 0 && a[i] <= 1e9);
	deque<int>q;
	for (int i = 0; i < n; i++) {
		if (i & 1) {
			q.push_back(a[i]);
		} else
			q.push_front(a[i]);
	}
	vector<int>ans;
	while (!q.empty()) {
		ans.push_back(q.front());
		q.pop_front();
	}
	if (n % 2 == 0) {
		int i = 0, j = n - 1;
		while (i < j) {
			swap(ans[i++], ans[j--]);
		}
	}
	for (int x : ans)cout << x << " ";
	cout << '\n';
	return 0;
}
// ====================================================================
/*
Q) Mock 3.2
There are N doors in a corridor and the i-th door has an integer X[i] written on it. You have to paint each door a colour. However, the condition is that if the i-th and j-th door are painted with the same colour, where i < j, then X[i] < X[j].
What is the minimum number of colours you need to paint every door?
CONSTRAINTS:
1 <= N <= 10^5
0 <= x[i] <= 10^9

Constraints:
1<=N<=2*1e5
0 <=A[i]<= 1e9
------------
i/p: 
5
3 2 5 6 4
o/p: 2
------------
*/
#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main() {
    int n,p,k = 0,tmp;
    cin >> n;
    while (n--){
   	 cin >> p;
   	 tmp = upper_bound(a,a + k,p,greater< int >()) - a;
   	 if (tmp == k){
   		 a[k] = p;
   		 ++ k;
   	 }
   	 else a[tmp] = p;
    }
    cout << k << endl;
}
// ====================================================================
/*
Q) Mock

*/
#define long long ll
int main() {
    ll i,x,n,count=1,mx;
    cin>>n;
    vector<ll> v(n);
    for(i=0;i<n;i++){
        cin>>v[i];
    }
    mx=v[n-1];
    for(i=n-2;i>=0;i--){
        if(v[i]>=mx){
            mx=max(mx,v[i]);
            count++;
        }
    }
    cout<<mx;

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}
// ====================================================================
/*
Q) Mock 3.3
You are given an integer K and an integer sequence X of length N, X = (X[1], X[2], ..., X[N]). You need to find the number of integer pairs (i, j) such that i <= j and K divides X[i] + X[i+1] + ... + X[j].
CONSTRAINTS:
2 <= K <= 10^9
1 <= X[i] <= 10^9
1 <= N <= 10^5
All input values are integers

Constraints: 
2<=K<=1e9
1<=X[i]<=1e9
1<=N<=1e9
------------
Sample #0:
i/p : 
3 2 
2 1 3
o/p : 3
------------
Sample #1:
i/p : 
1 5 
25 
o/p : 1
------------
*/
#include<bits/stdc++.h>
using namespace std;
long long sum,ans,n,m,x;
map<long int,long int>mp;

int main() {
  cin>>n>>m;
  ans=0;
  sum=0;
  mp[0]=1;
 
  for(int i=0;i<n;i++) {
      cin>>x;
      sum=sum+x;
      sum=sum%m;
      
      ans= ans+mp[sum];
      mp[sum]++;
  }
 
  cout<<ans<<endl;
}
// ====================================================================
/*
Q) Mock 4.1
A Tri-Prime number is a natural number with exactly 1 factor other than 1 and itself.
You need to find how many Tri-Prime numbers less than or equal to N are there.
You need to answer T such test cases.

constraints: 
1<=T<=1e5
1<=N<=1e12
i/p: 2 3 5
o/p: 0 1

i/p: 1 10
o/p: 2
*/
/* Tri-Prime Numbers are just squares of prime numbers.
Precompute all the Prime Numbers less than 10^6,
then store their squares in a vector/array,
then use upper_bound to answer the queries in O(logN) */
 
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e6;
 
vector<ll> tp;
int is_prime[N];
 
void sieve()
{
   for(int i=2; i<N; i++) is_prime[i]=1;
   for(ll i=2; i<N; i++)
   {
       if(is_prime[i])
       {
           tp.push_back(i*i);
           for(ll j=i*i; j<N; j+=i)
               is_prime[j]=0;
       }
   }
}
 
int main()
{
   sieve();
   int tc; cin>>tc;
   while(tc--)
   {
       ll n; cin>>n;
       ll x = upper_bound(tp.begin(),tp.end(),n) - tp.begin();
       cout<<x<<endl;
   }
}
// ====================================================================
/*
Q) Mock 4.2
You are given an array A of N integers. 
Across all i, j (1 ≤ i ≤ j ≤ N), find the distinct values of A[i] | A[i+1] | … | A[j] 

constraints:
1<=n<=1e5
0<=A[i]<=1e6

i/p:
2
1 2
o/p:
3
1 2 3

i/p:
5
0 1 2 3 4
o/p:
6 
0 1 3 4 7 
*/
#include<bits/stdc++.h>
using namespace std ;
using ll = long long ;
 
int main() {
 
	ios::sync_with_stdio(0) ;
	cin.tie(0) ;
 
	int n ; cin >> n ;
	set<int> ans, ORs ;
	ORs.insert(0) ; 
	for(int i = 0 ; i < n ; ++i) {
		int x; cin >> x ;
		set<int> temp ;
		for(auto j : ORs) {
			ans.insert(j | x) ;
			temp.insert(j | x) ;
		}
		ORs = temp ;
		ORs.insert(0) ;
	}
 
	cout << ans.size() << '\n';
       for(auto i : ans) cout << i << " " ;
 
	return 0 ;
}
// ====================================================================
/*
Q) Mock 4.3
You are given an integer N and an array A of length 2N + 1. 
You have to add xi to A[i] (1 ≤ i ≤ 2N + 1), such that x1 + x2 + … + x2N+1 = S
You have to choose xi such that it maximizes the median of the array A after the above operation.

constraints:
1<=N<=1e5
0<=S,A[i]<=1e9
i/p:
1 3 
5 1 20
o/p:
8
*/
#include<bits/stdc++.h>
using namespace std ;
using ll = long long ;
 
int main() {
 
	int n, k; cin >> n >> k;
	vector<ll> v(n) ;
	for(auto &i : v) cin >> i ;
	sort(v.begin(), v.end()) ;
	v.push_back(1e18) ;
	int idx = n/2;
	ll ans = v[idx] ; 
 
	while(k > 0 and idx < n) {
		ll d = v[idx+1] - v[idx] ;
		if(idx < n-1 and (idx - n/2 + 1) * d <= k) {
		    k -= (idx - n/2 + 1) * d ;
		    ++idx;
		    ans = v[idx];
		}
		else {
			ans += (k / (idx - n/2 + 1)) ;
			k -= (idx - n/2 + 1) * (k / (idx - n/2 + 1)) ;
			break ;
		}
	}
 
	cout << ans ;
 
	return 0 ;
}
// ====================================================================
// ====================================================================
