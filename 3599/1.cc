/**
 * @file 1.cc
 * @author Friendy (friend0@qq.com)
 * @date 2023-06-03
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
const int maxn = 1e6 + 1;
const int maxcoef = 1e3;
const int maxexpn = 1e9;
int n, m;
pii ce1[maxn], ce2[maxn];  // coef expn
forward_list<pll> lp;
forward_list<pll>::iterator pre = lp.before_begin();
int main() {
  ios::sync_with_stdio(false);
  // file(data);
  cin >> n >> m;
  rep(i, 0, n - 1) cin >> ce1[i].first >> ce1[i].second;
  rep(i, 0, m - 1) cin >> ce2[i].first >> ce2[i].second;
  int i = 0, j = 0;
  ll tmp;
  while (i < n && j < m) {
    if (ce1[i].second == ce2[j].second) {
      tmp = ce1[i].first + ce2[j].first;
      pre = lp.emplace_after(pre, pll{tmp, ce1[i].second});
      ++i, ++j;
    } else if (ce1[i].second < ce2[i].second)
      pre = lp.emplace_after(pre, ce1[i++]);
    else
      pre = lp.emplace_after(pre, ce2[j++]);
  }
  while (i < n) pre = lp.emplace_after(pre, ce1[i++]);
  while (j < m) pre = lp.emplace_after(pre, ce2[j++]);
  for (pll &p : lp)
    if (p.first) cout << p.first << ' ' << p.second << endl;
  return 0;
}