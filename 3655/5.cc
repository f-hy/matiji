/**
 * @file 5.cc
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
string s;
ll dp[101][51][2], n, INF = 0x3f3f3f3f;
int main() {
  ios::sync_with_stdio(false);
  // file(data);
  cin >> s >> n;
  int size = s.size();
  s = ' ' + s;
  for (int i = 0; i <= size; i++) {
    for (int j = 0; j <= n; j++) {
      dp[i][j][0] = dp[i][j][1] = -INF;
    }
  }
  dp[0][0][0] = dp[0][0][1] = 0;
  for (int i = 1; i <= size; i++) {
    for (int j = 0; j <= n; j++) {
      for (int k = 0; k <= j; k++) {
        if (s[i] == 'F') {
          if (k % 2 == 1) {
            dp[i][j][0] = max(dp[i][j][0], dp[i - 1][j - k][0]);
            dp[i][j][1] = max(dp[i][j][1], dp[i - 1][j - k][0]);
          } else {
            dp[i][j][0] = max(dp[i][j][0], dp[i - 1][j - k][0] + 1);
            dp[i][j][1] = max(dp[i][j][1], dp[i - 1][j - k][1] - 1);
          }
        } else if (k % 2 == 1) {
          dp[i][j][0] = max(dp[i][j][0], dp[i - 1][j - k][0] + 1);
          dp[i][j][1] = max(dp[i][j][1], dp[i - 1][j - k][1] - 1);
        } else {
          dp[i][j][0] = max(dp[i][j][0], dp[i - 1][j - k][1]);
          dp[i][j][1] = max(dp[i][j][1], dp[i - 1][j - k][0]);
        }
      }
    }
  }
  cout << max(dp[size][n][0], dp[size][n][1]);
  return 0;
}