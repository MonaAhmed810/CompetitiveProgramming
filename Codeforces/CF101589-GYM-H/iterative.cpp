/*
        DP - knapsack maximization problem:
            try to take or leave each board.
            and calculate the perimeter of left boards while going. 
            DP state : i --> index of board.
                       prev --> last board wasn't taken.
                       perimeter --> total perimeter till this state.

        How to calculate perimeter:
            initial previous board heigth = 0
            for each board we add to perimeter
                the absolute different between its height and previous height
                + 2  (the up and down width)
            then add the heigth of last board.
*/

#include <bits/stdc++.h>

using namespace std;

const int N = 51, OO = 1e9, MAX = 5300;
int n, a[N], tot, optimal, dp[N][N][MAX];

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int prv = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        tot += abs(a[i] - prv) + 2;
        prv = a[i];
    }
    tot += prv;

    for (int prev = 0; prev <= n; prev++) {
        for (int perimeter = 0; perimeter <= tot; perimeter++) {
            if (perimeter + a[prev] >= tot / 2)
                dp[n + 1][prev][perimeter] = 0;
            else
                dp[n + 1][prev][perimeter] = -OO;
        }
    }
    for (int i = n; i >= 1; i--) {
        for (int prev = i - 1; prev >= 0; prev--) {
            for (int perimeter = 0; perimeter <= tot; perimeter++) {
                dp[i][prev][perimeter] = a[i] + dp[i + 1][prev][perimeter]; // take
                int new_perimeter = perimeter + abs(a[prev] - a[i]) + 2;
                if (new_perimeter <= tot)
                    dp[i][prev][perimeter] = max(dp[i][prev][perimeter], dp[i + 1][i][new_perimeter]);
            }
        }
    }

    optimal = dp[1][0][0];
    printf("%d\n", optimal);

    vector<int> path;
    int i = 1, prev = 0, perimeter = 0;
    while (optimal) {
        if (a[i] + dp[i + 1][prev][perimeter] == optimal) {
            path.push_back(i);
            optimal -= a[i];
            i++;
        } else {
            perimeter += abs(a[prev] - a[i]) + 2;
            prev = i;
            i++;
        }
    }

    printf("%d\n", (int) path.size());
    for (int x : path)
        printf("%d ", x);

    return 0;
}
