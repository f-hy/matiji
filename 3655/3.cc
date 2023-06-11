/**
 * @file 3.cc
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
ll n, dp[40][160], sum1, sum2, fenmu = 1, temp;
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
int main() {
  ios::sync_with_stdio(false);
  // file(data);
  cin >> n;
  dp[1][1] = dp[1][2] = dp[1][3] = dp[1][4] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= 4 * n; j++) {
      for (int k = 1; k <= 4; k++) {
        if (j > k) {
          dp[i][j] += dp[i - 1][j - k];
        }
      }
    }
  }
  for (int i = n; i < 2 * n; i++) {
    sum1 += dp[n][i];
  }
  for (int i = 3 * n + 1; i <= 4 * n; i++) {
    sum2 += dp[n][i];
  }
  for (int i = 1; i <= n; i++) {
    fenmu *= 4;
  }
  temp = gcd(sum1, fenmu);
  cout << sum1 / temp << "/" << fenmu / temp << "\n";
  temp = gcd(sum2, fenmu);
  cout << sum2 / temp << "/" << fenmu / temp;
  return 0;
}