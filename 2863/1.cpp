/**
 * @file 1.cpp
 * @author Friendy (friend0@qq.com)
 * @date 2023-03-22
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
const int maxn = 5e5 + 1;
const int maxa = 1e5;
int n, a[maxn], ans, cnt[maxn];
int main() {
    ios::sync_with_stdio(false);
    // file(data);
    cin >> n;
    rep(i, 1, n) { cin >> a[i]; }
    rep(i, 1, n - 1) {
        if (a[i] < a[i + 1])
            cnt[i + 1] = cnt[i] + 1;
        else if (a[i] == a[i + 1])
            cnt[i + 1] = cnt[i];
    }
    dwn(i, n, 1) {
        if (a[i - 1] > a[i])
            cnt[i - 1] = max(cnt[i - 1], cnt[i] + 1);
    }
    rep(i, 1, n) ans += cnt[i];
    cout << (ans + n);
    return 0;
}