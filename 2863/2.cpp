/**
 * @file 2.cpp
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
map<int, int> mp;
int n, m, a, ans;
int main() {
    ios::sync_with_stdio(false);
    // file(data);
    cin >> m >> n;
    rep(i, 1, n) {
        cin >> a;
        a = -a;
        if (mp.find(a) == mp.end())
            mp[a] = 1;
        else
            mp[a] += 1;
    }
    int mb = mp.begin()->second;
    while (m > mb) {
        m -= mb;
        mp.erase(mp.begin());
        mp.begin()->second += mb;
        mb = mp.begin()->second;
    }
    int t = mp.begin()->first + 1;
    ans += t * t * m;
    t = mp.begin()->first;
    ans += t * t * (mp.begin()->second - m);
    mp.erase(mp.begin());
    if (!mp.empty())
        for (auto &x : mp) {
            ans += x.first * x.first * x.second;
        }
    cout << ans;
    return 0;
}