/**
 * @file 3.cpp
 * @author Friendy (friend0@qq.com)
 * @date 2023-03-23
 * @version 0.1
 * @brief csp competition
 * @copyright Copyright (c) 2023
 */
#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>
#define file(x)                                                                \
    freopen(#x ".in", "r", stdin);                                             \
    freopen(#x ".out", "w", stdout);
#define rep(i, s, t) for (int i = s; i <= t; i++)
#define dwn(i, s, t) for (int i = s; i >= t; i--)
#define ite(it, s, e) for (auto it = s; it != e; ++it)
int t0, t1, t2, x1, x2, y, yy;
pii ans;
double diff = INT_MAX;
double gett() { return double(t1 * y + t2 * yy) / (y + yy); }
void getyy() { yy = ceil(double(y * (t0 - t1)) / (t2 - t0)); }
int main() {
    ios::sync_with_stdio(false);
    // file(data);
    cin >> t1 >> t2 >> x1 >> x2 >> t0;
    for (y = x1; y >= 0; --y) {
        getyy();
        if (yy > x2)
            continue;
        double td = gett() - t0;
        if (td < diff) {
            ans = {y, yy};
            diff = td;
        }
    }
    cout << ans.first << ' ' << ans.second;
    return 0;
}