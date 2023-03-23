/**
 * @file 4.cpp
 * @author Friendy (friend0@qq.com)
 * @date 2023-03-23
 * @version 0.1
 * @brief csp competition
 * @github https://github.com/f-hy
 * @gitee https://gitee.com/friendhy
 * @copyright Copyright (c) 2023
 * _
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
const int maxn = 1e5 + 1;
int t, n, ans, a[maxn];
bool check(int num) {
    rep(i, 0, n - num) {
        int j = i + num - 1;
        if (a[j] <= 0 && -a[i] <= t)
            return true;
        if (a[i] >= 0 && a[j] <= t)
            return true;
        if (a[i] <= 0 && a[j] >= 0)
            if (min(-a[i], a[j]) + a[j] - a[i] <= t)
                return true;
    }
    return false;
}
int main() {
    ios::sync_with_stdio(false);
    // file(data);
    cin >> t >> n;
    rep(i, 0, n - 1) cin >> a[i];
    sort(a, a + n);
    int l = 1, r = n;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (check(mid))
            l = mid + 1, ans = mid;
        else
            r = mid - 1;
    }
    cout << ans;
    return 0;
}