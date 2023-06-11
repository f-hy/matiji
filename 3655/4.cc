/**
 * @file 4.cc
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
const int N = 1e5 + 7;
int n, a[N], dp[N];
int main() {
  ios::sync_with_stdio(false);
  // file(data);
  memset(dp, 0x3f3f3f3f, sizeof dp);
  dp[0] = 0;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= 550; j++) {
      if (dp[j] < a[i]) {
        dp[j ^ a[i]] = min(dp[j ^ a[i]], a[i]);
      }
    }
  }
  vector<int> ans;
  for (int i = 0; i <= 550; i++) {
    if (dp[i] != 0x3f3f3f3f) {
      ans.push_back(i);
    }
  }
  cout << ans.size() << "\n";
  for (int id : ans) {
    cout << id << " ";
  }
  return 0;
}