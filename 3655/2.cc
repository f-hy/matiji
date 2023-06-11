/**
 * @file 2.cc
 * @author Friendy (friend0@qq.com)
 * @date 2023-06-11
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
const int N = 27;
int n, m, h[N], dp[N], f[N], ans_t, ans_c;
int main() {
  ios::sync_with_stdio(false);
  //   file(data);
  cin >> m;
  while (m--) {
    ans_t = ans_c = 0;
    memset(h, 0, sizeof h);
    memset(dp, 0, sizeof dp);
    memset(f, 0, sizeof f);
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> h[i];
      dp[i] = f[i] = 1;
    }
    for (int i = 2; i <= n; i++) {
      for (int j = i - 1; j; --j) {
        if (h[j] <= h[i]) {
          if (dp[j] + 1 > dp[i]) {
            dp[i] = dp[j] + 1;
            f[i] = f[j];
          } else if (dp[j] + 1 == dp[i]) {
            f[i] += f[j];
          }
        }
      }
    }
    for (int i = 1; i <= n; i++) {
      ans_t = max(ans_t, dp[i]);
    }
    for (int i = 1; i <= n; ++i) {
      if (dp[i] == ans_t) {
        ans_c += f[i];
      }
    }
    cout << ans_t << " " << ans_c << "\n";
  }
  return 0;
}