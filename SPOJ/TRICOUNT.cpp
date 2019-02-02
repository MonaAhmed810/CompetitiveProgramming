#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll sum(ll n) {
    return n * (n + 1) / 2;
}

ll sumSqr(ll n) {
    return n * (n + 1) * (2 * n + 1) / 6;
}

ll sumOfSum(ll n) {
    return (sumSqr(n) + sum(n)) / 2;
}

ll sumEvenOdd(ll n) {
    if (n % 2) return ((n + 1) / 2) * ((n + 1) / 2);
    return 2 * sum(n / 2);
}

ll sumSqrEvenOdd(ll n) {
    ll even = 4 * sumSqr(n / 2);
    if (n % 2) return sumSqr(n) - even;
    return even;
}

ll sumOfSumEvenOdd(ll n) {
    return (sumSqrEvenOdd(n) + sumEvenOdd(n)) / 2;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        printf("%lld\n", sumOfSum(n) + sumOfSumEvenOdd(n - 1));
    }
    return 0;
}