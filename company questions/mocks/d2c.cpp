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
Q) Mock

*/
// ====================================================================
/*
Q) Mock

*/
// ====================================================================
/*
Q) Mock

*/
// ====================================================================
/*
Q) Mock

*/
// ====================================================================
/*
Q) Mock

*/
// ====================================================================
/*
Q) Mock

*/
// ====================================================================
// ====================================================================
// ====================================================================
