/**
 * @file 3.cc
 * @author Friendy (friend0@qq.com)
 * @date 2023-05-21
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
int m, n;
int a[1024][1024];
int res[1024][1024];
int main() {
  ios::sync_with_stdio(false);
  // file(data);
  cin >> n >> m;
  memset(a, 0, sizeof(a));
  memset(res, 0, sizeof(res));
  while (m--) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    for (int i = x1; i <= x2; i++) {
      a[i][y1]++;
      a[i][y2 + 1]--;
    }
  }
  for (int i = 1; i <= n; i++) {
    int now = 0;
    for (int j = 1; j <= n; j++) {
      now += a[i][j];
      res[i][j] = now;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (j > 1) cout << " ";
      cout << res[i][j];
    }
    cout << endl;
  }
  return 0;
}