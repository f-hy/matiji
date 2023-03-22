/**
 * @file 2.cpp
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
const int maxn = 17;
int n;
int need[5], a[maxn][5];
set<int> s;
bool status(int cnt[])
{
    rep(i, 0, 4) if (cnt[i] != need[i]) return false;
    return true;
}
void add(int a[], int b[])
{
    rep(i, 0, 4)
        a[i] += b[i];
}
int main()
{
    ios::sync_with_stdio(false);
    // file(data);
    cin >> n;
    rep(i, 1, n) rep(j, 0, 4) cin >> a[i][j];
    rep(i, 0, 4) cin >> need[i];
    int i = 0;
    for (; i < (1 << n); ++i)
    {
        int cnt[5] = {0};
        rep(j, 1, n)
        {
            if (i & (1 << (j - 1)))
            {
                add(cnt, a[j]);
            }
        }
        if (status(cnt))
        {
            break;
        }
    }
    rep(j, 1, n)
    {
        if (i & (1 << (j - 1)))
            cout << j << ' ';
    }
    return 0;
}