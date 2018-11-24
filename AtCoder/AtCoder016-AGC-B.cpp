/*
	editorial: (Page 6)
		https://atcoder.jp/img/agc016/editorial.pdf
*/

#include <bits/stdc++.h>
 
using namespace std;
 
const int OO = 1e9, N = 100005;
int freq[N];
 
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
#endif
 
    int n, mn = OO, mx = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        mn = min(mn, x);
        mx = max(mx, x);
        freq[x]++;
    }
    if (mn == mx) {
        if (2 * mn <= n || mn == n - 1) {
            puts("Yes");
            return 0;
        }
    } else if (mx - mn == 1) {
        if (freq[mn] + 1 <= mx && mx <= freq[mn] + freq[mx] / 2) {
            puts("Yes");
            return 0;
        }
    }
    puts("No");

    return 0;
}