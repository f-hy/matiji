/**
 * @file 3.cc
 * @author Friendy (friend0@qq.com)
 * @date 2023-04-06
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
const int maxn = 1e5 + 1;
int n, a[maxn], ra[maxn];
ll ans;
int main() {
  ios::sync_with_stdio(false);
  // file(data);
  cin >> n;
  rep(i, 0, n - 1) cin >> a[i];
  sort(a, a + n);
  rep(i, 0, n - 1) ra[i] = a[n - 1 - i];
  for (int i = 0; a[i] < ra[i]; ++i) ans += ra[i] - a[i];
  cout << ans;
  return 0;
}