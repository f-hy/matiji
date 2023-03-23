/**
 * @file 5.cpp
 * @author Friendy (friend0@qq.com)
 * @date 2023-03-23
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
int cnt1, cnt2, x, y, ans;
int a, b, ab;
int main() {
    ios::sync_with_stdio(false);
    // file(data);
    cin >> cnt1 >> cnt2 >> x >> y;
    // int l = max(((cnt1 - 1) * x) / (x - 1), ((cnt2 - 1) * y) / (y - 1));
    // int r = min(((cnt2 + 1) * x * y + 1) / (y - 1),
    //             ((cnt1 + 1) * x * y + 1) / (y - 1));
    int l = 1, r = 1e9;
    int mid;
    while (l <= r) {
        mid = l + (r - l) / 2;
        int tmp = mid - int(mid / (x * y)) - cnt1 - cnt2;
        if (tmp < 0 || mid - int(mid / x) - cnt1 < 0 ||
            mid - int(mid / y) - cnt2 < 0)
            l = mid + 1;
        else {
            r = mid - 1;
            ans = mid;
        }
    }
    cout << ans;
    return 0;
}