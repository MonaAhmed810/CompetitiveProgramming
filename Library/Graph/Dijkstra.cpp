#include <bits/stdc++.h>

using namespace std;

const int N = 100005, OO = (int) 1e9;
int n, m, src, dist[N];
vector<pair<int, int>> adj[N];

void dijkstra() {
    fill(dist, dist + n + 1, OO);
    dist[src] = 0;
    priority_queue<pair<int, int> > pq;
    pq.push({-dist[src], src});
    while (!pq.empty()) {
        pair<int, int> top = pq.top();
        pq.pop();
        int v = top.second;
        for (auto p : adj[v]) {
            int u = p.first, c = p.second;
            if (dist[v] + c < dist[u]) {
                dist[u] = dist[v] + c;
                pq.push({-dist[u], u});
            }
        }
    }
}