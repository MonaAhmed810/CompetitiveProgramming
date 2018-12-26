#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
 
const int N = 2503;
int in[N][4];
 
int main() {

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 4; j++)
            scanf("%d", &in[i][j]);
    vector<int> v1, v2;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            v1.push_back(in[i][0] + in[j][1]);
            v2.push_back(in[i][2] + in[j][3]);
        }
    }
    sort(v2.begin(), v2.end());
    ll res = 0;
    for (int i = 0; i < v1.size(); i++) {
        int st = lower_bound(v2.begin(), v2.end(), -v1[i]) - v2.begin();
        int ed = upper_bound(v2.begin(), v2.end(), -v1[i]) - v2.begin();
        res += ed - st;
    }
    printf("%lld", res);
 
 
    return 0;
} 
