/**
 * @file 3.cpp
 * @author Friendy (friend0@qq.com)
 * @date 2023-03-18
 * @version 0.1
 * @brief csp competition
 * @copyright Copyright (c) 2023
 */
#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>
#define file(x)                    \
    freopen(#x ".in", "r", stdin); \
    freopen(#x ".out", "w", stdout);
#define rep(i, s, t) for (int i = s; i <= t; i++)
#define dwn(i, s, t) for (int i = s; i >= t; i--)
#define ite(it, s, e) for (auto it = s; it != e; ++it)
const int maxn = 1e3 + 1;
int q;
int m, n;
pii cal(pii p, bool flag)
{
    if (m < 3 || n < 3)
    {
        if (flag)
            return {p.first + m * n, p.second};
        else
            return {p.first, p.second + m * n};
    }
    else
    {
        m -= 2;
        n -= 2;
        if (flag)
            return cal({p.first + m + m + n + n + 4, p.second}, !flag);
        else
            return cal({p.first, p.second + m + m + n + n + 4}, !flag);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    // file(data);
    cin >> q;
    rep(i, 1, q)
    {
        cin >> m >> n;
        pii ans = {0, 0};
        ans = cal(ans, true);
        cout << ans.first << ' ' << ans.second << endl;
    }
    return 0;
}