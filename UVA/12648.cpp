/*
    build a graph:
        each node represent the number of employee.
        each employee connects to the all employees that manage him,
        by creating adjacency list for each employee.

    if instruction from type management change:  T a b
        swap 2 lists and iterate over all lists if found a put b and if found b put a.
    if instruction from type query: P x
        initialise result by OO.
        dfs from x and minimize the answer.
        if result == OO then there is no employee manage this employee.
*/

#include <bits/stdc++.h>

using namespace std;

const int N = 502, OO = 1e9;
int a[N], res;
vector<int> adj[N];
bool vis[N];

void dfs(int i) {
    vis[i] = true;
    for (int x : adj[i]) {
        if (!vis[x]) {
            res = min(res, a[x]);
            dfs(x);
        }
    }
}

int main() {

    int n, m, k;
    while (scanf("%d%d%d", &n, &m, &k) != -1) {
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            adj[i].clear();
        }
        while (m--) {
            int a, b;
            scanf("%d%d", &a, &b);
            adj[b].push_back(a);
        }
        while (k--) {
            char t;
            scanf(" %c", &t);
            if (t == 'T') {
                int a, b;
                scanf("%d%d", &a, &b);
                adj[a].swap(adj[b]);
                for (int i = 1; i <= n; i++) {
                    for (int &x : adj[i]) {
                        if (x == a) x = b;
                        else if (x == b) x = a;
                    }
                }
            } else {
                memset(vis, 0, sizeof(vis));
                int a;
                scanf("%d", &a);
                res = OO;
                dfs(a);
                if (res == OO) puts("*");
                else printf("%d\n", res);
            }
        }
    }

    return 0;
}