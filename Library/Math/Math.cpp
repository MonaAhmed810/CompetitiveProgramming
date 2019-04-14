#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

ll fastPow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

// a = x * b + m, 0 <= m < b
int mod(int a, int b) {
    return a - (a / b) * b;
}

// Fermat's little theorem: (a ^ -1) % p = (a ^ (p - 2)) % p if p prime.

int gcd(int a, int b) {
    return (b == 0) ? a : gcd(b, mod(a, b));
}

/*
 *      res  = q*d  + m;     (divide by d)
 *     res/d =  q   + m/d;   (multiply by x)
 * (res/d)*x = q*x  + x*m/d;
 */
ll nCr(int n, int r) {
    ll ret = 1;
    for (int nn = r + 1; nn <= n; ++nn) {
        int d = nn - r;
        ll q = ret / d, m = ret % d;
        ret = (q * nn) + (nn * m / d);
    }
    return ret;
}

ll nCr(int n, int r) {
    ll res = 1;
    for (int i = r + 1; i <= n; i++) {
        int nn = i, d = nn - r;
        int g = __gcd(nn, d);
        nn /= g;
        d /= g;
        res *= nn;
        res /= d;
    }
    return res;
}