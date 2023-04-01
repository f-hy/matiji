/**
 * @file 3.cpp
 * @author Friendy (friend0@qq.com)
 * @date 2023-03-29
 * @version 0.1
 * @brief csp competition
 * @github https://github.com/f-hy
 * @gitee https://gitee.com/friendhy
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
const int maxn = 1e3 + 1;
int n, m;
float nn[maxn], steal[maxn];
float ans;
int main() {
    ios::sync_with_stdio(false);
    // file(data);
    cin >> n >> m;
    rep(i, 1, n) { cin >> nn[i]; }
    int x, y;
    float z;
    rep(i, 1, m) {
        cin >> x >> y >> z;
        float delta = z - floor(z);
        if (nn[x] >= z) {
            ans += delta;
            nn[x] -= z;
            nn[y] += floor(z);
            steal[y] += delta;
            if (steal[y] > 1)
                break;
        } else
            break;
    }
    // cout << ans;
    printf("%.2f", ans);
    return 0;
}