#include <bits/stdc++.h>

using namespace std;

const int N = 1000006;
int z[N];

void buildZArray(string &str) {
    int l = 0, r = 0, sz = (int) str.size();
    for (int i = 1; i < sz; ++i) {
        if (i > r) {
            l = r = i;
            while (r < sz && str[r - l] == str[r])
                ++r;
            z[i] = r - l, --r;
        } else if (z[i - l] < r - i + 1) {
            z[i] = z[i - l];
        } else {
            l = i;
            while (r < sz && str[r - l] == str[r])
                ++r;
            z[i] = r - l, --r;
        }
    }
}

vector<int> searchZFunction(string &text, string &pattern) {
    string concat = pattern + "$" + text;
    buildZArray(concat);
    vector<int> places;
    int sz = (int) pattern.size();
    for (int i = sz + 1; i < (int) concat.size(); ++i)
        if (z[i] == sz)
            places.push_back(i - sz - 1);
    return places;
}