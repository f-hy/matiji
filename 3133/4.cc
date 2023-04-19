/**
 * @file 4.cc
 * @author Friendy (friend0@qq.com)
 * @date 2023-04-19
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
const int maxn = 1e3 + 1;  // n,t
const int maxx = 1e5;
int n, t, x[maxn], f[maxn];
unordered_map<int, int> cnt;
int main() {
  ios::sync_with_stdio(false);
  // file(data);
  cin >> n >> t;
  t <<= 1;
  rep(i, 1, n) {
    cin >> x[i] >> f[i];
    x[i] <<= 1;
    ++cnt[x[i]];
  }
  while (t--) {
    rep(i, 1, n) {
      --cnt[x[i]];
      x[i] += f[i];
      ++cnt[x[i]];
    }
    rep(i, 1, n) if (cnt[x[i]] > 1) f[i] = -f[i];
  }
  rep(i, 1, n) cout << (x[i] >> 1) << ' ' << (cnt[x[i]] == 1 ? f[i] : 0)
                    << endl;
  return 0;
}