/*
 * DP (Counting Problem)
 *      state : i (index of original string)
 *              j (length of taken substring from original string)
 *              gta (flag indicate if the taken substring till now is strictly greater than string A)
 *              stb (flag indicate if the taken substring till now is strictly smaller than string B)
 *
 *      try leave
 *      or
 *      take iff
 *          taken substring is strictly greater than string A or this char won't make it smaller than A
 *          and taken substring is strictly smaller than string B or this char won't make it greater than B
 *      and going with the new gta and stb.
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

string s, a, b;
int memo[26][26][2][2];

int go(int i, int j, bool gta, bool stb) {
    if (i == s.size())
        return (gta || j == a.size()) && (stb || j <= b.size());
    int &ret = memo[i][j][gta][stb];
    if (ret != -1)
        return ret;
    ret = go(i + 1, j, gta, stb);
    if ((j >= a.size() || gta || s[i] >= a[j]) && (stb || (j < b.size() && s[i] <= b[j])))
        ret += go(i + 1, j + 1, j >= a.size() || gta || s[i] > a[j], stb || (j < b.size() && s[i] < b[j]));
    return ret;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
#endif
    memset(memo, -1, sizeof(memo));
    cin >> s >> a >> b;
    cout << go(0, 0, 0, 0);
    return 0;
}