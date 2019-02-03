#include <bits/stdc++.h>

using namespace std;

const int N = 10000007;
bool notPrime[N];
vector<int> allPrimes, primes[N];

// Primality Test - Naive Loop O(sqrt(n))
bool isPrime(int &n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

// Primality Test - Sieve.
// O(n) for pre-calculation.
// Query in O(1).
void sieve() {
    notPrime[0] = notPrime[1] = 1;
    for (int i = 2; i * i < N; ++i)
        if (!notPrime[i])
            for (int j = i * i; j < N; j += i)
                notPrime[j] = 1;
}


// O(n)
void factoriseWithSieve() {
    notPrime[0] = notPrime[1] = 1;
    for (int i = 2; i < N; ++i) {
        if (!notPrime[i]) {
            allPrimes.push_back(i);
            primes[i].push_back(i);
            for (int j = i + i; j < N; j += i) {
                primes[j].push_back(i);
                notPrime[j] = 1;
            }
        }
    }
}

// O(log(n))
// 2^x1 * 3^x2 * 5^x3 * ...
// number of divisors = (x1+1) * (x2+1) * (x3+1) * ...
void factorize(int &n) {
    int NumOfDivisors = 1;
    for (int prime : primes[n]) {
        int x = 0;
        while (n % prime == 0) {
            x++;
            n /= prime;
        }
        cout << prime << '^' << x << ' ';
        NumOfDivisors *= (x + 1);
    }
}