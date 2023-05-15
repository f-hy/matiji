/**
 * @file 1.cc
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
const int maxn = 1e3 + 1;
const int maxl = 1e9 + 1;
int n, l;
double ans, res, tmp;
set<int> ct;
int main() {
  ios::sync_with_stdio(false);
  //   file(data);
  cin >> n >> l;
  double* data = new double[n];
  rep(i, 0, n - 1) cin >> data[i];
  sort(data, data + n);
  rep(i, 0, n - 2) {
    tmp = data[i + 1] - data[i];
    if (res < tmp) res = tmp;
  }
  ans = res / 2.0;
  if (ans < data[0]) ans = data[0];
  tmp = l - data[n - 1];
  if (ans < tmp) ans = tmp;
  printf("%.2lf", ans);
  delete[] data;
  return 0;
}