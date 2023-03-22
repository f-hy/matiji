/**
 * @file 4.cpp
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
const int maxn = 1e5;
int n, a, t, ans;
pair<int, bool> sp[maxn << 1];
int main()
{
    ios::sync_with_stdio(false);
    // file(data);
    cin >> n;
    rep(i, 0, n - 1)
    {
        cin >> a >> t;
        sp[i << 1] = {a, true};
        sp[(i << 1) + 1] = {a + t, false};
    }
    sort(sp, sp + (n << 1));
    int cnt = 0;
    rep(i, 0, (n << 1) - 1)
    {
        if (sp[i].second)
        {
            ++cnt;
            if (cnt > ans)
                ans = cnt;
        }
        else
            --cnt;
    }
    cout << ans;
    return 0;
}