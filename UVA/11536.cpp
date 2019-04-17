#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const double PI = 3.14159265;

void fastInOut();

const int N = 1000006, K = 102;
int a[N], freq[K];

bool covered(int k) {
    for (int i = 1; i <= k; i++)
        if (!freq[i])
            return 0;
    return 1;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
#endif

    fastInOut();
    int t, n, m, k, c = 0;
    a[1] = 1, a[2] = 2, a[3] = 3;
    cin >> t;
    while (t--) {
        c++;
        cin >> n >> m >> k;
        for (int i = 4; i <= n; i++)
            a[i] = (a[i - 1] + a[i - 2] + a[i - 3]) % m + 1;
        int l = 1, r = 1, res = N;
        freq[a[r]]++;
        while (l <= n) {
            while (!covered(k) && r < n) {
                r++;
                if (a[r] <= k)
                    freq[a[r]]++;
            }
            if (covered(k))
                res = min(res, r - l + 1);
            if (a[l] <= k)
                freq[a[l]]--;
            l++;
        }
        cout << "Case " << c << ": ";
        if (res == N) cout << "sequence nai\n";
        else cout << res << '\n';
    }
    return 0;
}

void fastInOut() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);
}