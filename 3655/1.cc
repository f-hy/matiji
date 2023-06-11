/**
 * @file 1.cc
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
const int N = 4e6 + 5;
int n, mod;
ll dp[N], sum[N];
int main() {
  ios::sync_with_stdio(false);
  // file(data);
  cin >> n >> mod;
  dp[n] = sum[n] = 1;
  for (int i = n - 1; i >= 1; i--) {
    dp[i] = sum[i + 1];
    for (int j = 2; j * i <= n; j++) {
      int r = min(n, i * j + j - 1);
      dp[i] = (dp[i] + sum[i * j] - sum[r + 1]) % mod;
    }
    sum[i] = (sum[i + 1] + dp[i]) % mod;
  }
  cout << dp[1];
  return 0;
}