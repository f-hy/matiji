/**
 * @file 1.cc
 * @author Friendy (friend0@qq.com)
 * @date 2023-04-30
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
#define file(x)                  \
  freopen(#x ".in", "r", stdin); \
  freopen(#x ".out", "w", stdout);
#define rep(i, s, t) for (int i = s; i <= t; i++)
#define dwn(i, s, t) for (int i = s; i >= t; i--)
#define ite(it, s, e) for (auto it = s; it != e; ++it)
int n, c, a;
ll ans;  // 1,c,30
map<int, ll> mp, cnt;
int main() {
  ios::sync_with_stdio(false);
  // file(data);
  cin >> n >> c;
  rep(i, 0, n - 1) {
    cin >> a;
    ++mp[a];
  }
  for (auto &m : mp) {
    ans += (m.second * mp[m.first - c]);
  }
  cout << ans;
  return 0;
}