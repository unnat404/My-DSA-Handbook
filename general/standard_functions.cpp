// ================================================================================================
// Binary Exponentiation:: https://cp-algorithms.com/algebra/binary-exp.html
long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}
// ================================================================================================
// Sieve of Eratosthenes:: Sieve of Eratosthenes is an algorithm for finding all the prime numbers in a segment [1;n]  using O(n*logn) operations.
// - https://cp-algorithms.com/algebra/sieve-of-eratosthenes.html
// - https://cp-algorithms.com/algebra/prime-sieve-linear.html

// Approach -1 
int n;
vector<bool> is_prime(n+1, true);
is_prime[0] = is_prime[1] = false;
for (int i = 2; i <= n; i++) {
    if (is_prime[i] && (long long)i * i <= n) {
        for (int j = i * i; j <= n; j += i)
            is_prime[j] = false;
    }
}

// Optimization: Sieving till root
int n;
vector<bool> is_prime(n+1, true);
is_prime[0] = is_prime[1] = false;
for (int i = 2; i * i <= n; i++) {
    if (is_prime[i]) {
        for (int j = i * i; j <= n; j += i)
            is_prime[j] = false;
    }
}

// Segmented Sieve
int count_primes(int n) {
    const int S = 10000;

    vector<int> primes;
    int nsqrt = sqrt(n);
    vector<char> is_prime(nsqrt + 2, true);
    for (int i = 2; i <= nsqrt; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (int j = i * i; j <= nsqrt; j += i)
                is_prime[j] = false;
        }
    }

    int result = 0;
    vector<char> block(S);
    for (int k = 0; k * S <= n; k++) {
        fill(block.begin(), block.end(), true);
        int start = k * S;
        for (int p : primes) {
            int start_idx = (start + p - 1) / p;
            int j = max(start_idx, p) * p - start;
            for (; j < S; j += p)
                block[j] = false;
        }
        if (k == 0)
            block[0] = block[1] = false;
        for (int i = 0; i < S && start + i <= n; i++) {
            if (block[i])
                result++;
        }
    }
    return result;
}

// Find primes in range
// It's also possible that we don't pre-generate all prime numbers: (code below)
vector<char> segmentedSieveNoPreGen(long long L, long long R) {
    vector<char> isPrime(R - L + 1, true);
    long long lim = sqrt(R);
    for (long long i = 2; i <= lim; ++i)
        for (long long j = max(i * i, (L + i - 1) / i * i); j <= R; j += i)
            isPrime[j - L] = false;
    if (L == 1)
        isPrime[0] = false;
    return isPrime;
}

// ================================================================================================
// Counting no of set bits
// **Brian Kernighan's Algo (optimized) : This runs only that many times as the no of set bits the given input no. has
int countSetBits(int n){
    int count=0;
    while(n>0){
        n &= (n-1);
        count++;
    }
    return count;
}
/*
-------------------------------
n  bin(n)  n&(n-1)  n^(n-1)
-------------------------------
9: 1001    1000     9^8 :0001
8: 1000    0000     1111
7: 0111    0110     0001
6: 0110    0100     0011
5: 0101    0100     0001
4: 0100    0000     0111
3: 0011    0010     0001
2: 0010    0000     0011
1: 0001    0000     0001
0: 0000    0000
*/
// ================================================================================================
// https://www.geeksforgeeks.org/check-characters-given-string-can-rearranged-form-palindrome/
// C++ Implementation of the above approach
# include <bits/stdc++.h>
using namespace std;

bool canFormPalindrome(string a)
{
	// bitvector to store
	// the record of which character appear
	// odd and even number of times
	int bitvector = 0, mask = 0;
	for (int i=0; a[i] != '\0'; i++)
	{
		int x = a[i] - 'a';
		mask = 1 << x;

		bitvector = bitvector ^ mask;
	}

	return (bitvector & (bitvector - 1)) == 0;
}

// Driver Code
int main()
{

	if (canFormPalindrome("geeksforgeeks"))
	cout << ("Yes") << endl;
	else
	cout << ("No") << endl;

	return 0;
}
// ================================================================================================
