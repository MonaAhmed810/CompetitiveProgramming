#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const double PI = 3.14159265;

void fastInOut();

const int MAX = 1000001;
bool notPrime[MAX];

void sieve() {
    notPrime[0] = notPrime[1] = 1;
    for (int i = 2; i * i < MAX; i++) {
        if (!notPrime[i]) {
            for (int j = i * i; j < MAX; j += i)
                notPrime[j] = 1;
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
#endif

    fastInOut();
    sieve();
    int n;
    while (cin >> n && n) {
        bool ok = false;
        for (int i = 3; i <= n; i += 2) {
            if (!notPrime[i] && !notPrime[n - i]) {
                ok = true;
                cout << n << " = " << i << " + " << n - i << '\n';
                break;
            }
        }
        if (!ok) cout << "Goldbach's conjecture is wrong.\n";
    }
    return 0;
}

void fastInOut() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);
}