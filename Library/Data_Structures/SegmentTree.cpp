#include <bits/stdc++.h>

using namespace std;

const int N = 100005, OO = 1e9;
int n, arr[N], sg[4 * N], lp[4 * N];

int build(int idx, int l, int r) {
    if (l == r)
        return sg[idx] = arr[l];
    int m = (l + r) / 2;
    int prt1 = build(2 * idx + 1, l, m);
    int prt2 = build(2 * idx + 2, m + 1, r);
    return sg[idx] = max(prt1, prt2);
}

int update(int idx, int l, int r, int pos, int val) {
    if (r < pos || l > pos)
        return sg[idx];
    if (l == r)
        return sg[idx] = val;
    int m = (l + r) / 2;
    int prt1 = update(2 * idx + 1, l, m, pos, val);
    int prt2 = update(2 * idx + 2, m + 1, r, pos, val);
    return sg[idx] = max(prt1, prt2);
}

int updateRng(int idx, int l, int r, int st, int ed, int val) {
    if (ed < l || st > r)
        return sg[idx];
    if (l >= st && r <= ed) {
        lp[idx] = val;
        return sg[idx] = val;
    }
    int m = (l + r) / 2;
    if (lp[idx]) {
        lp[2 * idx + 1] = lp[idx];
        lp[2 * idx + 2] = lp[idx];
        sg[2 * idx + 1] = lp[idx];
        sg[2 * idx + 2] = lp[idx];
        lp[idx] = 0;
    }
    int prt1 = updateRng(2 * idx + 1, l, m, st, ed, val);
    int prt2 = updateRng(2 * idx + 2, m + 1, r, st, ed, val);
    return sg[idx] = max(prt1, prt2);
}

int query(int idx, int l, int r, int st, int ed) {
    if (ed < l || st > r)
        return -OO;
    if (l >= st && r <= ed)
        return sg[idx];
    if (lp[idx]) {
        lp[2 * idx + 1] = lp[idx];
        lp[2 * idx + 2] = lp[idx];
        sg[2 * idx + 1] = lp[idx];
        sg[2 * idx + 2] = lp[idx];
        lp[idx] = 0;
    }
    int m = (l + r) / 2;
    int prt1 = query(2 * idx + 1, l, m, st, ed);
    int prt2 = query(2 * idx + 2, m + 1, r, st, ed);
    return max(prt1, prt2);
}

int main() {
    build(0, 0, n - 1);
    return 0;
}
