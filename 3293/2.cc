/**
 * @file 2.cc
 * @author Friendy (friend0@qq.com)
 * @date 2023-05-12
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
const int maxn = 1e6 + 1;
int n, ans, a[maxn], h;
int main() {
  ios::sync_with_stdio(false);
  // file(data);
  cin >> n;
  rep(i, 0, n - 1) {
    cin >> h;
    a[h] > 0 ? --a[h] : ++ans;
    ++a[h - 1];
  }
  cout << ans;
  return 0;
}