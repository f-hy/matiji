/**
 * @file 5.cc
 * @author Friendy (friend0@qq.com)
 * @date 2023-04-13
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
const int maxn = 201;
int n, m, k;
int rec[maxn][maxn];
vector<int> u;
int main() {
  ios::sync_with_stdio(false);
  // file(data);
  cin >> n >> m >> k;
  rep(i, 1, n) rep(j, 1, m) cin >> rec[i][j];
  rep(i, 1, m) u.push_back(rec[1][i]);
  rep(i, 2, n) {
    vector<int> a, v;
    sort(rec[i] + 1, rec[i] + 1 + m);
    rep(j, 1, k) v.push_back(rec[i][j]);
    for (int uu : u)
      for (int vv : v) a.push_back(uu + vv);
    sort(a.begin(), a.end());
    u.clear();
    for (int i = 0; i < k; i++) u.push_back(a[i]);
  }
  rep(i, 0, k - 1) cout << u[i] << ' ';
  return 0;
}