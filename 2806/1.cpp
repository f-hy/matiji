/**
 * @file 1.cpp
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
const int maxn = 1e5 + 1;
int n, a[maxn], ans;
int main()
{
    ios::sync_with_stdio(false);
    // file(data);
    cin >> n;
    rep(i, 1, n)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    int e = (n - 1) / 2;
    rep(i, 1, e)
    {
        ans += abs(a[i + 1] - a[n - i + 1]);
        ans += abs(a[i] - a[n - i + 1]);
    }
    if (!(n % 2))
    { // even
        ans += abs(a[n / 2] - a[n / 2 + 1]);
    }
    ans += abs(a[1] - a[n / 2 + 1]);
    cout << ans;
    return 0;
}